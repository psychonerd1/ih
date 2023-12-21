#include "z_en_aza.h"
#include "assets/objects/object_aza/object_aza.h"
#include "terminal.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnAza_Init(Actor* thisx, PlayState* play);
void EnAza_Destroy(Actor* thisx, PlayState* play);
void EnAza_Update(Actor* thisx, PlayState* play);
void EnAza_Draw(Actor* thisx, PlayState* play);

void EnAza_80A56544(EnAza* this, PlayState* play);
void EnAza_80A5673C(EnAza* this, PlayState* play);
void EnAza_80A56328(EnAza* this, PlayState* play);
void EnAza_80A563BC(EnAza* this, PlayState* play);
void EnAza_80A56B40(EnAza* this, PlayState* play);
void EnAza_80A56614(EnAza* this, PlayState* play);
void EnAza_80A56874(EnAza* this, PlayState* play);
void EnAza_80A56900(EnAza* this, PlayState* play);
void EnAza_80A56994(EnAza* this, PlayState* play);
void EnAza_80A56A50(EnAza* this, PlayState* play);
void EnAza_80A56ACC(EnAza* this, PlayState* play);

ActorInit En_Aza_InitVars = {
	ACTOR_EN_AZA,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_AZA,
    sizeof(EnAza),
    (ActorFunc)EnAza_Init,
    (ActorFunc)EnAza_Destroy,
    (ActorFunc)EnAza_Update,
    (ActorFunc)EnAza_Draw,
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

void EnAza_Init(Actor* thisx, PlayState* play) {
    EnAza* this = (EnAza*)thisx;

    Actor_SetScale(thisx, 0.01f);
    this->type = thisx->params & 0xFF;
    thisx->colChkInfo.mass = MASS_IMMOVABLE;
    this->pos = thisx->world.pos;
    thisx->targetMode = 6;
    this->height = 82.0f;
    ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawCircle, 25.0f);
    SkelAnime_InitFlex(play, &this->skelAnime, &gAzaSkel, &gAzaIdleAnim, this->jointTable, this->morphTable,
                   19);
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, thisx, &sCylinderInit);
    this->collider.dim.yShift = 0;
    this->collider.dim.radius = 15;
    this->collider.dim.height = 70;
    this->aza_27C = (thisx->params >> 8) & 0xFF;
    this->actionFunc = EnAza_80A563BC;
    osSyncPrintf("\n\n");
    osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 兵士２セット完了！ ☆☆☆☆☆ %d\n" VT_RST, thisx->params);
    osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ 識別完了！\t    ☆☆☆☆☆ %d\n" VT_RST, this->type);
    osSyncPrintf(VT_FGCOL(MAGENTA) " ☆☆☆☆☆ メッセージ完了！   ☆☆☆☆☆ %x\n\n" VT_RST, (thisx->params >> 8) & 0xF);
    osSyncPrintf("\n\n");
}

void EnAza_Destroy(Actor* thisx, PlayState* play) {
    EnAza* this = (EnAza*)thisx;

    Collider_DestroyCylinder(play, &this->collider);
}

void EnAza_80A56328(EnAza* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gAzaIdleAnim);

    Animation_Change(&this->skelAnime, &gAzaIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    this->actionFunc = EnAza_80A563BC;
}

void EnAza_80A563BC(EnAza* this, PlayState* play) {
    
    this->aza_2B4 = 0;
	if (IS_DAY) {
            if (this->aza_284 == 0) {
                this->actor.textId = 0x5063;
            } else {
                this->actor.textId = 0x5064;
            }
        } else if (this->aza_284 == 0) {
            this->actor.textId = 0x5066;
        } else {
            this->actor.textId = 0x5067;
        }

        this->actionFunc = EnAza_80A56B40;
}

void EnAza_80A56544(EnAza* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gAzaIdleAnim);

    Animation_Change(&this->skelAnime, &gAzaIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    if (LINK_AGE_IN_YEARS == YEARS_CHILD) {
        osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ ぎゃぁ！オトナだー ☆☆☆☆☆ \n" VT_RST);
        Actor_Kill(&this->actor);
    } else {
        this->actionFunc = EnAza_80A56614;
    }
}

void EnAza_80A56614(EnAza* this, PlayState* play) {

    this->aza_2B4 = 0;
	this->actor.textId = 0x7003;
    this->actionFunc = EnAza_80A56B40;
}

