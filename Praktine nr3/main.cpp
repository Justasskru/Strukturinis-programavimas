#include <iostream>
#include <fstream>
using namespace std;
void pard_sum() {
    int bilK[100];
    int pard[100];
    int i=0, j=0;
    double sumb=0;
    double sumk=0;
    ifstream df;
    df.open("pardavimai.txt");
    if (!df.is_open()) {
        cout <<"Tokio failo nera"<<endl;

    }
while (!df.eof()) {
    df>>bilK[i]>>pard[j];
    i++; j++;
    sumk+=bilK[i]*pard[j];
    sumb+=pard[j];
    cout<<"Isviso parduota: "<<sumb<<" bilietu"<<endl;
    cout<<"Suma: "<<sumk<<"e"<<endl;
}
}
int main() {

    int pasirinkimas;
    cout << "Ka norima daryti?"<<endl;
    cout << "1. Bilietu pardavimu suma"<<endl;
    cout << "2. Atlyginimu skaiciavimas"<<endl;
    cout << "3. Baigti "<<endl;
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