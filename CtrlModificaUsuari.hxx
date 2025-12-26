#pragma once
#include "DAOUsuari.hxx"
#include "errors.hxx"
#include <string>

using namespace std;

class CtrlModificaUsuari {
public:
    explicit CtrlModificaUsuari(DAOUsuari* dao) : _daoUser(dao) {}

    DTOUsuari modificaUsuari(string nomU, string correuU, int edatU); 
   

private:
    DAOUsuari* _daoUser;
};
