// DTOUsuari.hxx
#pragma once

#include "usuari.hxx"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>

using namespace boost::gregorian;
class DTOUsuari {
public:
  DTOUsuari() {}
  // constructora que rep un objecte usuari
  DTOUsuari(Usuari &u);
  string get_username();
  string get_nomcomplet();
  string get_correu();
  int get_numReserves();
  date get_edat();

private:
  string _nom;
  string _sobrenom;
  string _correu;
  int _edat;
  int _numReserves;
};