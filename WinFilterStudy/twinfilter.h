#ifndef TWINFILTER_H
#define TWINFILTER_H
 #include "common.h"

  typedef struct
  {
    byte  bLastValues[256];
    byte  bCitac;
    word  wLastSoucet;
  }TFWinVar;

#ifdef __cplusplus
extern "C" {
#endif

  byte FilterWindow32(byte bInputValue,  TFWinVar *  FWinVar);

#ifdef __cplusplus
}
#endif

#endif // TWINFILTER_H

