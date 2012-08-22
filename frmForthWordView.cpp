//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "frmForthWordView.h"
#include "Unit1.h"
#include "LForthMachine.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmWordView *frmWordView;
//---------------------------------------------------------------------------
__fastcall TfrmWordView::TfrmWordView(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TfrmWordView::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Form1->mnuWords->Checked=false;
}
//---------------------------------------------------------------------------


void __fastcall TfrmWordView::Label1Click(TObject *Sender)
{
static int NumWord=0;
int n=0;
Dictionary *Beg=DictBegin;
int a=ListBox->ItemIndex;
ListBox->Clear();
do
{
n++;
ListBox->Items->Add(Beg->WordS->Name);
Beg=Beg->Link;
} while (Beg->Link!=NULL);
ListBox->ItemIndex=a+(n-NumWord);
NumWord=n;
}
//---------------------------------------------------------------------------



void __fastcall TfrmWordView::ListBoxDblClick(TObject *Sender)
{
DictBegin->FindDictionary(ListBox->Items->Strings[ListBox->ItemIndex])->ShowHelp();
}
//---------------------------------------------------------------------------

