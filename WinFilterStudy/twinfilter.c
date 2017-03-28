#include "twinfilter.h"

/*
okénkový filtr na 32 vzorků, klouzavý průměr, maximální
vstupní hodnota je 255
*/
byte FilterWindow32(byte bInputValue,  TFWinVar *  FWinVar)
{
  FWinVar->bCitac++;
  FWinVar->bCitac&=0x1F;

  FWinVar->wLastSoucet-=FWinVar->bLastValues[FWinVar->bCitac];
  FWinVar->bLastValues[FWinVar->bCitac]=bInputValue;
  FWinVar->wLastSoucet+=FWinVar->bLastValues[FWinVar->bCitac];


  return(FWinVar->wLastSoucet/32);
}

