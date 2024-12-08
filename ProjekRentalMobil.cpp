#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>

using namespace std;

string username, password, merek, tipe, mobilbaru;
long int price;
int choice, nominal;
float x;

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


class Akun {
private:
    string username;
    string password;

public:

    Akun(string uname = "", string pass = "") : username(uname), password(pass) {}


    void setUsername(const string& uname) {
        username = uname;
    }

    void setPassword(const string& pass) {
        password = pass;
    }

    string getUsername() const {
        return username;
    }


    bool verifyPassword(const string& pass) const {
        return password == pass;
    }

    void saveToFile(const string& fileSuffix) const {
        ofstream file(username + fileSuffix + ".txt");
        if (file.is_open()) {
            file << username << endl << password;
            file.close();
        } else {
            cout << "Error: Unable to save account data to file." << endl;
        }
    }

    bool loadFromFile(const string& fileSuffix) {
        ifstream file(username + fileSuffix + ".txt");
        if (file.is_open()) {
            string uname, pass;
            getline(file, uname);
            getline(file, pass);
            file.close();
            return (username == uname && password == pass);
        }
        return false;
    }
};


class mobil {

public:
     string merek;
    string tipe;
    long int price;
    bool ketersedian;
    mobil(string merek = "", string tipe = "", long int harga = 0, bool tersedia = false)
        :merek(merek), tipe(tipe), price(harga), ketersedian(tersedia) {}


    void setMerek(const string& m) {
        merek = m;
    }

    void setTipe(const string& t) {
        tipe = t;
    }

    void setHarga(long int h) {
        price = h;
    }

    void setTersedia(bool status) {
        ketersedian = status;
    }


    string getMerek() const {
        return merek;
    }

    string getTipe() const {
        return tipe;
    }

    long int getHarga() const {
        return price;
    }

    bool isTersedia() const {
        return ketersedian;
    }


    void displayDetails() const {
        cout << "Merek: " << merek << ", Tipe: " << tipe
             << ", Harga: " << price << ", Tersedia: " << (ketersedian ? "Ya" : "Tidak") << endl;
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << merek << " " << tipe << " " << price << " " << (ketersedian ? "Tersedia" : "Tidak") << endl;
            file.close();
        } else {
            cout << "Error: Unable to save car data to file." << endl;
        }
    }
};


class Pembeli {
private:
    string nama;
    string alamat;
    string noHp;

public:

    Pembeli(string nama = "", string alamat = "", string noHp = "")
        : nama(nama), alamat(alamat), noHp(noHp) {}


    void setNama(const string& n) {
        nama = n;
    }

    void setAlamat(const string& a) {
        alamat = a;
    }

    void setNoHp(const string& no) {
        noHp = no;
    }

    string getNama() const {
        return nama;
    }

    string getAlamat() const {
        return alamat;
    }

    string getNoHp() const {
        return noHp;
    }

    void displayDetails() const {
        cout << "Nama: " << nama << ", Alamat: " << alamat << ", No HP: " << noHp << endl;
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << "Nama: " << nama << endl
                 << "Alamat: " << alamat << endl
                 << "No HP: " << noHp << endl
                 << "-------------------------------------" << endl;
            file.close();
        } else {
            cout << "Error: Unable to save buyer data to file." << endl;
        }
    }
};

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


bool Loginb()
{
    string username, passwordb, unameb, passb;
    cout << "\n-------------------------Masuk-------------------------\n";
    cout << "Masukkan Username: "; cin >> username;
    cout << "Masukkan Password: "; cin >> passwordb;
    ifstream read(username + "b.txt");
    getline(read, unameb);
    getline(read, passb);
if (username == unameb && passwordb == passb)
{
    return true;
} else {
    return false;
}
}

bool Logina()
{
    string username, passworda, unamea, passa;
    cout << "\n-------------------------Masuk-------------------------\n";
    cout << "Masukkan Username: "; cin >> username;
    cout << "Masukkan Password: "; cin >> passworda;
    ifstream read(username + "a.txt");
    getline(read, unamea);
    getline(read, passa);
if (username == unamea && passworda == passa)
{
    return true;
} else {
    return false;
}
}


