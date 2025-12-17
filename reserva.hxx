// reserva.hxx
#pragma once

#include <iostream> 
#include <string>

#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

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

        date _dataRes; // Fer classe data? 
        int _numPlaces;
        float _preuPagat; 
};