#ifndef PEMBELI_H
#define PEMBELI_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Pembeli {
private:
    string nama;
    string alamat;
    string noHp;
public:
    Pembeli(string nama = "", string alamat = "", string noHp = "")
        : nama(nama), alamat(alamat), noHp(noHp) {}
    void setNama(const string& n) {
        nama = n;}
    void setAlamat(const string& a) {
        alamat = a;}
    void setNoHp(const string& no) {
        noHp = no;}
    string getNama() const {
        return nama;}
    string getAlamat() const {
        return alamat;}
    string getNoHp() const {
        return noHp;}
    void displayDetails() const {
        cout << "Nama: " << nama << ", Alamat: " << alamat << ", No HP: " << noHp << endl;}
    void saveToFile(const string& filename) const {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << "Nama: " << nama << endl
                 << "Alamat: " << alamat << endl
                 << "No HP: " << noHp << endl
                 << "-------------------------------------" << endl;
            file.close();
        } else {
            cout << "Error: Unable to save buyer data to file." << endl;}}};
#endif // PEMBELI_H
