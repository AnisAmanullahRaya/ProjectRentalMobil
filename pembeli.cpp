#include "pembeli.h"

using namespace std;

Pembeli::Pembeli(string nama, string alamat, string noHp)
    : nama(nama), alamat(alamat), noHp(noHp) {}

void Pembeli::setNama(const string& n) { nama = n; }
void Pembeli::setAlamat(const string& a) { alamat = a; }
void Pembeli::setNoHp(const string& no) { noHp = no; }

string Pembeli::getNama() const { return nama; }
string Pembeli::getAlamat() const { return alamat; }
string Pembeli::getNoHp() const { return noHp; }

void Pembeli::displayDetails() const {
    cout << "Nama: " << nama << ", Alamat: " << alamat << ", No HP: " << noHp << endl;
}
