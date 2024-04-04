//---------------------------------------------------------------------------
#include "Text.h"
#include "cClipboard.h"
#include <Classes.hpp>
#pragma hdrstop



//---------------------------------------------------------------------------

#pragma package(smart_init)


myTEXT::myTEXT(int aDimensiune, AnsiString aLista[], AnsiString aText)
    : myCLIPBOARD(aDimensiune, aLista)
{
        mText=aText;
}


void myTEXT::SetText(AnsiString aText)
{
        mText=aText;
}
AnsiString* myTEXT::Paste(int& aDimensiune, AnsiString aLista[], AnsiString aText)
{
        aDimensiune++;
        AnsiString* listaNoua = new AnsiString[aDimensiune];
        for (int i = 0; i < aDimensiune - 1; i++)
        {
                listaNoua[i] = aLista[i];
        }
        listaNoua[aDimensiune - 1] = aText;
        delete[] aLista;
        return listaNoua;

}
AnsiString* myTEXT::Delete(int& aDimensiune, AnsiString aLista[], int aPos)
{
        AnsiString* listaNoua = new AnsiString[aDimensiune];
        for (int i = 0; i < aDimensiune; i++)
        {
                listaNoua[i] = aLista[i];
        }
        for(int i=aPos; i<aDimensiune-1; i++)
        {
                listaNoua[i]=listaNoua[i+1];

        }
        aDimensiune--;
        delete[] aLista;
        return listaNoua;
}
