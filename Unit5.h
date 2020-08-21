//---------------------------------------------------------------------------
#ifndef Unit5H
#define Unit5H
#include <math.h>
static float _r, _i;
//---------------------------------------------------------------------------
typedef struct {
  float re, im;
  } complex;
   complex inv(const complex& Value)
     {complex res; res.re=Value.re; res.im=-Value.im; return res; }
   complex operator+ (float C, const complex& Value)
     {complex res; res.re=C+Value.re ; res.im=Value.im; return res; }
   complex operator+ (const complex& Value, float C)
     {complex res; res.re=C+Value.re ; res.im=Value.im; return res; }
   complex operator- (const complex& Value, float C)
     {complex res; res.re=Value.re-C ; res.im=Value.im-C; return res; }
   complex operator- (float C, const complex& Value)
     {complex res; res.re=C-Value.re ; res.im=C-Value.im-C; return res; }
   complex operator* (const complex& Value, float C)
     {complex res; res.re=C*Value.re ; res.im=C*Value.im; return res; }
   complex operator* (float C, const complex& Value)
     {complex res; res.re=C*Value.re ; res.im=C*Value.im; return res; }
   float norm (const complex& Value)
     {return Value.re*Value.re+Value.im*Value.im;}
   complex operator+ (const complex& Value1, const complex& Value2)
     {complex res; res.re=Value1.re+Value2.re ; res.im=Value1.im+Value2.im; return res; }
   complex operator- (const complex& Value1, const complex& Value2)
     {complex res; res.re=Value1.re-Value2.re ; res.im=Value1.im-Value2.im; return res; }
   complex operator* (const complex& Value1, const complex& Value2)
     {complex f;
      f.re=Value1.re*Value2.re-Value1.im*Value2.im;
      f.im=Value1.im*Value2.re+Value2.im*Value1.re;
      return f;}
   complex operator/ (const complex& Value, float C)
     {complex res; res.re=Value.re/C; res.im=Value.im/C; return res; }
   complex operator/ (const complex& Value1, const complex& Value2)
     {complex f;
      f=(Value1*inv(Value2))/(Value2.re*Value2.re+Value2.im*Value2.im);
      return f;}
   complex operator/ (float C, const complex& Value2)
     {complex f;
      f=(C*inv(Value2))/(Value2.re*Value2.re+Value2.im*Value2.im);
      return f;}
   complex Zabs (const complex& Value)
      {complex res; res.re=fabs(Value.re); res.im=fabs(Value.im); return res; }
   float Zarg (const complex& Value)
     { float f;
        f=Value.im/norm(Value);
        if (f>1) f=1; else
        if (f<-1) f=-1;
        return asin(f); }
   complex Zsqrt (const complex& Value)
     {complex res;
       float mZ;
       float aZ;
       aZ=(Zarg(Value))/2;
       mZ=sqrt(norm(Value));
       res.re=mZ*cos(aZ);
       res.im=mZ*sin(aZ);
       return res;}
   void __fastcall Zsqr (complex& Value)
     {_r=Value.re;
      _i=Value.im;
      Value.re=_r*_r-_i*_i; Value.im=2*_r*_i; }
   complex __fastcall Zsqr1 (const complex& Value)
     {complex res;
      _r=Value.re;
      _i=Value.im;
      res.re=_r*_r-_i*_i; res.im=2*_r*_i; return res; }
   complex Zexp (const complex& Value)
     {complex res; res.re=exp(Value.re);
      res.im=exp(Value.im); return res; }
//---------------------------------------------------------------
   void __fastcall sum(complex& V, const complex& C) {
     V.re+=C.re;
     V.im+=C.im;
   }
   void __fastcall mul(complex& V, const complex& C) {
      _r=V.re;
      V.re=V.re*C.re-V.im*C.im;
      V.im=V.im*C.re+C.im*_r;
   }
#endif

