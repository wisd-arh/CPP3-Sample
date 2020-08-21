//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TSpeedButton *SpeedButton1;
        TBevel *Bevel1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TLabel *Label1;
        TRadioButton *RadioButton5;
        TRadioButton *RadioButton6;
        TRadioButton *RadioButton7;
        TRadioButton *RadioButton8;
        TRadioButton *RadioButton9;
        TBevel *Bevel2;
        TBevel *Bevel3;
        TCheckBox *CBox1;
        TCheckBox *CBox2;
        TCheckBox *CBox3;
        TCheckBox *CBox0;
        TCheckBox *CBox4;
        TCheckBox *CBox5;
        TCheckBox *BoxInd;
        TLabel *Label3;
        TEdit *Edit1;
        TUpDown *UpDown1;
        TLabel *Label4;
        TEdit *Edit2;
        TUpDown *UpDown2;
        TSpeedButton *SpeedButton2;
        TRadioButton *RadioButton11;
        TRadioButton *RadioButton10;
        TImage *Image1;
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall RadioButton3Click(TObject *Sender);
        void __fastcall RadioButton4Click(TObject *Sender);
        void __fastcall RadioButton5Click(TObject *Sender);
        void __fastcall RadioButton6Click(TObject *Sender);
        void __fastcall RadioButton7Click(TObject *Sender);
        void __fastcall RadioButton8Click(TObject *Sender);
        void __fastcall RadioButton9Click(TObject *Sender);
        void __fastcall CBox0Click(TObject *Sender);
        void __fastcall BoxIndClick(TObject *Sender);
        void __fastcall Edit2Change(TObject *Sender);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall RadioButton10Click(TObject *Sender);
        void __fastcall RadioButton11Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
 /*       int frKind;*/
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
