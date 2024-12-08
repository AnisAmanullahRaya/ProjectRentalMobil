#ifndef Admin_H
#define Admin_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Admin {
private:
    string nama;
    string noHp;
public:
    Admin(string nama = "", string noHp = "")
        : nama(nama), noHp(noHp) {}
    void setNama(const string& n) {
        nama = n;}
    void setNoHp(const string& no) {
        noHp = no;}
    string getNama() const {
        return nama;}
    string getNoHp() const {
        return noHp;}
    void displayDetails() const {
        cout << "Nama: " << nama << ", No HP: " << noHp << endl;}
    void saveToFile(const string& filename) const {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << "Nama: " << nama << endl
                 << "No HP: " << noHp << endl
                 << "-------------------------------------" << endl;
            file.close();
        } else {
            cout << "Error: Unable to save admin data to file." << endl;}}};
#endif // Admin_H
