// errors.hxx 
// Struct ho fa més senzill, els errors no tenen atributs per tant no cal que siguin classes 
#pragma once

#include <stdexcept>
#include <string>

/* ----- Errors de registre d'usuari ----- */ 
struct SobrenomExisteix : public std::runtime_error {
    SobrenomExisteix() : std::runtime_error("Ja existeix un usuari amb aquest sobrenom") {}
};

struct CorreuExisteix : public std::runtime_error {
    CorreuExisteix() : std::runtime_error("Ja existeix un usuari amb aquest correu electrònic") {}
};

struct MenorEdat : public std::runtime_error {
    MenorEdat() : std::runtime_error("No es pot registrar un menor") {}
};

/* ----- Errors de modificació d'usuari ----- */

// SobrenomExisteix serà el mateix que a registre d'usuari 

struct ModCorreuExisteix : public std::runtime_error {
    ModCorreuExisteix() : std::runtime_error("El nou correu electrònic ja existeix") {}
};

struct ModMenorEdat : public std::runtime_error {
    ModMenorEdat() : std::runtime_error("No es poden registrar usuaris menors") {}
};

/* ----- Errors  de esborrar usuari ----- */
struct ErrorContrasenya : public std::runtime_error {
    ErrorContrasenya() : std::runtime_error("La contrasenya no es correcta, l'usuari no s'ha esborrat") {}
};