#include "z_en_lir.h"
#include "assets/objects/object_lir/object_lir.h"
#include "terminal.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnLir_Init(Actor* thisx, PlayState* play);
void EnLir_Destroy(Actor* thisx, PlayState* play);
void EnLir_Update(Actor* thisx, PlayState* play);
void EnLir_Draw(Actor* thisx, PlayState* play);

void EnLir_80A56544(EnLir* this, PlayState* play);
void EnLir_80A5673C(EnLir* this, PlayState* play);
void EnLir_80A56328(EnLir* this, PlayState* play);
void EnLir_80A563BC(EnLir* this, PlayState* play);
void EnLir_80A56B40(EnLir* this, PlayState* play);
void EnLir_80A56614(EnLir* this, PlayState* play);
void EnLir_80A56874(EnLir* this, PlayState* play);
void EnLir_80A56900(EnLir* this, PlayState* play);
void EnLir_80A56994(EnLir* this, PlayState* play);
void EnLir_80A56A50(EnLir* this, PlayState* play);
void EnLir_80A56ACC(EnLir* this, PlayState* play);

ActorInit En_Lir_InitVars = {
	ACTOR_EN_LIR,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_LIR,
    sizeof(EnLir),
    (ActorFunc)EnLir_Init,
    (ActorFunc)EnLir_Destroy,
    (ActorFunc)EnLir_Update,
    (ActorFunc)EnLir_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 33, 40, 0, { 0, 0, 0 } },
};

void EnLir_Init(Actor* thisx, PlayState* play) {
    EnLir* this = (EnLir*)thisx;

    Actor_SetScale(thisx, 0.01f);
    this->type = thisx->params & 0xFF;
    thisx->colChkInfo.mass = MASS_IMMOVABLE;
    this->pos = thisx->world.pos;
    thisx->targetMode = 6;
    this->height = 54.0f;
    ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawCircle, 25.0f);
    SkelAnime_InitFlex(play, &this->skelAnime, &gLirianSkel, &gLirianIdleAnim, this->jointTable, this->morphTable,
                   20);
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, thisx, &sCylinderInit);
    this->collider.dim.yShift = 0;
    this->collider.dim.radius = 15;
    this->collider.dim.height = 70;
    this->lir_27C = (thisx->params >> 8) & 0xFF;
    this->actionFunc = EnLir_80A56544;
    osSyncPrintf("\n\n");
    osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 兵士２セット完了！ ☆☆☆☆☆ %d\n" VT_RST, thisx->params);
    osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ 識別完了！\t    ☆☆☆☆☆ %d\n" VT_RST, this->type);
    osSyncPrintf(VT_FGCOL(MAGENTA) " ☆☆☆☆☆ メッセージ完了！   ☆☆☆☆☆ %x\n\n" VT_RST, (thisx->params >> 8) & 0xF);
    osSyncPrintf("\n\n");
}

void EnLir_Destroy(Actor* thisx, PlayState* play) {
    EnLir* this = (EnLir*)thisx;

    Collider_DestroyCylinder(play, &this->collider);
}

void EnLir_80A56328(EnLir* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gLirianIdleAnim);

    Animation_Change(&this->skelAnime, &gLirianIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    this->actionFunc = EnLir_80A563BC;
}

void EnLir_80A563BC(EnLir* this, PlayState* play) {

    this->lir_2B4 = 0;
	if (IS_DAY) {
            if (this->lir_284 == 0) {
                this->actor.textId = 0x5063;
            } else {
                this->actor.textId = 0x5064;
            }
        } else if (this->lir_284 == 0) {
            this->actor.textId = 0x5066;
        } else {
            this->actor.textId = 0x5067;
        }

        this->actionFunc = EnLir_80A56B40;
    }

void EnLir_80A56544(EnLir* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gLirianIdleAnim);

    Animation_Change(&this->skelAnime, &gLirianIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    this->actionFunc = EnLir_80A56614;
}

void EnLir_80A56614(EnLir* this, PlayState* play) {
    this->lir_2B4 = 0;
	this->actor.textId = 0x7002;
    this->actionFunc = EnLir_80A56B40;
}

void EnLir_80A5673C(EnLir* this, PlayState* play) {
    if (GET_EVENTCHKINF(EVENTCHKINF_45)) {
        osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ マスターソード祝入手！ ☆☆☆☆☆ \n" VT_RST);
        Actor_Kill(&this->actor);
        return;
    }
    this->lir_284 = 0;
    if (GET_EVENTCHKINF(EVENTCHKINF_80)) {
        if (!GET_INFTABLE(INFTABLE_6C)) {
            f32 frames = Animation_GetLastFrame(&gLirianIdleAnim);
            Animation_Change(&this->skelAnime, &gLirianIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP,
                             -10.0f);
            this->actor.textId = 0x7003;
            this->lir_282 = TEXT_STATE_EVENT;
            this->lir_284 = 1;
            osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ デモ開始！ ☆☆☆☆☆ \n" VT_RST);
        } else {
            this->actor.textId = 0x7003;
            this->lir_282 = TEXT_STATE_DONE;
            osSyncPrintf(VT_FGCOL(BLUE) " ☆☆☆☆☆ 返事なし ☆☆☆☆☆ \n" VT_RST);
        }
        this->actionFunc = EnLir_80A56874;
    } else {
        Actor_Kill(&this->actor);
    }
}

