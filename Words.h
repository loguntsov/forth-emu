#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------
#ifndef WordsH
#define WordsH


class EWord
// ������������ ������� ������ �����������
{
private:
bool AutoDelet;// ������� ��������������� �������� DATA
public:
void *Data;
EWord *Link;
EWord();
EWord(bool Delet);
~EWord();
};

// ������ �������� ������ ����� � �������
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
