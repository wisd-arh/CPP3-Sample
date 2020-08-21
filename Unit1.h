//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include "Unit5.cpp"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TEdit *Edit1;
        TBevel *Bevel1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TProgressBar *PrBar1;
        TImage *Image1;
        TTimer *Timer1;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton11;
        TLabel *Label1;
        TSpeedButton *SpeedButton12;
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall SpeedButton5Click(TObject *Sender);
        void __fastcall SpeedButton6Click(TObject *Sender);
        void __fastcall SpeedButton7Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall SpeedButton8Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall SpeedButton9Click(TObject *Sender);
        void __fastcall SpeedButton10Click(TObject *Sender);
        void __fastcall SpeedButton11Click(TObject *Sender);
        void __fastcall Image1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall SpeedButton12Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        TMemoryStream *st;
        __fastcall TForm1(TComponent* Owner);
        void __fastcall aMin(TObject *Sender);
        void __fastcall aRes(TObject *Sender);
        double FCRandom();
};
        void __fastcall NextValueZfrKind0 (complex& Zi, const complex& C);
        void __fastcall NextValueZfrKind1 (complex& Zi, const complex& C);
        void __fastcall NextValueZfrKind2 (complex& Zi, const complex& C);
        void __fastcall NextValueZfrKind3 (complex& Zi, const complex& C);
        void __fastcall NextValueZfrKind4 (complex& Zi, const complex& C);
        void __fastcall NextValueZfrKind5 (complex& Zi, const complex& C);
        void __fastcall NextValueZfrKind6 (complex& Zi, const complex& C);
        void __fastcall NextValueZfrKind9();
        void __fastcall NextValueZfrKind10();
        unsigned char __fastcall GetR(float A);
        unsigned char __fastcall GetG(float A);
        unsigned char __fastcall GetB(float A);
        void __fastcall Precache(complex& Zi);
        void __fastcall casefrKind();
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
char sign(float V) {
  if (V<0) return -1; else return 1; }

class ThPtk : public TThread
{
private:
protected:
        void __fastcall Execute();
public:
        __fastcall ThPtk();
        void ThPtk::GetBtmap();
};

#endif
