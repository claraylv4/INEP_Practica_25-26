// DAOUsuari.cxx
#include "DAOUsuari.hxx"
#include <odb/transaction.hxx>
using namespace std;

DAOUsuari::DAOUsuari()
{
    // Obtenim la connexió a la base de dades des de la classe singleton connexio
    db = connexioBD::getInstance().getDB();
}

bool DAOUsuari::existeix(const string& username)
{ // FET PER IA
    odb::transaction t(db->begin());
    shared_ptr<usuari> ptr = db->load<usuari>(username);
    t.commit();
    return ptr != nullptr;
}

usuari DAOUsuari::obte(const string& username)
{ // FET PER IA
    odb::transaction t(db->begin());
    shared_ptr<usuari> ptr = db->load<usuari>(username);
    t.commit();
    return *ptr;
}

std::vector<usuari> DAOUsuari::tots()
{ // FET PER IA
    odb::transaction t(db->begin());
    std::vector<usuari> usuaris = db->load_all<usuari>();
    t.commit();
    return usuaris;
}


void DAOUsuari::inserta(const usuari& u)
{
    odb::transaction t(db->begin());
    shared_ptr<usuari> ptr(new usuari(u));
    db->persist(ptr);
    t.commit();
}

void DAOUsuari::modifica(const usuari& u)
{ // FET PER IA
    odb::transaction t(db->begin());
    shared_ptr<usuari> ptr = db->load<usuari>(u.get_username());
    ptr->set_nomcomplet(u.get_nomcomplet());
    ptr->set_data_naixement(u.get_data_naixement());
    t.commit();
}

void DAOUsuari::esborra(const string& username)
{
    odb::transaction t(db->begin());
    db->erase<usuari>(username);
    t.commit();
}

