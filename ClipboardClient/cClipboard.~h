//---------------------------------------------------------------------------

#ifndef cClipboardH
#define cClipboardH
#include <Classes.hpp>
#include "FereastraAbout.h"

//---------------------------------------------------------------------------
class  myCLIPBOARD
{
private:
        int mDimensiune;
        AnsiString *mLista;
public:
        myCLIPBOARD(int, AnsiString[]);
        ~myCLIPBOARD(){};
        virtual AnsiString* Paste(int&, AnsiString [], AnsiString)=0;
        virtual AnsiString* Delete(int&, AnsiString [], int)=0;


};
#endif
