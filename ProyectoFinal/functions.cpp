#include <iostream>
#include <string>
#include <cctype>
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
            return principal();
        }
    } while (opt != 3);
}

void studentdata()
{
    ESTUDENTS student;

    cout << "Ingrese su nombre" << endl;
    cin.ignore();
    getline(cin, student.NAME);
    system("cls");
    cout << "Ingrese su CIF" << endl;
    scanf("%i", student.CIF);
    system("cls");
    cout << "Ingrese su edad" << endl;
    scanf("%i", student.AGE);
    system("cls");
    cout << "Ingrese su carrera" << endl;
    cin.ignore();
    getline(cin, student.CAREER);
    
    system("cls");

}

void registrerdata()
{
    REGISTRERS registrer;
    cout << "Ingrese su ID" << endl;
    cin.ignore();
    getline(cin, registrer.ID);
    system("cls");
    cout << "Ingrese su nombre" << endl;
    cin.ignore();
    getline(cin, registrer.NAME);
    system("cls");
}

void studentOptions()
{

    int opt;
    do
    {
        cout << "1. Ver datos" << endl;
        cout << "2. Marcar asistencia" << endl;
        cout << "3. Asistencia" << endl;
        cout << "4. Volver" << endl;
        cin >> opt;
        system("cls");
        switch (opt)
        {
        case 1:
            showstudentdata();
            system("pause");
            break;
        case 2:
            cout << "Proximamente" << endl;
            system("cls");
            break;
        case 3:
            cout << "Proximamente" << endl;
            system("cls");
            break;
        case 4:
            return principal();
            break;
        default:
            cout << "Opcion no valida" << endl;
            return studentOptions();
        }
    } while (opt != 4);
}

void showstudentdata()
{
    for (int i = 0; i < MAX ; i++)
    {
        cout << "Nombre: " << students[i].NAME << endl;
        cout << "CIF: " << students[i].CIF << endl;
        cout << "Edad: " << students[i].AGE << endl;
        cout << "Carrera: " << students[i].CAREER << endl;
    }
    
}

void student()
{
    studentdata();
    studentOptions();
}

void registrer()
{
    registrerdata();
}