#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_MOKINIAI = 100;
const int MAX_PAZYMIAI = 10;


void ivestiDuomenis(string vardai[MAX_MOKINIAI], int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI], int &mokiniuSkaicius, int &pazymiuSkaicius) {
cout<<"Mokiniu ir ju pazimiu ivedimas"<<endl;
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

void perziuretiPazymius(const string vardai[MAX_MOKINIAI], const int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI], int mokiniuSkaicius, int pazymiuSkaicius) {
cout<<"Pazymiu perziura";
    cout<<"---------------------"<<endl;
    cout << "Mokiniu pazymiai: " << endl;
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

void atnaujintiPazymi(string vardai[MAX_MOKINIAI], int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI], int mokiniuSkaicius, int pazymiuSkaicius) {
    string vardas;
cout<<"Pazymiu atnaujinimas"<<endl;
    cout<<"---------------------"<<endl;
    cout << "Iveskite mokinio varda: ";
    cin >> vardas;

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

void pasalintiMokini(string vardai[MAX_MOKINIAI], int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI], int &mokiniuSkaicius, int pazymiuSkaicius) {
    string vardas;
    cout<<"Mokinio pasalinimas"<<endl;
    cout<<"--------------------"<<endl;
    cout << "Iveskite mokinio varda: ";
    cin >> vardas;

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

// --- Pagrindinė programa ---

int main() {
    string vardai[MAX_MOKINIAI];
    int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI];
    int mokiniuSkaicius = 0;
    int pazymiuSkaicius = 0;

    int pasirinkimas;

    do {
        cout << "----Mokiniu pazymiu sistema----" << endl;
        cout << "1 Ivesti mokinius ir ju pazymius" << endl;
        cout << "2 Perziureti pazymius" << endl;
        cout << "3 Pakeisti pazymi" << endl;
        cout << "4 Pasalinti mokini" << endl;
        cout << "5 Baigti" << endl;
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
                atnaujintiPazymi(vardai, pazymiai, mokiniuSkaicius, pazymiuSkaicius);
                break;
            case 4:
                pasalintiMokini(vardai, pazymiai, mokiniuSkaicius, pazymiuSkaicius);
                break;
            case 5:
                cout << "Aciu kad naudojotes." << endl;
                break;
            default:
                cout << "Tokio pasirinkimo nera" << endl;
        }
    } while (pasirinkimas != 5);

    return 0;
}