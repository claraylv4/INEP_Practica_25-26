// DAOUsuari.hxx
#pragma once
#include <memory>
#include <vector>
#include <string>

#include <odb/core.hxx>
#include <odb/database.hxx> 
#include <odb/mysql/database.hxx>

#include "usuari.hxx"
#include "connexioBD.hxx"

class DAOUsuari {
    public:
    DAOUsuari();
    
    void inserta(const Usuari& u);
    void modifica(const Usuari& u);
    void esborra(const std::string& username);
    bool existeix(const std::string& username);
    
    Usuari obte(const std::string& username);
    vector<Usuari> tots();
    
    private:
        std::shared_ptr<odb::database> db;
        
};
