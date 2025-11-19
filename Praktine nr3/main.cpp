#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Funkcija skaiciuoti pardavimus ir gauta pelna
void Pardavimai() {
    ifstream in("Pardavimai.txt");
    ofstream out("Rezultatai.txt");
//Patikrinimas ar failas atsidare
    if (!in.is_open()) {
        cerr << "Nepavyko atidaryti failo Pardavimai.txt!" << endl;
        return;
    }

    double kaina;
    int kiekis;
    double bendraSuma = 0;
    int bendrasKiekis = 0;
//Nuskaitymas
    while (!in.eof()) {
        in >> kaina >> kiekis;
        bendraSuma += kaina * kiekis;
        bendrasKiekis += kiekis;
    }
    cout<<"--------------------------------------"<<endl;
//Isvedimas i ekrana
    cout << "Iš viso parduota bilietų: " << bendrasKiekis << endl;
    cout << "Bendra pardavimų suma: "<< fixed << setprecision(2) << bendraSuma << " EUR" << endl;
    cout<<"--------------------------------------"<<endl;
//Isvedimas i faila
    out << "Iš viso parduota bilietų: "<< bendrasKiekis << endl;
    out << "Bendra pardavimų suma: "<< fixed << setprecision(2)  << bendraSuma << " EUR" << endl;

    in.close();
    out.close();

    cout << "Rezultatai įrašyti į 'Rezultatai.txt'." << endl;

}

//Atlyginimu skaiciavimas
void Atlyginimai() {
    ifstream in("salary.txt");
    ofstream out("newSalary.txt");
//Tikrinimas ar failas atsidare
    if (!in.is_open()) {
        cerr << "Nepavyko atidaryti failo salary.txt!" << endl;
        return;
    }

    string pavarde, vardas;
    double atlyginimas, padidejimas;

    cout<<"Nauji atlyginimai"<<endl;
    cout << "------------------------------------------" << endl;
//Nuskaitymas ir isvedimas
    while (!in.eof()) {
        in >> pavarde >> vardas >> atlyginimas >> padidejimas;

        //Skaiciavimai
        double naujas = atlyginimas + atlyginimas * (padidejimas / 100.0);

        cout  <<" "<< pavarde  << " " << vardas << " "<< fixed << setprecision(2) << naujas << endl;

        out << pavarde << " " << vardas << " "<< fixed << setprecision(2) << naujas << endl;
    }

    in.close();
    out.close();
    cout<<"--------------------------------------"<<endl;
    cout << "Rezultatai įrašyti į 'NewSalary.txt'." << endl;
    cout<<"--------------------------------------"<<endl;
}


int main() {
    int pasirinkimas;

    do {
        cout<<"--------------------------------------"<<endl;
        cout << "Ka norima daryti?" << endl;
        cout<<"--------------------------------------"<<endl;
        cout << "1. Skaičiuoti bilietų pardavimų sumą" << endl;
        cout << "2. Atnaujinti darbuotojų atlyginimus" << endl;
        cout << "0. Baigti darbą" << endl;
        cout<<"--------------------------------------"<<endl;
        cout << "Pasirinkite: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                Pardavimai();
                break;
            case 2:
                Atlyginimai();
                break;
            case 0:
                cout << "Programa baigia darbą." << endl;
                break;
            default:
                cout << "Neteisingas pasirinkimas" << endl;
        }
    } while (pasirinkimas != 0);

    return 0;
}