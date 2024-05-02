#pragma once
#include "Game/LiveActor/LiveActor.h"

class FileSelectModel : public LiveActor
{
public:
  FileSelectModel(const char *modelName, MtxPtr, const char *jpName);

  void emitOpen();
  void emitVanish();
  void emitCompleteEffect();

  float *_90[4];
};