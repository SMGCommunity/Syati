#include "syati.h"
#include "Game/NPC/TicoEat.h"

class TicoShopDice : public TicoEat {
public:
    TicoShopDice(const char* pName);

    virtual ~TicoShopDice();
    virtual void init(const JMapInfoIter rIter);
    bool branchFunc(u32 u);
    bool eventFunc(u32 u);


    bool _1B8;
    s32 _1BC;
    s32 _1C0;
    s32 _1C4;
    s32 _1C8;
};