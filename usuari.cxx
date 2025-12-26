#include "usuari.hxx"
#include "errors.hxx"

// Constructor amb paràmetres
Usuari::Usuari(string sobrenom, string nom, string email, string password, int edat)
    : _sobrenom(sobrenom), _nom(nom), _email(email), _password(password), _edat(edat) {
}

// Per CtrlConsultaUsuari
DTOUsuari Usuari::obteInfo() {
    // Implementació pendent segons necessitats
    return DTOUsuari(_nom, _sobrenom, _email, _edat, _reserves.size());
    // nom, sobrenom, correu, edat, numReserves
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

vector<Reserva> Usuari::getReserves() {
    return _reserves;
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
    if (edat < 18) throw ModMenorEdat(); // #pragma db check dona problemes
    _edat = edat;
}
