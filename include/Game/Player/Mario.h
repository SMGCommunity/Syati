#pragma once

#include "revolution.h"
#include "Game/Player/MarioModule.h"

class MarioActor;
class MarioState;
class MarioSwim;
class FloorCode;
// Undocumented
class MarioFlow;
class MarioWall;
class MarioDamage;
class MarioFaint;
class MarioBlown;
class MarioHang;
class MarioSlider;
class MarioFireDamage;
class MarioFireRun;
class MarioFireDance;
class MarioAbyssDamage;
class MarioDarkDamage;
class MarioStep;
class MarioBump;
class MarioParalyze;
class MarioStun;
class MarioCrush;
class MarioFreeze;
class MarioMagic;
class MarioFpView;
class MarioRecovery;
class MarioFlip;
class MarioSideStep;
class MarioFrontStep;
class MarioStick;
class MarioRabbit;
class MarioSukekiyo;
class MarioBury;
class MarioWait;
class MarioClimb;
class MarioSkate;
class MarioFoo;
class MarioWarp;
class MarioTeresa;
class MarioTalk;
class MarioYoshiPull;
class MarioYoshiBalloon;
class MarioYoshiShot;
class MarioYoshiDash;
class MarioMove;
struct SoundList;

class Mario : public MarioModule {
public:
    Mario(MarioActor *pMarioActor);

    void initMember();
    
    bool isStatusActive(u32 statusCode) const;
    void closeStatus(MarioState*);
    u32 getCurrentStatus() const;

    void playSoundTrampleCombo(u8);
    
    void tryJump();
    void trySquatJump();
    void resetSleepTimer();

    void updateCubeCode();
    void updateCometCode();
    void updateOnSand();
    void updateOnPoison();

    bool isCurrentFloorSink() const;
    bool checkCurrentFloorCodeSevere(u32) const;

    bool isIgnoreTriangle(const Triangle *);
    void clear2DStick();
    void clearSlope();

    void initSound();
    u32 initSoundTable(SoundList *, u32);
    void initTask();
    void initActiveJumpVec();

    f32 sub_803B1BA0();
    void sub_80396BF0();
    bool isSwimming() const;

