#include "CtrlEsborraUsuari.hxx"

void CtrlEsborraUsuari::esborraUsuari(const string& contrasenyaU){
    Usuari u = PlanGo::instancia().obteUsuari();
    if (contrasenyaU != u.getPassword()){
        throw ErrorContrasenya();
    }
    _daoUser->esborra(u.getSobrenom());
}