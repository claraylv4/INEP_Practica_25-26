#include <iostream>
#include <memory>
#include <string>
#include "DAOUsuari.hxx"
#include "CtrlRegistreUsuari.hxx"
#include "CtrlModificaUsuari.hxx"
#include "CtrlEsborraUsuari.hxx"
#include "PlanGo.hxx"
#include "DTOUsuari.hxx"
#include "errors.hxx"

using namespace std;

void mostraMenu() {
    cout << "\n=== MENÚ USUARI ===\n";
    cout << "1. Registrar usuari\n";
    cout << "2. Login usuari\n";
    cout << "3. Modificar usuari\n";
    cout << "4. Consultar usuari actual\n";
    cout << "5. Esborrar usuari actual\n";
    cout << "6. Sortir\n";
    cout << "Tria una opció: ";
}

int main() {
    DAOUsuari dao;
    CtrlRegistreUsuari ctrlRegistre(&dao);
    CtrlModificaUsuari ctrlModifica(&dao);
    CtrlEsborraUsuari ctrlEsborra(&dao);

    bool sortida = false;

    while (!sortida) {
        mostraMenu();

        int opcio;
        cin >> opcio;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // neteja buffer

        try {
            switch (opcio) {
                case 1: { // Registrar
                    string sobrenom, password, nom, email;
                    int edat;
                    cout << "Sobrenom: "; getline(cin, sobrenom);
                    cout << "Password: "; getline(cin, password);
                    cout << "Nom complet: "; getline(cin, nom);
                    cout << "Correu: "; getline(cin, email);
                    cout << "Edat: "; cin >> edat; cin.ignore();

                    ctrlRegistre.registraUsuari(sobrenom, password, nom, email, edat);
                    cout << "Usuari registrat correctament!" << endl;
                    break;
                }
                case 2: { // Login
                    string sobrenom, password;
                    cout << "Sobrenom: "; getline(cin, sobrenom);
                    cout << "Password: "; getline(cin, password);

                    Usuari u = dao.obte(sobrenom);
                    if (u.getPassword() == password) {
                        PlanGo::instancia()._usuariActual = u; // només per proves
                        cout << "Login correcte: " << u.getSobrenom() << endl;
                    } else {
                        cout << "Password incorrecta!" << endl;
                    }
                    break;
                }
                case 3: { // Modificar
                    Usuari usuariActual = PlanGo::instancia().obteUsuari();
                    string nouNom, nouCorreu;
                    int novaEdat;

                    cout << "Nom nou (enter per mantenir actual): "; getline(cin, nouNom);
                    cout << "Correu nou (enter per mantenir actual): "; getline(cin, nouCorreu);
                    cout << "Edat nova (-1 per mantenir actual): "; cin >> novaEdat; cin.ignore();

                    DTOUsuari info = ctrlModifica.modificaUsuari(nouNom, nouCorreu, novaEdat);
                    cout << "Usuari modificat correctament!" << endl;
                    cout << "Nom: " << info.get_nomcomplet() << ", Correu: " << info.get_correu()
                         << ", Edat: " << info.get_edat() << endl;
                    break;
                }
                case 4: { // Consultar usuari actual
                    Usuari u = PlanGo::instancia().obteUsuari();
                    DTOUsuari info = u.obteInfo();
                    cout << "\n=== USUARI ACTUAL ===\n";
                    cout << "Nom: " << info.get_nomcomplet() << endl;
                    cout << "Sobrenom: " << info.get_username() << endl;
                    cout << "Correu: " << info.get_correu() << endl;
                    cout << "Edat: " << info.get_edat() << endl;
                    cout << "Número reserves: " << info.get_numReserves() << endl;
                    break;
                }
                case 5: { // Esborrar usuari
                    string password;
                    cout << "Introdueix la password per confirmar esborrat: ";
                    getline(cin, password);
                    ctrlEsborra.esborraUsuari(password);
                    cout << "Usuari esborrat correctament!" << endl;
                    break;
                }
                case 6:
                    sortida = true;
                    cout << "Sortint..." << endl;
                    break;
                default:
                    cout << "Opció incorrecta!" << endl;
            }
        } catch (const SobrenomExisteix& e) { cerr << "[ERROR] " << e.what() << endl; }
        catch (const CorreuExisteix& e) { cerr << "[ERROR] " << e.what() << endl; }
        catch (const MenorEdat& e) { cerr << "[ERROR] " << e.what() << endl; }
        catch (const ModCorreuExisteix& e) { cerr << "[ERROR] " << e.what() << endl; }
        catch (const ModMenorEdat& e) { cerr << "[ERROR] " << e.what() << endl; }
        catch (const ErrorContrasenya& e) { cerr << "[ERROR] " << e.what() << endl; }
        catch (const odb::exception& e) { cerr << "[ODB ERROR] " << e.what() << endl; }
        catch (const exception& e) { cerr << "[ERROR GENERAL] " << e.what() << endl; }
    }

    return 0;
}
