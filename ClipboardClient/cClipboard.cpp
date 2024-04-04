//---------------------------------------------------------------------------


#pragma hdrstop

#include "cClipboard.h"


//---------------------------------------------------------------------------

#pragma package(smart_init)


myCLIPBOARD::myCLIPBOARD(int aDimeniune, AnsiString aLista[])
{
        mDimensiune=aDimeniune;
        mLista= new AnsiString[mDimensiune];
        for(int i=0; i< mDimensiune; i++){
                mLista[i]=aLista[i];
        }
}




