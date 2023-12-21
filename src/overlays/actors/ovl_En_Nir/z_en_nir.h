#ifndef Z_EN_NIR_H
#define Z_EN_NIR_H

#include "ultra64.h"
#include "global.h"


struct EnNir;

typedef void (*EnNirActionFunc)(struct EnNir*, PlayState*);

typedef struct EnNir {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ Vec3s jointTable[17];
    /* 0x01F6 */ Vec3s morphTable[17];
    /* 0x025C */ EnNirActionFunc actionFunc;
    /* 0x0260 */ Vec3s headRot;
    /* 0x0266 */ Vec3s torsoRot;
    /* 0x026C */ Vec3f pos;
    /* 0x0278 */ f32 height;
    /* 0x027C */ s16 nir_27C;
    /* 0x027E */ s16 nir_27E;
    /* 0x0280 */ s16 type;
    /* 0x0282 */ s16 nir_282;
    /* 0x0284 */ s16 nir_284;
    /* 0x0288 */ f32 nir_288;
    s16 faceState;
    s16 faceTimer;
    /* 0x028C */ NpcInteractInfo interactInfo;
    /* 0x02B4 */ u8 nir_2B4;
    /* 0x02B6 */ char nir_2B6[7];
    /* 0x02BC */ ColliderCylinder collider;
} EnNir; // size = 0x0308

#endif
