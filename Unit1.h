//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include "SHDocVw_OCX.h"
#include <OleCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *mnuFile;
    TGroupBox *GroupBox1;
    TGroupBox *GroupBox2;
    TSplitter *Splitter1;
    TStatusBar *StatusBar1;
    TSplitter *Splitter2;
    TMenuItem *mnuDebug;
    TMenuItem *mnuQuestion;
    TMenuItem *ShowStack;
    TMenuItem *mnuExit;
    TMenuItem *mnuWords;
    TMenuItem *mnuOpen;
    TMenuItem *mnuSave;
    TMenuItem *N1;
    TOpenDialog *OpenDialog1;
    TSaveDialog *SaveDialog1;
    TRichEdit *Memo1;
    TToolBar *ToolBar1;
    TSpeedButton *SBOpen;
    TSpeedButton *SpeedButton1;
    TToolButton *ToolButton1;
    TSpeedButton *SpeedButton2;
    TSpeedButton *SpeedButton3;
    TToolButton *ToolButton2;
    TSpeedButton *SpeedButton4;
    TMenuItem *mnuStart;
    TMenuItem *mnuRun;
    TSpeedButton *SpeedButton5;
    TCppWebBrowser *Web;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall ShowStackClick(TObject *Sender);
    void __fastcall mnuWordsClick(TObject *Sender);
    void __fastcall mnuExitClick(TObject *Sender);
    void __fastcall mnuOpenClick(TObject *Sender);
    void __fastcall mnuSaveClick(TObject *Sender);
    void __fastcall SpeedButton5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    void OpenURL(AnsiString URL);    
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
