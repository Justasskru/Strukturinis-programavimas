#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct menuItemType {
    string menuItem;   // patiekalo pavadinimas
    double menuPrice;  // kaina
};

const int MAX_ITEMS = 20;

// Nuskaito meniu duomenis iš failo menu.txt
int getData(menuItemType menuList[]) {
    ifstream file("menu.txt");
    if (!file.is_open()) {
        cerr << "Failas neatsidaro" << endl;
        return 0;
    }


    int count = 0;
    while (!file.eof() && count < MAX_ITEMS) {
        getline(file, menuList[count].menuItem);
        file >> menuList[count].menuPrice;
        file.ignore();
        count++;
    }

    file.close();
    return count;
}

// Išveda meniu
void showMenu(menuItemType menuList[], int count) {
    cout << "Pusryciu meniu:"<<endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". "<< menuList[i].menuItem<<"   "<< fixed << setprecision(2) << menuList[i].menuPrice << "e" << endl;
    }
    cout << endl;
}

// Išveda sąskaitą ir įrašo į receipt.txt
void printCheck(menuItemType menuList[], int count, int quantities[]) {
    double subtotal = 0;

    ofstream receipt("receipt.txt");
    receipt << fixed << setprecision(2);
    cout << fixed << setprecision(2);

    cout << "--- Sąskaita ---" << endl;
    receipt << "Saskaita"<<endl;

    for (int i = 0; i < count; i++) {
        if (quantities[i] > 0) {
            double itemTotal = menuList[i].menuPrice * quantities[i];
            subtotal += itemTotal;

            cout << quantities[i] << " x "<< menuList[i].menuItem <<"  "<< itemTotal << "e" << endl;

            receipt << quantities[i] << " x "<< menuList[i].menuItem <<"  "<< itemTotal << "e" << endl;
        }
    }

    double tax = subtotal * 0.21;
    double total = subtotal + tax;
cout<<endl;
    cout << "Mokesčiai (21%)" <<"  "<< tax << "e" << endl;
    cout << "Galutinė suma" <<"  "<< total << "e" << endl;

    receipt << "Mokesčiai (21%)" <<"  "<< tax << "e" << endl;
    receipt << "Galutinė suma" <<"  "<< total << "e" << endl;

    receipt.close();
}

//----------------------------------------------
// MAIN – programos pradinė dalis
//----------------------------------------------
int main() {
    menuItemType menuList[MAX_ITEMS];
    int itemCount = getData(menuList);



    int quantities[MAX_ITEMS] = {0};

    cout << "Sveiki atvykę į restoraną" << endl;

    showMenu(menuList, itemCount);

    cout << "Pasirinkite patiekalus (iveskite numerį, 0 - pabaiga)"<<endl;

    while (true) {
        int choice;
        cout << "Patiekalas Nr.: ";
        cin >> choice;

        if (choice == 0) break;
        if (choice < 1 || choice > itemCount) {
            cout << "Neteisingas pasirinkimas!" << endl;
            continue;
        }

        int qty;
        cout << "Kiek porciju? ";
        cin >> qty;

        if (qty < 1) {
            cout << "Neteisingas kiekis!" << endl;
            continue;
        }

        quantities[choice - 1] += qty;
        cout << "Prideta!"<<endl;
    }

    printCheck(menuList, itemCount, quantities);

    return 0;
}