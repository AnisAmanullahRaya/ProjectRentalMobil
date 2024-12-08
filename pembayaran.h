#ifndef PEMBAYARAN_H
#define PEMBAYARAN_H

#include <string>
#include <iostream>
using namespace std;

class Pembayaran {
private:
    string jenisPembayaran;
    string statusPembayaran;

public:
    Pembayaran(string jenis = "", string status = "Belum Lunas")
        : jenisPembayaran(jenis), statusPembayaran(status) {}

  void setJenisPembayaran(const string& jenis) {
        jenisPembayaran = jenis;
    }

    void setStatusPembayaran(const string& status) {
        statusPembayaran = status;
    }

    string getJenisPembayaran() const {
        return jenisPembayaran;
    }

    string getStatusPembayaran() const {
        return statusPembayaran;
    }

    void displayDetails() const {
        cout << "Jenis Pembayaran: " << jenisPembayaran
             << ", Status: " << statusPembayaran << endl;
    }
};
#endif // PEMBAYARAN_H
