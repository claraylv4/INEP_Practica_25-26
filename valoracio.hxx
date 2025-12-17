// valoracio.hxx
#pragma once 

#include <odb/core.hxx>
#include <iostream>
#include <string>
using namespace std;
using namespace boost::gregorian;


class Valoracio {
    public: 
        // ...
    private: 
        friend class odb::access; 
            
        #pragma db id
        int _id;
        int _puntuacio;
        string _comentari; // [0..1]
        date _dataVal; 
}


