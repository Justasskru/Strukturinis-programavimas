#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//-------------------------------------
//Struktura mokinio
struct Mokinys {
    int id;
    char atsakymas[20];
    double taskai = 0.0;
    double proc = 0.0;
    int pazimys = 0;
};
//---------------------------------------
//funkcija klases statistikai
void KlasesStatistika(const vector<Mokinys>& mokiniai) {
    if (mokiniai.empty()) {
        cout << "Nera duomenu." << endl;
        return;
    }

    int kiekis = mokiniai.size();
    double sumaTasku = 0;
    double sumaProc = 0;
    double maxTaskai = mokiniai[0].taskai;
    double minTaskai = mokiniai[0].taskai;
    int pazymiuKiekis[11] = {0}; // 1–10

    for (const auto& m : mokiniai) {
        sumaTasku += m.taskai;
        sumaProc += m.proc;

        if (m.taskai > maxTaskai) maxTaskai = m.taskai;
        if (m.taskai < minTaskai) minTaskai = m.taskai;

        int paz;
        if (m.proc >= 90) paz = 10;
        else if (m.proc >= 80) paz = 9;
        else if (m.proc >= 70) paz = 8;
        else if (m.proc >= 60) paz = 7;
        else if (m.proc >= 50) paz = 6;
        else if (m.proc >= 40) paz = 5;
        else if (m.proc >= 30) paz = 4;
        else if (m.proc >= 20) paz = 3;
        else if (m.proc >= 10) paz = 2;
        else paz = 1;

        pazymiuKiekis[paz]++;
    }

cout <<"Klases statistika"<<endl;
    cout << "--------------------------------"<<endl;
    cout << "Studentu skaicius: " << kiekis << endl;
    cout << "Didziausias balas: " << maxTaskai << endl;
    cout << "Maziausias balas: " << minTaskai << endl;
    cout << "Vidutinis balas: " << sumaTasku / kiekis << endl;
    cout << "Vidutinis procentas: " << sumaProc / kiekis << "%" << endl;

    cout << "Pazymiu pasiskirstymas:" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << ": " << pazymiuKiekis[i] << endl;
    }
    cout << "--------------------------------"<<endl;
}

//---------------------------------------------------------
//funkcija klausimu statistikai
void KlausmStat(const vector<Mokinys>& mok, const vector<char>& teisingiAtsakymai) {
    if (mok.empty()) {
        cout << "Nera duomenu." << endl;
        return;
    }

    cout << "Klausimu statistika" << endl;
    cout << "--------------------------------" << endl;

    int klausimuKiekis = 20;

    for (int i = 0; i < klausimuKiekis; i++) {
        int teisingi = 0;
        int neteisingi = 0;
        int neatsakyti = 0;

        for (const auto& m : mok) {
            if (m.atsakymas[i] == '-') {
                neatsakyti++;
            } else if (m.atsakymas[i] == teisingiAtsakymai[i]) {
                teisingi++;
            } else {
                neteisingi++;
            }
        }

        cout << "Klausimas " << i + 1 << ":" << endl;
        cout << "  Teisingi: " << teisingi << endl;
        cout << "  Neteisingi: " << neteisingi << endl;
        cout << "  Neatsake: " << neatsakyti << endl;
        cout << "--------------------" << endl;
    }
}
//--------------------------------------------------------
//studentoc paieska pagal id
void Stud(const vector<Mokinys>& mok) {
    if (mok.empty()) {
        cout << "Nera duomenu." << endl;
        return;
    }

    int ieskomasID;
    cout <<"Studento paieska"<<endl;
    cout << "--------------------------------"<<endl;
    do {
        cout << "Iveskite studento ID (0 baigti paieska): ";
        cin >> ieskomasID;

        if (ieskomasID == 0)
            break;

        bool rastas = false;
        for (const auto& m : mok) {
            if (m.id == ieskomasID) {
                rastas = true;
                cout << "Studento ID: " << m.id << endl;
                cout << "Atsakymai: ";
                for (int i = 0; i < 20; i++) {
                    cout << m.atsakymas[i] << " ";
                }
                cout << endl;
                cout << "Taskai: " << m.taskai << endl;
                cout << "Procentai: " << m.proc << "%" << endl;
                break;
            }
        }

        if (!rastas) {
            cout << "Studentas su ID " << ieskomasID << " nerastas." << endl;
        }

    } while (ieskomasID != 0);
    cout << "--------------------------------"<<endl;
}

