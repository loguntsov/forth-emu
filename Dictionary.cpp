//---------------------------------------------------------------------------
//#include <vcl.h>

#include <stddef.h>
#include "Dictionary.h"
#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)
Dictionary::Dictionary(Words *Word)
{
WordS=Word;
Link=NULL;
}
Dictionary::Dictionary(AnsiString Name,int exec)
{
Words *a=new Words(Name,exec);
WordS=a;
Link=NULL;
}
Dictionary::Dictionary(char *Name,int exec)
{
Words *a=new Words(AnsiString(Name),exec);
WordS=a;
Link=NULL;
}
Dictionary::~Dictionary()
{
delete Link;
delete WordS;
}
Dictionary * Dictionary::Add(Dictionary *Dict)
{
Link=Dict;
return Link;
}
Words * Dictionary::Find(AnsiString Wrd)
{
if (WordS->Name==Wrd) return WordS; else
            { if (Link!=NULL) return Link->Find(Wrd);
                                else return NULL;
            } ;
}
static int ExecuteFile(const AnsiString FileName,
                           const AnsiString Params,
                           const AnsiString DefaultDir,
                           int ShowCmd)
{

  char zFileName[255], zParams[255], zDir[255];
  return (int) ShellExecute(Application->MainForm->Handle,
                            NULL,
                            strcpy(zFileName,
                                   FileName.c_str()),
                            strcpy(zParams,
                                   Params.c_str()),
                            strcpy(zDir,
                                   DefaultDir.c_str()),
                            ShowCmd);
}
void Dictionary::ShowHelp()
{
if (HelpFile!="") {
    AnsiString a=GetCurrentDir()+"\\Help\\"+HelpFile;
    Form1->OpenURL(a);
    }
}
Dictionary * Dictionary::FindDictionary(AnsiString Wrd)
{
if (WordS->Name==Wrd) return this; else {
                if (Link!=NULL) return Link->FindDictionary(Wrd); else
                return NULL ; }
}
