#pragma once

#include "Game/Screen/LayoutActor.h"
#include "Game/Util/BitArray.h"
#include "Game/Map/FileSelectIconID.h"

class MiiSelect : public LayoutActor
{
public:
  u16 getIconNum(); // Icon Count
  u16 getIconID(const FileSelectIconID &, const long);
  char unk[0x8];
  MR::BitArray *bitFlags; //_34
  u16 iconCount;          //_38
};
