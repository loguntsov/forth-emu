//---------------------------------------------------------------------------
#ifndef frmForthWordViewH
#define frmForthWordViewH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmWordView : public TForm
{
__published:	// IDE-managed Components
    TListBox *ListBox;
    TLabel *Label1;void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Label1Click(TObject *Sender);
    
    void __fastcall ListBoxDblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmWordView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmWordView *frmWordView;
//---------------------------------------------------------------------------
#endif
