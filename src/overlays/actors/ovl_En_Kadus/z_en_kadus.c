#include "z_en_kadus.h"
#include "assets/objects/object_kad/object_kad.h"
#include "terminal.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnKadus_Init(Actor* thisx, PlayState* play);
void EnKadus_Destroy(Actor* thisx, PlayState* play);
void EnKadus_Update(Actor* thisx, PlayState* play);
void EnKadus_Draw(Actor* thisx, PlayState* play);

void EnKadus_80A56544(EnKadus* this, PlayState* play);
void EnKadus_80A5673C(EnKadus* this, PlayState* play);
void EnKadus_80A56328(EnKadus* this, PlayState* play);
void EnKadus_80A563BC(EnKadus* this, PlayState* play);
void EnKadus_80A56B40(EnKadus* this, PlayState* play);
void EnKadus_80A56614(EnKadus* this, PlayState* play);
void EnKadus_80A56874(EnKadus* this, PlayState* play);
void EnKadus_80A56900(EnKadus* this, PlayState* play);
void EnKadus_80A56994(EnKadus* this, PlayState* play);
void EnKadus_80A56A50(EnKadus* this, PlayState* play);
void EnKadus_80A56ACC(EnKadus* this, PlayState* play);

ActorInit En_Kadus_InitVars = {
	ACTOR_EN_KADUS,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_KAD,
    sizeof(EnKadus),
    (ActorFunc)EnKadus_Init,
    (ActorFunc)EnKadus_Destroy,
    (ActorFunc)EnKadus_Update,
    (ActorFunc)EnKadus_Draw,
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

void EnKadus_Init(Actor* thisx, PlayState* play) {
    EnKadus* this = (EnKadus*)thisx;

    Actor_SetScale(thisx, 0.01f);
    this->type = thisx->params & 0xFF;
    thisx->colChkInfo.mass = MASS_IMMOVABLE;
    this->pos = thisx->world.pos;
    thisx->targetMode = 6;
    this->height = 54.0f;
    this->faceTimer = Rand_S16Offset(80, 80);
	this->freakoutTimer = Rand_S16Offset(4, 12);
    ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawCircle, 25.0f);
    SkelAnime_InitFlex(play, &this->skelAnime, &gKadusSkel, &gKadusFreakoutAnim, this->jointTable, this->morphTable,
                   19);
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, thisx, &sCylinderInit);
    this->collider.dim.yShift = 0;
    this->collider.dim.radius = 15;
    this->collider.dim.height = 70;
    this->kad_27C = (thisx->params >> 8) & 0xFF;
    this->actionFunc = EnKadus_80A56544;
    osSyncPrintf("\n\n");
    osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 兵士２セット完了！ ☆☆☆☆☆ %d\n" VT_RST, thisx->params);
    osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ 識別完了！\t    ☆☆☆☆☆ %d\n" VT_RST, this->type);
    osSyncPrintf(VT_FGCOL(MAGENTA) " ☆☆☆☆☆ メッセージ完了！   ☆☆☆☆☆ %x\n\n" VT_RST, (thisx->params >> 8) & 0xF);
    osSyncPrintf("\n\n");
}

void EnKadus_Destroy(Actor* thisx, PlayState* play) {
    EnKadus* this = (EnKadus*)thisx;

    Collider_DestroyCylinder(play, &this->collider);
}

void EnKadus_80A56328(EnKadus* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gKadusIdleAnim);

    Animation_Change(&this->skelAnime, &gKadusIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    this->actionFunc = EnKadus_80A563BC;
}

void EnKadus_80A563BC(EnKadus* this, PlayState* play) {

    this->kad_2B4 = 0;
	if (IS_DAY) {
            if (this->kad_284 == 0) {
                this->actor.textId = 0x5063;
            } else {
                this->actor.textId = 0x5064;
            }
        } else if (this->kad_284 == 0) {
            this->actor.textId = 0x5066;
        } else {
            this->actor.textId = 0x5067;
        }

        this->actionFunc = EnKadus_80A56B40;
    }

void EnKadus_80A56544(EnKadus* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gKadusIdleAnim);

    Animation_Change(&this->skelAnime, &gKadusIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    this->actionFunc = EnKadus_80A56614;
}

void EnKadus_80A56614(EnKadus* this, PlayState* play) {
    this->kad_2B4 = 0;
	this->actor.textId = 0x7003;
    this->actionFunc = EnKadus_80A56B40;
}

void EnKadus_80A5673C(EnKadus* this, PlayState* play) {
    if (GET_EVENTCHKINF(EVENTCHKINF_45)) {
        osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ マスターソード祝入手！ ☆☆☆☆☆ \n" VT_RST);
        Actor_Kill(&this->actor);
        return;
    }
    this->kad_284 = 0;
    if (GET_EVENTCHKINF(EVENTCHKINF_80)) {
        if (!GET_INFTABLE(INFTABLE_6C)) {
            f32 frames = Animation_GetLastFrame(&gKadusIdleAnim);
            Animation_Change(&this->skelAnime, &gKadusIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP,
                             -10.0f);
            this->actor.textId = 0x7003;
            this->kad_282 = TEXT_STATE_EVENT;
            this->kad_284 = 1;
            osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ デモ開始！ ☆☆☆☆☆ \n" VT_RST);
        } else {
            this->actor.textId = 0x7003;
            this->kad_282 = TEXT_STATE_DONE;
            osSyncPrintf(VT_FGCOL(BLUE) " ☆☆☆☆☆ 返事なし ☆☆☆☆☆ \n" VT_RST);
        }
        this->actionFunc = EnKadus_80A56874;
    } else {
        Actor_Kill(&this->actor);
    }
}

