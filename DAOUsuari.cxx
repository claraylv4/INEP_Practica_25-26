// DAOUsuari.cxx
#include "DAOUsuari.hxx"
#include <odb/transaction.hxx>
using namespace std;

DAOUsuari::DAOUsuari()
{
    // Obtenim la connexió a la base de dades des de la classe singleton connexio
    db = connexioBD::getInstance().getDB();
}

void DAOUsuari::inserta(const Usuari& u)
{
    odb::transaction t(db->begin());
    shared_ptr<Usuari> ptr(new Usuari(u));
    db->persist(ptr);
    t.commit();
}

void DAOUsuari::modifica(const Usuari& u)
{ // FET PER IA
    odb::transaction t(db->begin());
    shared_ptr<Usuari> ptr = db->load<Usuari>(u.getSobrenom());
    ptr->set_nom(u.getNom());
    ptr->set_edat(u.getEdat());
    t.commit();
}

void DAOUsuari::esborra(const string& username)
{
    odb::transaction t(db->begin());
    db->erase<Usuari>(username);
    t.commit();
}

bool DAOUsuari::existeix(const string& username)
{ 
    odb::transaction t(db->begin());
    shared_ptr<Usuari> ptr = db->load<Usuari>(username);
    t.commit();
    return ptr != nullptr;
}

Usuari DAOUsuari::obte(const string& username)
{ 
    odb::transaction t(db->begin());
    shared_ptr<Usuari> ptr = db->load<Usuari>(username);
    t.commit();
    return *ptr;
}

std::vector<Usuari> DAOUsuari::tots()
{ // FET PER IA
    odb::transaction t(db->begin());
    std::vector<Usuari> usuaris = db->load_all<Usuari>();
    t.commit();
    return usuaris;
}