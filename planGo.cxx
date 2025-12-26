#include "PlanGo.hxx"

PlanGo& PlanGo::instancia() {
    static PlanGo instanciaUnica;
    return instanciaUnica;
}

Usuari PlanGo::obteUsuari() const {
    // Pre: existeix un usuari loggejat
    return _usuariActual;
}
/* ESBORRAR AL FINAL SI ESO
Usuari PlanGo::obteUsuari() {
    // 1. Llegim l’usuari de la base de dades
    Usuari u = _daoUser->llegirUsuari(_sobrenomActual);

    // 2. Llegim totes les reserves d’aquest usuari
    vector<Reserva> reserves = _daoReserva->llegirReserves(u.getSobrenom());

    // 3. Omplim el vector de reserves de l’usuari
    u.setReserves(reserves);

    // 4. Retornem l’usuari complet
    return u;
}*/
