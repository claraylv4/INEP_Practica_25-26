//CapaDePresentacio.hxx
#pragma once
#include <iostream>
#include <string>
using namespace std;

class CapaDePresentacio
{
    public:
        // Patró Solter
        static CapaDePresentacio& getInstance() {
            static CapaDePresentacio instance;
            return instance;
        }
        // Operacions de presentació (només cin/cout)
        void registrarUsuari();
        void consultaUsuari(); 
    private:
    //constructor de la classe
    CapaDePresentacio() = default;
};