long int pilihitem(){

int x;

mobil Mobil2;
    Mobil2.merek = "Toyota";
    Mobil2.tipe = "Fortuner";
    Mobil2.price = 1500000;
    Mobil2.ketersedian = true;

mobil Mobil3;
    Mobil3.merek = "Toyota";
    Mobil3.tipe = "Agya";
    Mobil3.price = 400000;
    Mobil3.ketersedian = false;

    cout << "\nPilih Item Yang Diinginkan: ";
    cin >> choice;

    if (choice == 1){
    cout << "Maaf mobil sedang tidak tersedia, mohon pilih mobil yang lain\n";
 return pilihitem();}
 else if(choice == 2){
    cout << "\nMobil Yang Anda Pilih: " << Mobil2.merek << " " << Mobil2.tipe << ", Cost = " <<  Mobil2.price << " per 12 jam" << endl;

cout << "Berapa lama anda ingin menyewa mobil ini (x * 12 jam): "; cin >> x; cout << endl;

cout << "Untuk Menyewanya Selama " << x * 12 << " jam, Total Harga =" ; cout.precision(0); cout << fixed << Mobil2.price * x << endl;
    cout << "\nIngin Membayar Dengan: " << endl;
    cout << "1.Bayar Di Tempat" << endl;
    cout << "2.Transfer Ke Rekening" << endl;
    cout << "\nPilihan Anda: ";
    cin >> choice;

    if(choice == 1){
        cout << "\nTerima kasih atas pesanan anda, Mobil anda akan segera di kirim." << endl;
    string nama, a, nohp, pembeli1;

   
    ifstream checkFile("DataPembeli.txt");
    if (!checkFile.is_open()) { 
        cout << "Masukkan Data: \n";
        cout << "Nama: ";
        cin >> nama;
        cout << "Alamat Pembeli: ";
        cin >> a;
        cout << "No Telepon: ";
        cin >> nohp;

        ofstream file("DataPembeli.txt");
        file << endl << "Nama: " << nama << endl << "Alamat: " << a << endl << "No Telpon: " << nohp << endl << "Pesanan: " << Mobil2.merek << " " << Mobil2.tipe << ", Sewa untuk " <<  x * 12 << " jam" << "(Bayar Di Tempat)" << endl;
        file.close();
    } else {  
        cout << "Masukkan Data: \n";

       
        string existingContent;
        while (getline(checkFile, pembeli1)) {
            existingContent += pembeli1 + "\n";
        }
        checkFile.close();

    
        cout << "Nama: ";
        cin >> nama;
        cout << "Alamat Pembeli: ";
        cin >> a;
        cout << "No Telpon: ";
        cin >> nohp;


        ofstream file("DataPembeli.txt", ios::app);
        file << endl << "Nama: " << nama << endl << "Alamat: " << a << endl << "No Telpon: " << nohp << endl << "Pesanan: " << Mobil2.merek << " " << Mobil2.tipe << ", Sewa untuk " <<  x * 12 << " jam" << "(Bayar Di Tempat)" << endl;
        file.close();
    };
}
        else if(choice == 2){
        string nama, a, nohp, status, pembeli1;
        int nominal;

    cout << "\nMohon transfer ke rekening berikut: 0712357612\n";
cout << "Membayar..." << endl;
cout << "Masukkan nominal untuk di transfer ke 0712357612: ";
cin >> nominal;
if(nominal == Mobil2.price * x){
cout << "Berhasil mentransfer " << nominal << " ke 0712357612" << endl;
status =  "Transfer Lunas";
}
else if(nominal != Mobil2.price * x){
    cout << "Nominal Salah, Gagal mentransfer";
    status = "Transfer Belum Lunas";
    };

        ifstream checkFile("DataPembeli.txt");
    if (!checkFile.is_open()) { 
        cout << "Masukkan Data: \n";
        cout << "Nama: ";
        cin >> nama;
        cout << "Alamat Pembeli: ";
        cin >> a;
        cout << "No Telepon: ";
        cin >> nohp;

        ofstream file("DataPembeli.txt");
        file << endl << "Nama: " << nama << endl << "Alamat: " << a << endl << "No Telpon: " << nohp << endl << "Pesanan: " << Mobil2.merek << " " << Mobil2.tipe << ", Sewa untuk " <<  x * 12 << " jam" << "(" << status << ")" << endl;
        file.close();
    } else {  
        cout << "Masukkan Data: \n";

       
        string existingContent;
        while (getline(checkFile, pembeli1)) {
            existingContent += pembeli1 + "\n";
        }
        checkFile.close();

    
        cout << "Nama: ";
        cin >> nama;
        cout << "Alamat Pembeli: ";
        cin >> a;
        cout << "No Telpon: ";
        cin >> nohp;


        ofstream file("DataPembeli.txt", ios::app);
        file << endl << "Nama: " << nama << endl << "Alamat: " << a << endl << "No Telpon: " << nohp << endl << "Pesanan: " << Mobil2.merek << " " << Mobil2.tipe << ", Sewa untuk " <<  x * 12 << " jam"<< "(" << status << ")" << endl;
        file.close();
    };
    
            
}}

else if(choice == 3){
    cout << "\nYour item: " << Mobil3.merek << " " << Mobil3.tipe << ", Cost = " <<  Mobil3.price << " per 12 jam" << endl;

    cout << "Berapa lama anda ingin menyewa mobil ini (x * 12 jam): "; cin >> x; cout << endl;
cout << "Untuk Menyewanya Selama " << x * 12 << " jam, Total Harga ="; cout.precision(0); cout << fixed << Mobil3.price * x << endl;

    cout << "\nIngin Membayar Dengan: " << endl;
    cout << "1.Bayar Di Tempat" << endl;
    cout << "2.Transfer Ke Rekening" << endl;
    cout << "\nPilihan Anda: ";
    cin >> choice;

    if(choice == 1){
        cout << "\nTerima kasih atas pesanan anda, Mobil anda akan segera di kirim." << endl;
    string nama, a, nohp, pembeli1;
 

   
    ifstream checkFile("DataPembeli.txt");
    if (!checkFile.is_open()) { 
        cout << "Masukkan Data: \n";
        cout << "Nama: ";
        cin >> nama;
        cout << "Alamat Pembeli: ";
        cin >> a;
        cout << "No Telepon: ";
        cin >> nohp;

        ofstream file("DataPembeli.txt");
        file << endl << "Nama: " << nama << endl << "Alamat: " << a << endl << "No Telpon: " << nohp << endl << "Pesanan: " << Mobil3.merek << " " << Mobil3.tipe << ", Sewa untuk " <<  x * 12 << " jam" << "(Bayar Di Tempat)" << endl;
        file.close();
    } else {  
        cout << "Masukkan Data: \n";

       
        string existingContent;
        while (getline(checkFile, pembeli1)) {
            existingContent += pembeli1 + "\n";
        }
        checkFile.close();

    
        cout << "Nama: ";
        cin >> nama;
        cout << "Alamat Pembeli: ";
        cin >> a;
        cout << "No Telpon: ";
        cin >> nohp;


        ofstream file("DataPembeli.txt", ios::app);
        file << endl << "Nama: " << nama << endl << "Alamat: " << a << endl << "No Telpon: " << nohp << endl << "Pesanan: " << Mobil3.merek << " " << Mobil3.tipe << ", Sewa untuk " <<  x * 12 << " jam" << "(Bayar Di Tempat)" << endl;
        file.close();
    };
}
        else if(choice == 2){
            string nama, a, nohp, status, pembeli1;
        int nominal;

    cout << "\nMohon transfer ke rekening berikut: 0712357612\n";
cout << "Membayar..." << endl;
cout << "Masukkan nominal untuk di transfer ke 0712357612: ";
cin >> nominal;
if(nominal == Mobil3.price * x){
cout << "Berhasil mentransfer " << nominal << " ke 0712357612" << endl;
status =  "Transfer Lunas";
}
else if(nominal != Mobil3.price * x){
    cout << "Nominal Salah, Gagal mentransfer";
    status = "Transfer Belum Lunas";
    };

        ifstream checkFile("DataPembeli.txt");
    if (!checkFile.is_open()) { 
        cout << "Masukkan Data: \n";
        cout << "Nama: ";
        cin >> nama;
        cout << "Alamat Pembeli: ";
        cin >> a;
        cout << "No Telepon: ";
        cin >> nohp;

        ofstream file("DataPembeli.txt");
        file << endl << "Nama: " << nama << endl << "Alamat: " << a << endl << "No Telpon: " << nohp << endl << "Pesanan: " << Mobil3.merek << " " << Mobil3.tipe << ", Sewa untuk " <<  x * 12 << " jam" << "(" << status << ")" << endl;
        file.close();
    } else {  
        cout << "Masukkan Data: \n";

       
        string existingContent;
        while (getline(checkFile, pembeli1)) {
            existingContent += pembeli1 + "\n";
        }
        checkFile.close();

    
        cout << "Nama: ";
        cin >> nama;
        cout << "Alamat Pembeli: ";
        cin >> a;
        cout << "No Telpon: ";
        cin >> nohp;


        ofstream file("DataPembeli.txt", ios::app);
        file << endl << "Nama: " << nama << endl << "Alamat: " << a << endl << "No Telpon: " << nohp << endl << "Pesanan: " << Mobil3.merek << " " << Mobil3.tipe << ", Sewa untuk " <<  x * 12 << " jam"<< "(" << status << ")" << endl;
        file.close();
    };


}
}
else if(choice > 3){
    int nomorBaris;
    string namaFile = "Mobilbaru.txt";
nomorBaris = choice - 3;

{ifstream file("Mobilbaru.txt");
    if (!file.is_open()) {
        cout << "Error: File tidak dapat dibuka!" << endl;
       
    }

    string baris;
    int counter = 1;

    while (getline(file, baris)) {
        if (counter == nomorBaris) {
            cout << "Mobil Yang Anda Pilih: " << baris << " per 12 jam" << endl;


break; // Hentikan setelah baris ditemukan           
        }
        counter++;
    }

    if (counter < nomorBaris) {
        cout << "ERROR";
    }
{ifstream file("Mobilbaru.txt");
if (!file.is_open()) {
    cout << "ERROR: Tidak dapat membuka file!" << endl;
    return 1;
}

string line;
int targetRow = nomorBaris;    // Baris yang ingin diambil
int targetColumn = 4;          // Kolom yang ingin diambil
int currentRow = 0;            // Penghitung baris
string result = "";            // Untuk menyimpan hasil dalam bentuk string

while (getline(file, line)) {
    currentRow++;              // Tambahkan penghitung baris

    if (currentRow == targetRow) { // Jika baris saat ini adalah baris target
        stringstream ss(line);
        string value;
        int currentColumn = 0; // Penghitung kolom

        while (getline(ss, value, ' ')) {
            currentColumn++;   // Tambahkan penghitung kolom

            if (currentColumn == targetColumn) { // Jika kolom saat ini adalah kolom target
                result = value;
                break;
            }
        }
        break; // Berhenti setelah menemukan baris yang diinginkan
    }
}

file.close();
if (!result.empty()) {
    try {
        int numericValue = stoi(result);
        int j = numericValue;
        cout << "Nilai j: " << j << endl;

cout << "Berapa lama anda ingin menyewa mobil ini (x * 12 jam): "; cin >> x; cout << endl;
cout << "Untuk menyewanya selama " << x * 12 << " jam, Total harga ="; cout.precision(0); cout << fixed << j * x << endl;

    cout << "\nIngin membayar dengan: " << endl;
    cout << "1.Bayar Di Tempat" << endl;
    cout << "2.Transfer Rekening" << endl;
    cout << "\nPilihan anda: ";
    cin >> choice;

    if(choice == 1){
        cout << "\nTerima Kasih Atas Pesanannya, Mobil Anda Akan Segera Dikirim" << endl;
    string nama, a, nohp, pembeli1;
    ifstream checkFile("DataPembeli.txt");
    if (!checkFile.is_open()) { 
        cout << "Masukkan Data: \n";
        cout << "Nama: ";
        cin >> nama;
        cout << "Alamat Pembeli: ";
        cin >> a;
        cout << "No Telepon: ";
        cin >> nohp;

        ofstream file("DataPembeli.txt");
        file << endl << "Nama: " << nama << endl << "Alamat: " << a << endl << "No Telpon: " << nohp << endl << "Pesanan: " << baris << ", Sewa untuk " <<  x * 12 << " jam" << "(Bayar Di Tempat)" << endl;
        file.close();
    } else {  
        cout << "Masukkan Data: \n";

       
        string existingContent;
        while (getline(checkFile, pembeli1)) {
            existingContent += pembeli1 + "\n";
        }
        checkFile.close();
    
        cout << "Nama: ";
        cin >> nama;
        cout << "Alamat Pembeli: ";
        cin >> a;
        cout << "No Telpon: ";
        cin >> nohp;

        ofstream file("DataPembeli.txt", ios::app);
        file << endl << "Nama: " << nama << endl << "Alamat: " << a << endl << "No Telpon: " << nohp << endl << "Pesanan: " << baris << ", Sewa untuk " <<  x * 12 << " jam" << "(Bayar Di Tempat)" << endl;
        file.close();
    };
}
        else if(choice == 2){
            string nama, a, nohp, status, pembeli1;
        int nominal;

    cout << "\nMohon Transfer ke Rekening Berikut: 0712357612\n";
cout << "Membayar..." << endl;
cout << "Masukkan nominal untuk di transfer ke 0712357612: ";
cin >> nominal;
if(nominal == j * x){
cout << "Berhasil mentransfer " << nominal << " ke 0712357612" << endl;
status =  "Transfer Lunas";
}
else if(nominal != j * x){
    cout << "Nominal Salah, Gagal mentransfer";
    status = "Transfer Belum Lunas";
    };

        ifstream checkFile("DataPembeli.txt");
    if (!checkFile.is_open()) { 
        cout << "Masukkan Data: \n";
        cout << "Nama: ";
        cin >> nama;
        cout << "Alamat Pembeli: ";
        cin >> a;
        cout << "No Telepon: ";
        cin >> nohp;

        ofstream file("DataPembeli.txt");
        file << endl << "Nama: " << nama << endl << "Alamat: " << a << endl << "No Telpon: " << nohp << endl << "Pesanan: " << baris << ", Sewa untuk " <<  x * 12 << " jam" << "(" << status << ")" << endl;
        file.close();
    } else {  
        cout << "Masukkan Data: \n";

       
        string existingContent;
        while (getline(checkFile, pembeli1)) {
            existingContent += pembeli1 + "\n";
        }
        checkFile.close();
    
        cout << "Nama: ";
        cin >> nama;
        cout << "Alamat Pembeli: ";
        cin >> a;
        cout << "No Telpon: ";
        cin >> nohp;

        ofstream file("DataPembeli.txt", ios::app);
        file << endl << "Nama: " << nama << endl << "Alamat: " << a << endl << "No Telpon: " << nohp << endl << "Pesanan: " << baris << ", Sewa untuk " <<  x * 12 << " jam"<< "(" << status << ")" << endl;
        file.close();
    };
}        
    } catch (const invalid_argument& e) {
        cout << "Error: Data tidak dapat dikonversi ke integer." << endl;
    } catch (const out_of_range& e) {
        cout << "Error: Data terlalu besar untuk tipe integer." << endl;
    }
} else {
    cout << "Data tidak ditemukan (baris atau kolom melebihi batas)." << endl;
}    }        }            }                }