void EnKadus_80A56874(EnKadus* this, PlayState* play) {
    if (this->kad_284 != 0) {
        SkelAnime_Update(&this->skelAnime);
    }
    if (Actor_ProcessTalkRequest(&this->actor, play)) {
        { this->actionFunc = EnKadus_80A56900; }
    } else {
       func_8002F2CC(&this->actor, play, 100.0f);
    }
}

void EnKadus_80A56900(EnKadus* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gKadusIdleAnim);

    Animation_Change(&this->skelAnime, &gKadusIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    this->actionFunc = EnKadus_80A56994;
}

void EnKadus_80A56994(EnKadus* this, PlayState* play) {
    SkelAnime_Update(&this->skelAnime);
    Actor_TrackPlayer(play, &this->actor, &this->headRot, &this->torsoRot, this->actor.focus.pos);
    if ((this->kad_282 == Message_GetState(&play->msgCtx)) && Message_ShouldAdvance(play)) {
        Message_CloseTextbox(play);
        SET_INFTABLE(INFTABLE_6C);
        func_8002DF54(play, NULL, PLAYER_CSACTION_8);
        this->actionFunc = EnKadus_80A56A50;
    }
}

void EnKadus_80A56A50(EnKadus* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gKadusIdleAnim);
    this->kad_2B4 = 0;
    this->kad_288 = frames;
    Animation_Change(&this->skelAnime, &gKadusIdleAnim, 1.0f, 0.0f, frames, ANIMMODE_ONCE, -10.0f);
    this->actionFunc = EnKadus_80A56B40;
}

void EnKadus_80A56ACC(EnKadus* this, PlayState* play) {
    f32 currentFrame = this->skelAnime.curFrame;

    SkelAnime_Update(&this->skelAnime);
    if (this->kad_288 <= currentFrame) {
        func_8002DF54(play, NULL, PLAYER_CSACTION_7);
        this->actionFunc = EnKadus_80A5673C;
    }
}

void EnKadus_80A56B40(EnKadus* this, PlayState* play) {
    SkelAnime_Update(&this->skelAnime);
    Actor_TrackPlayer(play, &this->actor, &this->headRot, &this->torsoRot, this->actor.focus.pos);
    func_8002F2F4(&this->actor, play);
}

void EnKadus_Update(Actor* thisx, PlayState* play) {
    EnKadus* this = (EnKadus*)thisx;
    s32 pad;
    f32 frames;
    Player* player = GET_PLAYER(play);
    if (this->faceTimer == 0) {
        (this->faceState = Rand_S16Offset(1, 3));
        (this->faceTimer = Rand_S16Offset(80, 80));
    }
    if (this->skelAnime.animation == &gKadusIdleAnim) {
        if (Animation_OnFrame(&this->skelAnime, Animation_GetLastFrame(&gKadusIdleAnim))) {
            if (this->freakoutTimer > 0) {
                this->freakoutTimer--;
            } else {
            this->freakoutTimer = Rand_S16Offset(4, 12);
            frames = Animation_GetLastFrame(&gKadusFreakoutAnim);
            Animation_Change(&this->skelAnime, &gKadusFreakoutAnim, 1.0f, 0.0f, frames, ANIMMODE_ONCE, 0.0f); //If the end value is not 0 the game crashes. WTF
            }
        }
    } else if (this->skelAnime.animation == &gKadusFreakoutAnim) {
       if (Animation_OnFrame(&this->skelAnime, Animation_GetLastFrame(&gKadusFreakoutAnim))) {
            frames = Animation_GetLastFrame(&gKadusIdleAnim);
            Animation_Change(&this->skelAnime, &gKadusIdleAnim, 1.0f, 0.0f, frames, ANIMMODE_LOOP, 0.0f);
        }
    } 
    this->faceTimer--;
    thisx->world.pos.x = this->pos.x;
    thisx->world.pos.y = this->pos.y;
    thisx->world.pos.z = this->pos.z;
    Actor_SetFocus(thisx, this->height);
    this->kad_27E++;
    this->actionFunc(this, play);
    Actor_MoveXZGravity(thisx);
    Actor_UpdateBgCheckInfo(play, thisx, 10.0f, 10.0f, 30.0f,
                            UPDBGCHECKINFO_FLAG_0 | UPDBGCHECKINFO_FLAG_2 | UPDBGCHECKINFO_FLAG_3 |
                                UPDBGCHECKINFO_FLAG_4);
    Collider_UpdateCylinder(&this->actor, &this->collider);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
}

s32 EnKadus_OverrideLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnKadus* this = (EnKadus*)thisx;
    if (limbIndex == 2) {
        rot->x += this->torsoRot.y;
    }
    if (limbIndex == 3) {
        rot->y -= this->headRot.y;
        rot->z -= this->headRot.z;
    }
    return false;
}

void EnKadus_Draw(Actor* thisx, PlayState* play) {
    static void* sKadusMouthTextures[] = { gKadusSkel_mouth_1_ci8, gKadusSkel_mouth_2_ci8, gKadusSkel_mouth_3_ci8, gKadusSkel_mouth_4_ci8 };
    EnKadus* this = (EnKadus*)thisx;
    OPEN_DISPS(play->state.gfxCtx, __FILE__, __LINE__);

    Gfx_SetupDL_25Opa(play->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(sKadusMouthTextures[this->faceState]));
    SkelAnime_DrawFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount,
                      EnKadus_OverrideLimbDraw, NULL, this);
    CLOSE_DISPS(play->state.gfxCtx, __FILE__, __LINE__);
}
