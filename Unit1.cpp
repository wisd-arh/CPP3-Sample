#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit3.h"
//#include "Unit5.h"
#include "Unit6.cpp"
#include "Unit2.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <stdio.h>
#include <stdlib.h>
//#include <alloc.h>
#include <io.h>
#include <sys\timeb.h >;
//#include <filectrl.hpp>
//#include <sysutils.hpp>
#include <registry.hpp>

#include <string.h>
#include <fcntl.h>
#include <sys\stat.h>


//---------------------------------------------------------------------------
#include <filectrl.hpp>
TForm1 *Form1;
__int16 PicHeight=1024, size;
static complex C, prC, Z;//={ -0.63773, -0.39308 };
void (__fastcall *func)(complex& Zi, const complex& C);
static float epsilon=2.0;
unsigned __int8 ColorBuf[786432][3];
bool chec;
static bool saving=false, gohome=false;
long g;
float d;
complex Zi;
__int32 i, j, k, _j, _k;
static float sq, _sq;
//__int32 sbgr[64000];
static unsigned __int8 zag320[54]={0x42,0x4D,0x36,0xEE,0x02,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x28,0x00,0x00,0x00,0x40,0x01,0x00,0x00,0xC8,0x00,0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0x02,0x00,0xC4,0x0E,0x00,0x00,0xC4,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
static unsigned __int8 zag1024[54]={0x42,0x4D,0x36,0x00,0x24,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x28,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x03,0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x24,0x00,0xA4,0x0E,0x00,0x00,0xA4,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
static unsigned __int8 zag640[54]={0x42,0x4D,0x36,0x10,0x0E,0x0,0,0,0,0,0x36,0,0,0,0x28,0,0,0,0x80,2,0,0,0xE0,1,0,0,1,0,0x18,0,0,0,0,0,0,0,0,0,0xC4,0x0E,0,0,0xC4,0x0E,0,0,0,0,0,0,0,0,0,0};
static unsigned __int8 zag800[54]={0x42,0x4D,0x36,0xE9,0x15,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x28,0x00,0x00,0x00,0x20,0x03,0x00,0x00,0x58,0x02,0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0xE9,0x15,0x00,0x84,0x0E,0x00,0x00,0x84,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
complex  temp, temp2, temp3, temp4;
//FILE *tfile;
///unsigned __int8 pbuf[64000][3];
timeb time1, time2, time3;
//float bn, r;
static unsigned int nom=0;
ThPtk *Ptk;
AnsiString s;
__int8 l=1, prl=1;
TRegistry *Reg;
char* p1 = "Software\\FCreater";
char* p2 = "Software\\FCreater\\v0.3";
int x1, y1, x2, y2;
float mx1=0, my1=0, mx2=0, my2=0, dmx, dmy;
float step;
bool iz=false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner){
  st=new  TMemoryStream();
  Application->OnMinimize=aMin;
  Application->OnRestore=aRes;
  Reg = new TRegistry();
  Reg->RootKey=HKEY_LOCAL_MACHINE;
  if (!Reg->OpenKey((AnsiString)p1, false)) {
    try {
      Reg->CreateKey((AnsiString)p1);
      Reg->CreateKey((AnsiString)p2);
      Reg->OpenKey((AnsiString)p2, false);
      Reg->WriteInteger("0", 90);  //left
      Reg->WriteInteger("1", 106); //top
      Reg->WriteInteger("2", 2);   //size  0,1, 2
      Reg->WriteInteger("3", 1);   //frKind
      Reg->WriteInteger("4", 10);  //mx/10;
      Reg->WriteInteger("5", 1);   //(float)obl;
      Reg->WriteInteger("6", 0);   //ind
      Reg->WriteString("7", (AnsiString)"c:\\windows\\рабочий стол");   //ind
      ShowMessage("Вас одолело непреодолимое желание нажать две кнопочки. Сначала ОK, затем Help."); 
    }
    catch (Exception &exception) {
      Application->ShowException(&exception);
    }
  }
  Reg->CloseKey();
  Reg->OpenKey((AnsiString)p2, false);
  Form1->Left=Reg->ReadInteger("0");  //left
  Form1->Top=Reg->ReadInteger("1"); //top
  switch (Reg->ReadInteger("2")) {
    case 0: PicHeight=640; SpeedButton5->Down=true; break;
    case 1: PicHeight=800; SpeedButton6->Down=true; break;
    case 2: PicHeight=1024; SpeedButton7->Down=true; break;
  }
  frKind=Reg->ReadInteger("3");
  mx=Reg->ReadInteger("4")*10;
  obl=(float)Reg->ReadInteger("5");
  ind=(bool)Reg->ReadInteger("6");
  ws=Reg->ReadString("7").c_str();
  Edit1->Text=ws+(AnsiString)"\\fr0";
  Reg->CloseKey();
  Ptk = new ThPtk();
  Ptk->Suspended=true;
  Ptk->FreeOnTerminate=true;
  Ptk->Priority=tpNormal;
  step=0.0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton3Click(TObject *Sender) {
  if (Ptk->Suspended==true) {
    iz=false;
    nom++;
    prC.re=C.re;
    prC.im=C.im;
    prl=l;
    C.re=FCRandom();//(random(200000)-100000)/100000.0;
    C.im=FCRandom();//(random(200000)-100000)/100000.0;
    l=(__int8)random(6);
    size=320;
    st->SetSize(192054);
    st->Position=0;
    st->Write(zag320, 54);
    mx1=mx2=my1=my2=0;
    step=0;
    Ptk->Suspended=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender) {
  if (Ptk->Suspended==true) {
    nom++;
    if (Edit1->Focused()) { Edit1->Enabled=false; Edit1->Enabled=true; }
    s=Edit1->Text+IntToStr(nom)+(AnsiString)".bmp";
    if (!access(s.c_str(), 0))
    { ShowMessage(AnsiString("File already exist ") + s + ".");
      return; }
    switch (PicHeight) {
      case 640: st->SetSize(921654); st->Position=0; st->Write(zag640, 54); break;
      case 800: st->SetSize(1440054); st->Position=0; st->Write(zag800, 54); break;
      case 1024: st->SetSize(2359350); st->Position=0; st->Write(zag1024, 54); break;
    }
    size=PicHeight; // Убрать одну из них
    saving=true;
    Ptk->Suspended=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender) {
  if (Ptk->Suspended) Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton4Click(TObject *Sender) {
  if (Ptk->Suspended) {
    Form2->Left=Form1->Left+Form1->Width+7;
    Form2->Top=Form1->Top;
    Form2->Visible=true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton5Click(TObject *Sender) {
  PicHeight=640;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton6Click(TObject *Sender) {
  PicHeight=800;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton7Click(TObject *Sender) {
  PicHeight=1024;
}
//---------------------------------------------------------------------------
void __fastcall NextValueZfrKind0 (complex&  Zi, const complex& C) {
  Zsqr(Zi);
  sum(Zi,C);
}
//---------------------------------------------------------------------------
void __fastcall NextValueZfrKind1 (complex& Zi, const complex& C) {
  temp=Zi;
  Zsqr(Zi);
  mul(Zi, temp);
  sum(Zi, C);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
  randomize();
  for (int i=0; i<random(1000); i++) {}
//  ShowMessage("Random init");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton8Click(TObject *Sender) {
  Form3->Left=Form1->Left+Form1->Width+7;
  Form3->Top=Form1->Top;
  Form3->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall NextValueZfrKind2 (complex& Zi, const complex& C) {
  temp=Zi;
  Zsqr(Zi);
  Zsqr(Zi);
  mul(Zi, temp);
  sum(Zi, C);
}
//---------------------------------------------------------------------------
void __fastcall NextValueZfrKind3 (complex& Zi, const complex& C) {
  temp=Zsqr1(Zi);
  temp2=Zsqr1(temp);
  temp3=Zsqr1(temp2);
  Zi=Zsqr1(temp3);
  sum(Zi, temp3);
  sum(Zi, temp2);
  sum(Zi, temp);
  sum(Zi, C);
}
//---------------------------------------------------------------------------
void __fastcall NextValueZfrKind4 (complex& Zi, const complex& C) {
  temp=Zsqr1(Zi);
  temp2=Zsqr1(temp);
  temp3=Zsqr1(temp2);
  temp4=Zsqr1(temp3);
  Zi=Zsqr1(temp4);
  sum(Zi, temp4);
  sum(Zi, temp3);
  sum(Zi, temp2);
  sum(Zi, temp);
  sum(Zi, C);
}
//---------------------------------------------------------------------------
void __fastcall NextValueZfrKind5 (complex& Zi, const complex& C) {
  float n;
  n=0.5/(norm(Zi)+0.01);
  Zi.re*=n;
  Zi.im*=n;
  Zsqr(Zi);
  sum(Zi, C);
}
//---------------------------------------------------------------------------
void __fastcall NextValueZfrKind6 (complex& Zi, const complex& C) {
  Zi=C/(Zsqr1(Zi)+0.00001)+C;
}
//---------------------------------------------------------------------------
unsigned char __fastcall GetR(float A) {
  if ((A>1.41)||(A<-1.41)) return 0; else
  if (A>0) return A*180.85; else return -A*180.85;
}
//---------------------------------------------------------------------------
unsigned char __fastcall GetG(float A) {
  if ((A>1.41)||(A<-1.41)) return 0; else
  if (A>0) return A*180.85; else return -A*180.85;
}
//---------------------------------------------------------------------------
unsigned char __fastcall GetB(float A) {
  if ((A>2)||(A<-2)) return 0; else
  if (A>0) return A*127.5; else return -A*127.5;
}
//---------------------------------------------------------------------------
void __fastcall NextValueZfrKind9() {
long double t1;
__int32 q1, q2, q3;
complex f;
float t11, t2;
  switch (size) {
    case 320: _j=320/2, _k=200/2; break;
    case 640: _j=640/2, _k=480/2; break;
    case 800: _j=800/2, _k=600/2; break;
    case 1024: _j=1024/2, _k=768/2; break;
  }
  t11=obl/_k;
  t2=obl/_j;
  g=0;
  if (saving||ind) {
    Form1->PrBar1->Position=0;
    Form1->PrBar1->Visible=true;
    Form1->PrBar1->Max=2*_k;
    ftime(&time1);
  }
  chec=Form2->CBox0->Checked;
  for (k=-_k; k<_k; k++) {
    for (j=-_j; j<_j; j++) {
       Zi.im=k*t11;
       Zi.re=j*t2;
       for (i=0; i< mx; i++) {
        if (chec) Precache(Zi);
        f=Zsqr1(Zi);
        Zi=(Zi*3)/5.85+C/(f*Zi*l+0.0001);
        t1=norm(Zsqr1(f)-1)+0.001;
      if (t1<=0.001) {
        Zi.re=0; Zi.im=0;
        t1=0;
        break;
      }
    }
    q1=(__int16)fmod(fabs(256*Zi.re), 0x100);
    q2=(__int16)fmod(fabs(256*Zi.im), 0x100);
    q3=(__int16)fmod(2560*t1, 0x100);
    ColorBuf[g][0]=(unsigned __int8)q1;
    ColorBuf[g][1]=(unsigned __int8)q2;
    ColorBuf[g][2]=(unsigned __int8)q3;
    g++;
    }
    if (saving||ind) {
      ftime(&time2);
      d=((time2.millitm-time1.millitm)+(time2.time-time1.time)*1000)/(1+k+_k);
      d=d*(_k-k);
      if (d<60000)  Form1->Label1->Caption="Est. time " + IntToStr(int(d/1000.0)+1)+ " sec.";
      else Form1->Label1->Caption="Est. time " + IntToStr(((int(d/1000.0))/60)+1)+ " min.";
      Form1->PrBar1->StepBy(1);
    }
  }
  if (saving||ind) { Form1->PrBar1->Visible=false;
    Form1->Label1->Caption="";
  }
}
//----------------------------------------------------------------------------
void __fastcall Precache(complex& Zi) {
    if (Form2->CBox5->Checked==true)
      { float a, b; a=Zi.re; b=Zi.im;
        Zi.re=a-a*sin(a)*cos(a); Zi.im=b-b*sin(b)*cos(b); }
    if (Form2->CBox4->Checked==true)
      { Zi.re=Zi.re*sqrt(fabs(Zi.re)); Zi.im=Zi.im*sqrt(fabs(Zi.im)); }
    if (Form2->CBox3->Checked==true)
      { Zi.re=pow(Zi.re,3); Zi.im=pow(Zi.im,3); }
    if (Form2->CBox2->Checked==true)
      if (frKind<6){Zi.re=log(1.75+Zi.re); Zi.im=log(1.75+Zi.im); }
      else {Zi.re=log(0.00005 +sign(Zi.re)*Zi.re); Zi.im=log(0.00005+sign(Zi.im)*Zi.im); }
    if (Form2->CBox1->Checked==true)
      { Zi=Zexp(Zi)-1.35; }
  return;
}
//---------------------------------------------------------------------------------
void __fastcall casefrKind() {
  switch (frKind) {
    case 1: func=NextValueZfrKind0; break;
    case 2: func=NextValueZfrKind1; break;
    case 3: func=NextValueZfrKind2; break;
    case 4: func=NextValueZfrKind3; break;
    case 5: func=NextValueZfrKind4; break;
    case 6: epsilon=0xFFFFFFFF; func=NextValueZfrKind5; break;
    case 7: epsilon=0xFFFFFFFF; func=NextValueZfrKind6; break;
    case 8: func=NextValueZfrKind0; break;
   default: exit;
  }
  return;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action) {
  if (!er) {
  if (Reg->OpenKey((AnsiString)p2, false)) {
    Reg->WriteInteger("0", Form1->Left);  //left
    Reg->WriteInteger("1", Form1->Top); //top
    switch (PicHeight) {
      case 640: Reg->WriteInteger("2", 0); break;
      case 800: Reg->WriteInteger("2", 1); break;
      case 1024: Reg->WriteInteger("2", 2); break;
    }
    Reg->WriteInteger("3", frKind);   //frKind
    Reg->WriteInteger("4", mx/10);  //mx/10;
    Reg->WriteInteger("5", (int)obl);   //(float)obl;
    Reg->WriteInteger("6", (int)ind);   //ind
    Reg->WriteString("7", (AnsiString)ws);
    Reg->CloseKey();
  }
  } else {
    Reg->DeleteKey((AnsiString)p2);
    Reg->DeleteKey((AnsiString)p1);
    Reg->CloseKey();
  }
  delete Reg;
  delete st;
  if (nom>0) { gohome=true;
               Ptk->Suspended=false; }
   else { Ptk->Terminate(); }//delete Ptk; }
}
//---------------------------------------------------------------------------
void ThPtk::GetBtmap() {
__int32 g=0;
float t1, t2;
  switch (size) {
    case 320: _j=320/2, _k=200/2; g=64000; break;
    case 640: _j=640/2, _k=480/2; g=307200; break;
    case 800: _j=800/2, _k=600/2; g=480000; break;
    case 1024: _j=1024/2, _k=768/2; g=786432; break;
  }
  t2=obl/_j;
  t1=obl/_k;
  casefrKind();
  sq=sqrt(epsilon); _sq=-sq;
  chec=Form2->CBox0->Checked;
  if (saving||ind) {
    Form1->PrBar1->Position=0;
    Form1->PrBar1->Visible=true;
    Form1->PrBar1->Max=2*_k;
    ftime(&time1);
  }
//  dmx=mx2-mx1;
//  dmy=my2-my1;

  if ((my2!=0)||(mx2!=0)||(my1!=0)||(mx1!=0))
    step+=1;
  if ((mx1==0)&&(my1==0)&&((mx2!=0)||(my2!=0))&&(saving)) {
     mx1=mx2; my1=my2;
  }
  for (k=-_k; k<_k; k++) {
    for (j=-_j; j<_j; j++) {
       if ((my1!=0)||(mx1!=0)) {
//             Z.re=mx2-((j+_j)*dmx)/(2*_j);
//             Z.im=my2-((k+_k)*dmy)/(2*_k);
//           Z.re=mx1+((j+_j)*dmx)/(2*_j);
//           Z.im=my1+((k+_k)*dmy)/(2*_k);
             Z.re=((mx1-0.5/step)+((float)(j+_j)/(float)(2.0*_j))/step);
             Z.im=((my1-0.5/step)+((float)(k+_k)/(float)(2.0*_k))/step);
       }
       else {
         Z.re=j*t2;
         Z.im=k*t1;
       }
       if (frKind==8) Z=Zabs(Z);
       for (i=0; i< mx; i++) {
          if (chec) Precache(Z);
          func(Z, C);
          if ((Z.re>=sq)||(Z.im>=sq)||(Z.re<=_sq)||(Z.im<=_sq)) break;
       }
       if (i==mx) {
          ColorBuf[g][0]=GetB(norm(Z));
          ColorBuf[g][1]=GetG(Z.im);
          ColorBuf[g][2]=GetR(Z.re);
          iz=true;
       } else {
          ColorBuf[g][0]=0;
          ColorBuf[g][1]=0;
          ColorBuf[g][2]=0;
       }
       g--;
    }
    if (saving||ind) {
      ftime(&time2);
      d=((time2.millitm-time1.millitm)+(time2.time-time1.time)*1000)/(1+k+_k);
      d=d*(_k-k);
      if (d<60000)  Form1->Label1->Caption="Est. time " + IntToStr(int(d/1000.0)+1)+ " sec.";
      else Form1->Label1->Caption="Est. time " + IntToStr(((int(d/1000.0))/60)+1)+ " min.";
      Form1->PrBar1->StepBy(1);
    }
  }
  if (saving||ind) { Form1->PrBar1->Visible=false;
    Form1->Label1->Caption="";
  }
}
//---------------------------------------------------------------------------
__fastcall ThPtk::ThPtk()
        : TThread(true) {
}
//---------------------------------------------------------------------------
void __fastcall ThPtk::Execute() {
  do {
    if (!saving) Form1->SpeedButton3->Enabled=false;
      else Form1->SpeedButton1->Enabled=false;
    if (frKind<9)
      while (!iz) {
        GetBtmap();
        if (!iz) {
          if (step) break; else {
            C.re=Form1->FCRandom();//(random(200000)-100000)/100000.0;
            C.im=Form1->FCRandom();//(random(200000)-100000)/100000.0;
          }
        }
      }
    else if (frKind==9) NextValueZfrKind9();
    else if (frKind==10) NextValueZfrKind10();
    switch (size) {
      case 320: Form1->st->Write(ColorBuf, 192000); break;
      case 640: Form1->st->Write(ColorBuf, 921600); break;
      case 800: Form1->st->Write(ColorBuf, 1440000); break;
      case 1024: Form1->st->Write(ColorBuf, 2359296); break;
    }
    iz=false;
    Form1->st->Position=0;
    if (saving) { Form1->st->SaveToFile(s); saving=false;
                  Form1->SpeedButton1->Enabled=true; }
          else  { Form1->Image1->Picture->Bitmap->LoadFromStream(Form1->st);
                  Form1->SpeedButton3->Enabled=true; }
    mx2=mx1;
    my2=my1;
    mx1=my1=0.0;
    Suspended=true;
    if (gohome) Terminate();
  } while (!Terminated);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender) {
  Application->Title=(AnsiString)(FloatToStrF(((float)k/_k+1)*50, ffFixed, 3, 1)+ " %");
  if (!Timer1->Enabled)
    Application->Title=(AnsiString)"Fractal creater";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::aMin(TObject *Sender) {
  if (!Ptk->Suspended) Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::aRes(TObject *Sender) {
  Timer1->Enabled=false;
  while (Timer1->Enabled) {};
  Application->Title=(AnsiString)"Fractal creater";
  Form1->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose) {
  if (!Ptk->Suspended) CanClose=false;
  else CanClose=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton9Click(TObject *Sender){
  Dlg1->ShowModal();
  if (Dlg1->ModalResult == mrOk)
    Edit1->Text=Dlg1->DirectoryListBox1->Directory +(AnsiString)"\\fr0";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton11Click(TObject *Sender) {
  if (Ptk->Suspended==true) {
    nom++;
    size=320;
    if (Sender!=NULL) { step=0; mx1=mx2=my1=my2=0; }
    st->SetSize(192054);
    st->Position=0;
    st->Write(zag320, 54);
    Ptk->Suspended=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton10Click(TObject *Sender) {
float t;
  if (Ptk->Suspended==true) {
    t=C.re;
    C.re=prC.re;
    prC.re=t;
    t=C.im;
    C.im=prC.im;
    prC.im=t;
    nom++;
    size=320;
    st->SetSize(192054);
    st->Position=0;
    st->Write(zag320, 54);
    Ptk->Suspended=false;
  }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall NextValueZfrKind10() {
double t1, t2;
double r, ii, q, _q, zr, zi, _r, _i;
complex V;
  switch (size) {
    case 320: _j=320/2, _k=200/2; break;
    case 640: _j=640/2, _k=480/2; break;
    case 800: _j=800/2, _k=600/2; break;
    case 1024: _j=1024/2, _k=768/2; break;
  }
  t1=obl/_k;
  t2=obl/_j;
  g=0;
  if (saving||ind) {
    Form1->PrBar1->Position=0;
    Form1->PrBar1->Visible=true;
    Form1->PrBar1->Max=2*_k;
    ftime(&time1);
  }
  chec=Form2->CBox0->Checked;
  q=mx*sqrt(epsilon); _q=-mx*sqrt(epsilon);
  for (k=-_k; k<_k; k++) {
    for (j=-_j; j<_j; j++) {
       r=0; ii=0;
       zi=k*t1;
       zr=j*t2-0.5;
       for (i=0; i< mx; i++) {
          if (chec) {
            V.re=r; V.im=ii;
            Precache(V);
            r=V.re; ii=V.im;
          }
          _r=r;
          _i=ii;
          r=_r*_r-_i*_i;
          ii=2*_r*_i;
          r+=zr;
          ii+=zi;
          if ((r>=q)||(ii>=q)||(r<=_q)||(ii<=_q)) break;
       }
       if (i!=mx) {
          ColorBuf[g][0]=(unsigned __int8)(255-abs(128*k/_k));//GetB(norm(C)*10);
          ColorBuf[g][1]=(unsigned __int8)(155-abs(128*k/_k));//GetG(C.im);
          ColorBuf[g][2]=(unsigned __int8)(255-abs(128*k/_k));//GetR(C.re);
       } else {
          ColorBuf[g][1]=0;
          ColorBuf[g][0]=GetG(ii);
          ColorBuf[g][2]=GetR(r);
       }
    g++;
    }
    if (saving||ind) {
      ftime(&time2);
      d=((time2.millitm-time1.millitm)+(time2.time-time1.time)*1000)/(1+k+_k);
      d=d*(_k-k);
      if (d<60000)  Form1->Label1->Caption="Est. time " + IntToStr(int(d/1000.0)+1)+ " sec.";
      else Form1->Label1->Caption="Est. time " + IntToStr(((int(d/1000.0))/60)+1)+ " min.";
      Form1->PrBar1->StepBy(1);
    }
  }
  if (saving||ind) { Form1->PrBar1->Visible=false;
    Form1->Label1->Caption="";
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   x1=X, y1=Y;
  if ((!mx2)&&(!my2)) {
  mx1=(2.0/Image1->Width)*x1-1;
  my1=(2.0/Image1->Height)*y1-1;
  Image1->Canvas->Pixels[x1][y1]=clRed;
  } else {
    mx1=mx2-0.5+((float)x1)/Image1->Width;
    my1=my2-0.5+((float)y1)/Image1->Height;
    Image1->Canvas->Pen->Color=clWhite;
    Image1->Canvas->Brush->Style=bsClear;
    Image1->Canvas->Rectangle(x1-10, y1-10, x1+10, y1+10);
  }
  SpeedButton11Click(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
/*  int h;
  x2=X, y2=Y;
  if (x2<x1) { h=x2; x2=x1; x1=h; }
  if (y2<y1) { h=y2; y2=y1; y1=h; }
  mx1=(2.0/Image1->Width)*x1-1;
  mx2=(2.0/Image1->Width)*x2-1;
  my1=(2.0/Image1->Height)*y1-1;
  my2=(2.0/Image1->Height)*y2-1;
  Image1->Canvas->Pen->Color=clWhite;
  Image1->Canvas->Brush->Style=bsClear;
  Image1->Canvas->Rectangle(x1, y1, x2, y2);*/
}
//---------------------------------------------------------------------------
double TForm1::FCRandom() {
//  return (random(200000)-100000.0)/100000.0;
//  return (random(2000000000)-1000000000.0)/1000000000.0;
  return (random(2000000000)-1000000000.0)*1E-09;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton12Click(TObject *Sender)
{
  double s=0, prev, tek, hsr=0;
  double sr=0;
  double d=0, max=0, min=0;
  const int N=100000;
  AnsiString as1;
  FILE *f1;

  tek=FCRandom();

//  randomize();
//  h1=open("rnddata.txt", O_CREAT|O_RDWR|O_TEXT, S_IREAD | S_IWRITE);//|O_BINARY);
//  if (h1==-1) ShowMessage("Unable create file");
  f1=fopen("rnddata.txt", "w");
  if (f1==NULL) ShowMessage("Unable create file");
  for (int i=0; i<N; i++) {
    prev=tek;
    tek=FCRandom();
    if (tek>max) max=tek;
    if (tek<min) min=tek;
    s+=tek;
    sr+=(prev-tek)*(prev-tek);
    d+=fabs((prev-tek));
    hsr+=prev*prev-tek*tek;

    as1=FloatToStr(tek);
    as1.SetLength(as1.Length()-1);
//    if (h1!=-1) { write(h1, arr, StrLen(arr)); write (h1, &br, 1); }
    if (f1!=NULL) fprintf(f1, "%s\n", as1.c_str());
  }
  s/=N;
  sr/=N;
  d/=N;
  ShowMessage("s= " + FloatToStr(s));
  hsr/=sqrt(N);
  ShowMessage("Hsr= " + FloatToStr(hsr));
  ShowMessage("sr= " + FloatToStr(sr));
  ShowMessage("d= " + FloatToStr(d));
//  ShowMessage("Max= " + FloatToStr(max));
//  ShowMessage("Min= " + FloatToStr(min));
//  if (h1!=-1) close(h1);
  fclose(f1);
}
//---------------------------------------------------------------------------

