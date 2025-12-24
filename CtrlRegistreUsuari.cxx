// CtrlRegistraUsuari.cxx
#include "CtrlRegistreUsuari.hxx"

CtrlRegistreUsuari::CtrlRegistreUsuari(DAOUsuari *dao) : _daoUser(dao) {}

void CtrlRegistreUsuari::registraUsuari(const string &username, const string &password,
                                        const string &nom, const string &email, const int &edat) {
  Usuari u(username, nom, email, password, edat);
  _daoUser->inserta(u);
}
