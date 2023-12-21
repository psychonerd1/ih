#include "z_en_nir.h"
#include "assets/objects/object_nir/object_nir.h"
#include "terminal.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnNir_Init(Actor* thisx, PlayState* play);
void EnNir_Destroy(Actor* thisx, PlayState* play);
void EnNir_Update(Actor* thisx, PlayState* play);
void EnNir_Draw(Actor* thisx, PlayState* play);

void EnNir_80A56544(EnNir* this, PlayState* play);
void EnNir_80A5673C(EnNir* this, PlayState* play);
void EnNir_80A56328(EnNir* this, PlayState* play);
void EnNir_80A563BC(EnNir* this, PlayState* play);
void EnNir_80A56B40(EnNir* this, PlayState* play);
void EnNir_80A56614(EnNir* this, PlayState* play);
void EnNir_80A56874(EnNir* this, PlayState* play);
void EnNir_80A56900(EnNir* this, PlayState* play);
void EnNir_80A56994(EnNir* this, PlayState* play);
void EnNir_80A56A50(EnNir* this, PlayState* play);
void EnNir_80A56ACC(EnNir* this, PlayState* play);

ActorInit En_Nir_InitVars = {
	ACTOR_EN_NIR,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_NIR,
    sizeof(EnNir),
    (ActorFunc)EnNir_Init,
    (ActorFunc)EnNir_Destroy,
    (ActorFunc)EnNir_Update,
    (ActorFunc)EnNir_Draw,
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

void EnNir_Init(Actor* thisx, PlayState* play) {
    EnNir* this = (EnNir*)thisx;

    Actor_SetScale(thisx, 0.01f);
    this->type = thisx->params & 0xFF;
    thisx->colChkInfo.mass = MASS_IMMOVABLE;
    this->pos = thisx->world.pos;
    thisx->targetMode = 6;
    this->height = 54.0f;
    ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawCircle, 25.0f);
    SkelAnime_InitFlex(play, &this->skelAnime, &gNiraelSkel, &gNiraelIdleAnim, this->jointTable, this->morphTable,
                   19);
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, thisx, &sCylinderInit);
    this->collider.dim.yShift = 0;
    this->collider.dim.radius = 15;
    this->collider.dim.height = 70;
    this->nir_27C = (thisx->params >> 8) & 0xFF;
    this->actionFunc = EnNir_80A56544;
    osSyncPrintf("\n\n");
    osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 兵士２セット完了！ ☆☆☆☆☆ %d\n" VT_RST, thisx->params);
    osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ 識別完了！\t    ☆☆☆☆☆ %d\n" VT_RST, this->type);
    osSyncPrintf(VT_FGCOL(MAGENTA) " ☆☆☆☆☆ メッセージ完了！   ☆☆☆☆☆ %x\n\n" VT_RST, (thisx->params >> 8) & 0xF);
    osSyncPrintf("\n\n");
}

void EnNir_Destroy(Actor* thisx, PlayState* play) {
    EnNir* this = (EnNir*)thisx;

    Collider_DestroyCylinder(play, &this->collider);
}

void EnNir_80A56328(EnNir* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gNiraelIdleAnim);

    Animation_Change(&this->skelAnime, &gNiraelIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    this->actionFunc = EnNir_80A563BC;
}

void EnNir_80A563BC(EnNir* this, PlayState* play) {

    this->nir_2B4 = 0;
	if (IS_DAY) {
            if (this->nir_284 == 0) {
                this->actor.textId = 0x5063;
            } else {
                this->actor.textId = 0x5064;
            }
        } else if (this->nir_284 == 0) {
            this->actor.textId = 0x5066;
        } else {
            this->actor.textId = 0x5067;
        }

        this->actionFunc = EnNir_80A56B40;
    }

void EnNir_80A56544(EnNir* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gNiraelIdleAnim);

    Animation_Change(&this->skelAnime, &gNiraelIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    this->actionFunc = EnNir_80A56614;
}

void EnNir_80A56614(EnNir* this, PlayState* play) {
    this->nir_2B4 = 0;
	this->actor.textId = 0x7001;
    this->actionFunc = EnNir_80A56B40;
}

void EnNir_80A5673C(EnNir* this, PlayState* play) {
    if (GET_EVENTCHKINF(EVENTCHKINF_45)) {
        osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ マスターソード祝入手！ ☆☆☆☆☆ \n" VT_RST);
        Actor_Kill(&this->actor);
        return;
    }
    this->nir_284 = 0;
    if (GET_EVENTCHKINF(EVENTCHKINF_80)) {
        if (!GET_INFTABLE(INFTABLE_6C)) {
            f32 frames = Animation_GetLastFrame(&gNiraelIdleAnim);
            Animation_Change(&this->skelAnime, &gNiraelIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP,
                             -10.0f);
            this->actor.textId = 0x7003;
            this->nir_282 = TEXT_STATE_EVENT;
            this->nir_284 = 1;
            osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ デモ開始！ ☆☆☆☆☆ \n" VT_RST);
        } else {
            this->actor.textId = 0x7003;
            this->nir_282 = TEXT_STATE_DONE;
            osSyncPrintf(VT_FGCOL(BLUE) " ☆☆☆☆☆ 返事なし ☆☆☆☆☆ \n" VT_RST);
        }
        this->actionFunc = EnNir_80A56874;
    } else {
        Actor_Kill(&this->actor);
    }
}

