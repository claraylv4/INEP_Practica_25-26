
// CtrlEsborraUsuari.hxx
#pragma once
#include <string>
#include "DAOUsuari.hxx"
#include "planGo.hxx"
#include "errors.hxx"
#include "usuari.hxx"

class CtrlEsborraUsuari {
public:
    explicit CtrlEsborraUsuari(DAOUsuari* dao) : _daoUser(dao) {}
    // retorna true si s'esborra; false si no s'ha confirmat (S)
    void esborraUsuari(const string& contrasenyaU);

private:
    DAOUsuari* _daoUser; // injectat
};
