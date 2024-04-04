//---------------------------------------------------------------------------

#ifndef AplicatieClipboardH
#define AplicatieClipboardH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "cClipboard.h"
#include "Text.h"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <jpeg.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TfClipboard : public TForm
{
__published:	// IDE-managed Components
        TButton *btnCopy;
        TEdit *eEdit;
        TListBox *lstBox;
        TButton *btnPaste;
        TButton *btnDelete;
        TButton *btnCut;
        TImage *imgClipboard;
        TImage *imgFundal;
        TButton *btnAbout;
        TClientSocket *ClientSocket;
        void __fastcall btnCopyClick(TObject *Sender);
        void __fastcall btnPasteClick(TObject *Sender);
        void __fastcall btnDeleteClick(TObject *Sender);
        void __fastcall btnCutClick(TObject *Sender);
        void __fastcall btnAboutClick(TObject *Sender);
        void __fastcall ClientSocketRead(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ClientSocketConnect(TObject *Sender,
          TCustomWinSocket *Socket);
private:	// User declarations
public:		// User declarations
        __fastcall TfClipboard(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfClipboard *fClipboard;
//---------------------------------------------------------------------------
#endif
