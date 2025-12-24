//main.cpp
#include <iostream>
#include <string>
#include <locale>
#include "CapaDePresentacio.hxx"
using namespace std;

void menu_principal()
{
    int opcio;
    do
    {
        cout << "\n===== MENU PRINCIPAL =====" << endl;
        cout << "1. Iniciar Sessio" << endl;
        cout << "2. Registrar usuari" << endl;
        cout << "3. Consultes" << endl;  
        cout << "0. Sortir" << endl;
        cout << "Opcio: " << endl;
        cin >> opcio;
        CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
        
        switch (opcio) {
            case 1: 
                presentacio.iniciar_sessio();
                break;
            case 2:
                presentacio.crear_usuari();
                break;
            case 3:
                //presentacio.consultes_public();
                break;  
            case 0:
                cout << "Sortint del programa...\n";
                break;
            default: cout << "Opcio no valida.\n"; break;
        }
        
    } while (opcio != 0);
}

void menu_usuari_iniciat()
{
    int opcio;
    do
    {
        cout << "\n===== MENU PRINCIPAL =====" << endl;
            cout << "1. Gestio usuaris" << endl;
            cout << "2. Gestio reserves" << endl;
            cout << "3. Consultes" << endl; 
            cout << "4. Tancar sessio" << endl; 
            cout << "0. Sortir" << endl;
            cout << "Opcio: " << endl;
            cin >> opcio;
       
        // Obtenim la façana de presentació (Singleton)
        CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    
        switch (opcio) {
            case 1: 
            default: cout << "Opcio no valida.\n"; break;
        }
    } while (opcio != 0);
}

int main() {
    // Aquí ja NO hi ha cap connexió a la BD
    std::locale::global(std::locale("es_ES.UTF-8"));
    menu_principal();
    return 0;
}
