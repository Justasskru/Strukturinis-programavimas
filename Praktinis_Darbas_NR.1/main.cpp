#include <iostream>
using namespace std;
//------------------------------------
// Funkcija valiutos pirkimui
void Val_pirk() {
//kintamieji
    string valiut;
    double kiek=0;
    double rezult=0;
     double GBP_Pirkti    = 0.8600;
     double USD_Pirkti    = 1.1460;
     double INR_Pirkti    = 101.3862;
    //------------------------------------
    //uzklausos zmogui
cout<<"Paisrinkite valiuta kuria pirksite (GBP, USD, INR)"<<endl;
    cin>>valiut;
    cout<<"Iveskite kiek EUR isleisite:"<<endl;
    cin>>kiek;
    //-------------------------------------------
    //tikrinama kokia valiuta ivesta ir atliekami sakaiciavimai
    if (valiut=="GBP") {
        rezult=kiek*GBP_Pirkti;
        cout<<"Gavote "<<rezult<<" GBP"<<endl;

    }
  else  if (valiut=="USD") {
    rezult=kiek*USD_Pirkti;
    cout<<"Gavote "<<rezult<<" USD"<<endl;

}
   else  if (valiut=="INR") {
        rezult=kiek*INR_Pirkti;
        cout<<"Gavote "<<rezult<<" INR"<<endl;
    }
    else  cout<<"Pasirinkimas neteisingas"<<endl;

};
//--------------------------------------
//Funkcija valiutos pardavimui
void Val_par() {
//kintamieji
    string pav;
    double kiek=0;
    double rezult=0;
    double GBP_Parduoti  = 0.9220;
    double USD_Parduoti  = 1.2340;
    double INR_Parduoti  = 107.8546;
    //---------------------------------------
    //uzklausos zmogui
cout<<"Iveskite valiuta kuria norite parduoti (GBP, USD, INR)"<<endl;
    cin>>pav;
    cout<<"Kiek norite parduoti:"<<endl;
    cin>>kiek;
    //---------------------------------------
    // tikrinama kokia valiuta buvo ivesta ir atliekami skaiciavimai
   if (pav=="GBP") {
        rezult=kiek/GBP_Parduoti;
        cout<<"Gavote "<<rezult<<" EUR"<<endl;
    }
   else if (pav=="USD") {
        rezult=kiek/USD_Parduoti;
        cout<<"Gavote "<<rezult<<" EUR"<<endl;

    }
    else if (pav=="INR") {
        rezult=kiek/INR_Parduoti;
        cout<<"Gavote "<<rezult<<" EUR"<<endl;
    }
    else cout<<"Pasirinkimas neteisingas"<<endl;

};

int main() {
//bendras kursas
    cout <<"Valiutos Keitykla"<<endl;
    double GBP_Bendras   = 0.8729;
    double USD_Bendras   = 1.1793;
    double INR_Bendras   = 104.6918;
    int pasirinkimas;
    int a=0;
    //----------------------------------------
while (a!=1) {
    // uzklausos zmogui
    cout <<"Pasirinkite ka norima daryti pasirinkdami numeri:"<<endl;
    cout <<"1 Valiutos kurso palyginimas"<<endl;
    cout <<"2 Valiutos pirkimas"<<endl;
    cout <<"3 Valiutos pardavimas"<<endl;
    cout <<"Jusu pasirinkimas:"<<endl;
    cin >>pasirinkimas;
    //---------------------------------------
    //paleidziama pasirinkta funkcija
    switch (pasirinkimas) {

        case 1:
            cout<<"Valiutos kurso palyginimas:"<<endl;
            cout<<"1 EUR - "<<GBP_Bendras<<" GBP"<<endl;
            cout<<"1 EUR - " <<USD_Bendras<<" USD"<<endl;
            cout<<"1 EUR - "<<INR_Bendras<<" INR"<<endl;
            break;

        case 2:
            Val_pirk();
            break;

        case 3:
            Val_par();
            break;

        default:
            cout<<"Pasirinkimas neteisingas"<<endl;
    }
    //Klausimas ar norima test
    cout<<"Ar tai viskas?"<<endl;
    cout<<"1 Taip"<<endl;
    cout<<"2 Ne"<<endl;
    //jeigu norima ivedama 1 ir gryztame i pradzia
    cin>>a;
}
    //------------------------------
    cout<<"Aciu, kad naudojotes musu paslaugomis"<<endl;
return 0;
}