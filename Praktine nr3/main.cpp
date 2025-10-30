#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void pard_sum() {
    int bilK[4];
    int pard[4];
    int i=0;
    int sumb=0;
    double sumk=0;
    ifstream df("Pardavimai.txt");
    ofstream fo("Rezultatai.txt");
    if (!df.is_open()) {
        cerr << "Failas neatsidaro" << endl;
      

    }
while ( df >> bilK[i]>>pard[i]) {
df>>ws;
    sumk+=bilK[i]*pard[i];
    sumb+=pard[i];
    i++;
}

    cout<<"Isviso parduota: "<<sumb<<" bilietu"<<endl;
    cout<<"Suma: "<<fixed<<setprecision(2)<<sumb<<sumk<<"e"<<endl;
    fo<<"Isviso parduota: "<<sumb<<" bilietu"<<endl;
    fo<<"Suma: "<<fixed<<setprecision(2)<<sumb<<sumk<<"e"<<endl;
    df.close();
    fo.close();
};

int main() {

    int pasirinkimas;
    cout << "Ka norima daryti?"<<endl;
    cout << "1. Bilietu pardavimu suma"<<endl;
    cout << "2. Atlyginimu skaiciavimas"<<endl;
    cout << "3. Baigti "<<endl;
    cout << "Iveskite pasirinkima: ";
    cin>>pasirinkimas;
do {
    switch(pasirinkimas) {
        case 1:
pard_sum();
            break;
        case 2:

break;
        case 3:
cout <<"Aciu kad naudojtes";
break;
    }

}while (pasirinkimas != 3);
}