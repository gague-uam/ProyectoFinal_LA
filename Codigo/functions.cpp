#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <conio.h>
#include "variables.h"
#include <regex>

using namespace std;

/*Funciones prototipo*/
void student();
void registrer();
int menu();
void principal();
void studentdata();
void registrerdata();
void showregistrerdata();
void studentOptions();
void registrerOptions();
void showstudentdata();
void showmatchdata();
void addmatch();
void assisted();
void saveMatches();
void loadMatches();

/*Validaciones*/

bool isStudentDataEntered = false;
bool isRegistrerDataEntered = false;

bool isValidDateFormat(const std::string &dateStr)
{
    std::regex dateRegex("^(0[1-9]|[1-2][0-9]|3[0-1])/(0[1-9]|1[0-2])/\\d{4}$");
    return std::regex_match(dateStr, dateRegex);
}

bool isValidTimeFormat(const std::string &timeStr)
{
    std::regex timeRegex("^(0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$");
    return std::regex_match(timeStr, timeRegex);
}

bool isValidStudentName(const std::string &nameStr)
{
    std::regex nameRegex("^[a-zA-Z]+\\s[a-zA-Z]+$");
    return std::regex_match(nameStr, nameRegex);
}

bool isValidCIF(const std::string &cifStr)
{
    std::regex cifRegex("^\\d{8}$");
    return std::regex_match(cifStr, cifRegex);
}

bool isValidAge(const std::string &ageStr)
{
    std::regex ageRegex("^(1[5-9]|[2-9][0-9])$");
    return std::regex_match(ageStr, ageRegex);
}

bool isValidCareer(const std::string &careerStr)
{
    std::regex careerRegex("^[a-zA-Z\\s]+$");
    return std::regex_match(careerStr, careerRegex);
}

bool isValidID(const std::string &idStr)
{
    std::regex idRegex("^[a-zA-Z0-9]{14}$");
    return std::regex_match(idStr, idRegex);
}

bool isValidRegistrerName(const std::string &nameStr)
{
    std::regex nameRegex("^[a-zA-Z]+\\s[a-zA-Z]+$");
    return std::regex_match(nameStr, nameRegex);
}

bool isLocalTeamValid(const std::string &localTeamStr)
{
    std::regex localTeamRegex("^[a-zA-Z\\s]+$");
    return std::regex_match(localTeamStr, localTeamRegex);
}

bool isVisitTeamValid(const std::string &visitTeamStr)
{
    std::regex visitTeamRegex("^[a-zA-Z\\s]+$");
    return std::regex_match(visitTeamStr, visitTeamRegex);
}

bool isLocalPointsValid(const std::string &localPointsStr)
{
    if (localPointsStr.empty())
    {
        return false;
    }

    for (char c : localPointsStr)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }

    return true;
}

bool isVisitPointsValid(const std::string &visitPointsStr)
{
    if (visitPointsStr.empty())
    {
        return false;
    }

    for (char c : visitPointsStr)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }

    return true;
}

/*Funciones*/
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
    std::string tester = "";
    std::string tester2 = "";

    if (isStudentDataEntered)
    {
        cout << "La informacion ya ha sido ingresada." << endl;
        system("pause");
        system("cls");
        return;
    }

    while (true)
    {
        cout << "Ingrese su nombre y apellido" << endl;
        cin.ignore();
        getline(cin, persona.NAME);
        system("cls");

        if (isValidStudentName(persona.NAME))
        {
            break;
        }
        else
        {
            cout << "Ingrese un nombre valido\n";
            system("pause");
            system("cls");
        }
    }

    while (true)
    {
        cout << "Ingrese su CIF" << endl;
        cin >> tester;
        system("cls");

        if (isValidCIF(tester))
        {
            persona.CIF = stoi(tester);
            break;
        }
        else
        {
            cout << "Ingrese un CIF valido de 8 digitos\n";
            system("pause");
            system("cls");
        }
    }

    while (true)
    {
        cout << "Ingrese su edad" << endl;
        cin >> tester2;
        system("cls");

        if (isValidAge(tester2))
        {
            persona.AGE = stoi(tester2);
            break;
        }
        else
        {
            cout << "Ingrese una edad valida entre 15 y 99\n";
            system("pause");
            system("cls");
        }
    }

    while (true)
    {
        cout << "Ingrese su carrera" << endl;
        cin.ignore();
        getline(cin, persona.CAREER);
        system("cls");

        if (isValidCareer(persona.CAREER))
        {
            break;
        }
        else
        {
            cout << "Ingrese una carrera valida\n";
            system("pause");
            system("cls");
        }
    }

    isStudentDataEntered = true;
}

