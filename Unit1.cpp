//---------------------------------------------------------------------------
#include <vcl.h>
#include "Unit1.h"
#include "Unit2.h"
#include "frmForthWordView.h"
#include "LForthMachine.h"


#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
LFMInit(300);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
LFMRunString(Memo1->Lines->GetText());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
LFMDelete();    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ShowStackClick(TObject *Sender)
{
ShowStack->Checked = !ShowStack->Checked;
if (ShowStack->Checked) Form2->Show(); else Form2->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mnuWordsClick(TObject *Sender)
{
mnuWords->Checked = !mnuWords->Checked;
if (mnuWords->Checked) frmWordView->Show(); else frmWordView->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mnuExitClick(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mnuOpenClick(TObject *Sender)
{
if (OpenDialog1->Execute()) {
    Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mnuSaveClick(TObject *Sender)
{
if (SaveDialog1->Execute()) {
    Memo1->Lines->SaveToFile(SaveDialog1->FileName);
    }    
}
//---------------------------------------------------------------------------







void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{
    Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
void TForm1::OpenURL(AnsiString URL)
{
	//Web->Navigate(URL.WideChar);
}
