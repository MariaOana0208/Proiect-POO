//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AplicatieClipboard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfClipboard *fClipboard;
AnsiString text;

//---------------------------------------------------------------------------
__fastcall TfClipboard::TfClipboard(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfClipboard::btnCopyClick(TObject *Sender)
{
          if (eEdit->Text != "")
          {
                text=eEdit->Text;
                int Dimensiune=lstBox->Count;
                AnsiString *listaObiecte= new AnsiString[Dimensiune];

                for(int i=0; i<Dimensiune; i++)
                {
                        listaObiecte[i]=lstBox->Items->Strings[i];
                }

                myTEXT textObject(Dimensiune, listaObiecte, text);
                textObject.SetText(text);

                ClientSocket->Socket->SendText(text);

                eEdit->Clear();
                delete[] listaObiecte;
                eEdit->SetFocus();
          }



}
//---------------------------------------------------------------------------


void __fastcall TfClipboard::btnPasteClick(TObject *Sender)
{
        if(eEdit->Text!="") text=eEdit->Text;

        int dimensiune = lstBox->Count;
        AnsiString* listaObiecte = new AnsiString[dimensiune];

        for (int i = 0; i < dimensiune; i++)
        {
                listaObiecte[i] = lstBox->Items->Strings[i];
        }

        myCLIPBOARD *textObject;
        textObject=new myTEXT(dimensiune, listaObiecte, text);
        listaObiecte = textObject->Paste(dimensiune, listaObiecte, text);

        lstBox->Clear();
        for (int i = 0; i < dimensiune; i++)
        {
                lstBox->Items->Add(listaObiecte[i]);
        }

        ClientSocket->Socket->SendText("PASTE|" + text);

        eEdit->Clear();
        delete[] listaObiecte;
        delete textObject;
        eEdit->SetFocus();
}

//---------------------------------------------------------------------------



void __fastcall TfClipboard::btnDeleteClick(TObject *Sender)
{

        if(lstBox->ItemIndex!=-1)
        {
                int selectedIndex = lstBox->ItemIndex;
                text=lstBox->Items->Strings[selectedIndex];

                AnsiString textTrimis = "DELETE|" + IntToStr(selectedIndex);
                ClientSocket->Socket->SendText(textTrimis);

                int dimensiune = lstBox->Count;
                AnsiString* listaObiecte = new AnsiString[dimensiune];
                for (int i = 0; i < dimensiune; i++)
                {
                        listaObiecte[i] = lstBox->Items->Strings[i];
                }

                myCLIPBOARD *textObject;
                textObject = new myTEXT(dimensiune, listaObiecte, text);
                listaObiecte = textObject->Delete(dimensiune, listaObiecte, selectedIndex);
                lstBox->Clear();
                for (int i = 0; i < dimensiune; i++)
                {
                        lstBox->Items->Add(listaObiecte[i]);
                }
                text="";
                delete[] listaObiecte;
                delete textObject;
                lstBox->ItemIndex = -1;
                eEdit->SetFocus();
        }
}
//---------------------------------------------------------------------------

void __fastcall TfClipboard::btnCutClick(TObject *Sender)
{

        if(lstBox->ItemIndex!=-1)
        {
                int selectedIndex = lstBox->ItemIndex;
                text=lstBox->Items->Strings[selectedIndex];

                AnsiString textTrimis = "CUT|" + IntToStr(selectedIndex);
                ClientSocket->Socket->SendText(textTrimis);

                int dimensiune = lstBox->Count;
                AnsiString* listaObiecte = new AnsiString[dimensiune];
                for (int i = 0; i < dimensiune; i++)
                {
                        listaObiecte[i] = lstBox->Items->Strings[i];
                }
                myCLIPBOARD *textObject;
                textObject=new myTEXT(dimensiune, listaObiecte, text);
                listaObiecte = textObject->Delete(dimensiune, listaObiecte,selectedIndex);

                text=lstBox->Items->Strings[selectedIndex];

                lstBox->Clear();
                for (int i = 0; i < dimensiune; i++)
                {
                        lstBox->Items->Add(listaObiecte[i]);
                }
                delete[] listaObiecte;
                delete textObject;
                lstBox->ItemIndex = -1;
                eEdit->SetFocus();
        }
}
//---------------------------------------------------------------------------


void __fastcall TfClipboard::btnAboutClick(TObject *Sender)
{
        fAbout->Show();
}
//---------------------------------------------------------------------------


void __fastcall TfClipboard::ClientSocketRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AnsiString textPrimit;
        //pt butonul Copy
        textPrimit = Socket->ReceiveText();

        //pt butonul Paste
        if(textPrimit.Pos("PASTE|") == 1)
        {
                textPrimit = textPrimit.SubString(7, textPrimit.Length());

                int dimensiune = lstBox->Count;
                AnsiString* listaObiecte = new AnsiString[dimensiune];

                for (int i = 0; i < dimensiune; i++)
                {
                        listaObiecte[i] = lstBox->Items->Strings[i];
                }

                myCLIPBOARD *textObject;
                textObject=new myTEXT(dimensiune, listaObiecte, textPrimit);
                listaObiecte = textObject->Paste(dimensiune, listaObiecte, textPrimit);

                lstBox->Clear();
                for (int i = 0; i < dimensiune; i++)
                {
                        lstBox->Items->Add(listaObiecte[i]);
                }

                eEdit->Clear();
                delete[] listaObiecte;
                delete textObject;
        }

        //pt butonul Delete

        if(textPrimit.Pos("DELETE|") == 1)
        {
                textPrimit=textPrimit.SubString(8, textPrimit.Length());

                int selectedIndex = StrToInt(textPrimit);

                if (selectedIndex != -1)
                {

                        int dimensiune = lstBox->Count;
                        AnsiString* listaObiecte = new AnsiString[dimensiune];
                        for (int i = 0; i < dimensiune; i++)
                        {
                                listaObiecte[i] = lstBox->Items->Strings[i];
                        }

                        myCLIPBOARD *textObject;
                        textObject=new myTEXT(dimensiune, listaObiecte, textPrimit);
                        listaObiecte = textObject->Delete(dimensiune, listaObiecte, selectedIndex);

                        lstBox->Clear();
                        for (int i = 0; i < dimensiune; i++)
                        {
                                lstBox->Items->Add(listaObiecte[i]);
                        }
                        textPrimit="";

                        delete[] listaObiecte;
                        delete textObject;
                        lstBox->ItemIndex = -1;
                }
                 else
                {
                        ShowMessage("Textul nu reprezinta un numar valid!");
                }

        }
        //pt butonul Cut
        if(textPrimit.Pos("CUT|") == 1)
        {
                textPrimit=textPrimit.SubString(5, textPrimit.Length());

                int selectedIndex = StrToInt(textPrimit);

                if (selectedIndex != -1)
                {

                        int dimensiune = lstBox->Count;
                        AnsiString* listaObiecte = new AnsiString[dimensiune];
                        for (int i = 0; i < dimensiune; i++)
                        {
                                listaObiecte[i] = lstBox->Items->Strings[i];
                        }
                        myCLIPBOARD *textObject;
                        textObject=new myTEXT(dimensiune, listaObiecte, textPrimit);
                        listaObiecte = textObject->Delete(dimensiune, listaObiecte, selectedIndex);

                        text=lstBox->Items->Strings[selectedIndex];
                        textPrimit="";

                        lstBox->Clear();
                        for (int i = 0; i < dimensiune; i++)
                        {
                                lstBox->Items->Add(listaObiecte[i]);
                        }

                        delete[] listaObiecte;
                        delete textObject;
                        lstBox->ItemIndex = -1;
                }
                else
                {
                        ShowMessage("Textul nu reprezinta un numar valid!");
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TfClipboard::ClientSocketConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        ShowMessage("Conectat la server cu succes!");
}
//---------------------------------------------------------------------------