void registrerdata()
{
    if (isRegistrerDataEntered)
    {
        cout << "La informacion ya ha sido ingresada." << endl;
        system("pause");
        system("cls");
        return;
    }

    while (true)
    {
        cout << "Ingrese su cedula (14 Caracteres)" << endl;
        cin >> persona2.ID;
        system("cls");

        if (isValidID(persona2.ID))
        {
            break;
        }
        else
        {
            cout << "Ingrese una cedula valida de 14 caracteres\n";
            system("pause");
            system("cls");
        }
    }

    while (true)
    {
        cout << "Ingrese su nombre y Apellido" << endl;
        cin.ignore();
        getline(cin, persona2.NAME);
        system("cls");

        if (isValidRegistrerName(persona2.NAME))
        {
            break;
        }
        else
        {
            cout << "Ingrese un nombre valido\n";
            system("pause");
            system("cls");
        }
    }

    isRegistrerDataEntered = true;
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
            assisted();
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
    char choice;
    do
    {
        cout << "Ingrese la informacion del partido #" << (contador + 1) << ":" << endl;

        while (true)
        {
            cout << "Fecha (DD/MM/YYYY): ";
            cin >> partido[contador].DATE;
            if (isValidDateFormat(partido[contador].DATE))
            {
                break;
            }
            else
            {
                cout << "Ingrese un formato de fecha valido DD/MM/YYYY \n";
                system("pause");
                system("cls");
            }
        }

        while (true)
        {
            cout << "Hora (HH:MM): ";
            cin >> partido[contador].HOUR;
            if (isValidTimeFormat(partido[contador].HOUR))
            {
                break;
            }
            else
            {
                cout << "Ingrese un formato de hora valido HH:MM \n";
                system("pause");
                system("cls");
            }
        }

        while (true)
        {
            cout << "Equipo Local: ";
            cin.ignore();
            getline(cin, partido[contador].LOCAL);
            if (isLocalTeamValid(partido[contador].LOCAL))
            {
                break;
            }
            else
            {
                cout << "Ingrese un nombre de equipo local valido\n";
                system("pause");
                system("cls");
            }
        }

        while (true)
        {
            cout << "Equipo Visitante: ";
            getline(cin, partido[contador].VISIT);
            if (isVisitTeamValid(partido[contador].VISIT))
            {
                break;
            }
            else
            {
                cout << "Ingrese un nombre de equipo visitante valido\n";
                system("pause");
                system("cls");
            }
        }

       while (true)
        {
            cout << "Puntos del equipo local: ";
            cin >> partido[contador].LOCALPOINTS;
            if (isLocalPointsValid(to_string(partido[contador].LOCALPOINTS)))
            {
                break;
            }
            else
            {
                cout << "Ingrese un numero de puntos valido\n";
                system("pause");
                system("cls");
            }
        }

        while (true)
        {
            cout << "Puntos del equipo visitante: ";
            cin >> partido[contador].VISITPOINTS;
            if (isVisitPointsValid(to_string(partido[contador].VISITPOINTS)))
            {
                break;
            }
            else
            {
                cout << "Ingrese un numero de puntos valido\n";
                system("pause");
                system("cls");
            }
        }

        cin >> partido[contador].VISITPOINTS;

        contador++;

        partido[contador].ID = contador;

        cout << "¿Desea ingresar otro partido? (s/n): ";
        cin >> choice;
    } while (choice == 's' || choice == 'S');

    saveMatches();
}

void showmatchdata()
{   
    loadMatches();
    cout << "Los partidos se mostraran en el siguiente formato" << endl;
    cout << "ID--Fecha--Hora--Local--Visitante--PuntosLocal--PuntosVisitantes" << endl;
    for (int i = 0; i < contador; ++i)
    {
        cout << partido[i].ID << "  ";
        cout << partido[i].DATE << "  ";
        cout << partido[i].HOUR << "   ";
        cout << partido[i].LOCAL << "  ";
        cout << partido[i].VISIT << "   ";
        cout << partido[i].LOCALPOINTS << "             ";
        cout << partido[i].VISITPOINTS << endl;
    }
}

void assisted()
{
    int id = 0;

    showmatchdata();
    cout << "Digite el id del partido al que fue: " << endl;
    cin >> id;
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
}

void saveMatches()
{
    ofstream file("matches.txt");
    if (file.is_open())
    {
        for (int i = 0; i < contador; ++i)
        {
            file << partido[i].ID << "," << partido[i].DATE << "," << partido[i].HOUR << ","
                 << partido[i].LOCAL << "," << partido[i].VISIT << ","
                 << partido[i].LOCALPOINTS << "," << partido[i].VISITPOINTS << endl;
        }
        file.close();
        cout << "Partidos guardados exitosamente." << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo para guardar los partidos." << endl;
    }
}

void loadMatches()
{
    ifstream file("matches.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string token;
            int i = 0;
            while (getline(ss, token, ','))
            {
                switch (i)
                {
                case 0:
                    partido[contador].ID = stoi(token);
                    break;
                case 1:
                    partido[contador].DATE = token;
                    break;
                case 2:
                    partido[contador].HOUR = token;
                    break;
                case 3:
                    partido[contador].LOCAL = token;
                    break;
                case 4:
                    partido[contador].VISIT = token;
                    break;
                case 5:
                    partido[contador].LOCALPOINTS = stoi(token);
                    break;
                case 6:
                    partido[contador].VISITPOINTS = stoi(token);
                    break;
                }
                i++;
            }
            contador++;
        }
        file.close();
        cout << "Partidos cargados exitosamente." << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo para cargar los partidos." << endl;
    }
}

