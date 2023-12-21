#include "z_en_met1.h"
#include "assets/objects/object_met1/object_met1.h"
#include "terminal.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3)

void EnMet1_Init(Actor* thisx, PlayState* play);
void EnMet1_Destroy(Actor* thisx, PlayState* play);
void EnMet1_Update(Actor* thisx, PlayState* play);
void EnMet1_Draw(Actor* thisx, PlayState* play);

void EnMet1_80A56544(EnMet1* this, PlayState* play);
void EnMet1_80A5673C(EnMet1* this, PlayState* play);
void EnMet1_80A56328(EnMet1* this, PlayState* play);
void EnMet1_80A563BC(EnMet1* this, PlayState* play);
void EnMet1_80A56B40(EnMet1* this, PlayState* play);
void EnMet1_80A56614(EnMet1* this, PlayState* play);
void EnMet1_80A56874(EnMet1* this, PlayState* play);
void EnMet1_80A56900(EnMet1* this, PlayState* play);
void EnMet1_80A56994(EnMet1* this, PlayState* play);
void EnMet1_80A56A50(EnMet1* this, PlayState* play);
void EnMet1_80A56ACC(EnMet1* this, PlayState* play);

ActorInit En_Met1_InitVars = {
	ACTOR_EN_MET1,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MET1,
    sizeof(EnMet1),
    (ActorFunc)EnMet1_Init,
    (ActorFunc)EnMet1_Destroy,
    (ActorFunc)EnMet1_Update,
    (ActorFunc)EnMet1_Draw,
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

void EnMet1_Init(Actor* thisx, PlayState* play) {
    EnMet1* this = (EnMet1*)thisx;

    Actor_SetScale(thisx, 0.01f);
    this->type = thisx->params & 0xFF;
    thisx->colChkInfo.mass = MASS_IMMOVABLE;
    this->pos = thisx->world.pos;
    thisx->targetMode = 6;
    this->height = 30.0f;
    ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawCircle, 55.0f);
    SkelAnime_InitFlex(play, &this->skelAnime, &gMetSkel, &gMetHammeringAnim, this->jointTable, this->morphTable,
                   12);
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, thisx, &sCylinderInit);
    this->collider.dim.yShift = 0;
    this->collider.dim.radius = 35;
    this->collider.dim.height = 70;
    this->met1_27C = (thisx->params >> 8) & 0xFF;
    this->actionFunc = EnMet1_80A56544;
    osSyncPrintf("\n\n");
    osSyncPrintf(VT_FGCOL(GREEN) " ☆☆☆☆☆ 兵士２セット完了！ ☆☆☆☆☆ %d\n" VT_RST, thisx->params);
    osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ 識別完了！\t    ☆☆☆☆☆ %d\n" VT_RST, this->type);
    osSyncPrintf(VT_FGCOL(MAGENTA) " ☆☆☆☆☆ メッセージ完了！   ☆☆☆☆☆ %x\n\n" VT_RST, (thisx->params >> 8) & 0xF);
    osSyncPrintf("\n\n");
}

void EnMet1_Destroy(Actor* thisx, PlayState* play) {
    EnMet1* this = (EnMet1*)thisx;

    Collider_DestroyCylinder(play, &this->collider);
}

void EnMet1_80A56328(EnMet1* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gMetHammeringAnim);

    Animation_Change(&this->skelAnime, &gMetHammeringAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    this->actionFunc = EnMet1_80A563BC;
}

void EnMet1_80A563BC(EnMet1* this, PlayState* play) {

    this->met1_2B4 = 0;
	if (IS_DAY) {
            if (this->met1_284 == 0) {
                this->actor.textId = 0x5063;
            } else {
                this->actor.textId = 0x5064;
            }
        } else if (this->met1_284 == 0) {
            this->actor.textId = 0x5066;
        } else {
            this->actor.textId = 0x5067;
        }

        this->actionFunc = EnMet1_80A56B40;
    }

void EnMet1_80A56544(EnMet1* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gMetHammeringAnim);

    Animation_Change(&this->skelAnime, &gMetHammeringAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    this->actionFunc = EnMet1_80A56614;
}

void EnMet1_80A56614(EnMet1* this, PlayState* play) {
	if (IS_NIGHT) {
	Actor_Kill(&this->actor);
	} else {
		s16 text;
		this->met1_2B4 = 0;
		text = Rand_S16Offset(1, 9);
		if (text < 6) {
			this->actor.textId = 0x608B;
		} else if (text == 6) {
			this->actor.textId = 0x608A;
		} else if (text == 7) {
			this->actor.textId = 0x608C;
		} else if (text == 8) {
			this->actor.textId = 0x608D;
		} else if (text == 9) {
			this->actor.textId = 0x608E;
		} else if (text == 10) {
		this->actor.textId = 0x608F;
		}
		this->actionFunc = EnMet1_80A56B40;
	}
}

