#include<iostream>
#include <conio.h>
#include<windows.h>
#include "Vector.h"
#include "Meniuri.h"
using namespace std;

enum
{
    KEY_ESC = 27,
    ARROW_UP = 256 + 72,
    ARROW_DOWN = 256 + 80,
    ARROW_LEFT = 256 + 75,
    ARROW_RIGHT = 256 + 77
};
int Meniuri::getCode(void)
{
    int c = getch();
    if (c == 0 || c == 224)
        c = 256+getch();
    return c;
}

static const char *menu_optionsFirst[] =
{
    "1. Operatii cu tipul vector \n",
    "2. Operatii cu multimi\n",
    "3. Date despre autor \n",
    "4. Exit "
};

static const int menu_size = 4;

void Meniuri::menuFirst(int arrow)
{
    HANDLE  handleConsole;
    handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < menu_size; i++)
    {
        if (i == arrow)
        {
            SetConsoleTextAttribute(handleConsole, 269);
            cout<<" --> ";
            cout<< menu_optionsFirst[i];

            SetConsoleTextAttribute(handleConsole, 9);
        }
        else
        {
            cout<<" ";
            cout<< menu_optionsFirst[i];
        }

    }
}
void Meniuri::MeniuFirst()
{
    int arrow=0,action;
    system("cls");
    menuFirst(arrow);
    while ((action = getCode()) != KEY_ESC)
    {
        switch (action)
        {
        case ARROW_UP:
            if (--arrow < 0)
                arrow = menu_size - 1;
            break;
        case ARROW_DOWN:
            if (++arrow == menu_size)
                arrow = 0;
            break;
        case '\r':
            switch(menu_optionsFirst[arrow][0])
            {
            case '1':
                MeniuSecond();
                break;
            case '2':
                MeniuThird();
                break;

            case '3':
                system("cls");
                HANDLE  handleConsole;
                handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(handleConsole, 269);
                cout<<"\n                                                                  ";
                cout<<"\n    FACULTATEA DE INGINERIE ELECTRICA SI STIINTA CALCULATOARELOR  ";
                cout<<"\n                                                                  ";
                cout<<"\n    PROIECT: PROGRAMARE ORIENTATA PE OBIECTE                      ";
                cout<<"\n                                                                  ";
                cout<<"\n    IMPLEMENTARE MULTIMI PE TIPUL VECTOR                          ";
                cout<<"\n                                                                  ";
                cout<<"\n    NUME: BEILIC MARIA                                            ";
                cout<<"\n                                                                  ";
                cout<<"\n    GRUPA: 3122B                                                  ";
                cout<<"\n                                                                  ";
                cout<<"\n    SPECIALIZAREA: CALCULATOARE                                   ";
                cout<<"\n                                                                  ";
                cout<<"\n    AN STUDIU: II                                                 ";
                cout<<"\n                                                                  ";
                cout<<"\n    AN UNIVERSITAR: 2019/2020                                     ";
                cout<<"\n                                                                  ";
                SetConsoleTextAttribute(handleConsole, 5);
                break;

            case '4':
                exit(0);
                break;

            default:
                cout<<"\nOptiune inexistenta!";
                getch();
                break;
            }

            getCode();
            break;
        default:
            break;
        }
        system("cls");
        menuFirst(arrow);
    }

}
static const char *menu_optionsSecond[] =
{
    "A. Citire vector\n",
    "B. Afisare vector\n",
    "C. Inserare element in vector la inceput\n",
    "D. Inserare element in vector la final\n",
    "E. Inserare element in vector pe o pozitie data\n",
    "F. Stergere element de la inceput\n",
    "G. Stergere element de la la final\n",
    "H. Stergere element de pe o pozitie data\n",
    "I. Copie vector\n",
    "J. Cauta element in vector\n",
    "K. Get element\n",
    "L. Set element\n",
    "M. Revenire la meniu principal"
};
static const int menu_size2 = 13;

