// categoria.hxx
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
        string _nomCat; 
}