void EnMet1_80A5673C(EnMet1* this, PlayState* play) {
    if (GET_EVENTCHKINF(EVENTCHKINF_45)) {
        osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ マスターソード祝入手！ ☆☆☆☆☆ \n" VT_RST);
        Actor_Kill(&this->actor);
        return;
    }
    this->met1_284 = 0;
    if (GET_EVENTCHKINF(EVENTCHKINF_80)) {
        if (!GET_INFTABLE(INFTABLE_6C)) {
            f32 frames = Animation_GetLastFrame(&gMetHammeringAnim);
            Animation_Change(&this->skelAnime, &gMetHammeringAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP,
                             -10.0f);
            this->actor.textId = 0x7003;
            this->met1_282 = TEXT_STATE_EVENT;
            this->met1_284 = 1;
            osSyncPrintf(VT_FGCOL(YELLOW) " ☆☆☆☆☆ デモ開始！ ☆☆☆☆☆ \n" VT_RST);
        } else {
            this->actor.textId = 0x7003;
            this->met1_282 = TEXT_STATE_DONE;
            osSyncPrintf(VT_FGCOL(BLUE) " ☆☆☆☆☆ 返事なし ☆☆☆☆☆ \n" VT_RST);
        }
        this->actionFunc = EnMet1_80A56874;
    } else {
        Actor_Kill(&this->actor);
    }
}

void EnMet1_80A56874(EnMet1* this, PlayState* play) {
    if (this->met1_284 != 0) {
        SkelAnime_Update(&this->skelAnime);
    }
    if (Actor_ProcessTalkRequest(&this->actor, play)) {
        { this->actionFunc = EnMet1_80A56900; }
    } else {
       func_8002F2CC(&this->actor, play, 100.0f);
    }
}

void EnMet1_80A56900(EnMet1* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gMetHammeringAnim);

    Animation_Change(&this->skelAnime, &gMetHammeringAnim, 1.0f, 0.0f, (s16)frames, ANIMMODE_LOOP, -10.0f);
    this->actionFunc = EnMet1_80A56994;
}

void EnMet1_80A56994(EnMet1* this, PlayState* play) {
    SkelAnime_Update(&this->skelAnime);
    Actor_TrackPlayer(play, &this->actor, &this->headRot, &this->torsoRot, this->actor.focus.pos);
    if ((this->met1_282 == Message_GetState(&play->msgCtx)) && Message_ShouldAdvance(play)) {
        Message_CloseTextbox(play);
        SET_INFTABLE(INFTABLE_6C);
        func_8002DF54(play, NULL, PLAYER_CSACTION_8);
        this->actionFunc = EnMet1_80A56A50;
    }
}

void EnMet1_80A56A50(EnMet1* this, PlayState* play) {
    f32 frames = Animation_GetLastFrame(&gMetHammeringAnim);
    this->met1_2B4 = 0;
    this->met1_288 = frames;
    Animation_Change(&this->skelAnime, &gMetHammeringAnim, 1.0f, 0.0f, frames, ANIMMODE_ONCE, -10.0f);
    this->actionFunc = EnMet1_80A56B40;
}

void EnMet1_80A56ACC(EnMet1* this, PlayState* play) {
    f32 currentFrame = this->skelAnime.curFrame;

    SkelAnime_Update(&this->skelAnime);
    if (this->met1_288 <= currentFrame) {
        func_8002DF54(play, NULL, PLAYER_CSACTION_7);
        this->actionFunc = EnMet1_80A5673C;
    }
}

void EnMet1_80A56B40(EnMet1* this, PlayState* play) {
    SkelAnime_Update(&this->skelAnime);
    Actor_TrackPlayer(play, &this->actor, &this->headRot, &this->torsoRot, this->actor.focus.pos);
    func_8002F2F4(&this->actor, play);
}

void EnMet1_Update(Actor* thisx, PlayState* play) {
    EnMet1* this = (EnMet1*)thisx;
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
    this->met1_27E++;
    this->actionFunc(this, play);
    Actor_MoveXZGravity(thisx);
    Actor_UpdateBgCheckInfo(play, thisx, 10.0f, 10.0f, 30.0f,
                            UPDBGCHECKINFO_FLAG_0 | UPDBGCHECKINFO_FLAG_2 | UPDBGCHECKINFO_FLAG_3 |
                                UPDBGCHECKINFO_FLAG_4);
    Collider_UpdateCylinder(&this->actor, &this->collider);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
}

s32 EnMet1_OverrideLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnMet1* this = (EnMet1*)thisx;

    return false;
}

void EnMet1_Draw(Actor* thisx, PlayState* play) {
    static void* sEyeTextures[] = {  gMetSkel_eyes_open_ci8_rgba16, gMetSkel_eyes_half_ci8_rgba16, gMetSkel_eyes_closed_ci8_rgba16, NULL };
    EnMet1* this = (EnMet1*)thisx;
    OPEN_DISPS(play->state.gfxCtx, __FILE__, __LINE__);

    Gfx_SetupDL_25Opa(play->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyeTextures[this->faceState]));
    SkelAnime_DrawFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount,
                      EnMet1_OverrideLimbDraw, NULL, this);
    CLOSE_DISPS(play->state.gfxCtx, __FILE__, __LINE__);
}
