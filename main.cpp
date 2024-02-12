Zadanie 1
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string haslo[200]; // To jest tablica przechowująca hasła

int policzHaslaNumeryczne() {
    int licznik = 0;
    for (int i = 0; i < 200; ++i) {
        bool tylkoCyfry = true;
        for (char znak : haslo[i]) {
            if (!isdigit(znak)) { // Sprawdza, czy znak nie jest cyfrą
                tylkoCyfry = false;
                break; //
            }
        }
        if (tylkoCyfry) {
            licznik++;
        }
    }
    return licznik;
}

void wczytajHasla() {
    ifstream plik("hasla.txt"); // Otwiera plik do odczytu

    if (!plik.good()) {
        cout << "Nie udalo sie otworzyc pliku hasla.txt!" << endl;
        return;
    }

    for (int i = 0; i < 200; ++i) {
        getline(plik, haslo[i]); // Wczytuje każde hasło do tablicy
    }

    plik.close(); // Zamyka plik
}

int main() {
    wczytajHasla(); // Wczytuje hasła z pliku
    cout << "Liczba haseł zlozonych jedynie ze znakow numerycznych: " << policzHaslaNumeryczne() << endl;
    return 0;
}
..............................................................................................................................................................................................................................
    Zadanie 2
