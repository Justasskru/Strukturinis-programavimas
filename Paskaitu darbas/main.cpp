#include <iostream>
using namespace std;
int main() {
// int masyvas [100][100];
//     int n, m;
//
//
//
//     cout <<"Kiek bus mokiniu?"<<endl;
//     cin >>n;
//     cout<<"Kiek bus dalyku?"<<endl;
//     cin >> m;
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<m;j++) {
//             cout<<"Iveskite "<<i+1<<" mokinio "<<j+1<<" dalyko pazymi"<<endl;
//             cin >>masyvas[i][j];
//         }
//     }
//
// for(int i=0;i<n;i++) {
//         for(int j=0;j<m;j++) {
//             cout<<masyvas[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//
//     for(int i=0;i<n;i++) {
//         double vidM=0;
//         for(int j=0;j<m;j++) {
//
//             vidM+=masyvas[i][j];
//         }
//         vidM=vidM/n;
//         cout<<"Mokinio "<<i+1<<" vidurkis: "<<vidM<<endl;
//     }
//
//     for(int j=0;j<m;j++) {
//         double vidD=0;
//         for(int i=0;i<n;i++) {
//
//             vidD+=masyvas[i][j];
//             vidD=vidD/m;
//         }
//
//         cout<<"Dalyko "<<j+1<<" vidurkis: "<<vidD<<endl;
//     }
// double vidB=0;
//     for(int i=0;i<n;i++) {
//
//         for(int j=0;j<m;j++) {
//
//             vidB+=masyvas[i][j];
//         }
//
//
//     }
//     vidB=vidB/n;
//     cout<<"Bendras vidurkis: "<<vidB<<endl;
#include <iostream>
 using namespace std;

 // MIE - miestai, DIE - dienos, LAI - paros laikai
 // temp - temperatūros duomenys
 // sum - suma vidurkiui
 // vidL - vidutinės paros temperatūros
 // kiekL - kiek kartų skaičiuota kiekvienam laikui
 // silInd - šilčiausio laiko indeksas


  const int MIE = 3, DIE = 7, LAI = 4;
  double temp[MIE][DIE][LAI], sum, vidL[LAI] = {0}, kiekL[LAI] = {0};

  for (int m = 0; m < MIE; m++) {
   cout << "Miestas " << m + 1 << endl;
   for (int d = 0; d < DIE; d++) {
    cout << "  Diena " << d + 1 << endl;
    for (int l = 0; l < LAI; l++) {
     cout << "    Laikas " << l + 1 << ": ";
     cin >> temp[m][d][l];
    }
   }
  }

  for (int m = 0; m < MIE; m++) {
   sum = 0;
   for (int d = 0; d < DIE; d++)
    for (int l = 0; l < LAI; l++)
     sum += temp[m][d][l];
   cout << "Miestas " << m + 1 << " vid: " << sum / (DIE * LAI) << endl;
  }

  for (int m = 0; m < MIE; m++)
   for (int d = 0; d < DIE; d++)
    for (int l = 0; l < LAI; l++) {
     vidL[l] += temp[m][d][l];
     kiekL[l]++;
    }

  for (int l = 0; l < LAI; l++)
   vidL[l] /= kiekL[l];

  int silInd = 0;
  for (int l = 1; l < LAI; l++)
   if (vidL[l] > vidL[silInd])
    silInd = l;

  cout << "Silciausias laikas: " << silInd + 1 << endl;
  return 0;
 }
