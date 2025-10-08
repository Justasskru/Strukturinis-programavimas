#include <iostream>
using namespace std;

int main() {
const int N = 3;
    int masyvas [N][N];
    cout << "Iveskite matricos elementus:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
cout << "Matricos [" << i << "][" << j << "]" << endl;
            cin >> masyvas[i][j];

        }
    }
    cout << "-----------------------------"<<endl;
    cout <<"Jusu matrica:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << masyvas[i][j] << " ";
        }
        cout << endl;
    }
int det = masyvas[0][0]*masyvas[1][1]*masyvas[2][2]+
          masyvas[0][1]*masyvas[1][2]*masyvas[2][0]+
          masyvas[0][2]*masyvas[1][0]*masyvas[2][1]-
              masyvas[0][2]*masyvas[1][1]*masyvas[2][0]-
              masyvas[0][1]*masyvas[1][0]*masyvas[2][2]-
                  masyvas[0][0]*masyvas[1][2]*masyvas[2][1];
    cout << "--------------------------"<<endl;
    cout << "Matricos determinantas :" << endl;
    cout << det << endl;



    return 0;
}