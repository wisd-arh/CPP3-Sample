//----------------------------------------------------------------------------
#ifndef Unit6H
#define Unit6H
//----------------------------------------------------------------------------
#include <vcl\System.hpp>
#include <vcl\Windows.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <FileCtrl.hpp>
//----------------------------------------------------------------------------
class TDlg1 : public TForm
{
__published:
	TBevel *Bevel1;
        TDirectoryListBox *DirectoryListBox1;
        TButton *Button1;
        TButton *Button2;
        TLabel *Label1;
        TDriveComboBox *DriveComboBox1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:
public:
	virtual __fastcall TDlg1(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TDlg1 *Dlg1;
//----------------------------------------------------------------------------
#endif
