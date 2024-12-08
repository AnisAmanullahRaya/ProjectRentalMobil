#include "Akun.h"
using namespace std;
Akun::Akun(string uname, string pass) : username(uname), password(pass) {}

void Akun::setUsername(const string& uname) { username = uname; }
void Akun::setPassword(const string& pass) { password = pass; }

string Akun::getUsername() const { return username; }
bool Akun::verifyPassword(const string& pass) const { return password == pass; }

void Akun::saveToFile(const string& fileSuffix) const {
    ofstream file(username + fileSuffix + ".txt");
    if (file.is_open()) {
        file << username << endl << password;
        file.close();
    }
}

bool Akun::loadFromFile(const string& fileSuffix) {
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
