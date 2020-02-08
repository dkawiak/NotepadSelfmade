//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString nazwapliku="";

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Otwrz1Click(TObject *Sender)
{
        if (Application->MessageBox(
        "Czy chcesz zapisac zmiany w pliku?","PotwierdŸ",
        MB_YESNO | MB_ICONQUESTION) ==IDYES )
                {
                Form1->Zapisz1Click(MainMenu1);
                }
        if (OpenDialog1->Execute())
        {
        try
        {
         tresc->Lines->LoadFromFile(OpenDialog1->FileName);
         nazwapliku = OpenDialog1->FileName;
        }
        catch (...)
        {
          ShowMessage("B³¹d otwarcia pliku. Upewnij siê, ¿e plik istnieje");
        }

        }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Zapiszjako1Click(TObject *Sender)
{
         if (SaveDialog1->Execute())
        {
        try
        {
         tresc->Lines->SaveToFile(SaveDialog1->FileName);
         nazwapliku = SaveDialog1->FileName;
        }
        catch (...)
        {
          ShowMessage("Zapis zakoñczy³ siê niepowodzeniem!");
        }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapisz1Click(TObject *Sender)
{
        if (nazwapliku!="")
        {
         tresc->Lines->SaveToFile(nazwapliku);
        }
        else
        {
         Form1->Zapiszjako1Click(MainMenu1);
        }
        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Nowy1Click(TObject *Sender)
{
        if (Application->MessageBox(
        "Czy na pewno utworzyæ nowy plik?","PotwierdŸ",
        MB_YESNOCANCEL | MB_ICONQUESTION) ==IDYES )
        {
        if (Application->MessageBox(
        "Czy chcesz zapisac zmiany w pliku?","PotwierdŸ",
        MB_YESNO | MB_ICONQUESTION) ==IDYES )
                {
                Form1->Zapisz1Click(MainMenu1);

                }

        tresc->Lines->Clear();
        nazwapliku="";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::trescKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Shift.Contains(ssCtrl))
        {
                if ((Key == 's') || (Key == 'S'))
                {
                Form1->Zapisz1Click(MainMenu1);
                }

                if ((Key =='n') || (Key == 'N'))
                {
                Form1->Nowy1Click(MainMenu1);
                }
                if ((Key =='a') || (Key == 'A'))
                {
                Form1->ZaznaczwszystkoCtrlA1Click(MainMenu1);
                }
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zakocz1Click(TObject *Sender)
{

        if (Application->MessageBox(
        "Czy chcesz zapisac zmiany w pliku?","PotwierdŸ",
        MB_YESNO | MB_ICONQUESTION) ==IDYES )
                {
                Form1->Zapisz1Click(MainMenu1);
                Application->Terminate();
                }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
     if (Application->MessageBox(
        "Czy chcesz zapisac zmiany w pliku?","PotwierdŸ",
        MB_YESNO | MB_ICONQUESTION) ==IDYES )
                {
                Form1->Zapisz1Click(MainMenu1);
                Application->Terminate();
                }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::WytnijCtrlX1Click(TObject *Sender)
{
    tresc->CutToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::KopiujCtrlC1Click(TObject *Sender)
{
    tresc->CopyToClipboard();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::WklejCtrlV1Click(TObject *Sender)
{
    tresc->PasteFromClipboard();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Zawijaniewierszy1Click(TObject *Sender)
{
     if (Zawijaniewierszy1->Checked==false)
     {
        Zawijaniewierszy1->Checked==false;
        tresc->WordWrap=false;
        tresc->ScrollBars = ssBoth;
      }
      else
      {
        Zawijaniewierszy1->Checked==true;
        tresc->WordWrap=true;
        tresc->ScrollBars = ssVertical;
      }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Czcionka2Click(TObject *Sender)
{
       if (FontDialog1->Execute())
       {
         //kroj czcionki
         tresc->Font->Name = FontDialog1->Font->Name;

         //kolor czcionki
         tresc->Font->Color = FontDialog1->Font->Color;

         //rozmiar czcionki
         tresc->Font->Size = FontDialog1->Font->Size;

         //styl (pochylanie, pogrubienie)
         tresc->Font->Style = FontDialog1->Font->Style;
       }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Oprogramie1Click(TObject *Sender)
{
   Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zapraszamnabloga1Click(TObject *Sender)
{
        try{
    ShellExecute(NULL,"open","www", NULL, NULL, SW_SHOWNORMAL);
    }
        catch (...){
  ShowMessage("Unable to start web browser.");
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZaznaczwszystkoCtrlA1Click(TObject *Sender)
{
        tresc->SelectAll();
}
//---------------------------------------------------------------------------

