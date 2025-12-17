// usuari.hxx
#pragma once 

#include <odb/core.hxx>
#include <iostream>
#include <string>
using namespace std;
using namespace boost::gregorian;

class Usuari {
    public: 
        // Constructor 
        Usuari () = default;
        // Constructor per còpia 
        Usuari(string _sobrenom, string _nom, string _email, string _password, int _edat);
        // getters 
        string getSobrenom(); // getUsername?
        string getNom(); // getNomComplet?
        string getEmail(); 
        string getPassword(); 
        int getEdat(); 
        // setters 
        void set_sobrenom(string sobrenom); 
        void set_nom(string nom);
        void set_email(string email);
        void set_password(string password); 
        void set_edat(int edat); 
    private: 
        friend class odb::access; 

        #pragma db id // Anotacio per indicar que l'atribut és clau primària
        string _sobrenom; // username? 
        string _nom; // nom complet?
        string _email; 
        string _password; 
        int _edat; 

}; 