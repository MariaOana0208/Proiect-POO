//---------------------------------------------------------------------------

#ifndef FereastraAboutH
#define FereastraAboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TfAbout : public TForm
{
__published:	// IDE-managed Components
        TButton *btnExit;
        TImage *imgAbout;
        void __fastcall btnExitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfAbout *fAbout;
//---------------------------------------------------------------------------
#endif
