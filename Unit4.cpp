//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner){
}
//---------------------------------------------------------------------------
void __fastcall TForm4::SpeedButton1Click(TObject *Sender){
  Form4->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ComboBox1Change(TObject *Sender)
{
  switch (ComboBox1->ItemIndex) {
    case 0:
    {
      Image2->Visible=false;
      Image3->Visible=false;
      Image4->Visible=false;
      Image5->Visible=false;
      Image6->Visible=false;
      Image7->Visible=false;
      Image8->Visible=false;
      Image9->Visible=false;
      Image10->Visible=false;
      Image1->Visible=true;
    } break;
    case 1:
    {
      Image1->Visible=false;
      Image3->Visible=false;
      Image4->Visible=false;
      Image5->Visible=false;
      Image6->Visible=false;
      Image7->Visible=false;
      Image8->Visible=false;
      Image9->Visible=false;
      Image10->Visible=false;
      Image2->Visible=true;
    }break;
    case 2:
    {
      Image2->Visible=false;
      Image1->Visible=false;
      Image4->Visible=false;
      Image5->Visible=false;
      Image6->Visible=false;
      Image7->Visible=false;
      Image8->Visible=false;
      Image9->Visible=false;
      Image10->Visible=false;
      Image3->Visible=true;
    }break;
    case 3:
    {
      Image2->Visible=false;
      Image3->Visible=false;
      Image1->Visible=false;
      Image5->Visible=false;
      Image6->Visible=false;
      Image7->Visible=false;
      Image8->Visible=false;
      Image9->Visible=false;
      Image10->Visible=false;
      Image4->Visible=true;
    }break;
    case 4:
    {
      Image2->Visible=false;
      Image3->Visible=false;
      Image4->Visible=false;
      Image1->Visible=false;
      Image6->Visible=false;
      Image7->Visible=false;
      Image8->Visible=false;
      Image9->Visible=false;
      Image10->Visible=false;
      Image5->Visible=true;
    }break;
    case 5:
    {
      Image2->Visible=false;
      Image3->Visible=false;
      Image4->Visible=false;
      Image5->Visible=false;
      Image1->Visible=false;
      Image7->Visible=false;
      Image8->Visible=false;
      Image9->Visible=false;
      Image10->Visible=false;
      Image6->Visible=true;
    }break;
    case 6:
    {
      Image2->Visible=false;
      Image3->Visible=false;
      Image4->Visible=false;
      Image5->Visible=false;
      Image6->Visible=false;
      Image1->Visible=false;
      Image8->Visible=false;
      Image9->Visible=false;
      Image10->Visible=false;
      Image7->Visible=true;
    }break;
    case 7:
    {
      Image2->Visible=false;
      Image3->Visible=false;
      Image4->Visible=false;
      Image5->Visible=false;
      Image6->Visible=false;
      Image7->Visible=false;
      Image1->Visible=false;
      Image9->Visible=false;
      Image10->Visible=false;
      Image8->Visible=true;
    }break;
    case 8:
    {
      Image2->Visible=false;
      Image3->Visible=false;
      Image4->Visible=false;
      Image5->Visible=false;
      Image6->Visible=false;
      Image7->Visible=false;
      Image8->Visible=false;
      Image1->Visible=false;
      Image10->Visible=false;
      Image9->Visible=true;
    }break;
    case 9:
    {
      Image2->Visible=false;
      Image3->Visible=false;
      Image4->Visible=false;
      Image5->Visible=false;
      Image6->Visible=false;
      Image7->Visible=false;
      Image8->Visible=false;
      Image9->Visible=false;
      Image1->Visible=false;
      Image10->Visible=true;
    }break;
  default: break;
  }

}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender){
  ComboBox1->ItemIndex=0;
}
//---------------------------------------------------------------------------

