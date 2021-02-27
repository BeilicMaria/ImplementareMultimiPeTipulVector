#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;
#define NMAX 40
struct Vectorstruct
{
    int vec[NMAX];
    int n;
};

class Vector
{
public:
    Vector();
    Vector(int);
    friend ostream & operator <<(ostream &, Vector &);
    friend istream & operator >>(istream &, Vector &);
    void inserare_in_fata( );
    void inserare_la_final( int );
    void inserare_v();
    bool compara(Vector &);
    bool cauta_elem( int );
    void copie(Vector &);
    bool isEmpty();
    bool isFull();
    void sterge_primul();
    void sterge_ultimul();
    void sterge_v(int);
    void GetElementVec();
    int setElementVec();
    void Intersectia(Vector &,Vector &);
    void Reuniunea(Vector &,Vector &);
    void Diferenta(Vector &, Vector &);
    virtual ~Vector();

protected:
    struct Vectorstruct
{
    int vec[NMAX];
    int n;
};
    Vectorstruct V;

private:




};

#endif // VECTOR_H