int main(){

    int Choise;

mobil Mobil1;
    Mobil1.merek = "Toyota";
    Mobil1.tipe = "Avanza";
    Mobil1.price = 500000;
    Mobil1.ketersedian = false;

mobil Mobil2;
    Mobil2.merek = "Toyota";
    Mobil2.tipe = "Fortuner";
    Mobil2.price = 1500000;
    Mobil2.ketersedian = true;

mobil Mobil3;
    Mobil3.merek = "Toyota";
    Mobil3.tipe = "Agya";
    Mobil3.price = 400000;
    Mobil3.ketersedian = true;

    cout << "Pilih Halaman\n";
    cout << "1.Daftar Sebagai Pembeli\n";
    cout << "2.Daftar Sebagai Admin\n";
    cout << "3.Masuk Sebagai Pembeli\n";
    cout << "4.Masuk Sebagai Admin\n";
    cout << "Pilihan Anda: ";
    cin >> Choise;

if(Choise == 1) {
    string username, passwordb, address, phonenumber;
    cout << "\n-----Tolong Daftar Akun Baru-----\n";
    cout << "Buat Username: ";
    cin >> username;
    cout << "Buat Password: ";
    cin >> passwordb;
    ofstream file;
    file.open(username + "b.txt");
    file << username << endl << passwordb;
    file.close();
    main();
}

    else if(Choise == 2) {
    string username, passworda;
    cout << "\n-----Tolong Daftar Akun Baru-----\n";
    cout << "Buat Username: ";
    cin >> username;
    cout << "Buat Password: ";
    cin >> passworda;
    ofstream file;
    file.open(username + "a.txt");
    file << username << endl << passworda;
    file.close();
    main();
}

else if (Choise == 3) {
    bool status = Loginb();
    while (!status) { // Loop hingga login berhasil
        string username, passwordb, unameb, passb;
        cout << "Maaf username atau password salah, tolong ulangi sekali lagi.\n";
        cout << "\n-------------------------Masuk-------------------------\n";
        cout << "Masukkan Username: "; cin >> username;
        cout << "Masukkan Password: "; cin >> passwordb;

        ifstream read(username + "b.txt");
        if (read.is_open()) {
            getline(read, unameb);
            getline(read, passb);
            read.close();
        }
        if (username == unameb && passwordb == passb) {
            cout << "\n           ----Berhasil Masuk----\n";
            status = true; // Berhasil login, keluar dari loop
        } else {
            cout << " \n";
        }
    }

    cout << "Pilih Halaman: " << endl;
    cout << "1. Daftar Mobil" << endl;
    cout << "2. Kembalikan Mobil" << endl;
    cout << "Pilihan Anda: ";
    cin >> Choise;

    if (Choise == 1) {
        cout << "\n       ---------Daftar Item---------\n" << endl;
        cout << "1. " << Mobil1.merek << " " << Mobil1.tipe << " = " << Mobil1.price << " per 12 jam" << endl;
        cout << "2. " << Mobil2.merek << " " << Mobil2.tipe << " = " << Mobil2.price << " per 12 jam" << endl;
        cout << "3. " << Mobil3.merek << " " << Mobil3.tipe << " = " << Mobil3.price << " per 12 jam" << endl;

        ifstream file("Mobilbaru.txt");
        if (!file.is_open()) {
            cout << " " << endl;
        } else {
            string line;
            int count = 4;
            while (getline(file, line)) {
                cout << count++ << ". " << line << " per 12 jam" << endl;
            }
            file.close();}

pilihitem();
    }
    else if(Choise == 2){
        
        cout << "\nMobil yang ingin di kembalikan:\n";
    cout << "\n" << "1." << Mobil1.merek << " " << Mobil1.tipe << endl;
    cout << "2." << Mobil2.merek << " " << Mobil2.tipe << endl;
    cout << "3." << Mobil3.merek << " " << Mobil3.tipe << endl;
     ifstream file("Mobilbaru.txt");
        if (!file.is_open()) {
            cout << " " << endl;
        } else {
            string line;
            int count = 4;
            while (getline(file, line)) {
                cout << count++ << "." << line << endl;
            }
            file.close();}
    cout << "\nIngin mengembalikan mobil nomor: ";
    cin >> Choise;
    if(Choise == 1){
        cout << "Berhasil mengembalikan " << Mobil1.merek << " " << Mobil1.tipe;
    }
    else if(Choise == 2){
        cout << "Berhasil mengembalikan " << Mobil2.merek << " " << Mobil2.tipe;
    }
    else if(Choise == 3){
        cout << "Berhasil mengembalikan " << Mobil3.merek << " " << Mobil3.tipe;
    }
    else if(Choise > 3){
        int nomorBaris;
    string namaFile = "Mobilbaru.txt";
nomorBaris = Choise - 3;
{ifstream file("Mobilbaru.txt");
    if (!file.is_open()) {
        cout << "Error: File tidak dapat dibuka!" << endl;
       
    }

    string baris;
    int counter = 1;

    while (getline(file, baris)) {
        if (counter == nomorBaris) {
            cout << "Berhasil mengembalikan " << baris << endl;


break; // Hentikan setelah baris ditemukan           
        }
        counter++;
    }

    if (counter < nomorBaris) {
        cout << "ERROR";
    }
    }
    }
        
}}

    else if (Choise == 4){
        bool status = Logina();
    while (!status) { // Loop hingga login berhasil
        string username, passworda, unamea, passa;
        cout << "Maaf username atau password salah, tolong ulangi sekali lagi.\n";
        cout << "\n-------------------------Masuk-------------------------\n";
        cout << "Masukkan Username: "; cin >> username;
        cout << "Masukkan Password: "; cin >> passworda;

        ifstream read(username + "a.txt");
        if (read.is_open()) {
            getline(read, unamea);
            getline(read, passa);
            read.close();
        }
        if (username == unamea && passworda == passa) {
            cout << "\n           ----Berhasil Masuk----\n";
            status = true; // Berhasil login, keluar dari loop
        } else {
            cout << " \n";
        }    }

    cout << "\n-----------------Berhasil Masuk-----------------" << endl;
    cout << "Pilih Halaman: " << endl;
       cout << "1.Lihat Data Pembeli\n";
       cout << "2.Tambah Mobil" << endl;
    cout << "Pilihan Anda: ";
    cin >> Choise;cout << endl;
    
if(Choise == 1)
    {
        cout << "\nDaftar Pembeli:\n";
    ifstream readFile("DataPembeli.txt");
    string line;
    while (getline(readFile, line)) {
        cout << line << endl;
    }
    readFile.close();

    return 0;
    }

else if(Choise ==2){
string merk, tipe, mobil1, mobil2;
    long int prices;

    ifstream checkFile("Mobilbaru.txt");
    if (!checkFile.is_open()) {
        cout << "File belum ada. Membuat file baru\n";

        cout << "Merek: ";
        cin >> merk;
        cout << "Tipe: ";
        cin >> tipe;
        cout << "Harga: ";
        cin >> prices;

        ofstream file("Mobilbaru.txt");
        file << merk << " " << tipe << " = " << prices << endl;
        file.close();
    } else {
        cout << "File ditemukan. Menambahkan data ke dalam file\n";

        string existingContent;
        while (getline(checkFile, mobil1)) {
            existingContent += mobil1 + "\n";
        }
        checkFile.close();

        cout << "Merek: ";
        cin >> merk;
        cout << "Tipe: ";
        cin >> tipe;
        cout << "Harga: ";
        cin >> prices;

        ofstream file("Mobilbaru.txt", ios::app);
        file << merk << " " << tipe << " = " << prices << endl;
        file.close();
    }

    cout << "\nDaftar Mobil Yang Sudah Di Tambahkan:\n";
    ifstream readFile("Mobilbaru.txt");
    string line;
    while (getline(readFile, line)) {
        cout << line << endl;
    }
    readFile.close();

    return 0;
}   }   }