void EnLir_80A56874(EnLir* this, PlayState* play) {
    if (this->lir_284 != 0) {
        SkelAnime_Update(&this->skelAnime);
    }
    if (Actor_ProcessTalkRequest(&this->actor, play)) {
        { this->actionFunc = EnLir_80A56900; }
    } else {
       func_8002F2CC(&this->actor, play, 100.0f);
    }
}

void EnLir_80A56900(EnLir* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gLirianIdleAnim);

    Animation_Change(&this->skelAnime, &gLirianIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    this->actionFunc = EnLir_80A56994;
}

void EnLir_80A56994(EnLir* this, PlayState* play) {
    SkelAnime_Update(&this->skelAnime);
    Actor_TrackPlayer(play, &this->actor, &this->headRot, &this->torsoRot, this->actor.focus.pos);
    if ((this->lir_282 == Message_GetState(&play->msgCtx)) && Message_ShouldAdvance(play)) {
        Message_CloseTextbox(play);
        SET_INFTABLE(INFTABLE_6C);
        func_8002DF54(play, NULL, PLAYER_CSACTION_8);
        this->actionFunc = EnLir_80A56A50;
    }
}

void EnLir_80A56A50(EnLir* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gLirianIdleAnim);
    this->lir_2B4 = 0;
    this->lir_288 = frames;
    Animation_Change(&this->skelAnime, &gLirianIdleAnim, 1.0f, 0.0f, frames, ANIMMODE_ONCE, -10.0f);
    this->actionFunc = EnLir_80A56B40;
}

void EnLir_80A56ACC(EnLir* this, PlayState* play) {
    f32 currentFrame = this->skelAnime.curFrame;

    SkelAnime_Update(&this->skelAnime);
    if (this->lir_288 <= currentFrame) {
        func_8002DF54(play, NULL, PLAYER_CSACTION_7);
        this->actionFunc = EnLir_80A5673C;
    }
}

void EnLir_80A56B40(EnLir* this, PlayState* play) {
    SkelAnime_Update(&this->skelAnime);
    Actor_TrackPlayer(play, &this->actor, &this->headRot, &this->torsoRot, this->actor.focus.pos);
    func_8002F2F4(&this->actor, play);
}

void EnLir_Update(Actor* thisx, PlayState* play) {
    EnLir* this = (EnLir*)thisx;
    s32 pad;
    Player* player = GET_PLAYER(play);
 	if (this->faceState > 0) {
		this->faceState++;
        if (this->faceState > 2) {
            this->faceState = 0;
        }
	}
    if (this->faceTimer == 0) {
        this->faceState++;
        this->faceTimer = 60;
    }
	this->faceTimer--;

    thisx->world.pos.x = this->pos.x;
    thisx->world.pos.y = this->pos.y;
    thisx->world.pos.z = this->pos.z;
    Actor_SetFocus(thisx, this->height);
    this->lir_27E++;
    this->actionFunc(this, play);
    Actor_MoveXZGravity(thisx);
    Actor_UpdateBgCheckInfo(play, thisx, 10.0f, 10.0f, 30.0f,
                            UPDBGCHECKINFO_FLAG_0 | UPDBGCHECKINFO_FLAG_2 | UPDBGCHECKINFO_FLAG_3 |
                                UPDBGCHECKINFO_FLAG_4);
    Collider_UpdateCylinder(&this->actor, &this->collider);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
}

s32 EnLir_OverrideLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnLir* this = (EnLir*)thisx;
    if (limbIndex == 2) {
        rot->x += this->torsoRot.y;
    }
    if (limbIndex == 3) {
        rot->y -= this->headRot.y;
        rot->z -= this->headRot.z;
    }
    return false;
}

void EnLir_Draw(Actor* thisx, PlayState* play) {
    static void* sLirianEyeTextures[] = { gLirianSkel_lirian_eye_open_rgba16, gLirianSkel_lirian_eye_half_rgba16, gLirianSkel_lirian_eye_closed_rgba16, NULL };
    EnLir* this = (EnLir*)thisx;
    OPEN_DISPS(play->state.gfxCtx, __FILE__, __LINE__);

    Gfx_SetupDL_25Opa(play->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sLirianEyeTextures[this->faceState]));
    SkelAnime_DrawFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount,
                      EnLir_OverrideLimbDraw, NULL, this);
    CLOSE_DISPS(play->state.gfxCtx, __FILE__, __LINE__);
}
