#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//maximalios reiksmes
const int MAX_MOKINIAI = 100;
const int MAX_PAZYMIAI = 10;

//funkcija duomenims ivesti
void ivestiDuomenis(string vardai[MAX_MOKINIAI], int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI], int &mokiniuSkaicius, int &pazymiuSkaicius) {
    cout<<"----------------------"<<endl;
    cout<<"Mokiniu ir ju pazymiu ivedimas"<<endl;
    cout<<"----------------------"<<endl;
    cout << "Kiek bus mokiniu? ";
    cin >> mokiniuSkaicius;
    cout << "Kiek pazymiu tures kiekvienas mokinys? ";
    cin >> pazymiuSkaicius;

    for (int i = 0; i < mokiniuSkaicius; i++) {
        cout << "Iveskite " << i + 1 << "-o mokinio varda: "<<endl;
        cin >> vardai[i];
        for (int j = 0; j < pazymiuSkaicius; j++) {
            cout << "Iveskite " << j + 1 << "-a pazymi: "<<endl;
            cin >> pazymiai[i][j];
        }
    }
}
//funkcija duomenu perziurai
void perziuretiPazymius(const string vardai[MAX_MOKINIAI], const int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI], int mokiniuSkaicius, int pazymiuSkaicius) {

    cout<<"----------------------"<<endl;
    cout << "Mokiniu pazymiai: " << endl;
    cout<<"----------------------"<<endl;
    double vid;
    for (int i = 0; i < mokiniuSkaicius; i++) {
        cout << vardai[i] << ": ";
        double suma = 0;
        for (int j = 0; j < pazymiuSkaicius; j++) {
            cout << pazymiai[i][j] << " ";
            suma += pazymiai[i][j];
        }
        vid = suma / pazymiuSkaicius;
        cout << "  Vidurkis: " <<fixed<< setprecision(2)<< vid << endl;
    }
}
//Konkretaus mokinio pazimiu perziura
void  perziuretiKonkPaz(const string vardai[MAX_MOKINIAI], const int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI], int mokiniuSkaicius, int pazymiuSkaiciu) {
string vardas;
    double sum=0, vid=0;
    int k=0;
    cout<<"----------------------"<<endl;
    cout<<"Iveskite mokinio varda:"<<endl;
    cout<<"----------------------"<<endl;
    cin>>vardas;
    bool rastas = false;
    for (int i = 0; i < mokiniuSkaicius; i++) {
        if (vardai[i] == vardas) {
            rastas = true;
            cout <<vardai[i] << ": ";
            for (int j = 0; j < pazymiuSkaiciu; j++) {
                cout << pazymiai[i][j] << " ";
                sum += pazymiai[i][j];
                k++;
            }
            vid = sum / k;
            cout << "  Vidurkis: " <<fixed<< setprecision(2)<< vid << endl;

            if (!rastas) {

                cout<<"Tokio mokinio nera"<<endl;
            }
        }
    }
    if (!rastas) cout << "Toks mokinys nerastas." << endl;
}
//pazymio atnaujinimo funkcija
void atnaujintiPazymi(string vardai[MAX_MOKINIAI], int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI], int mokiniuSkaicius, int pazymiuSkaicius) {
    string vardas;
    //kreipiames i funkcija kad isvestu visus duomenis
    perziuretiPazymius(vardai, pazymiai, mokiniuSkaicius, pazymiuSkaicius);
    cout<<"----------------------"<<endl;
cout<<"Pazymiu atnaujinimas"<<endl;
    cout<<"---------------------"<<endl;
    cout << "Iveskite mokinio varda: ";
    cin >> vardas;
    // mokionio vardo suradimas
    bool rastas = false;
    for (int i = 0; i < mokiniuSkaicius; i++) {
        if (vardai[i] == vardas) {
            rastas = true;
            cout << "Iveskite pazymio numeri (1-" << pazymiuSkaicius << "): ";
            int nr;
            cin >> nr;
            if (nr >= 1 && nr <= pazymiuSkaicius) {
                cout << "Iveskite nauja pazymi: ";
                cin >> pazymiai[i][nr - 1];
                cout << "Pazymys atnaujintas!" << endl;
            } else {
                cout << "Tokio pazymio numerio nera" << endl;
            }
            break;
        }
    }
    if (!rastas) cout << "Toks mokinys nerastas." << endl;
}
//mokinio pasalinimo funkcija
void pasalintiMokini(string vardai[MAX_MOKINIAI], int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI], int &mokiniuSkaicius, int pazymiuSkaicius) {
    string vardas;
    //kreipiames i funkcija kad isvestu visus duomenis
    perziuretiPazymius(vardai, pazymiai, mokiniuSkaicius, pazymiuSkaicius);
    cout<<"----------------------"<<endl;
    cout<<"Mokinio pasalinimas"<<endl;
    cout<<"--------------------"<<endl;
    cout << "Iveskite mokinio varda: ";
    cin >> vardas;
// mokinio vardo suradimas
    bool rastas = false;
    for (int i = 0; i < mokiniuSkaicius; i++) {
        if (vardai[i] == vardas) {
            for (int j = i; j < mokiniuSkaicius - 1; j++) {
                vardai[j] = vardai[j + 1];
                for (int k = 0; k < pazymiuSkaicius; k++) {
                    pazymiai[j][k] = pazymiai[j + 1][k];
                }
            }
            mokiniuSkaicius--;
            rastas = true;
            cout << "Mokinys pasalintas" << endl;
            break;
        }
    }
    if (!rastas) cout << "Tokio mokinio nera" << endl;
}



int main() {
    string vardai[MAX_MOKINIAI];
    int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI];
    int mokiniuSkaicius = 0;
    int pazymiuSkaicius = 0;
//meniu
    int pasirinkimas;

    do {
        cout << "----Mokiniu pazymiu sistema----" << endl;
        cout << "1 Ivesti mokinius ir ju pazymius" << endl;
        cout << "2 Perziureti pazymius" << endl;
        cout <<"3 Perziureti konkretaus mokinio pazimi"<<endl;
        cout << "4 Pakeisti pazymi" << endl;
        cout << "5 Pasalinti mokini" << endl;
        cout << "6 Baigti" << endl;
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                ivestiDuomenis(vardai, pazymiai, mokiniuSkaicius, pazymiuSkaicius);
                break;
            case 2:
                perziuretiPazymius(vardai, pazymiai, mokiniuSkaicius, pazymiuSkaicius);
                break;
                case 3:
                perziuretiKonkPaz(vardai, pazymiai, mokiniuSkaicius,pazymiuSkaicius);
                break;
            case 4:
                atnaujintiPazymi(vardai, pazymiai, mokiniuSkaicius, pazymiuSkaicius);
                break;
            case 5:
                pasalintiMokini(vardai, pazymiai, mokiniuSkaicius, pazymiuSkaicius);
                break;
            case 6:
                cout << "Aciu kad naudojotes." << endl;
                break;
            default:
                cout << "Tokio pasirinkimo nera" << endl;
        }
    } while (pasirinkimas != 6);

    return 0;
}