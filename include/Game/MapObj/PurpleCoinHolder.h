#pragma once
#include "syati.h"

class PurpleCoinHolder : public LiveActorGroup {
public:
    PurpleCoinHolder();
    virtual void initAfterPlacement();
};

namespace MR {
    PurpleCoinHolder* createPurpleCoinHolder();
    void addToPurpleCoinHolder(const NameObj*, Coin*);
};