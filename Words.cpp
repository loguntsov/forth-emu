//---------------------------------------------------------------------------
#include <vcl.h>
#include "Words.h"


#pragma hdrstop



//---------------------------------------------------------------------------
#pragma package(smart_init)

EWord::EWord()
{
Data=NULL;
Link=NULL;
AutoDelet=true;
}
EWord::EWord(bool Delet)
{
Data=NULL;
Link=NULL;
AutoDelet=Delet;
}
EWord::~EWord()
{
delete Link;
// Может не удалять DATA;
if (AutoDelet) delete Data;
}
Words::Words(AnsiString NameS,int exec)
{
Name=NameS;
Link=NULL;
Execute=exec;
Immediate=false;
}
Words::~Words()
{
delete Link;
}

