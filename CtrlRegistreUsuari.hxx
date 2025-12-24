
// CtrlRegistraUsuari.hxx
#pragma once
#include "DAOUsuari.hxx"
#include "usuari.hxx"

class CtrlRegistreUsuari {
public:
  explicit CtrlRegistreUsuari(DAOUsuari *dao);

  void registraUsuari(const string &username, 
                      const string &password,
                      const string &nom, 
                      const string &email, 
                      const int &edat);

private:
  DAOUsuari *_daoUser;
};