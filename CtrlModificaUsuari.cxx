#include "CtrlModificaUsuari.hxx"
#include "DAOUsuari.hxx"
#include "planGo.hxx"

DTOUsuari CtrlModificaUsuari::modificaUsuari(string nomU, string correuU, int edatU) {
    // 1) Usuari actiu
    Usuari u = PlanGo::instancia().obteUsuari();

    // 2) Calcular nous valors
    const string nouNom    = !nomU.empty()    ? nomU    : u.getNom();
    const string nouCorreu = !correuU.empty() ? correuU : u.getEmail();
    const int         novaEdat  = (edatU != -1)    ? edatU   : u.getEdat();

    // 3) Validació només si es demana canvi d'edat
    if (edatU != -1 && novaEdat < 18)
        throw ModMenorEdat();

    // 4) Aplicar canvis selectivament
    bool hiHaCanvis = false;
    if (nouNom    != u.getNom())   { u.set_nom(nouNom);       hiHaCanvis = true; }
    if (nouCorreu != u.getEmail()) { u.set_email(nouCorreu);  hiHaCanvis = true; }
    if (novaEdat  != u.getEdat())  { u.set_edat(novaEdat);    hiHaCanvis = true; }

    // 5) Persistència via _daoUser (la dependència injectada)
    if (hiHaCanvis) {
        try {
            _daoUser->modifica(u);
        } catch (const odb::exception&) {
            // viola el unique(_email)
            throw ModCorreuExisteix();
        }
    }

    // 6) Llegir estat final desat (mateix DAO injectat)
    Usuari uMod = _daoUser->obte(u.getSobrenom());
    return uMod.obteInfo();
}
