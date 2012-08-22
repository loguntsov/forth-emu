//---------------------------------------------------------------------------
#ifndef LForthMachineH
#define LForthMachineH

#include "Dictionary.h"
#include "Stack.h"
#include "ForthDataType.h"

// ��������� ������ ����������
const bool Compilat=false;
const bool Immediat=true;
//inline EWord *LnkLnk(void *x) { return ((EWord*) x)->Link; }
extern Stack *Stk;
extern unsigned int LFMBase;
extern bool StateLFM;
extern void LFMInit(int SizeStack); // ������� ����� ������ ��� ������
extern void LFMDelete(); // ��� ����������� ������ � �������
extern void LFMRunWord(AnsiString Word); // ���������� ������ �����
extern Dictionary * LFMAddWord(char * Name,void (*Exec)(void *),AnsiString HelpFile);
extern void LFMRunString(char *Str); // ���������� ������
bool LFMRunFile(AnsiString File); // ������ �� ���������� ������ �� �����
extern long Pos;
extern char *Inpt;
extern Dictionary *DictBegin;
//---------------------------------------------------------------------------
#endif