void EnNir_80A56874(EnNir* this, PlayState* play) {
    if (this->nir_284 != 0) {
        SkelAnime_Update(&this->skelAnime);
    }
    if (Actor_ProcessTalkRequest(&this->actor, play)) {
        { this->actionFunc = EnNir_80A56900; }
    } else {
       func_8002F2CC(&this->actor, play, 100.0f);
    }
}

void EnNir_80A56900(EnNir* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gNiraelIdleAnim);

    Animation_Change(&this->skelAnime, &gNiraelIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    this->actionFunc = EnNir_80A56994;
}

void EnNir_80A56994(EnNir* this, PlayState* play) {
    SkelAnime_Update(&this->skelAnime);
    Actor_TrackPlayer(play, &this->actor, &this->headRot, &this->torsoRot, this->actor.focus.pos);
    if ((this->nir_282 == Message_GetState(&play->msgCtx)) && Message_ShouldAdvance(play)) {
        Message_CloseTextbox(play);
        SET_INFTABLE(INFTABLE_6C);
        func_8002DF54(play, NULL, PLAYER_CSACTION_8);
        this->actionFunc = EnNir_80A56A50;
    }
}

void EnNir_80A56A50(EnNir* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gNiraelIdleAnim);
    this->nir_2B4 = 0;
    this->nir_288 = frames;
    Animation_Change(&this->skelAnime, &gNiraelIdleAnim, 1.0f, 0.0f, frames, ANIMMODE_ONCE, -10.0f);
    this->actionFunc = EnNir_80A56B40;
}

void EnNir_80A56ACC(EnNir* this, PlayState* play) {
    f32 currentFrame = this->skelAnime.curFrame;

    SkelAnime_Update(&this->skelAnime);
    if (this->nir_288 <= currentFrame) {
        func_8002DF54(play, NULL, PLAYER_CSACTION_7);
        this->actionFunc = EnNir_80A5673C;
    }
}

void EnNir_80A56B40(EnNir* this, PlayState* play) {
    SkelAnime_Update(&this->skelAnime);
    Actor_TrackPlayer(play, &this->actor, &this->headRot, &this->torsoRot, this->actor.focus.pos);
    func_8002F2F4(&this->actor, play);
}

void EnNir_Update(Actor* thisx, PlayState* play) {
    EnNir* this = (EnNir*)thisx;
    s32 pad;
    Player* player = GET_PLAYER(play);
	if (this->faceState == 1) {
		this->faceTimer = 80;
		this->faceState = 0;
	}
    if (this->faceTimer == 0) {
		this->faceState = 1;
    }
    this->faceTimer--;
    thisx->world.pos.x = this->pos.x;
    thisx->world.pos.y = this->pos.y;
    thisx->world.pos.z = this->pos.z;
    Actor_SetFocus(thisx, this->height);
    this->interactInfo.trackPos = player->actor.world.pos;
    Npc_TrackPoint(thisx, &this->interactInfo, 2, NPC_TRACKING_FULL_BODY);
    this->headRot = this->interactInfo.headRot;
    this->torsoRot = this->interactInfo.torsoRot;
    this->nir_27E++;
    this->actionFunc(this, play);
    Actor_MoveXZGravity(thisx);
    Actor_UpdateBgCheckInfo(play, thisx, 10.0f, 10.0f, 30.0f,
                            UPDBGCHECKINFO_FLAG_0 | UPDBGCHECKINFO_FLAG_2 | UPDBGCHECKINFO_FLAG_3 |
                                UPDBGCHECKINFO_FLAG_4);
    Collider_UpdateCylinder(&this->actor, &this->collider);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
}

s32 EnNir_OverrideLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnNir* this = (EnNir*)thisx;
    if (limbIndex == 3) {
        rot->z -= this->headRot.z;
    }
    return false;
}

void EnNir_Draw(Actor* thisx, PlayState* play) {
    static void* sNiraelEyeTextures[] = { gNiraelSkel_eyes_half_rgba16, gNiraelSkel_eyes_closed_rgba16, NULL, NULL };
    EnNir* this = (EnNir*)thisx;
    OPEN_DISPS(play->state.gfxCtx, __FILE__, __LINE__);

    Gfx_SetupDL_25Opa(play->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sNiraelEyeTextures[this->faceState]));
    SkelAnime_DrawFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount,
                      EnNir_OverrideLimbDraw, NULL, this);
    CLOSE_DISPS(play->state.gfxCtx, __FILE__, __LINE__);
}
