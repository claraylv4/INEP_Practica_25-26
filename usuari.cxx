#include "usuari.hxx"
// Falta constructor default? 

// Constructor amb paràmetres
Usuari::Usuari(string sobrenom, string nom, string email, string password, int edat)
    : _sobrenom(sobrenom), _nom(nom), _email(email), _password(password), _edat(edat) {
}

// Getters
string Usuari::getSobrenom() {
    return _sobrenom;
}

string Usuari::getNom() {
    return _nom;
}

string Usuari::getEmail() {
    return _email;
}

string Usuari::getPassword() {
    return _password;
}

int Usuari::getEdat() {
    return _edat;
}

// Setters
void Usuari::set_sobrenom(string sobrenom) {
    _sobrenom = sobrenom;
}

void Usuari::set_nom(string nom) {
    _nom = nom;
}

void Usuari::set_email(string email) {
    _email = email;
}

void Usuari::set_password(string password) {
    _password = password;
}

void Usuari::set_edat(int edat) {
    _edat = edat;
}
