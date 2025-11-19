#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
   
struct Patiekalas{
    string pavadinimas[50];
    double kaina[50];
};

vector<Patiekalas> meniu;

struct Uzsakymas{
    string pasirinkimas;
    int kiekis;
};

vector<Uzsakymas> uzsakymai;

void getData(){
    ifstream df("meniu.txt");
    if(!df.is_open()){
        cerr << "Klaida atidarant faila!" << endl;
        return;
    }
    Patiekalas x;
   int i=0;
   while(df.eof())
    {
         df >> x.pavadinimas[i];
         df >> x.kaina[i];
         meniu.push_back(x);
         i++;
    }
    df.close();
}
void showMenu(){

    cout << "Pusryciu meniu:" << endl;
    for(size_t i=0; i<meniu.size(); i++){
        cout << i+1 << ". " << meniu[i].pavadinimas[i] << " - " << meniu[i].kaina[i] << " EUR" << endl;
    }
}
int main()
{
    getData();
    
Patiekalas x;
int pas=0;
while( pas != 4){
    cout << "Pusryciu meniu:" << endl;
    cout << "Ka norima daryti?" << endl;
    cout << "1. Meniu" << endl;
    cout << "2. Uzsakyti" << endl;
    cout << "3. Saskaita" << endl;
    cout << "4. Baigti" << endl;
    cout << "Iveskite pasirinkimo numeri: ";
    cin >> pas;
    switch (pas)
    {
    case 1:
    showMenu();

    break;
    case 2:
    break;
    case 3:
    break;
    case 4:
    cout << "Viso gero!" << endl;
    break;
    default:
    cout << "Neteisingas pasirinkimas!" << endl;
        } 
        
    }
}