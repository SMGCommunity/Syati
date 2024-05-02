#pragma once

#include "Game/Screen/LayoutActor.h"

class MiiSelectIcon : public LayoutActor
{
public:
  MiiSelectIcon(int, int, int, const char *unk);
  void appearMiiDummy();
  void appear();
};