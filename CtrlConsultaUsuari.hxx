// CtrlConsultaUsuari.hxx
#pragma once
#include <string>

#include "DAOUsuari.hxx"
#include "DTOUsuari.hxx"
#include "planGo.hxx"

using namespace std; 

class CtrlConsultaUsuari {
    public:
        explicit CtrlConsultaUsuari(DAOUsuari *dao);
        DTOUsuari consultaUsuari();
    private:
        DAOUsuari *_daoUser;
        string _usernamelogged;
};