void Meniuri::menuSecond(int arrow)
{
    HANDLE  handleConsole;
    handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < menu_size2; i++)
    {
        if (i == arrow)
        {
            SetConsoleTextAttribute(handleConsole, 269);
            cout<<" --> ";
            cout<<menu_optionsSecond[i]<<endl;
            SetConsoleTextAttribute(handleConsole, 9);
        }
        else
        {
            cout<<" ";
            cout<<menu_optionsSecond[i]<<endl;
        }
    }
}
void Meniuri::MeniuSecond()
{
    Vector v1,v2;
    int elem;
    int arrow=0,action;

    system("cls");
    menuSecond(arrow);

    while ((action = getCode()) != KEY_ESC)
    {
        switch (action)
        {
        case ARROW_UP:
            if (--arrow < 0)
                arrow = menu_size2 - 1;
            break;
        case ARROW_DOWN:
            if (++arrow == menu_size2)
                arrow = 0;
            break;
        case '\r':
            switch(menu_optionsSecond[arrow][0])
            {
            case 'A':
                cin>>v1;
                break;
            case 'B':
                if(!v1.isEmpty())
                {
                    cout<<"\nVectorul este: \n";
                    cout<<v1;
                }
                else
                    cout<<"Vectorul nu are elemente!"<<endl;

                break;
            case 'C':

                v1.inserare_in_fata();
                cout<<"Elementul a fost inserat!"<<endl;
                break;
            case 'D':
                cout<<"\nDati elementul pe care doriti sa-l introduceti la final:"<<endl;
                cin>>elem;
                v1.inserare_la_final(elem);
                cout<<"Elementul a fost inserat!"<<endl;
                break;
            case 'E':
                if(!v1.isEmpty())
                {
                    v1.inserare_v();
                    cout<<"Elementul a fost inserat!"<<endl;
                }
                else
                    cout<<"Vectorul nu are elemente!"<<endl;
                break;
            case 'F':
                if(!v1.isEmpty())
                {
                    v1.sterge_primul();
                    cout<<"Elementul a fost sters!"<<endl;
                }
                else
                    cout<<"Vectorul nu are elemente!"<<endl;
                break;
            case 'G':
                if(!v1.isEmpty())
                {
                    v1.sterge_ultimul();
                    cout<<"Elementul a fost sters!"<<endl;
                }
                else
                    cout<<"Vectorul nu are elemente!!"<<endl;
                break;
            case 'H':
                if(!v1.isEmpty())
                {
                    int poz;
                    cout<<"\nDati pozitia de pe care doriti sa stergeti elementul:"<<endl;
                    cin>>poz;
                    v1.sterge_v(poz);
                    cout<<"Elementul a fost sters!"<<endl;
                }
                else
                    cout<<"Vectorul nu are elemente!!"<<endl;
                break;
            case 'I':
                if(!v1.isEmpty())
                {
                    v2.copie(v1);
                    cout<<"Vectorul copie este:";
                    cout<<v2;
                }
                else
                    cout<<"Vectorul nu are elemente!!"<<endl;
                break;
            case 'J':
                if(!v1.isEmpty())
                {
                    int ele;
                    cout<<"\nDati elementul pe care doriti sa-l cautati in vector:"<<endl;
                    cin>>ele;
                    if(v1.cauta_elem(ele))
                        cout<<"Elementul a fost gasit!"<<endl;
                    else
                        cout<<"Elementul cautat nu este in vector!!"<<endl;
                }
                else
                    cout<<"Vectorul nu are elemente!"<<endl;
                break;
            case 'K':
                if(!v1.isEmpty())
                {
                    v1.GetElementVec();
                }
                else
                    cout<<"Vectorul nu are elemente!"<<endl;
                break;
            case 'L':
                if(!v1.isEmpty())
                {
                    v1.setElementVec();

                }
                else
                    cout<<"Vectorul nu are elemente!"<<endl;
                break;

            case 'M':
                MeniuFirst();
                break;
            default:
                cout<<"Optiune incorecta!";
                break;
            }
            getCode();
            break;
        default:
            break;
        }
        system("cls");
        menuSecond(arrow);
    }
}
static const char *menu_optionsThird[] =
{
    "1. Reuniune\n",
    "2. Intersectie\n",
    "3. Diferenta\n",
    "4. Revenire la meniul principal"
};

static const int menu_size3 = 4;
void Meniuri::menuThird(int arrow)
{
    HANDLE  handleConsole;
    handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < menu_size; i++)
    {
        if (i == arrow)
        {
            SetConsoleTextAttribute(handleConsole, 269);
            cout<<" --> ";
            cout<< menu_optionsThird[i];

            SetConsoleTextAttribute(handleConsole, 9);
        }
        else
        {
            cout<<" ";
            cout<< menu_optionsThird[i];
        }

    }
}

void Meniuri::MeniuThird()
{
    Vector v1, v2, v3;

    int arrow=0,action;

    system("cls");
    menuThird(arrow);

    while ((action = getCode()) != KEY_ESC)
    {
        switch (action)
        {
        case ARROW_UP:
            if (--arrow < 0)
                arrow = menu_size3 - 1;
            break;
        case ARROW_DOWN:
            if (++arrow == menu_size3)
                arrow = 0;
            break;
        case '\r':
            switch(menu_optionsThird[arrow][0])
            {
            case '1':
                cin>>v1;
                cin>>v2;
                v3.Reuniunea(v1,v2);

                break;
            case '2':
                cin>>v1;
                cin>>v2;
                v3.Intersectia(v1,v2);
                break;
            case '3':
                cout<<"\nFunctioneaza corect  doar pentru multimi cu acelasi numar de elemente!";
                cin>>v1;
                cin>>v2;
                v3.Diferenta(v1,v2);
                break;
            case '4':
                MeniuFirst();
                break;

            default:
                cout<<"Optiune incorecta!";
                break;
            }
            getCode();
            break;
        default:
            break;
        }
        system("cls");
        menuThird(arrow);
    }
}

