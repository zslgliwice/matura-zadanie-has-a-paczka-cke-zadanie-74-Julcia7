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
#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int main() {
    ifstream plik("hasla.txt");
    if (!plik.good()) {
        cout << "Nie udalo sie otworzyc pliku hasla.txt" << endl;
        return 1;
    }

    set<string> hasla;
    set<string> powtorzenia;
    string haslo;

    while (getline(plik, haslo)) {
        if (!hasla.insert(haslo).second) {
            powtorzenia.insert(haslo);
        }
    }
    plik.close();

    if (powtorzenia.empty()) {
        cout << "W pliku nie ma żadnych powtorzen." << endl;
    } else {
        cout << "Hasla uzyte przez co najmniej dwoch uzytkownikow:" << endl;
        for (const auto &powtorzenie : powtorzenia) {
            cout << powtorzenie << endl;
        }
    }
    return 0;
}
.............................................................................................................................................................................................................................
    Zadanie 3
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

bool maCzteryKolejneZnakiASCII(const string &haslo) {
    for (int i = 0; i < haslo.length() - 3; ++i) {
        if (isalnum(haslo[i]) && isalnum(haslo[i + 1]) &&
            isalnum(haslo[i + 2]) && isalnum(haslo[i + 3])) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream plik("hasla.txt");
    if (!plik) {
        cout << "Blad otwierania pliku hasla.txt!" << endl;
        return 1;
    }

    int liczbaUzytkownikow = 0;
    string haslo;
    while (getline(plik, haslo)) {
        if (maCzteryKolejneZnakiASCII(haslo)) {
            liczbaUzytkownikow++;
        }
    }
    plik.close();

    cout << "Liczba uzytkownikow posiadajacych hasla z czterema kolejnymi znakami ASCII: " << liczbaUzytkownikow << endl;

    return 0;
}
............................................................................................................................................................................................................................
    Zadanie 4




    
