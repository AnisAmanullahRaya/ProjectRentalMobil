#ifndef Mobil_H
#define Mobil_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Mobil {
public:
    string merek;
    string tipe;
    long int price;
    bool ketersedian;
    Mobil(string merek = "", string tipe = "", long int harga = 0, bool tersedia = false)
        :merek(merek), tipe(tipe), price(harga), ketersedian(tersedia) {}
    void setMerek(const string& m) {
        merek = m;}
    void setTipe(const string& t) {
        tipe = t;}
    void setHarga(long int h) {
        price = h;}
    void setTersedia(bool status) {
        ketersedian = status;}
    string getMerek() const {
        return merek;}
    string getTipe() const {
        return tipe;}
    long int getHarga() const {
        return price;}
    bool isTersedia() const {
        return ketersedian;}
    void displayDetails() const {
        cout << "Merek: " << merek << ", Tipe: " << tipe
             << ", Harga: " << price << ", Tersedia: " << (ketersedian ? "Ya" : "Tidak") << endl;}
    void saveToFile(const string& filename) const {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << merek << " " << tipe << " " << price << " " << (ketersedian ? "Tersedia" : "Tidak") << endl;
            file.close();
        } else {
            cout << "Error: Unable to save car data to file." << endl;
        } }};
#endif // Mobil_H
