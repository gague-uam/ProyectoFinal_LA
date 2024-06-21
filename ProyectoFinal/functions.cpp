#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>
#include "variables.h"


using namespace std;

void student();
void registrer();
int menu();
void principal();
void studentdata();
void registrerdata();
void studentOptions();
void registrerOptions();
void showstudentdata();
void showregistrerdata();
void addmatch();
void showmatchdata();

int menu()
{

    int opt;
    cout << "Bienvenido al sistema de control de partidos de Baloncesto" << endl;
    cout << "!Vamos Jaguares!" << endl;
    cout << "1. Modo estudiante" << endl;
    cout << "2. Modo registrador" << endl;
    cout << "3. Salir" << endl;
    cin >> opt;
    return opt;
}

void principal()
{

    int opt;
    do
    {
        opt = menu();
        system("cls");
        switch (opt)
        {
        case 1:
            student();
            system("cls");
            break;
        case 2:
            registrer();
            system("cls");
            break;
        case 3:
            cout << "Hasta pronto" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            system("pause");
            system("cls");
            return principal();
        }
    } while (opt != 3);
}

void studentdata()
{
    cout << "Ingrese su nombre" << endl;
    cin.ignore();
    getline(cin, persona.NAME);
    system("cls");
    cout << "Ingrese su CIF" << endl;
    cin >> persona.CIF;
    system("cls");
    cout << "Ingrese su edad" << endl;
    cin >> persona.AGE;
    system("cls");
    cout << "Ingrese su carrera" << endl;
    cin.ignore();
    getline(cin, persona.CAREER);
    
    system("cls");

}

void registrerdata()
{
    cout << "Ingrese su cedula" << endl;
    cin.ignore();
    getline(cin, persona2.ID);
    system("cls");
    cout << "Ingrese su nombre" << endl;
    cin.ignore();
    getline(cin, persona2.NAME);
    system("cls");
}

void studentOptions()
{

    int opt;
    do
    {
        cout << "1. Ver datos" << endl;
        cout << "2. Partidos" << endl;
        cout << "3. Asistencia" << endl;
        cout << "4. Volver" << endl;
        cin >> opt;
        system("cls");
        switch (opt)
        {
        case 1:
            showstudentdata();
            system("pause");
            system("cls");
            
            break;
        case 2:
            showmatchdata();
            system("pause");
            system("cls");
            
            break;
        case 3:
            cout << "Proximamente" << endl;
            system("pause");
            system("cls");
            
            break;
        case 4:
            return principal();
            break;
        default:
            cout << "Opcion no valida" << endl;
            system("pause");
            system("cls");
            return studentOptions();
        }
    } while (opt != 4);
}

void showstudentdata()
{
        cout << "Nombre: " << persona.NAME << endl;
        cout << "CIF: " << persona.CIF << endl;
        cout << "Edad: " << persona.AGE << endl;
        cout << "Carrera: " << persona.CAREER << endl;
    
}

void addmatch()
{
    
    MATCHES partido[30];
    int matchCount = 0;
    char choice;

    do {
        cout << "Ingrese la información del partido #" << (matchCount + 1) << ":" << endl;
        cout << "Fecha: ";
        cin >> partido[matchCount].DATE;
        cout << "Hora: ";
        cin >> partido[matchCount].HOUR;
        cout << "Equipo Local: ";
        cin.ignore();
        getline(cin, partido[matchCount].LOCAL);
        cout << "Equipo Visitante: ";
        cin.ignore();
        getline(cin, partido[matchCount].VISIT);
        cout << "Puntos del equipo local: ";
        cin >> partido[matchCount].LOCALPOINTS;
        cout << "Puntos del equipo visitante: ";
        cin >> partido[matchCount].VISITPOINTS;

        matchCount++;

        cout << "¿Desea ingresar otro partido? (s/n): ";
        cin >> choice;
    } while (choice == 's' || choice == 'S');
}

void showmatchdata() {
    MATCHES partido[MAX];
    int matchCount = 0;
    cout << "Fecha       Hora    Local       Visitante   Puntos Local  Puntos Visitante" << endl;
    cout << "============================================================================" << endl;
    for (int i = 0; i < matchCount; ++i) {
        cout << partido[i].DATE << "  ";
        cout << partido[i].HOUR << "   ";
        cout << partido[i].LOCAL << "  ";
        cout << partido[i].VISIT << "   ";
        cout << partido[i].LOCALPOINTS << "             ";
        cout << partido[i].VISITPOINTS << endl;
    }
}



















void registrerOptions()
{
    int opt;
    do
    {
        cout << "1. Ver datos" << endl;
        cout << "2. Agregar nuevo partido" << endl;
        cout << "3. Volver" << endl;
        cin >> opt;
        system("cls");
        switch (opt)
        {
        case 1:
            showregistrerdata();
            system("pause");
            system("cls");
            
            break;
        case 2:
            addmatch();
            system("pause");
            system("cls");
            
            break;
        case 3:
            return principal();
            break;
        default:
            cout << "Opcion no valida" << endl;
            system("pause");
            system("cls");
            return registrerOptions();
        }
    } while (opt != 3);
}

void showregistrerdata()
{
    
    cout << "Cedula: " << persona2.ID << endl;
    cout << "Nombre: " << persona2.NAME << endl;
}

















void student()
{
    studentdata();
    studentOptions();
}

void registrer()
{
    registrerdata();
    registrerOptions();
    showregistrerdata();
}