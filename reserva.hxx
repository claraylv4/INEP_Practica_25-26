// reserva.hxx
#pragma once

#include <odb/core.hxx>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;
using namespace std;

class Reserva {
public:
  Reserva() = default;

  Reserva(int id, date data, int numPlaces, float preuPagat);
  // Getters
  // ...
  // Setters
  // ...

private:
  friend class odb::access;

  #pragma db id // Anotacio per indicar que l'atribut és clau primària
  int _id;

  date _dataRes; 
  int _numPlaces;
  float _preuPagat;
};