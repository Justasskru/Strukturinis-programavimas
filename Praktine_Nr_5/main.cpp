#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Mokinys {
    int id;
    char atsakymas[20];
    double taskai;
    double proc;
    int pazimys;
};

int main() {
ifstream df("testData.txt");
    if (!df.is_open()) {
        cerr << "Failas neatsidaro" << endl;
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
cout<<"Teisingi atsakymai: ";

    // patikrinimui – atspausdiname
    for (char x : teisingiAtsakymai) {
        cout << x << " ";
    }
    cout<<endl;
    cout<<"---------------------------"<<endl;
    //_________________________________________________

    vector<Mokinys> mok;
    Mokinys X;

    while (df >> X.id) {
        for (int i = 0; i < 20; i++) {
            df >> X.atsakymas[i];

        }
        mok.push_back(X);
    }
    for (int i = 0; i < mok.size(); i++) {
        cout << mok[i].id << " ";
        for (int j = 0; j < 20; j++) {
            cout << mok[i].atsakymas[j] << " ";
        }
        cout<<endl;
    }








    int pasirinkimas;
    do {
cout<<"Ka norima daryti?"<<endl;
    cout<<"Perziureti: "<<endl;
    cout<<"1. Klasės statistika"<<endl;
    cout<<"2. Kiekvieno klausimo statistika"<<endl;
    cout<<"Kita: "<<endl;
    cout<<"3. Studento paieška pagal ID "<<endl;
    cout<<"4. Sunkiausio klausimo nustatymas"<<endl;
    cout<<"0. Baigti"<<endl;
cout <<"Iveskite pasirinkima: "<<endl;

    cin>>pasirinkimas;
    switch(pasirinkimas) {
        //sudek pasirinkimus cia

    }

} while (pasirinkimas!=0);


}