//CapaDePresentacio.cxx
#include "CapaDePresentacio.hxx"
#include "CtrlRegistreUsuari.hxx"
#include "CtrlConsultaUsuari.hxx"
#include "CtrlModificaUsuari.hxx"
#include "CtrlEsborraUsuari.hxx"
#include "DTOUsuari.hxx"
#include "errors.hxx"
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

        DAOUsuari dao;
        CtrlRegistreUsuari ctrlRegUser(&dao);
        ctrlRegUser.registraUsuari(username, password, nom, email, edat);
        cout << "Nou usuari registrat correctament!\n";
    }
    catch (const SobrenomExisteix& se ) {
        cout << se.what() << endl;
    }
    catch (const CorreuExisteix& ce){
        cout << ce.what() << endl;
    }
    catch (const MenorEdat& me){
        cout << me.what() << endl;
    }

}

void CapaDePresentacio::consultaUsuari(){ // No hi ha tractament d'errors 
    cout << "** Consulta usuari **" << endl; 
    // Crear DAO i controlador 
    DAOUsuari dao;
    CtrlConsultaUsuari ctrlConsultaUser(&dao);
    // Obtenir la informacio de l'usuari loggejat (usuariActual)
    DTOUsuari info = ctrlConsultaUser.consultaUsuari();

    cout << "Nom complet: " << info.get_nomcomplet() << endl;
    cout << "Sobrenom: " << info.get_username() << endl;
    cout << "Correu electronic: " << info.get_correu() << endl;
    cout << "Edat: " << info.get_edat() << endl;
    cout << "Nombre total d'experiencies reservades: " << info.get_numReserves() << endl;
}

void CapaDePresentacio::modificaUsuari(){
    cout << "** Modifica usuari **" << endl; 
    try {

        // 1. consultaUsuari per obtenir l'usuari actual (loggejat)
        DAOUsuari dao;
        CtrlConsultaUsuari ctrlConsultaUser(&dao);
        
        DTOUsuari info = ctrlConsultaUser.consultaUsuari();
        // retorna info de l'usuari loggejat
        
        // Mostrar la info actual per a que l'usuari vegi que vol modificar
        cout << "Nom complet: "         << info.get_nomcomplet() << endl;
        cout << "Sobrenom: "            << info.get_username() << endl;    
        cout << "Correu electronic: "   << info.get_correu() << endl;
        cout << "Edat: "                << info.get_edat() << endl;
        // <Intro> 
        string nouNom, nouSobrenom,nouCorreu, novaEdatstr; // COMPROVAR SI SOBRENOM ES CANVIA O NO
        // valor per defecte novaEdat si no es vol canviar;
        int novaEdat = -1;
        cout << "Omplir la informacio a modificar..." << endl; 
        cout << "Nom complet: "; getline(cin, nouNom);
        cout << "Sobrenom: ";    getline(cin, nouSobrenom);
        cout << "Correu electronic: "; getline(cin, nouCorreu);
        cout << "Edat: ";        getline(cin, novaEdatstr);
        
        if (!novaEdatstr.empty()) {
            try { novaEdat = std::stoi(novaEdatstr); }
            catch (...) {
                cout << "Edat no valida. S'ignora el canvi d'edat." << endl;
                novaEdat = -1;
            }
        }
        
        // 2. modificaUsuari(nomU, contraU, correuU, edatU)
        CtrlModificaUsuari ctrlMod(&dao);
        ctrlMod.modificaUsuari(nouNom, nouCorreu, novaEdat);
        
        // 3. Mostrar informacio actualitzada 
        DTOUsuari infoUpdate = ctrlConsultaUser.consultaUsuari();
        cout << "** Dades usuari modificades ** " << endl;
        cout << "Nom complet: "         << infoUpdate.get_nomcomplet() << endl;
        cout << "Sobrenom: "            << infoUpdate.get_username() << endl;
        cout << "Correu electronic: "   << infoUpdate.get_correu() << endl;
        cout << "Edat: "                << infoUpdate.get_edat() << endl;

    }
    // 3. try catch per tractar errors sobrenom, correu, menor edat 
    // Encara que al diagrama aparegui una excepcio SobrenomExisteix, no està a l'operacio
    // No estira aquesta excepcio ja que en cap moment es canvia el sobrenom 
    catch (const ModCorreuExisteix& mce){
        cout << mce.what() << endl;
    }
    catch (const ModMenorEdat& mme){
        cout << mme.what() << endl;
    }
}

void CapaDePresentacio::esborraUsuari() {
    cout << "** Esborra usuari **" << endl;
    try {
        cout << "Per confirmar has d'entrar la contrasenya:" << endl; 
        cout << "Contrasenya: ";
        string password;
        cin >> password; 
        // <Intro> 
        cout << "Vols confirmar l'esborrat? (S/N)" << endl; 
        char confirma;
        cin >> confirma;
        if (confirma == 'S' || confirma == 's') {
            // Cridar al controlador per esborrar l'usuari
            DAOUsuari dao;
            CtrlEsborraUsuari ctrEsb(&dao);
            ctrEsb.esborraUsuari(password);
            cout << "Usuari esborrat correctament!" << endl;
        } 

    }
    catch (const ErrorContrasenya& ec) {
        cout << ec.what() << endl;
        return;
    } 
    catch (const std::exception& e) {
        cout << "L'usuari no s'ha esborrat correctament!" << e.what() << endl;
        return;
    }
}