//----------------------------------------------------------
//sunkiausio klausimo radimo funkcija
void SunkiausiasKlausimas(const vector<Mokinys>& mok, const vector<char>& teisingiAtsakymai) {
    if (mok.empty()) {
        cout << "Nera duomenu." << endl;
        return;
    }

    int klausimuKiekis = 20;
    vector<int> teisinguKiekis(klausimuKiekis, 0);

    for (int i = 0; i < klausimuKiekis; i++) {
        for (const auto& m : mok) {
            if (m.atsakymas[i] == teisingiAtsakymai[i]) {
                teisinguKiekis[i]++;
            }
        }
    }

    vector<double> procentai(klausimuKiekis);
    for (int i = 0; i < klausimuKiekis; i++) {
        procentai[i] = (double)teisinguKiekis[i] / mok.size() * 100.0;
    }

    double minProc = *min_element(procentai.begin(), procentai.end());
    cout << "--------------------------------" << endl;
    cout << "Sunkiausias klausimas(-ai)" << endl;
    cout << "Maziausias teisingu atsakymu procentas: " << minProc << "%" << endl;
    cout << "--------------------------------" << endl;

    for (int i = 0; i < klausimuKiekis; i++) {
        if (procentai[i] == minProc) {
            cout << "Klausimas " << i + 1 << endl;
        }
    }
    cout << "--------------------------------" << endl;
}

//--------------------------------------------------------------
//main
int main() {
   int studKiek=0;
    ifstream df("testData.txt");
    if (!df.is_open()) {
        cout << "Failas neatsidaro" << endl;
        return 0;
    }
    //__________________________________________________
    //Teisingiems atsakymams nuskaityti
    string line;
    getline(df, line);

    vector<char> teisingiAtsakymai;
    for (char c : line) {
        if (c == 'T' || c == 'F' || c == '-') {
            teisingiAtsakymai.push_back(c);
        }
    }

    //_________________________________________________
//mokinio id ir atsakymu nuskaitymas
    vector<Mokinys> mok;
    Mokinys X;

    while (df >> X.id) {
        X.taskai = 0;
        for (int i = 0; i < 20; i++) {
            df >> X.atsakymas[i];
            if (X.atsakymas[i] == teisingiAtsakymai[i]) {
                X.taskai += 2;
            } else {
                X.taskai -= 2;
            }
        }
        //pazymio skaiciavimas
        X.proc = (X.taskai / 40.0) * 100.0;
        if (X.proc >= 95) X.pazimys = 10;
        else if (X.proc >= 85) X.pazimys = 9;
        else if (X.proc >= 75) X.pazimys = 8;
        else if (X.proc >= 65) X.pazimys = 7;
        else if (X.proc >= 55) X.pazimys = 6;
        else if (X.proc >= 45) X.pazimys = 5;
        else if (X.proc >= 35) X.pazimys = 4;
        else if (X.proc >= 25) X.pazimys = 3;
        else if (X.proc >= 15) X.pazimys = 2;
        else X.pazimys = 1;
        mok.push_back(X);
    }


//-----------------------------------------------------------------------------

ofstream rf("results.txt");

    for (int i = 0; i < mok.size(); i++) {
        rf << mok[i].id << " Taskai: "<<mok[i].taskai<<" Procentai: "<<mok[i].proc<<"% Pazimys: "<<mok[i].pazimys<<endl;
    }

    //------------------------------------------------------------------------

    int pasirinkimas;
    do {
cout<<"Ka norima daryti?"<<endl;
    cout<<"Perziureti: "<<endl;
    cout<<"1. Klasės statistika"<<endl;
    cout<<"2. Kiekvieno klausimo statistika"<<endl;
    cout<<"Kita: "<<endl;
    cout<<"3. Studento paieška pagal ID "<<endl;
    cout<<"4. Sunkiausio klausimo nustatymas"<<endl;
    cout<<"5. Baigti"<<endl;
cout <<"Iveskite pasirinkima: "<<endl;

    cin>>pasirinkimas;
    switch(pasirinkimas) {
        case 1:
            KlasesStatistika(mok);
            break;
case 2:
            KlausmStat(mok, teisingiAtsakymai);
            break;

            case 3:
            Stud(mok);
            break;
            case 4:
                SunkiausiasKlausimas(mok, teisingiAtsakymai);
            break;
            case 5:
            cout<<"Baigta"<<endl;
            break;
            default:
            cout<<"Pasirinkimas neteisingas"<<endl;
            break;

    }

} while (pasirinkimas != 5);

rf.close();
df.close();

}