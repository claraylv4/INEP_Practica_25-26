// CtrlConsultaUsuari.cxx
#include "CtrlConsultaUsuari.hxx"
#include "planGo.hxx"
#include <string>

CtrlConsultaUsuari::CtrlConsultaUsuari(DAOUsuari *dao)
    : _daoUser(dao) {}

DTOUsuari CtrlConsultaUsuari::consultaUsuari() {
    // 1. Obtenir l'usuari loggejat des del singleton
    Usuari u = PlanGo::instancia().obteUsuari();
    // 2. Construir el DTO a partir del model
    return u.obteInfo();
}