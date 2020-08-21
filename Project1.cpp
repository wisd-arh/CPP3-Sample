//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

USEUNIT("Unit5.cpp");
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit2.cpp", Form2);
USEFORM("Unit3.cpp", Form3);
USEFORM("Unit4.cpp", Form4);
USERES("PROJECT1.res");
USEFORM("Unit6.cpp", Dlg1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
       {
                 Application->Initialize();
                 Application->Title = "Fractal creater";
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TForm2), &Form2);
                 Application->CreateForm(__classid(TForm3), &Form3);
                 Application->CreateForm(__classid(TForm4), &Form4);
                 Application->CreateForm(__classid(TDlg1), &Dlg1);
                 Application->Run();
        }
       catch (Exception &exception)
       {
                Application->ShowException(&exception);
       }
        return 0;
}
//---------------------------------------------------------------------------

