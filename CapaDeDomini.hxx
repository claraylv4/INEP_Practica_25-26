#ifndef CAPADEDOMINI_HXX
#define CAPADEDOMINI_HXX

#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include "DTOUsuari.hxx"

using namespace std;
using namespace boost::gregorian;

class CapaDeDomini {
public:
    // Singleton access
    static CapaDeDomini& getInstance() {
        static CapaDeDomini instance;
        return instance;
    }

    // Deleted copy constructor and assignment operator to prevent copies
    CapaDeDomini(const CapaDeDomini&) = delete;
    void operator=(const CapaDeDomini&) = delete;

    // Business logic methods
    void registrarUsuari(const string& username, const string& nomcomplet, const date& data_naixement);
    void esborrarUsuari(const string& username);
    void modificarUsuari(const string& username, const string& nou_nom, const date& nova_data);
    DTOUsuari consultarUsuari(const string& username);

private:
    // Private constructor for Singleton
    CapaDeDomini() {}
};

#endif // CAPADEDOMINI_HXX
