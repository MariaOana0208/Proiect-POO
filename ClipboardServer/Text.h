//---------------------------------------------------------------------------

#ifndef TextH
#define TextH
#include <Classes.hpp>
#include "cClipboard.h"
//---------------------------------------------------------------------------
class myTEXT : public myCLIPBOARD
{
private:
        AnsiString mText;
public:
        myTEXT(int , AnsiString [], AnsiString);
        ~myTEXT(){};
        void SetText(AnsiString);
        AnsiString *Paste(int&, AnsiString [], AnsiString);
        AnsiString* Delete(int&, AnsiString [], int);

};
#endif

