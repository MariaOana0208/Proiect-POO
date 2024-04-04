//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FereastraAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfAbout *fAbout;
//---------------------------------------------------------------------------
__fastcall TfAbout::TfAbout(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfAbout::btnExitClick(TObject *Sender)
{
        fAbout->Hide();
}
//---------------------------------------------------------------------------



