#ifndef Z_EN_MET2_H
#define Z_EN_MET2_H

#include "ultra64.h"
#include "global.h"


struct EnMet2;

typedef void (*EnMet2ActionFunc)(struct EnMet2*, PlayState*);

typedef struct EnMet2 {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ Vec3s jointTable[17];
    /* 0x01F6 */ Vec3s morphTable[17];
    /* 0x025C */ EnMet2ActionFunc actionFunc;
    /* 0x0260 */ Vec3s headRot;
    /* 0x0266 */ Vec3s torsoRot;
    /* 0x026C */ Vec3f pos;
    /* 0x0278 */ f32 height;
    /* 0x027C */ s16 met2_27C;
    /* 0x027E */ s16 met2_27E;
    /* 0x0280 */ s16 type;
    /* 0x0282 */ s16 met2_282;
    /* 0x0284 */ s16 met2_284;
    /* 0x0288 */ f32 met2_288;
    s16 faceState;
    s16 faceTimer;
    /* 0x028C */ NpcInteractInfo interactInfo;
    /* 0x02B4 */ u8 met2_2B4;
    /* 0x02B6 */ char met2_2B6[7];
    /* 0x02BC */ ColliderCylinder collider;
} EnMet2; // size = 0x0308

#endif
