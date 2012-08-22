//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "LForthMachine.h"
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
//#include "ForthDataType.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

const NumRunMet=100;

Dictionary *DictBegin=NULL; // ������ �������
static void *PrevData=NULL; // ������, ���� ������������ ���������� ������ �� ����� ����������
static int NumElemFunc=0; // ���������� ���� ������������ � Forth ����������� ������� �����
//static Dictionary *Prev=NULL;
static void (*Run[NumRunMet])(void*);
Stack *Stk;
bool StateLFM=Immediat;
unsigned int LFMBase=10;
long Pos0=0;
char *Inpt; // ����� �������� ������ ����.
// �����, ������� ����� ������� �����
static bool CatDat(EWord *x); // �������� �����
static AnsiString WOrd(char *Str,char Ogr);
static int FindExecution(char *NameExecution);
static Stack *Stret;
//
//
//
#include "StandartForthWords.h"
//
//
//
// --------------------------------------------------------------------------
// ���������� ���� ���� LForthMachine
//----------------------------------------------------------------------------
void LFMInit(int SizeStack)
{
Stret=new Stack(400);
for(int i=0;i<NumRunMet;i++) Run[i]=NULL;
PrevData=NULL;
//Prev=NULL;
DictBegin=NULL;
NumElemFunc=0;
Stk= new Stack(SizeStack);
StateLFM=Immediat;
//
// �������� ������� �� ������� ����.
//
LFMAddWord("FORGET",forget,"");
LFMAddWord("_EXECUTE",execute,"");
LFMAddWord("_ILITERAL",iliteral,"");
LFMAddWord("_IF",aIFa,"");
LFMAddWord("_ELSE",aELSEa,"");
LFMAddWord("NOP",nop,"");
LFMAddWord(".",dot,"");
LFMAddWord("+",iplus,"");
LFMAddWord("-",iminus,"");
LFMAddWord("*",imultip,"");
LFMAddWord("/",idiv,"");
LFMAddWord("MOD",imod,"mod.htm");
LFMAddWord("IMMEDIATE",immediate,"immediate.htm");immediate(NULL);
LFMAddWord("?IMMEDIATE",woprimmediate,"");
LFMAddWord("?COMP",woprcomp,"");
LFMAddWord(":",dbldot,"");
LFMAddWord(";",dotpunkt,"");immediate(NULL);
//LFMAddWord("DUP",dup,"dup.htm");
LFMAddWord("SWAP",swap,"swap.htm");
LFMAddWord("ROT",rot,"rot.htm");
//LFMAddWord("OVER",over,"over.htm");
LFMAddWord("DROP",drop,"drop.htm");
//LFMAddWord("2DUP",dupdup,"2dup.htm");
LFMAddWord("2DROP",dropdrop,"2drop.htm");
LFMAddWord("1+",plus1,"");
LFMAddWord("1-",minus1,"");
LFMAddWord("2*",dwumn,"");
LFMAddWord("2/",dwdiv,"");
LFMAddWord("BEEP",beep,"beep.htm");
LFMAddWord("R>",rb,"");
LFMAddWord("R<",rm,"");
LFMAddWord("\\**",kom,"kom.htm");immediate(NULL);// \**
LFMAddWord("IF",IF,"if.htm");immediate();
LFMAddWord("THEN",THEN,"if.htm");immediate();
LFMAddWord("ELSE",ELSE,"if.htm");immediate();
LFMAddWord("0=",arwa,"0rw.htm");
LFMAddWord("0>",abla,"0bl.htm");
LFMAddWord("0<",amna,"0mn.htm");
LFMAddWord("NOT",NOT,"not.htm");
LFMAddWord("AND",AND,"and.htm");
LFMAddWord("OR",OR,"or.htm");
LFMAddWord("XOR",XOR,"xor.htm");
}
//----------------------------------------------------------
// ���������� ����� ����������� �� ������ ����� � ������� ��� ������ Name
Dictionary * LFMAddWord(char *Name,void (*exec)(void *),AnsiString HelpF)
{
Dictionary *a=new Dictionary(Name,NumElemFunc);
Run[NumElemFunc]=exec;
a->Add(DictBegin);
a->HelpFile=HelpF;
DictBegin=a;NumElemFunc++;
return DictBegin;
}
//-----------------------------------------------------------
// ���������� ����� ����������� � ������� Run.
static int FindExecution(char *NameExecution)
{
return DictBegin->Find(AnsiString(NameExecution))->Execute;
}
//-----------------------------------------------------
static bool CatDat(EWord *x) // �������� �����
{
if (PrevData==DictBegin->WordS) {
                          DictBegin->WordS->Link=x;
                          x->Link=NULL;PrevData=x;
                          } else { ((EWord *) PrevData)->Link=x;
                          x->Link=NULL;PrevData=x;
                          }
return true; // ��������������� ��� �������� �������������
}
//-----------------------------------------------------
void LFMDelete(void)
{
delete Stk,Stret;
delete DictBegin;
}
//-----------------------------------------------------
static bool IntConvert(AnsiString Str) // ������ � ���� ����� �����, ���� ����� ���������� �� ������
{
bool Otr=false;
int n=0;
char s;
for(int i=1;i<=Str.Length();i++)
{
s=Str[i];
if (s>=48) {
            n=n*LFMBase;
            if ((Str[i]-48)>=LFMBase)
                    return false;
                        else
                    n=n+(Str[i]-48);
           } else  {
           if ((s=='-')&&(i<Str.Length()))
                    { if (Str[i+1]>=48) Otr=true; }
                        else
                    return false;
                    }
}
if (Otr) n=-n;
FINT *a=new FINT;
*a=n;return Stk->push(a);
}
//--------------------------------------------------------------------------
// ��������� �� ����� ���������� �������������� (FINT) ��������
// ������� ������ ����������, �����������
static bool ILit(void)
{
    EWord *x=new EWord;
    Words *y=DictBegin->Find("_ILITERAL");
    x->Data=y;
    CatDat(x);
    x=new EWord;
    x->Data=Stk->pop();
    CatDat(x);
    return true;
}
// ���������� ������ �����
void LFMRunWord(AnsiString Word)
{
if (Word!="") {
    try{
    if (!IntConvert(Word)) {
                    Words *Wrd=DictBegin->Find(Word);
                    if (Wrd==NULL)
                                    throw (AnsiString("���������� �����: "+Word)).c_str();
                                        else
                                    if ((StateLFM==Immediat) || (Wrd->Immediate))
                                        {
                                        Stret->push(NULL);
                                        (Run[Wrd->Execute])(Wrd->Link);
                                        Stret->pop();
                                        }
                                            else {
                                        EWord *x=new EWord;
                                        x->Data=Wrd;CatDat(x); }
                    } else {
                        if (StateLFM==Compilat) {
                            bool typ=false;
                            typ=ILit();
                            if (!typ) throw "������ ������������� ����������� ����������� ������";
                            }
                    }
    }
    catch (char *S) {
    MessageDlg(AnsiString(S),mtError,TMsgDlgButtons() << mbOK,0);
    }
}
}
//---------------------------------------------------------------------
// ����� ��������� ������������� �������� ORG.
static AnsiString WOrd(char *Str,char Ogr)
{
char *St=new char [strlen(Str)];
strcpy(St,"");
int n=strlen(Str);
//int pos=0;
while ((Str[Pos0]==Ogr)&&(Pos0<n)) {Pos0++;}
for(;(Str[Pos0]!=Ogr)&&(Pos0<n);Pos0++)
{
if (Str[Pos0]!=Ogr) {strncat(St,Str+Pos0,1);}
}
AnsiString a=AnsiString(St);
Pos0++;
delete St;
return a;
}
//-----------------------------------------------------------------------
// ���������� ������
void LFMRunString(char *Str)
{
Pos0=0;
int n=strlen(Str);
char *St=new char [n];
strcpy(St,"");
for(int i=0;i<n;i++)
{
if (unsigned(*Str)>31) { strncat(St,Str,1); } else { strcat(St," "); }
Str++;
}
Inpt=St;
while (Pos0<strlen(St))
{
LFMRunWord(WOrd(St,' '));
}
delete St;
Inpt=NULL;
}
bool LFMRunFile(AnsiString File)
{
FILE *fl;
if ((fl=fopen(File.c_str(),"r"))!=NULL)
            {
            int h=open(File.c_str(),O_RDONLY);
            char *buf=new char[filelength(h)];
            fread(buf,filelength(h),filelength(h),fl);
            fclose(fl);close(h);
            LFMRunString(buf);
            delete buf;
            return true;
            } else return false;
}

