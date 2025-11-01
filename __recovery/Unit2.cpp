//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
randomize();
secretNum=random(100)+1;
tries =0;
LabelMessage->Caption ="";
LabelEssais->Caption= "number of tries:0";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BtnEssayerClick(TObject *Sender)
{
int userNum;

if(EditNombre->Text == ""){
LabelMessage->Caption="enter a number plz";
return;
}

userNum= StrToInt(EditNombre->Text);

tries ++;

LabelEssais->Caption="number of tries: "+IntToStr(tries);

if(userNum<secretNum){
LabelMessage->Caption="the number is smaller";
}else if(userNum>secretNum){
LabelMessage->Caption="the number is bigger";
}else{
LabelMessage->Caption="gongratulations you did it"+ IntToStr(tries);
}
EditNombre->Text ="";
//
EditNombre->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BtnRejouerClick(TObject *Sender)
{
secretNum=random(100)+1;
EditNombre->Text ="";
tries=0;
LabelMessage->Caption="";
LabelEssais->Caption="number of tries: ";
}
//---------------------------------------------------------------------------
