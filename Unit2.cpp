#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
static int frKind;
static int mx;
static bool ind, er;
static float obl;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner){
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton1Click(TObject *Sender){
  Form2->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton1Click(TObject *Sender){
  frKind=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton2Click(TObject *Sender){
 // frKind=2;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton3Click(TObject *Sender){
  frKind=3;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton4Click(TObject *Sender){
  frKind=4;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton5Click(TObject *Sender){
  frKind=5;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton6Click(TObject *Sender){
  frKind=6;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton7Click(TObject *Sender){
  frKind=7;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton8Click(TObject *Sender){
  frKind=8;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton9Click(TObject *Sender){
  frKind=9;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::CBox0Click(TObject *Sender){
   if (CBox0->Checked==true) {
     CBox1->Visible=true;
     CBox2->Visible=true;
     CBox3->Visible=true;
     CBox4->Visible=true;
     CBox5->Visible=true;
     Image1->Visible=true;
   } else {
     CBox1->Visible=false;
     CBox2->Visible=false;
     CBox3->Visible=false;
     CBox4->Visible=false;
     CBox5->Visible=false;
     CBox1->Checked=false;
     CBox2->Checked=false;
     CBox3->Checked=false;
     CBox4->Checked=false;
     CBox5->Checked=false;
     Image1->Visible=false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BoxIndClick(TObject *Sender) {
  ind=BoxInd->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit2Change(TObject *Sender){
   obl=StrToFloat(Edit2->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1Change(TObject *Sender){
  try {
  mx=StrToInt(Edit1->Text)*10;
  }
  catch (...)
  { mx=10; }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender){
  switch (frKind) {
    case 1: Form2->RadioButton1->Checked=true; break;
    case 2: Form2->RadioButton10->Checked=true; break;
    case 3: Form2->RadioButton3->Checked=true; break;
    case 4: Form2->RadioButton4->Checked=true; break;
    case 5: Form2->RadioButton5->Checked=true; break;
    case 6: Form2->RadioButton6->Checked=true; break;
    case 7: Form2->RadioButton7->Checked=true; break;
    case 8: Form2->RadioButton8->Checked=true; break;
    case 9: Form2->RadioButton9->Checked=true; break;
    case 10: Form2->RadioButton11->Checked=true; break;
  }
  UpDown1->Position=short(mx/10);
  UpDown2->Position=short(obl);
  BoxInd->Checked=ind;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton2Click(TObject *Sender){
  er=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton10Click(TObject *Sender){
  frKind=2;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton11Click(TObject *Sender) {
   frKind=10;
}
//---------------------------------------------------------------------------
 
