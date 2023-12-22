/**
 * Object Table
 *
 * DEFINE_OBJECT should be used for normal objects
 *    - Argument 1: Name of the object segment in spec
 *    - Argument 2: Enum value for this object
 *
 * DEFINE_OBJECT_UNSET and DEFINE_OBJECT_NULL are needed to define empty entries from the original game
 */
/* 0x0000 */ DEFINE_OBJECT_UNSET(OBJECT_INVALID) // Object ID 0 isn't usable and should remain unset
/* 0x0001 */ DEFINE_OBJECT(gameplay_keep, OBJECT_GAMEPLAY_KEEP)
/* 0x0002 */ DEFINE_OBJECT(gameplay_field_keep, OBJECT_GAMEPLAY_FIELD_KEEP)
/* 0x0003 */ DEFINE_OBJECT(gameplay_dangeon_keep, OBJECT_GAMEPLAY_DANGEON_KEEP)
/* 0x0004 */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_4)
/* 0x0005 */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_5)
/* 0x0006 */ DEFINE_OBJECT(object_human, OBJECT_HUMAN)
/* 0x0007 */ DEFINE_OBJECT(object_okuta, OBJECT_OKUTA)
/* 0x0008 */ DEFINE_OBJECT(object_crow, OBJECT_CROW)
/* 0x0009 */ DEFINE_OBJECT(object_poh, OBJECT_POH)
/* 0x000A */ DEFINE_OBJECT(object_dy_obj, OBJECT_DY_OBJ)
/* 0x000B */ DEFINE_OBJECT(object_wallmaster, OBJECT_WALLMASTER)
/* 0x000C */ DEFINE_OBJECT(object_dodongo, OBJECT_DODONGO)
/* 0x000D */ DEFINE_OBJECT(object_firefly, OBJECT_FIREFLY)
/* 0x000E */ DEFINE_OBJECT(object_box, OBJECT_BOX)
/* 0x000F */ DEFINE_OBJECT(object_fire, OBJECT_FIRE)
/* 0x0010 */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_10)
/* 0x0011 */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_11)
/* 0x0012 */ DEFINE_OBJECT(object_bubble, OBJECT_BUBBLE)
/* 0x0013 */ DEFINE_OBJECT(object_niw, OBJECT_NIW)
/* 0x0014 */ DEFINE_OBJECT(object_link_boy, OBJECT_LINK_BOY)
/* 0x0015 */ DEFINE_OBJECT(object_link_child, OBJECT_LINK_CHILD)
/* 0x0016 */ DEFINE_OBJECT(object_tite, OBJECT_TITE)
/* 0x0017 */ DEFINE_OBJECT(object_reeba, OBJECT_REEBA)
/* 0x0018 */ DEFINE_OBJECT(object_peehat, OBJECT_PEEHAT)
/* 0x0019 */ DEFINE_OBJECT(object_kingdodongo, OBJECT_KINGDODONGO)
/* 0x001A */ DEFINE_OBJECT(object_horse, OBJECT_HORSE)
/* 0x001B */ DEFINE_OBJECT(object_zf, OBJECT_ZF)
/* 0x001C */ DEFINE_OBJECT(object_goma, OBJECT_GOMA)
/* 0x001D */ DEFINE_OBJECT(object_zl1, OBJECT_ZL1)
/* 0x001E */ DEFINE_OBJECT(object_gol, OBJECT_GOL)
/* 0x001F */ DEFINE_OBJECT(object_dodojr, OBJECT_DODOJR)
/* 0x0020 */ DEFINE_OBJECT(object_torch2, OBJECT_TORCH2)
/* 0x0021 */ DEFINE_OBJECT(object_bl, OBJECT_BL)
/* 0x0022 */ DEFINE_OBJECT(object_tp, OBJECT_TP)
/* 0x0023 */ DEFINE_OBJECT(object_oA1, OBJECT_OA1)
/* 0x0024 */ DEFINE_OBJECT(object_st, OBJECT_ST)
/* 0x0025 */ DEFINE_OBJECT(object_bw, OBJECT_BW)
/* 0x0026 */ DEFINE_OBJECT(object_ei, OBJECT_EI)
/* 0x0027 */ DEFINE_OBJECT(object_horse_normal, OBJECT_HORSE_NORMAL)
/* 0x0028 */ DEFINE_OBJECT(object_oB1, OBJECT_OB1)
/* 0x0029 */ DEFINE_OBJECT(object_o_anime, OBJECT_O_ANIME)
/* 0x002A */ DEFINE_OBJECT(object_spot04_objects, OBJECT_SPOT04_OBJECTS)
/* 0x002B */ DEFINE_OBJECT(object_ddan_objects, OBJECT_DDAN_OBJECTS)
/* 0x002C */ DEFINE_OBJECT(object_hidan_objects, OBJECT_HIDAN_OBJECTS)
/* 0x002D */ DEFINE_OBJECT(object_horse_ganon, OBJECT_HORSE_GANON)
/* 0x002E */ DEFINE_OBJECT(object_oA2, OBJECT_OA2)
/* 0x002F */ DEFINE_OBJECT(object_spot00_objects, OBJECT_SPOT00_OBJECTS)
/* 0x0030 */ DEFINE_OBJECT(object_mb, OBJECT_MB)
/* 0x0031 */ DEFINE_OBJECT(object_bombf, OBJECT_BOMBF)
/* 0x0032 */ DEFINE_OBJECT(object_sk2, OBJECT_SK2)
/* 0x0033 */ DEFINE_OBJECT(object_oE1, OBJECT_OE1)
/* 0x0034 */ DEFINE_OBJECT(object_oE_anime, OBJECT_OE_ANIME)
/* 0x0035 */ DEFINE_OBJECT(object_oE2, OBJECT_OE2)
/* 0x0036 */ DEFINE_OBJECT(object_ydan_objects, OBJECT_YDAN_OBJECTS)
/* 0x0037 */ DEFINE_OBJECT(object_gnd, OBJECT_GND)
/* 0x0038 */ DEFINE_OBJECT(object_am, OBJECT_AM)
/* 0x0039 */ DEFINE_OBJECT(object_dekubaba, OBJECT_DEKUBABA)
/* 0x003A */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_3A)
/* 0x003B */ DEFINE_OBJECT(object_oA3, OBJECT_OA3)
/* 0x003C */ DEFINE_OBJECT(object_oA4, OBJECT_OA4)
/* 0x003D */ DEFINE_OBJECT(object_oA5, OBJECT_OA5)
/* 0x003E */ DEFINE_OBJECT(object_oA6, OBJECT_OA6)
/* 0x003F */ DEFINE_OBJECT(object_oA7, OBJECT_OA7)
/* 0x0040 */ DEFINE_OBJECT(object_jj, OBJECT_JJ)
/* 0x0041 */ DEFINE_OBJECT(object_oA8, OBJECT_OA8)
/* 0x0042 */ DEFINE_OBJECT(object_oA9, OBJECT_OA9)
/* 0x0043 */ DEFINE_OBJECT(object_oB2, OBJECT_OB2)
/* 0x0044 */ DEFINE_OBJECT(object_oB3, OBJECT_OB3)
/* 0x0045 */ DEFINE_OBJECT(object_oB4, OBJECT_OB4)
/* 0x0046 */ DEFINE_OBJECT(object_horse_zelda, OBJECT_HORSE_ZELDA)
/* 0x0047 */ DEFINE_OBJECT(object_opening_demo1, OBJECT_OPENING_DEMO1)
/* 0x0048 */ DEFINE_OBJECT(object_warp1, OBJECT_WARP1)
/* 0x0049 */ DEFINE_OBJECT(object_b_heart, OBJECT_B_HEART)
/* 0x004A */ DEFINE_OBJECT(object_dekunuts, OBJECT_DEKUNUTS)
/* 0x004B */ DEFINE_OBJECT(object_oE3, OBJECT_OE3)
/* 0x004C */ DEFINE_OBJECT(object_oE4, OBJECT_OE4)
/* 0x004D */ DEFINE_OBJECT(object_menkuri_objects, OBJECT_MENKURI_OBJECTS)
/* 0x004E */ DEFINE_OBJECT(object_oE5, OBJECT_OE5)
/* 0x004F */ DEFINE_OBJECT(object_oE6, OBJECT_OE6)
/* 0x0050 */ DEFINE_OBJECT(object_oE7, OBJECT_OE7)
/* 0x0051 */ DEFINE_OBJECT(object_oE8, OBJECT_OE8)
/* 0x0052 */ DEFINE_OBJECT(object_oE9, OBJECT_OE9)
/* 0x0053 */ DEFINE_OBJECT(object_oE10, OBJECT_OE10)
/* 0x0054 */ DEFINE_OBJECT(object_oE11, OBJECT_OE11)
/* 0x0055 */ DEFINE_OBJECT(object_oE12, OBJECT_OE12)
/* 0x0056 */ DEFINE_OBJECT(object_vali, OBJECT_VALI)
/* 0x0057 */ DEFINE_OBJECT(object_oA10, OBJECT_OA10)
/* 0x0058 */ DEFINE_OBJECT(object_oA11, OBJECT_OA11)
/* 0x0059 */ DEFINE_OBJECT(object_mizu_objects, OBJECT_MIZU_OBJECTS)
/* 0x005A */ DEFINE_OBJECT(object_fhg, OBJECT_FHG)
/* 0x005B */ DEFINE_OBJECT(object_ossan, OBJECT_OSSAN)
/* 0x005C */ DEFINE_OBJECT(object_mori_hineri1, OBJECT_MORI_HINERI1)
/* 0x005D */ DEFINE_OBJECT(object_Bb, OBJECT_BB)
/* 0x005E */ DEFINE_OBJECT(object_toki_objects, OBJECT_TOKI_OBJECTS)
/* 0x005F */ DEFINE_OBJECT(object_yukabyun, OBJECT_YUKABYUN)
/* 0x0060 */ DEFINE_OBJECT(object_zl2, OBJECT_ZL2)
/* 0x0061 */ DEFINE_OBJECT(object_mjin, OBJECT_MJIN)
/* 0x0062 */ DEFINE_OBJECT(object_mjin_flash, OBJECT_MJIN_FLASH)
/* 0x0063 */ DEFINE_OBJECT(object_mjin_dark, OBJECT_MJIN_DARK)
/* 0x0064 */ DEFINE_OBJECT(object_mjin_flame, OBJECT_MJIN_FLAME)
/* 0x0065 */ DEFINE_OBJECT(object_mjin_ice, OBJECT_MJIN_ICE)
/* 0x0066 */ DEFINE_OBJECT(object_mjin_soul, OBJECT_MJIN_SOUL)
/* 0x0067 */ DEFINE_OBJECT(object_mjin_wind, OBJECT_MJIN_WIND)
/* 0x0068 */ DEFINE_OBJECT(object_mjin_oka, OBJECT_MJIN_OKA)
/* 0x0069 */ DEFINE_OBJECT(object_haka_objects, OBJECT_HAKA_OBJECTS)
/* 0x006A */ DEFINE_OBJECT(object_spot06_objects, OBJECT_SPOT06_OBJECTS)
/* 0x006B */ DEFINE_OBJECT(object_ice_objects, OBJECT_ICE_OBJECTS)
/* 0x006C */ DEFINE_OBJECT(object_relay_objects, OBJECT_RELAY_OBJECTS)
/* 0x006D */ DEFINE_OBJECT(object_po_field, OBJECT_PO_FIELD)
/* 0x006E */ DEFINE_OBJECT(object_po_composer, OBJECT_PO_COMPOSER)
/* 0x006F */ DEFINE_OBJECT(object_mori_hineri1a, OBJECT_MORI_HINERI1A)
/* 0x0070 */ DEFINE_OBJECT(object_mori_hineri2, OBJECT_MORI_HINERI2)
/* 0x0071 */ DEFINE_OBJECT(object_mori_hineri2a, OBJECT_MORI_HINERI2A)
/* 0x0072 */ DEFINE_OBJECT(object_mori_objects, OBJECT_MORI_OBJECTS)
/* 0x0073 */ DEFINE_OBJECT(object_mori_tex, OBJECT_MORI_TEX)
/* 0x0074 */ DEFINE_OBJECT(object_spot08_obj, OBJECT_SPOT08_OBJ)
/* 0x0075 */ DEFINE_OBJECT(object_warp2, OBJECT_WARP2)
/* 0x0076 */ DEFINE_OBJECT(object_hata, OBJECT_HATA)
/* 0x0077 */ DEFINE_OBJECT(object_bird, OBJECT_BIRD)
/* 0x0078 */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_78)
/* 0x0079 */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_79)
/* 0x007A */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_7A)
/* 0x007B */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_7B)
/* 0x007C */ DEFINE_OBJECT(object_wood02, OBJECT_WOOD02)
/* 0x007D */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_7D)
/* 0x007E */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_7E)
/* 0x007F */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_7F)
/* 0x0080 */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_80)
/* 0x0081 */ DEFINE_OBJECT(object_lightbox, OBJECT_LIGHTBOX)
/* 0x0082 */ DEFINE_OBJECT(object_pu_box, OBJECT_PU_BOX)
/* 0x0083 */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_83)
/* 0x0084 */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_84)
/* 0x0085 */ DEFINE_OBJECT(object_trap, OBJECT_TRAP)
/* 0x0086 */ DEFINE_OBJECT(object_vase, OBJECT_VASE)
/* 0x0087 */ DEFINE_OBJECT(object_im, OBJECT_IM)
/* 0x0088 */ DEFINE_OBJECT(object_ta, OBJECT_TA)
/* 0x0089 */ DEFINE_OBJECT(object_tk, OBJECT_TK)
/* 0x008A */ DEFINE_OBJECT(object_xc, OBJECT_XC)
/* 0x008B */ DEFINE_OBJECT(object_vm, OBJECT_VM)
/* 0x008C */ DEFINE_OBJECT(object_bv, OBJECT_BV)
/* 0x008D */ DEFINE_OBJECT(object_hakach_objects, OBJECT_HAKACH_OBJECTS)
/* 0x008E */ DEFINE_OBJECT(object_efc_crystal_light, OBJECT_EFC_CRYSTAL_LIGHT)
/* 0x008F */ DEFINE_OBJECT(object_efc_fire_ball, OBJECT_EFC_FIRE_BALL)
/* 0x0090 */ DEFINE_OBJECT(object_efc_flash, OBJECT_EFC_FLASH)
/* 0x0091 */ DEFINE_OBJECT(object_efc_lgt_shower, OBJECT_EFC_LGT_SHOWER)
/* 0x0092 */ DEFINE_OBJECT(object_efc_star_field, OBJECT_EFC_STAR_FIELD)
/* 0x0093 */ DEFINE_OBJECT(object_god_lgt, OBJECT_GOD_LGT)
/* 0x0094 */ DEFINE_OBJECT(object_light_ring, OBJECT_LIGHT_RING)
/* 0x0095 */ DEFINE_OBJECT(object_triforce_spot, OBJECT_TRIFORCE_SPOT)
/* 0x0096 */ DEFINE_OBJECT(object_bdan_objects, OBJECT_BDAN_OBJECTS)
/* 0x0097 */ DEFINE_OBJECT(object_sd, OBJECT_SD)
/* 0x0098 */ DEFINE_OBJECT(object_rd, OBJECT_RD)
/* 0x0099 */ DEFINE_OBJECT(object_po_sisters, OBJECT_PO_SISTERS)
/* 0x009A */ DEFINE_OBJECT(object_heavy_object, OBJECT_HEAVY_OBJECT)
/* 0x009B */ DEFINE_OBJECT(object_gndd, OBJECT_GNDD)
/* 0x009C */ DEFINE_OBJECT(object_fd, OBJECT_FD)
/* 0x009D */ DEFINE_OBJECT(object_du, OBJECT_DU)
/* 0x009E */ DEFINE_OBJECT(object_fw, OBJECT_FW)
/* 0x009F */ DEFINE_OBJECT(object_medal, OBJECT_MEDAL)
/* 0x00A0 */ DEFINE_OBJECT(object_horse_link_child, OBJECT_HORSE_LINK_CHILD)
/* 0x00A1 */ DEFINE_OBJECT(object_spot02_objects, OBJECT_SPOT02_OBJECTS)
/* 0x00A2 */ DEFINE_OBJECT(object_haka, OBJECT_HAKA)
/* 0x00A3 */ DEFINE_OBJECT(object_ru1, OBJECT_RU1)
/* 0x00A4 */ DEFINE_OBJECT(object_syokudai, OBJECT_SYOKUDAI)
/* 0x00A5 */ DEFINE_OBJECT(object_fd2, OBJECT_FD2)
/* 0x00A6 */ DEFINE_OBJECT(object_dh, OBJECT_DH)
/* 0x00A7 */ DEFINE_OBJECT(object_rl, OBJECT_RL)
/* 0x00A8 */ DEFINE_OBJECT(object_efc_tw, OBJECT_EFC_TW)
/* 0x00A9 */ DEFINE_OBJECT(object_demo_tre_lgt, OBJECT_DEMO_TRE_LGT)
/* 0x00AA */ DEFINE_OBJECT(object_gi_key, OBJECT_GI_KEY)
/* 0x00AB */ DEFINE_OBJECT(object_mir_ray, OBJECT_MIR_RAY)
/* 0x00AC */ DEFINE_OBJECT(object_brob, OBJECT_BROB)
/* 0x00AD */ DEFINE_OBJECT(object_gi_jewel, OBJECT_GI_JEWEL)
/* 0x00AE */ DEFINE_OBJECT(object_spot09_obj, OBJECT_SPOT09_OBJ)
/* 0x00AF */ DEFINE_OBJECT(object_spot18_obj, OBJECT_SPOT18_OBJ)
/* 0x00B0 */ DEFINE_OBJECT(object_bdoor, OBJECT_BDOOR)
/* 0x00B1 */ DEFINE_OBJECT(object_spot17_obj, OBJECT_SPOT17_OBJ)
/* 0x00B2 */ DEFINE_OBJECT(object_shop_dungen, OBJECT_SHOP_DUNGEN)
/* 0x00B3 */ DEFINE_OBJECT(object_nb, OBJECT_NB)
/* 0x00B4 */ DEFINE_OBJECT(object_mo, OBJECT_MO)
/* 0x00B5 */ DEFINE_OBJECT(object_sb, OBJECT_SB)
/* 0x00B6 */ DEFINE_OBJECT(object_gi_melody, OBJECT_GI_MELODY)
/* 0x00B7 */ DEFINE_OBJECT(object_gi_heart, OBJECT_GI_HEART)
/* 0x00B8 */ DEFINE_OBJECT(object_gi_compass, OBJECT_GI_COMPASS)
/* 0x00B9 */ DEFINE_OBJECT(object_gi_bosskey, OBJECT_GI_BOSSKEY)
/* 0x00BA */ DEFINE_OBJECT(object_gi_medal, OBJECT_GI_MEDAL)
/* 0x00BB */ DEFINE_OBJECT(object_gi_nuts, OBJECT_GI_NUTS)
/* 0x00BC */ DEFINE_OBJECT(object_sa, OBJECT_SA)
/* 0x00BD */ DEFINE_OBJECT(object_gi_hearts, OBJECT_GI_HEARTS)
/* 0x00BE */ DEFINE_OBJECT(object_gi_arrowcase, OBJECT_GI_ARROWCASE)
/* 0x00BF */ DEFINE_OBJECT(object_gi_bombpouch, OBJECT_GI_BOMBPOUCH)
/* 0x00C0 */ DEFINE_OBJECT(object_in, OBJECT_IN)
/* 0x00C1 */ DEFINE_OBJECT(object_tr, OBJECT_TR)
/* 0x00C2 */ DEFINE_OBJECT(object_spot16_obj, OBJECT_SPOT16_OBJ)
/* 0x00C3 */ DEFINE_OBJECT(object_oE1s, OBJECT_OE1S)
/* 0x00C4 */ DEFINE_OBJECT(object_oE4s, OBJECT_OE4S)
/* 0x00C5 */ DEFINE_OBJECT(object_os_anime, OBJECT_OS_ANIME)
/* 0x00C6 */ DEFINE_OBJECT(object_gi_bottle, OBJECT_GI_BOTTLE)
/* 0x00C7 */ DEFINE_OBJECT(object_gi_stick, OBJECT_GI_STICK)
/* 0x00C8 */ DEFINE_OBJECT(object_gi_map, OBJECT_GI_MAP)
/* 0x00C9 */ DEFINE_OBJECT(object_oF1d_map, OBJECT_OF1D_MAP)
/* 0x00CA */ DEFINE_OBJECT(object_ru2, OBJECT_RU2)
/* 0x00CB */ DEFINE_OBJECT(object_gi_shield_1, OBJECT_GI_SHIELD_1)
/* 0x00CC */ DEFINE_OBJECT(object_dekujr, OBJECT_DEKUJR)
/* 0x00CD */ DEFINE_OBJECT(object_gi_magicpot, OBJECT_GI_MAGICPOT)
/* 0x00CE */ DEFINE_OBJECT(object_gi_bomb_1, OBJECT_GI_BOMB_1)
/* 0x00CF */ DEFINE_OBJECT(object_oF1s, OBJECT_OF1S)
/* 0x00D0 */ DEFINE_OBJECT(object_ma2, OBJECT_MA2)
/* 0x00D1 */ DEFINE_OBJECT(object_gi_purse, OBJECT_GI_PURSE)
/* 0x00D2 */ DEFINE_OBJECT(object_hni, OBJECT_HNI)
/* 0x00D3 */ DEFINE_OBJECT(object_tw, OBJECT_TW)
/* 0x00D4 */ DEFINE_OBJECT(object_rr, OBJECT_RR)
/* 0x00D5 */ DEFINE_OBJECT(object_bxa, OBJECT_BXA)
/* 0x00D6 */ DEFINE_OBJECT(object_anubice, OBJECT_ANUBICE)
/* 0x00D7 */ DEFINE_OBJECT(object_gi_gerudo, OBJECT_GI_GERUDO)
/* 0x00D8 */ DEFINE_OBJECT(object_gi_arrow, OBJECT_GI_ARROW)
/* 0x00D9 */ DEFINE_OBJECT(object_gi_bomb_2, OBJECT_GI_BOMB_2)
/* 0x00DA */ DEFINE_OBJECT(object_gi_egg, OBJECT_GI_EGG)
/* 0x00DB */ DEFINE_OBJECT(object_gi_scale, OBJECT_GI_SCALE)
/* 0x00DC */ DEFINE_OBJECT(object_gi_shield_2, OBJECT_GI_SHIELD_2)
/* 0x00DD */ DEFINE_OBJECT(object_gi_hookshot, OBJECT_GI_HOOKSHOT)
/* 0x00DE */ DEFINE_OBJECT(object_gi_ocarina, OBJECT_GI_OCARINA)
/* 0x00DF */ DEFINE_OBJECT(object_gi_milk, OBJECT_GI_MILK)
/* 0x00E0 */ DEFINE_OBJECT(object_ma1, OBJECT_MA1)
/* 0x00E1 */ DEFINE_OBJECT(object_ganon, OBJECT_GANON)
/* 0x00E2 */ DEFINE_OBJECT(object_sst, OBJECT_SST)
/* 0x00E3 */ DEFINE_OBJECT_NULL(object_ny, OBJECT_NY_UNUSED) // unused duplicate with size 0
/* 0x00E4 */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_E4)
/* 0x00E5 */ DEFINE_OBJECT(object_ny, OBJECT_NY)
/* 0x00E6 */ DEFINE_OBJECT(object_fr, OBJECT_FR)
/* 0x00E7 */ DEFINE_OBJECT(object_gi_pachinko, OBJECT_GI_PACHINKO)
/* 0x00E8 */ DEFINE_OBJECT(object_gi_boomerang, OBJECT_GI_BOOMERANG)
/* 0x00E9 */ DEFINE_OBJECT(object_gi_bow, OBJECT_GI_BOW)
/* 0x00EA */ DEFINE_OBJECT(object_gi_glasses, OBJECT_GI_GLASSES)
/* 0x00EB */ DEFINE_OBJECT(object_gi_liquid, OBJECT_GI_LIQUID)
/* 0x00EC */ DEFINE_OBJECT(object_ani, OBJECT_ANI)
/* 0x00ED */ DEFINE_OBJECT(object_demo_6k, OBJECT_DEMO_6K)
/* 0x00EE */ DEFINE_OBJECT(object_gi_shield_3, OBJECT_GI_SHIELD_3)
/* 0x00EF */ DEFINE_OBJECT(object_gi_letter, OBJECT_GI_LETTER)
/* 0x00F0 */ DEFINE_OBJECT(object_spot15_obj, OBJECT_SPOT15_OBJ)
/* 0x00F1 */ DEFINE_OBJECT(object_jya_obj, OBJECT_JYA_OBJ)
/* 0x00F2 */ DEFINE_OBJECT(object_gi_clothes, OBJECT_GI_CLOTHES)
/* 0x00F3 */ DEFINE_OBJECT(object_gi_bean, OBJECT_GI_BEAN)
/* 0x00F4 */ DEFINE_OBJECT(object_gi_fish, OBJECT_GI_FISH)
/* 0x00F5 */ DEFINE_OBJECT(object_gi_saw, OBJECT_GI_SAW)
/* 0x00F6 */ DEFINE_OBJECT(object_gi_hammer, OBJECT_GI_HAMMER)
/* 0x00F7 */ DEFINE_OBJECT(object_gi_grass, OBJECT_GI_GRASS)
/* 0x00F8 */ DEFINE_OBJECT(object_gi_longsword, OBJECT_GI_LONGSWORD)
/* 0x00F9 */ DEFINE_OBJECT(object_spot01_objects, OBJECT_SPOT01_OBJECTS)
/* 0x00FA */ DEFINE_OBJECT_NULL(object_md, OBJECT_MD_UNUSED) // unused duplicate with size 0
/* 0x00FB */ DEFINE_OBJECT(object_md, OBJECT_MD)
/* 0x00FC */ DEFINE_OBJECT(object_km1, OBJECT_KM1)
/* 0x00FD */ DEFINE_OBJECT(object_kw1, OBJECT_KW1)
/* 0x00FE */ DEFINE_OBJECT(object_zo, OBJECT_ZO)
/* 0x00FF */ DEFINE_OBJECT(object_kz, OBJECT_KZ)
/* 0x0100 */ DEFINE_OBJECT(object_umajump, OBJECT_UMAJUMP)
/* 0x0101 */ DEFINE_OBJECT(object_masterkokiri, OBJECT_MASTERKOKIRI)
/* 0x0102 */ DEFINE_OBJECT(object_masterkokirihead, OBJECT_MASTERKOKIRIHEAD)
/* 0x0103 */ DEFINE_OBJECT(object_mastergolon, OBJECT_MASTERGOLON)
/* 0x0104 */ DEFINE_OBJECT(object_masterzoora, OBJECT_MASTERZOORA)
/* 0x0105 */ DEFINE_OBJECT(object_aob, OBJECT_AOB)
/* 0x0106 */ DEFINE_OBJECT(object_ik, OBJECT_IK)
/* 0x0107 */ DEFINE_OBJECT(object_ahg, OBJECT_AHG)
/* 0x0108 */ DEFINE_OBJECT(object_cne, OBJECT_CNE)
/* 0x0109 */ DEFINE_OBJECT(object_gi_niwatori, OBJECT_GI_NIWATORI)
/* 0x010A */ DEFINE_OBJECT(object_skj, OBJECT_SKJ)
/* 0x010B */ DEFINE_OBJECT(object_gi_bottle_letter, OBJECT_GI_BOTTLE_LETTER)
/* 0x010C */ DEFINE_OBJECT(object_bji, OBJECT_BJI)
/* 0x010D */ DEFINE_OBJECT(object_bba, OBJECT_BBA)
/* 0x010E */ DEFINE_OBJECT(object_gi_ocarina_0, OBJECT_GI_OCARINA_0)
/* 0x010F */ DEFINE_OBJECT(object_ds, OBJECT_DS)
/* 0x0110 */ DEFINE_OBJECT(object_ane, OBJECT_ANE)
/* 0x0111 */ DEFINE_OBJECT(object_boj, OBJECT_BOJ)
/* 0x0112 */ DEFINE_OBJECT(object_spot03_object, OBJECT_SPOT03_OBJECT)
/* 0x0113 */ DEFINE_OBJECT(object_spot07_object, OBJECT_SPOT07_OBJECT)
/* 0x0114 */ DEFINE_OBJECT(object_fz, OBJECT_FZ)
/* 0x0115 */ DEFINE_OBJECT(object_bob, OBJECT_BOB)
/* 0x0116 */ DEFINE_OBJECT(object_ge1, OBJECT_GE1)
/* 0x0117 */ DEFINE_OBJECT(object_yabusame_point, OBJECT_YABUSAME_POINT)
/* 0x0118 */ DEFINE_OBJECT(object_gi_boots_2, OBJECT_GI_BOOTS_2)
/* 0x0119 */ DEFINE_OBJECT(object_gi_seed, OBJECT_GI_SEED)
/* 0x011A */ DEFINE_OBJECT(object_gnd_magic, OBJECT_GND_MAGIC)
/* 0x011B */ DEFINE_OBJECT(object_d_elevator, OBJECT_D_ELEVATOR)
/* 0x011C */ DEFINE_OBJECT(object_d_hsblock, OBJECT_D_HSBLOCK)
/* 0x011D */ DEFINE_OBJECT(object_d_lift, OBJECT_D_LIFT)
/* 0x011E */ DEFINE_OBJECT(object_mamenoki, OBJECT_MAMENOKI)
/* 0x011F */ DEFINE_OBJECT(object_goroiwa, OBJECT_GOROIWA)
/* 0x0120 */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_120)
/* 0x0121 */ DEFINE_OBJECT(object_toryo, OBJECT_TORYO)
/* 0x0122 */ DEFINE_OBJECT(object_daiku, OBJECT_DAIKU)
/* 0x0123 */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_123)
/* 0x0124 */ DEFINE_OBJECT(object_nwc, OBJECT_NWC)
/* 0x0125 */ DEFINE_OBJECT(object_blkobj, OBJECT_BLKOBJ)
/* 0x0126 */ DEFINE_OBJECT(object_gm, OBJECT_GM)
/* 0x0127 */ DEFINE_OBJECT(object_ms, OBJECT_MS)
/* 0x0128 */ DEFINE_OBJECT(object_hs, OBJECT_HS)
/* 0x0129 */ DEFINE_OBJECT(object_ingate, OBJECT_INGATE)
/* 0x012A */ DEFINE_OBJECT(object_lightswitch, OBJECT_LIGHTSWITCH)
/* 0x012B */ DEFINE_OBJECT(object_kusa, OBJECT_KUSA)
/* 0x012C */ DEFINE_OBJECT(object_tsubo, OBJECT_TSUBO)
/* 0x012D */ DEFINE_OBJECT(object_gi_gloves, OBJECT_GI_GLOVES)
/* 0x012E */ DEFINE_OBJECT(object_gi_coin, OBJECT_GI_COIN)
/* 0x012F */ DEFINE_OBJECT(object_kanban, OBJECT_KANBAN)
/* 0x0130 */ DEFINE_OBJECT(object_gjyo_objects, OBJECT_GJYO_OBJECTS)
/* 0x0131 */ DEFINE_OBJECT(object_owl, OBJECT_OWL)
/* 0x0132 */ DEFINE_OBJECT(object_mk, OBJECT_MK)
/* 0x0133 */ DEFINE_OBJECT(object_fu, OBJECT_FU)
/* 0x0134 */ DEFINE_OBJECT(object_gi_ki_tan_mask, OBJECT_GI_KI_TAN_MASK)
/* 0x0135 */ DEFINE_OBJECT(object_gi_redead_mask, OBJECT_GI_REDEAD_MASK)
/* 0x0136 */ DEFINE_OBJECT(object_gi_skj_mask, OBJECT_GI_SKJ_MASK)
/* 0x0137 */ DEFINE_OBJECT(object_gi_rabit_mask, OBJECT_GI_RABIT_MASK)
/* 0x0138 */ DEFINE_OBJECT(object_gi_truth_mask, OBJECT_GI_TRUTH_MASK)
/* 0x0139 */ DEFINE_OBJECT(object_ganon_objects, OBJECT_GANON_OBJECTS)
/* 0x013A */ DEFINE_OBJECT(object_siofuki, OBJECT_SIOFUKI)
/* 0x013B */ DEFINE_OBJECT(object_stream, OBJECT_STREAM)
/* 0x013C */ DEFINE_OBJECT(object_mm, OBJECT_MM)
/* 0x013D */ DEFINE_OBJECT(object_fa, OBJECT_FA)
/* 0x013E */ DEFINE_OBJECT(object_os, OBJECT_OS)
/* 0x013F */ DEFINE_OBJECT(object_gi_eye_lotion, OBJECT_GI_EYE_LOTION)
/* 0x0140 */ DEFINE_OBJECT(object_gi_powder, OBJECT_GI_POWDER)
/* 0x0141 */ DEFINE_OBJECT(object_gi_mushroom, OBJECT_GI_MUSHROOM)
/* 0x0142 */ DEFINE_OBJECT(object_gi_ticketstone, OBJECT_GI_TICKETSTONE)
/* 0x0143 */ DEFINE_OBJECT(object_gi_brokensword, OBJECT_GI_BROKENSWORD)
/* 0x0144 */ DEFINE_OBJECT(object_js, OBJECT_JS)
/* 0x0145 */ DEFINE_OBJECT(object_cs, OBJECT_CS)
/* 0x0146 */ DEFINE_OBJECT(object_gi_prescription, OBJECT_GI_PRESCRIPTION)
/* 0x0147 */ DEFINE_OBJECT(object_gi_bracelet, OBJECT_GI_BRACELET)
/* 0x0148 */ DEFINE_OBJECT(object_gi_soldout, OBJECT_GI_SOLDOUT)
/* 0x0149 */ DEFINE_OBJECT(object_gi_frog, OBJECT_GI_FROG)
/* 0x014A */ DEFINE_OBJECT(object_mag, OBJECT_MAG)
/* 0x014B */ DEFINE_OBJECT(object_door_gerudo, OBJECT_DOOR_GERUDO)
/* 0x014C */ DEFINE_OBJECT(object_gt, OBJECT_GT)
/* 0x014D */ DEFINE_OBJECT(object_efc_erupc, OBJECT_EFC_ERUPC)
/* 0x014E */ DEFINE_OBJECT(object_zl2_anime1, OBJECT_ZL2_ANIME1)
/* 0x014F */ DEFINE_OBJECT(object_zl2_anime2, OBJECT_ZL2_ANIME2)
/* 0x0150 */ DEFINE_OBJECT(object_gi_golonmask, OBJECT_GI_GOLONMASK)
/* 0x0151 */ DEFINE_OBJECT(object_gi_zoramask, OBJECT_GI_ZORAMASK)
/* 0x0152 */ DEFINE_OBJECT(object_gi_gerudomask, OBJECT_GI_GERUDOMASK)
/* 0x0153 */ DEFINE_OBJECT(object_ganon2, OBJECT_GANON2)
/* 0x0154 */ DEFINE_OBJECT(object_ka, OBJECT_KA)
/* 0x0155 */ DEFINE_OBJECT(object_ts, OBJECT_TS)
/* 0x0156 */ DEFINE_OBJECT(object_zg, OBJECT_ZG)
/* 0x0157 */ DEFINE_OBJECT(object_gi_hoverboots, OBJECT_GI_HOVERBOOTS)
/* 0x0158 */ DEFINE_OBJECT(object_gi_m_arrow, OBJECT_GI_M_ARROW)
/* 0x0159 */ DEFINE_OBJECT(object_ds2, OBJECT_DS2)
/* 0x015A */ DEFINE_OBJECT(object_ec, OBJECT_EC)
/* 0x015B */ DEFINE_OBJECT(object_fish, OBJECT_FISH)
/* 0x015C */ DEFINE_OBJECT(object_gi_sutaru, OBJECT_GI_SUTARU)
/* 0x015D */ DEFINE_OBJECT(object_gi_goddess, OBJECT_GI_GODDESS)
/* 0x015E */ DEFINE_OBJECT(object_ssh, OBJECT_SSH)
/* 0x015F */ DEFINE_OBJECT(object_bigokuta, OBJECT_BIGOKUTA)
/* 0x0160 */ DEFINE_OBJECT(object_bg, OBJECT_BG)
/* 0x0161 */ DEFINE_OBJECT(object_spot05_objects, OBJECT_SPOT05_OBJECTS)
/* 0x0162 */ DEFINE_OBJECT(object_spot12_obj, OBJECT_SPOT12_OBJ)
/* 0x0163 */ DEFINE_OBJECT(object_bombiwa, OBJECT_BOMBIWA)
/* 0x0164 */ DEFINE_OBJECT(object_hintnuts, OBJECT_HINTNUTS)
/* 0x0165 */ DEFINE_OBJECT(object_rs, OBJECT_RS)
/* 0x0166 */ DEFINE_OBJECT(object_spot00_break, OBJECT_SPOT00_BREAK)
/* 0x0167 */ DEFINE_OBJECT(object_gla, OBJECT_GLA)
/* 0x0168 */ DEFINE_OBJECT(object_shopnuts, OBJECT_SHOPNUTS)
/* 0x0169 */ DEFINE_OBJECT(object_geldb, OBJECT_GELDB)
/* 0x016A */ DEFINE_OBJECT(object_gr, OBJECT_GR)
/* 0x016B */ DEFINE_OBJECT(object_dog, OBJECT_DOG)
/* 0x016C */ DEFINE_OBJECT(object_jya_iron, OBJECT_JYA_IRON)
/* 0x016D */ DEFINE_OBJECT(object_jya_door, OBJECT_JYA_DOOR)
/* 0x016E */ DEFINE_OBJECT_UNSET(OBJECT_UNSET_16E)
/* 0x016F */ DEFINE_OBJECT(object_spot11_obj, OBJECT_SPOT11_OBJ)
/* 0x0170 */ DEFINE_OBJECT(object_kibako2, OBJECT_KIBAKO2)
/* 0x0171 */ DEFINE_OBJECT(object_dns, OBJECT_DNS)
/* 0x0172 */ DEFINE_OBJECT(object_dnk, OBJECT_DNK)
/* 0x0173 */ DEFINE_OBJECT(object_gi_fire, OBJECT_GI_FIRE)
/* 0x0174 */ DEFINE_OBJECT(object_gi_insect, OBJECT_GI_INSECT)
/* 0x0175 */ DEFINE_OBJECT(object_gi_butterfly, OBJECT_GI_BUTTERFLY)
/* 0x0176 */ DEFINE_OBJECT(object_gi_ghost, OBJECT_GI_GHOST)
/* 0x0177 */ DEFINE_OBJECT(object_gi_soul, OBJECT_GI_SOUL)
/* 0x0178 */ DEFINE_OBJECT(object_bowl, OBJECT_BOWL)
/* 0x0179 */ DEFINE_OBJECT(object_demo_kekkai, OBJECT_DEMO_KEKKAI)
/* 0x017A */ DEFINE_OBJECT(object_efc_doughnut, OBJECT_EFC_DOUGHNUT)
/* 0x017B */ DEFINE_OBJECT(object_gi_dekupouch, OBJECT_GI_DEKUPOUCH)
/* 0x017C */ DEFINE_OBJECT(object_ganon_anime1, OBJECT_GANON_ANIME1)
/* 0x017D */ DEFINE_OBJECT(object_ganon_anime2, OBJECT_GANON_ANIME2)
/* 0x017E */ DEFINE_OBJECT(object_ganon_anime3, OBJECT_GANON_ANIME3)
/* 0x017F */ DEFINE_OBJECT(object_gi_rupy, OBJECT_GI_RUPY)
/* 0x0180 */ DEFINE_OBJECT(object_spot01_matoya, OBJECT_SPOT01_MATOYA)
/* 0x0181 */ DEFINE_OBJECT(object_spot01_matoyab, OBJECT_SPOT01_MATOYAB)
/* 0x0182 */ DEFINE_OBJECT(object_mu, OBJECT_MU)
/* 0x0183 */ DEFINE_OBJECT(object_wf, OBJECT_WF)
/* 0x0184 */ DEFINE_OBJECT(object_skb, OBJECT_SKB)
/* 0x0185 */ DEFINE_OBJECT(object_gj, OBJECT_GJ)
/* 0x0186 */ DEFINE_OBJECT(object_geff, OBJECT_GEFF)
/* 0x0187 */ DEFINE_OBJECT(object_haka_door, OBJECT_HAKA_DOOR)
/* 0x0188 */ DEFINE_OBJECT(object_gs, OBJECT_GS)
/* 0x0189 */ DEFINE_OBJECT(object_ps, OBJECT_PS)
/* 0x018A */ DEFINE_OBJECT(object_bwall, OBJECT_BWALL)
/* 0x018B */ DEFINE_OBJECT(object_cow, OBJECT_COW)
/* 0x018C */ DEFINE_OBJECT(object_cob, OBJECT_COB)
/* 0x018D */ DEFINE_OBJECT(object_gi_sword_1, OBJECT_GI_SWORD_1)
/* 0x018E */ DEFINE_OBJECT(object_door_killer, OBJECT_DOOR_KILLER)
/* 0x018F */ DEFINE_OBJECT(object_ouke_haka, OBJECT_OUKE_HAKA)
/* 0x0190 */ DEFINE_OBJECT(object_timeblock, OBJECT_TIMEBLOCK)
/* 0x0191 */ DEFINE_OBJECT(object_zl4, OBJECT_ZL4)
DEFINE_OBJECT(object_kad, OBJECT_KAD)
DEFINE_OBJECT(object_aza, OBJECT_AZA)
DEFINE_OBJECT(object_lir, OBJECT_LIR)
DEFINE_OBJECT(object_nir, OBJECT_NIR)
DEFINE_OBJECT(object_met1, OBJECT_MET1)
DEFINE_OBJECT(object_met2, OBJECT_MET2)
