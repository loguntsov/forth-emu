//---------------------------------------------------------------------------
#include <vcl.h>
#include "Stack.h"
#include "stdlib.h"


#pragma hdrstop


//---------------------------------------------------------------------------
#pragma package(smart_init)
Stack::Stack(int Num)
{
Stck=new void *[Num];
uk=0;num=Num;
}
Stack::~Stack()
{
delete Stck;
}
bool Stack::push(void *Data)
{
try {
Stck[uk]=Data;
uk++;
if (uk>num) { uk--;
              throw "Переполнение стека";
            } else return true;
}
catch (char *s)
{
MessageDlg(AnsiString(s),mtError,TMsgDlgButtons() << mbOK,0);
return false;
}
}
void *Stack::pop(void)
{
    try {
    if (uk==0) throw "Стек уже пуст";
        else { uk--;return Stck[uk]; }
}
catch (char *s)
{
MessageDlg(AnsiString(s),mtError,TMsgDlgButtons() << mbOK,0);
return NULL;
}
}
void * Stack::ret(void)
{
    if (uk==0) return NULL; else return Stck[uk-1];
}
void Stack::Reset(void)
{
    uk=0;
}