    u8 _8;
    u8 _9;
    u8 _A;
    u8 _B;
    u32 _C;
    u32 _10;
    u32 _14;
    u32 _18;
    u32 _1C;
    u32 _20;
    u32 _24;
    u32 _28;
    u32 _2C;
    u32 _30;
    u32 _34;
    u32 _38;
    f32 _3C;
    f32 _40;
    MarioTeresa *mMarioTeresa;
    TVec3f _48;
    TVec3f _54;
    TVec3f _60;
    MtxPtr _6C;
    u32 _70;
    u32 _74;
    u32 _78;
    u32 _7C;
    u32 _80;
    u32 _84;
    u32 _88;
    u32 _8C;
    u32 _90;
    u32 _94;
    u32 _98;
    MtxPtr _9C;
    u32 _A0;
    u32 _A4;
    u32 _A8;
    u32 _AC;
    u32 _B0;
    u32 _B4;
    u32 _B8;
    u32 _BC;
    u32 _C0;
    u32 _C4;
    u32 _C8;
    MtxPtr _CC;
    u32 _D0;
    u32 _D4;
    u32 _D8;
    u32 _DC;
    u32 _E0;
    u32 _E4;
    u32 _E8;
    u32 _EC;
    u32 _F0;
    u32 _F4;
    u32 _F8;
    MtxPtr _FC;
    u32 _100;
    u32 _104;
    u32 _108;
    u32 _10C;
    u32 _110;
    u32 _114;
    u32 _118;
    u32 _11C;
    u32 _120;
    u32 _124;
    u32 _128;
    f32 _12C;
    f32 _130;
    u32 _134;
    u32 *_138; // undocumented class, see 0x80405E40 and 0x80405F90
    TVec3f _13C;
    TVec3f _148;
    TVec3f _154;
    TVec3f _160;
    TVec3f _16C;
    TVec3f _178;
    TVec3f _184;
    TVec3f _190;
    TVec3f _19C;
    TVec3f _1A8;
    TVec3f _1B4;
    f32 _1C0;
    f32 _1C4;
    f32 _1C8;
    TVec3f _1CC;
    TVec3f _1D8;
    TVec3f _1E4;
    TVec3f _1F0;
    TVec3f _1FC;
    TVec3f _208;
    f32 _214;
    f32 _218;
    f32 _21C;
    TVec3f _220;
    f32 _22C;
    f32 _230;
    f32 _234;
    TVec3f _238;
    TVec3f _244;
    TVec3f _250;
    TVec3f _25C;
    TVec3f _268;
    u32 _274;
    f32 _278;
    f32 _27C;
    f32 _280;
    TVec3f _284;
    f32 _290;
    u32 _294;
    u32 _298;
    TVec3f _29C;
    TVec3f _2A8;
    f32 _2B4;
    TVec3f _2B8;
    TVec3f _2C4;
    f32 _2D0;
    TVec3f _2D4;
    TVec3f _2E0;
    TVec3f _2EC;
    TVec3f _2F8;
    TVec3f _304;
    TVec3f _310;
    TVec3f _31C;
    TVec3f _328;
    TVec3f _334;
    f32 _340;
    f32 _344;
    f32 _348;
    f32 _34C;
    TVec3f _350;
    TVec3f _35C;
    f32 _368;
    f32 _36C;
    f32 _370;
    TVec3f _374;
    TVec3f _380;
    TVec3f _38C;
    f32 _398;
    f32 _39C;
    f32 _3A0;
    TVec3f _3A4;
    TVec3f _3B0;
    u16 _3BC;
    u16 _3BE;
    u16 _3C0;
    u16 _3C2;
    u16 _3C4;
    u16 _3C6;
    u16 _3C8;
    u16 _3CA;
    u16 _3CC;
    u16 _3CE;
    u16 _3D0;
    u16 _3D2;
    u16 _3D4;
    u16 _3D6;
    TVec3f _3D8;
    f32 _3E4;
    f32 _3E8;
    f32 _3EC;
    f32 _3F0;
    f32 _3F4;
    u16 _3F8;
    u16 _3FA;
    u16 _3FC;
    u16 _3FE;
    u16 _400;
    u16 _402;
    u16 _404;
    u16 _406;
    u16 _408;
    u16 _40A;
    u16 _40C;
    u16 _40E;
    u16 _410;
    u16 _412;
    u16 _414;
    u16 _416;
    u16 _418;
    u16 _41A;
    u16 _41C;
    u16 _41E;
    u16 _420;
    u16 _422;
    u16 _424;
    u16 _426;
    u16 _428;
    u16 _42A;
    u32 _42C;
    u16 _430;
    u16 mDashNotice;
    u16 _434;
    u16 _436;
    TVec3f _438;
    TVec3f _444;
    f32 _450;
    u32 *_454; // undocumented class, see 0x80387140 and beyond
    Triangle *_458[11];
    f32 _484;
    TVec3f _488;
    TVec3f _494;
    TVec3f _4A0;
    TVec3f _4AC;
    TVec3f _4B8;
    Triangle *_4C4[6];
    f32 _4DC;
    f32 _4E0;
    TVec3f _4E4;
    TVec3f _4F0;
    u32 _4FC;
    u32 _500;
    u32 _504;
    TVec3f _508;
    TVec3f _514;
    f32 _520;
    f32 _524;
    f32 _528;
    f32 _52C;
    u16 _530;
    u16 _532;
    f32 _534;
    f32 _538;
    f32 _53C;
    u16 _540;
    u16 _542;
    f32 _544;
    TVec3f _548;
    u32 _554;
    u32 _558;
    u32 _55C;
    s32 _560;
    u32 _564;
    u8 _568;
    u8 _569;
    u8 _56A;
    u8 _56B;
    u32 _56C;
    u32 _570;
    Triangle *_574[32];
    u32 _5F4;
    u32 _5F8;
    u32 _5FC;
    TVec3f _600;
    u8 _60C;
    u8 _60D;
    u8 _60E;
    u8 _60F;
    u8 _610;
    u8 _611;
    u8 _612;
    u8 _613;
    f32 _614;
    f32 _618;
    f32 _61C;
    f32 _620;
    u8 _624;
    u8 _625;
    u8 _626;
    u8 _627;
    f32 _628;
    u8 _62C;
    u8 _62D;
    u8 _62E;
    u8 _62F;
    f32 _630;
    f32 _634;
    f32 _638;
    f32 _63C;
    f32 _640;
    f32 _644;
    f32 _648;
    f32 _64C;
    f32 _650;
    TVec3f _654;
    u8 _660;
    u8 _661;
    u8 _662;
    u8 _663;
    TVec3f _664;
    TVec3f _670;
    TVec3f _67C;
    TVec3f _688;
    TVec3f _694;
    u32 _6A0;
    u8 _6A4;
    u8 _6A5;
    u8 _6A6;
    u8 _6A7;
    TVec3f _6A8;
    TVec3f _6B4;
    f32 _6C0;
    f32 _6C4;
    TVec3f _6C8;
    TVec3f _6D4;
    TVec3f _6E0;
    u32 _6EC;
    u32 _6F0;
    u32 _6F4;
    TVec3f _6F8;
    TVec3f _704;
    f32 _710;
    u8 _714;
    u8 _715;
    u8 _716;
    u8 _717;
    u32 _718;
    u32 _71C;
    u32 _720;
    f32 _724;
    u32 _728;
    u8 _72C;
    u8 _72D;
    u8 _72E;
    u8 _72F;
    f32 _730;
    f32 _734;
    f32 _738;
    f32 _73C;
    u8 _740;
    u8 _741;
    u8 _742;
    u8 _743;
    f32 _744;
    u32 _748;
    u32 _74C;
    MarioWall *mMarioWall;
    TVec3f _754;
    MarioStick *mMarioStick;
    u16 _764;
    u16 _766;
    f32 _768;
    u16 _76C;
    u16 _76E;
    MarioRabbit *mMarioRabbit;
    MarioFoo *mMarioFoo;
    MarioSukekiyo *mMarioSukekiyo;
    MarioBury *mMarioBury;
    MarioWait *mMarioWait;
    MarioClimb *mMarioClimb;
    TVec3f _788;
    MarioHang *mMarioHang;
    MarioRecovery *mMarioRecovery;
    MarioWarp *mMarioWarp;
    MarioFlip *mMarioFlip;
    MarioSideStep *mMarioSideStep;
    MarioFrontStep *mMarioFrontStep;
    MarioSkate *mMarioSkate;
    MarioTalk *mMarioTalk;
    MarioYoshiPull *mMarioYoshiPull;
    MarioYoshiBalloon *mMarioYoshiBalloon;
    MarioYoshiShot *mMarioYoshiShot;
    MarioYoshiDash *mMarioYoshiDash;
    MarioDamage *mMarioDamage;
    TVec3f _7C8;
    u32 _7D4;
    TVec3f _7D8;
    Triangle *_7E4;
    MtxPtr _7E8;
    u32 _7EC;
    u32 _7F0;
    u32 _7F4;
    u32 _7F8;
    u32 _7FC;
    u32 _800;
    u32 _804;
    u32 _808;
    u32 _80C;
    u32 _810;
    u32 _814;
    TVec3f _818;
    Triangle *_824;
    MtxPtr _828;
    u32 _82C;
    u32 _830;
    u32 _834;
    u32 _838;
    u32 _83C;
    u32 _840;
    u32 _844;
    u32 _848;
    u32 _84C;
    u32 _850;
    u32 _854;
    MarioFlow *mMarioFlow;
    MarioFireDamage *mMarioFireDamage;
    MarioFireDance *mMarioFireDance;
    MarioFireRun *mMarioFireRun;
    MarioParalyze *mMarioParalyze;
    MarioStun *mMarioStun;
    MarioCrush *mMarioCrush;
    MarioFreeze *mMarioFreeze;
    MarioAbyssDamage *mMarioAbyssDamage;
    MarioDarkDamage *mMarioDarkDamage;
    MarioFaint *mMarioFaint;
    MarioBlown *mMarioBlown;
    MarioSwim *mMarioSwim;
    MarioSlider *mMarioSlider;
    MarioStep *mMarioStep;
    MarioBump *mMarioBump;
    MarioMagic *mMarioMagic;
    u32 _89C;
    MarioFpView *mMarioFpView;
    MarioMove *mMarioMove;
    TVec3f _8A8;
    TVec3f _8B4;
    TVec3f _8C0;
    Triangle *_8CC[3];
    u32 _8D8;
    u32 _8DC;
    TVec3f _8E0;
    Triangle *_8EC;
    u8 _8F0;
    u8 _8F1;
    u8 _8F2;
    u8 _8F3;
    u32 _8F4;
    f32 _8F8;
    TVec3f _8FC;
    TVec3f _908;
    TVec3f _914;
    TVec3f _920;
    TVec3f _92C;
    f32 _938;
    TVec3f _93C;
    TVec3f _948;
    TVec3f _954;
    FloorCode *_960;
    u16 _964;
    u16 _966;
    u16 _968;
    u16 _96A;
    u16 _96C;
    u16 _96E;
    HashSortTable *mHashSortTable;
    u32 _974;
    u32 _978;
    u32 _97C;
    MarioState *mMarioState;
    u32 _984;
    u32 _988;
    u32 _98C;
    u32 _990;
    u32 _994;
    u32 _998;
    u32 _99C;
    u32 _9A0;
    u32 _9A4;
    u32 _9A8;
    u32 _9AC;
    u32 _9B0;
    u32 _9B4;
    u32 _9B8;
    u32 _9BC;
    u32 _9C0;
    u32 _9C4;
    u32 _9C8;
    u32 _9CC;
    u32 _9D0;
    u32 _9D4;
    u32 _9D8;
    u32 _9DC;
    u32 _9E0;
    u32 _9E4;
    u32 _9E8;
    u32 _9EC;
    u32 _9F0;
    u32 _9F4;
    u32 _9F8;
    u32 _9FC;
    u32 _A00;
    u32 _A04;
    u32 _A08;
    u32 _A0C;
    u32 _A10;
    u32 _A14;
    u32 _A18;
    u32 _A1C;
    u32 _A20;
    u32 _A24;
    u32 _A28;
    u32 _A2C;
    u32 _A30;
    u32 _A34;
    u16 _A38;
    u16 _A3A;
    u32 _A3C;
    u16 _A40;
    u16 _A42;
    TVec3f _A44;
    TVec3f _A50;
    TVec3f _A5C;
    f32 _A68;
    u32 _A6C;
    u8 _A70;
    u8 _A71;
    u8 _A72;
    u8 _A73;
    u32 _A74;
    u8 _A78;
    u8 _A79;
    u8 _A7A;
    u8 _A7B;
    u8 _A7C;
    u8 _A7D;
    u8 _A7E;
    u8 _A7F;
    u8 _A80;
    u8 _A81;
    u8 _A82;
    u8 _A83;
    u32 *_A84; // undocumented class, see 0x8040B7A0
    u8 _A88;
    u8 _A89;
    u8 _A8A;
    u8 _A8B;
    u32 _A8C;
    u32 _A90; // undocumented class, see 0x8038C890
    u32 _A94;
    u32 _A98;
    u32 _A9C;
    u32 _AA0;
    u32 _AA4;
};
