#include "PlanGo.hxx"

PlanGo& PlanGo::instancia() {
    static PlanGo instanciaUnica;
    return instanciaUnica;
}

Usuari PlanGo::obteUsuari() {
    // Pre: existeix un usuari loggejat
    return _usuariActual;
}
