#include "DTOUsuari.hxx"
DTOUsuari:: DTOUsuari() {}

DTOUsuari::DTOUsuari(const string& nom, const string& sobrenom, const string& correu, int edat, int nreserves) 
    : _nom(nom), _sobrenom(sobrenom), _correu(correu), _edat(edat), _numReserves(nreserves) {}

string DTOUsuari::get_nomcomplet() const { return _nom; }

string DTOUsuari::get_username() const { return _sobrenom; }

string DTOUsuari::get_correu() const { return _correu; }
int DTOUsuari::get_edat() const { return _edat; }

int DTOUsuari::get_numReserves() const { return _numReserves; }