#pragma once

#include "usuari.hxx"

class PlanGo {
public:
    static PlanGo& instancia();

    Usuari obteUsuari();  // usuari loggejat

private:
    PlanGo() {}
    Usuari _usuariActual;
};
