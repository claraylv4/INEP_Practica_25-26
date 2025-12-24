//CapaDePresentacio.cxx
#include "CapaDePresentacio.hxx"
#include "CtrlRegistreUsuari.hxx"
#include "CtrlConsultaUsuari.hxx"
#include "DTOUsuari.hxx"
#include <iostream>
#include <string>

void CapaDePresentacio::registrarUsuari(){
    cout << "** Registre usuari **" << endl; 
    try {
        string nom, username, password, email;
        int edat;
        
        cout << "Nom complet: "; getline(cin, nom);
        cout << "Sobrenom: ";   getline(cin, username);
        cout << "Contrasenya: ";getline(cin, password);
        cout << "Correu: ";     getline(cin, email);
        cout << "Edat: ";       cin >> edat; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // neteja buffer

        CtrlRegistreUsuari ctrlRegUser(new DAOUsuari());
        ctrlRegUser.registraUsuari(username, password, nom, email, edat);
        cout << "Nou usuari registrat correctament!\n";
    }
    // Falta fitxer de gestió d'excepcions
    catch (const SobrenomExisteix& se ) {
        cout << "Ja existeix un usuari amb aquest sobrenom" << endl;
    }
    catch (const CorreuExisteix& ce){
        cout << "Ja existeix un usuari amb aquest correu electrònic" << endl;
    }
    catch (const MenorEdat& me){
        cout << "No es pot registrar un menor" << endl;
    }

}

void CapaDePresentacio::consultaUsuari(){
    cout << "** Consulta usuari **" << endl; 
    // Demanem la informació a la capa de control
    CtrlConsultaUsuari ctrlConsultaUser(new DAOUsuari());
    DTOUsuari info = ctrlConsultaUser.consultaUsuari();

    cout << "Nom complet: " << info.get_nomcomplet() << endl;
    cout << "Sobrenom: " << info.get_username() << endl;
    cout << "Correu electronic: " << info.get_correu() << endl;
    cout << "Edat: " << info.get_edat() << endl;
    cout << "Nombre total d'experiencies reservades: " << info.get_numReserves() << endl;
}