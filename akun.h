#ifndef AKUN_H
#define AKUN_H
#include <string>
#include <fstream>
#include <iostream>
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

#endif // AKUN_H
