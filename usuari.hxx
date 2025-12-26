// usuari.hxx
#pragma once
#include <iostream>
#include <string>
#include <vector> 
#include <odb/core.hxx>

#include "DTOUsuari.hxx"
#include "reserva.hxx"
using namespace std;

class Usuari {
public:
  // Constructor
  Usuari() = default;
  // Constructor per còpia
  Usuari(string _sobrenom, string _nom, string _email, string _password,
         int _edat);
  
  // Per CtrlConsultaUsuari
  DTOUsuari obteInfo(); 
  // getters
  string getSobrenom(); 
  string getNom();      
  string getEmail();
  string getPassword();
  int getEdat();
  vector<Reserva> getReserves();
  // setters
  void set_sobrenom(string sobrenom);
  void set_nom(string nom);
  void set_email(string email);
  void set_password(string password);
  void set_edat(int edat);

private:
  friend class odb::access;

  #pragma db id       // Anotacio per indicar que l'atribut és clau primària
  string _sobrenom; 
  
  string _nom;      
  
  #pragma db unique
  string _email;
  
  string _password;

  int _edat;

  vector<Reserva> _reserves;
};