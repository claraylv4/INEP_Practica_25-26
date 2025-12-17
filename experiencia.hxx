// experiencia.hxx
#pragma once 

#include <odb/core.hxx>
#include <iostream>
#include <string>
using namespace std;
using namespace boost::gregorian;

class Experiencia {
    public:
    // ... 
    private: 
        friend class odb::access; 
            
        #pragma db id
        string _nomExp;
        string _descrip;
        string _ciutat; 
        int _maxPlaces; 
        float _preu; 
        date _dataAlta;
        int _numRes; 
}