//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Language.res");
USEUNIT("Dictionary.cpp");
USEUNIT("ForthDataType.cpp");
USEFORM("frmForthWordView.cpp", frmWordView);
USEUNIT("Language.cpp");
USEUNIT("LForthMachine.cpp");
USEUNIT("Memory.cpp");
USEUNIT("Stack.cpp");
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit2.cpp", Form2);
USEUNIT("Words.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->Title = "Forth System";
        Application->CreateForm(__classid(TForm1), &Form1);
        Application->CreateForm(__classid(TfrmWordView), &frmWordView);
        Application->CreateForm(__classid(TForm2), &Form2);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
