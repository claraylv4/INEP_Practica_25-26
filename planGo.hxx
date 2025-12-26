#pragma once

#include "usuari.hxx"

class PlanGo {
public:
    static PlanGo& instancia();

    Usuari obteUsuari() const;  // usuari loggejat

private:
    PlanGo() {}
    Usuari _usuariActual;
};
