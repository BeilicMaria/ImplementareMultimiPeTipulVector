#include <iostream>
#include <ctype.h>
#include<windows.h>
#include "Vector.h"
#include "Meniuri.h"

using namespace std;

int main()
{

    int pass=2020,p,op;
    Meniuri m;
    do
    {
        cout<<"\n   PAROLA: ";
        cin>>p;
        HANDLE  handleConsole;
        handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if(p==pass)
        {
            system("cls");
            SetConsoleTextAttribute(handleConsole, 266);
            cout<<"\n                  ";
            cout<<"\n PAROLA ESTE CORECTA  ";
            cout<<"\n                  ";
            SetConsoleTextAttribute(handleConsole, 9);
            cout<<endl<<endl<<endl<<endl;
            system("pause");
            m.MeniuFirst();
        }
        else
        {
            system("cls");
            SetConsoleTextAttribute(handleConsole, 260 );
            cout<<"\n                   ";
            cout<<"\n PAROLA ESTE INCORECTA ";
            cout<<"\n                   "<<endl;
            SetConsoleTextAttribute(handleConsole, 9);

            cout<<"\n STITI PAROLA? \n     1 - STIU  \n     2 - NU STIU\n";
            cin>>op;
            if(op==1)
                system("cls");
            else
                break;
        }
    }
    while(p!=2020);
    return 0;
}
