//---------------------------------------------------------------------------
#ifndef LForthMachineH
#define LForthMachineH

#include "Dictionary.h"
#include "Stack.h"
#include "ForthDataType.h"

// Константы режима компиляции
const bool Compilat=false;
const bool Immediat=true;
//inline EWord *LnkLnk(void *x) { return ((EWord*) x)->Link; }
extern Stack *Stk;
extern unsigned int LFMBase;
extern bool StateLFM;
extern void LFMInit(int SizeStack); // Расзмер стека данных для машины
extern void LFMDelete(); // Для прекращения работы с ьашиной
extern void LFMRunWord(AnsiString Word); // Выполнение одного слова
extern Dictionary * LFMAddWord(char * Name,void (*Exec)(void *),AnsiString HelpFile);
extern void LFMRunString(char *Str); // Выполнение текста
bool LFMRunFile(AnsiString File); // Запуск на выполнение текста из файла
extern long Pos;
extern char *Inpt;
extern Dictionary *DictBegin;
//---------------------------------------------------------------------------
#endif
