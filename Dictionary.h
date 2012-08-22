//---------------------------------------------------------------------------
#ifndef DictionaryH
#define DictionaryH

#include "Words.h"

//---------------------------------------------------------------------------

class Dictionary
{
private:

public:
Words *WordS;
Dictionary *Link;
AnsiString HelpFile;
public:
Words * Find(AnsiString Word);
Dictionary * FindDictionary(AnsiString Wrd);
Dictionary(Words *Word);
Dictionary(AnsiString Name,int a);
Dictionary(char *Name,int a);
Dictionary * Add(Dictionary *Dict);
void ShowHelp(void);
~Dictionary();
};
#endif
