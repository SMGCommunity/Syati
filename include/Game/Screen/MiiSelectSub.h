#pragma once

#include "syati.h"

#include "Game/Map/FileSelectIconID.h"

class MiiSelect;

namespace MiiSelectSub {
    class Page {
      Page(MiiSelect *);
      void refresh(long);
      void movement();
      void calcAnim();
      void invalidateAllIcon();
      void validateAllIcon();
      void prohibitIcon(const FileSelectIconID&);
    };
};
