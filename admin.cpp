#include "Admin.h"
#include <fstream>
#include <iostream>
using namespace std;
Admin::Admin(string nama, string noHp)
    : nama(nama), noHp(noHp) {}

void Admin::setNama(const string& n) {
    nama = n;
}

void Admin::setNoHp(const string& no) {
    noHp = no;
}

string Admin::getNama() const {
    return nama;
}

string Admin::getNoHp() const {
    return noHp;
}

void Admin::displayDetails() const {
    cout << "Nama: " << nama << ", No HP: " << noHp << endl;
