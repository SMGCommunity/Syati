#pragma once

#include "Game/MapObj/BenefitItemObj.h"

class BenefitItemOneUp : public BenefitItemObj {
public:
    BenefitItemOneUp(const char *pName) : BenefitItemObj(pName, "KinokoOneUp") {

    }
    BenefitItemOneUp(const char *pName, const char *pModelName) : BenefitItemObj(pName, pModelName) {

    }
};