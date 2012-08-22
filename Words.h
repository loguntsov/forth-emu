#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------
#ifndef WordsH
#define WordsH


class EWord
// Элементарная частица памяти транслятора
{
private:
bool AutoDelet;// Признак автоматического удаления DATA
public:
void *Data;
EWord *Link;
EWord();
EWord(bool Delet);
~EWord();
};

// Начало описания любого слова в словаре
class Words
{
public:
AnsiString Name;
void *Link;
int Execute;
bool Immediate;
public:
Words(AnsiString NameS,int Execute);
~Words();
};
//---------------------------------------------------------------------------
#endif
