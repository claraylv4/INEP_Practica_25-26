// DTOUsuari.hxx
#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>

using namespace std;
using namespace boost::gregorian;

class DTOUsuari {
public:
  // Constructora per defecte 
  DTOUsuari();
  
  // Constructor que rep tots els camps directament
  DTOUsuari(const string& nom,
            const string& sobrenom,
            const string& correu,
            int edat,
            int nreserves);

  // getters 
  string get_username() const;
  string get_nomcomplet() const;
  string get_correu() const;
  int get_numReserves() const;
  int get_edat() const;
private:
  string _nom;
  string _sobrenom;
  string _correu;
  int _edat;
  int _numReserves;
};