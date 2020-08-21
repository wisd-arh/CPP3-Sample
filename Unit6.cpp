//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit6.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TDlg1 *Dlg1;
static AnsiString ws;
//---------------------------------------------------------------------
__fastcall TDlg1::TDlg1(TComponent* AOwner)
	: TForm(AOwner){
}
//---------------------------------------------------------------------
void __fastcall TDlg1::Button1Click(TObject *Sender){
  ws=DirectoryListBox1->Directory;
}
//---------------------------------------------------------------------------
void __fastcall TDlg1::FormCreate(TObject *Sender){
  try {
  DirectoryListBox1->Directory=(AnsiString)ws;
  }
  catch (...)
  { }
}
//---------------------------------------------------------------------------
