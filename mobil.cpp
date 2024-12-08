#include "Mobil.h"
#include <fstream>
#include <iostream>
using namespace std;

Mobil::Mobil(string merek, string tipe, long int harga, bool tersedia)
    : merek(merek), tipe(tipe), price(harga), ketersedian(tersedia) {}

void Mobil::setMerek(const string& m) { merek = m; }
void Mobil::setTipe(const string& t) { tipe = t; }
void Mobil::setHarga(long int h) { price = h; }
void Mobil::setTersedia(bool status) { ketersedian = status; }

string Mobil::getMerek() const { return merek; }
string Mobil::getTipe() const { return tipe; }
long int Mobil::getHarga() const { return price; }
bool Mobil::isTersedia() const { return ketersedian; }

void Mobil::displayDetails() const {
    cout << "Merek: " << merek << ", Tipe: " << tipe
              << ", Harga: " << price << ", Tersedia: "
              << (ketersedian ? "Ya" : "Tidak") << endl;
}

void Mobil::saveToFile(const string& filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << merek << " " << tipe << " " << price << " "
             << (ketersedian ? "Tersedia" : "Tidak") << endl;
        file.close();
    } else {
        cout << "Error: Unable to save car data to file." << endl;
    }
}