void EnAza_80A5673C(EnAza* this, PlayState* play) {
    if (GET_EVENTCHKINF(EVENTCHKINF_45)) {
        osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ マスターソード祝入手！ ☆☆☆☆☆ \n" VT_RST);
        Actor_Kill(&this->actor);
        return;
    }
    this->aza_284 = 0;
    if (GET_EVENTCHKINF(EVENTCHKINF_80)) {
        if (!GET_INFTABLE(INFTABLE_6C)) {
            f32 frames = Animation_GetLastFrame(&gAzaIdleAnim);
            Animation_Change(&this->skelAnime, &gAzaIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP,
                             -10.0f);
            this->actor.textId = 0x7007;
            this->aza_282 = TEXT_STATE_EVENT;
            this->aza_284 = 1;
            osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ デモ開始！ ☆☆☆☆☆ \n" VT_RST);
        } else {
            this->actor.textId = 0x7008;
            this->aza_282 = TEXT_STATE_DONE;
            osSyncPrintf(VT_FGCOL(BLUE) " ☆☆☆☆☆ 返事なし ☆☆☆☆☆ \n" VT_RST);
        }
        this->actionFunc = EnAza_80A56874;
    } else {
        Actor_Kill(&this->actor);
    }
}

void EnAza_80A56874(EnAza* this, PlayState* play) {
    if (this->aza_284 != 0) {
        SkelAnime_Update(&this->skelAnime);
    }
    if (Actor_ProcessTalkRequest(&this->actor, play)) {
        if (this->aza_284 == 0) {
            this->actionFunc = EnAza_80A5673C;

        } else {
            this->actionFunc = EnAza_80A56900;
        }
    } else {
       func_8002F2CC(&this->actor, play, 100.0f);
    }
}

void EnAza_80A56900(EnAza* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gAzaIdleAnim);

    Animation_Change(&this->skelAnime, &gAzaIdleAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    this->actionFunc = EnAza_80A56994;
}

void EnAza_80A56994(EnAza* this, PlayState* play) {
    SkelAnime_Update(&this->skelAnime);
    Actor_TrackPlayer(play, &this->actor, &this->headRot, &this->torsoRot, this->actor.focus.pos);
    if ((this->aza_282 == Message_GetState(&play->msgCtx)) && Message_ShouldAdvance(play)) {
        Message_CloseTextbox(play);
        SET_INFTABLE(INFTABLE_6C);
        func_8002DF54(play, NULL, PLAYER_CSACTION_8);
        this->actionFunc = EnAza_80A56A50;
    }
}

void EnAza_80A56A50(EnAza* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gAzaIdleAnim);

    this->aza_288 = frames;
    Animation_Change(&this->skelAnime, &gAzaIdleAnim, 1.0f, 0.0f, frames, ANIMMODE_ONCE, -10.0f);
    this->actionFunc = EnAza_80A56ACC;
}

void EnAza_80A56ACC(EnAza* this, PlayState* play) {
    f32 currentFrame = this->skelAnime.curFrame;

    SkelAnime_Update(&this->skelAnime);
    if (this->aza_288 <= currentFrame) {
        func_8002DF54(play, NULL, PLAYER_CSACTION_7);
        this->actionFunc = EnAza_80A5673C;
    }
}

void EnAza_80A56B40(EnAza* this, PlayState* play) {
    SkelAnime_Update(&this->skelAnime);
    Actor_TrackPlayer(play, &this->actor, &this->headRot, &this->torsoRot, this->actor.focus.pos);
    func_8002F2F4(&this->actor, play);
}

void EnAza_Update(Actor* thisx, PlayState* play) {
    EnAza* this = (EnAza*)thisx;
    s32 pad;
    Player* player = GET_PLAYER(play);
    thisx->world.pos.x = this->pos.x;
    thisx->world.pos.y = this->pos.y;
    thisx->world.pos.z = this->pos.z;
    Actor_SetFocus(thisx, this->height);
    this->aza_27E++;
    this->actionFunc(this, play);
    Actor_MoveXZGravity(thisx);
    Actor_UpdateBgCheckInfo(play, thisx, 10.0f, 10.0f, 30.0f,
                            UPDBGCHECKINFO_FLAG_0 | UPDBGCHECKINFO_FLAG_2 | UPDBGCHECKINFO_FLAG_3 |
                                UPDBGCHECKINFO_FLAG_4);
    Collider_UpdateCylinder(&this->actor, &this->collider);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
}

s32 EnAza_OverrideLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnAza* this = (EnAza*)thisx;
    if (limbIndex == 2) {
        rot->x += this->torsoRot.y;
    }
    if (limbIndex == 3) {
        rot->y -= this->headRot.y;
        rot->z -= this->headRot.z;
    }
    return false;
}

void EnAza_Draw(Actor* thisx, PlayState* play) {
    EnAza* this = (EnAza*)thisx;

    Gfx_SetupDL_25Opa(play->state.gfxCtx);
    SkelAnime_DrawFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount,
                      EnAza_OverrideLimbDraw, NULL, this);
}
