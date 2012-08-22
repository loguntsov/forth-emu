//---------------------------------------------------------------------------
#include <vcl.h>
#include "Unit2.h"
#include "LForthMachine.h"
#include "Unit1.h"


#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
StringGrid1->RowCount=(Stk->uk)+1;
for(int i=1;i<=Stk->uk;i++)
{
void *a;
a=Stk->Stck[Stk->uk-i];
StringGrid1->Cells[0][i]=*(FINT *) a;
/*switch (a.Type)
{
    case INTF :
        StringGrid1->Cells[0][i]=*(FINT *) a.Data;
        break;
    case ADRESSF :
        StringGrid1->Cells[0][i]="адрес";
        break;
default:
    StringGrid1->Cells[0][i]="Неизвестный тип";
}
*/
}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender)
{
Timer1->Enabled=true;    
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormHide(TObject *Sender)
{
Timer1->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
Form1->ShowStack->Checked=false;
}
//---------------------------------------------------------------------------

