#include "Vector.h"
#include <iostream>
using namespace std;
///CONSTRUCTORUL IMPLICIT
Vector::Vector()
{
    V.vec[0]=NULL;
    V.n=0;
}
///CONSTRUCTORUL CU PARAMETRII
Vector::Vector(int l)
{
    V.vec[0]=NULL;
    V.n=l;
}

///SUPRADEFINIRE OPERATOR >>
istream &operator >>(istream &c, Vector &v)
{
    cout<<"\nIntroduceti numarul de elemente ale vectorului: ";
    c>>v.V.n;
    cout<<"\nIntroduceti elementele vectorului: \n";
    for(int i=0; i<v.V.n; i++)
    {
        cout<<"V["<<i<<"]:";
        c>>v.V.vec[i];
    }
    return c;
}
///SUPRADEFINIRE OPERATOR <<
ostream &operator<<(ostream &c, Vector& v)
{
    for(int i=0; i<v.V.n; i++)
        c<<v.V.vec[i]<<" ";
    return  c;
}
///INSERAREA UNUI ELEMENT IN FATA VECTORULUI
void Vector::inserare_in_fata()
{
    int x,tmp;
    cout<<"\nDati elementul dorit pentru inserarea la inceput:\n";
    cin>>x;
    if(!isFull())
    {
        for(int i=0; i<=V.n; i++)
        {
            tmp=V.vec[i];
            V.vec[i]=x;
            x=tmp;
        }
        V.n++;
    }

}
///INSERAREA UNUI ELEMENT LA FINALUL VECTORULUI
void Vector::inserare_la_final(int x)
{
    if(!isFull())
    {
        V.vec[V.n]=x;
        V.n++;
    }

}
///INSERAREA UNUI ELEMENT PE O POZITIE DATA
void Vector:: inserare_v ()
{
    int x,poz,tmp;
    cout<<"\nDati pozitia pe care doriti sa inserati un element:\n";
    cin>>poz;

    if(poz<=V.n)
    {
        cout<<"\nDati elementul:\n";
        cin>>x;

        for(int i=poz; i<=V.n; i++)
        {
            tmp=V.vec[i];
            V.vec[i]=x;
            x=tmp;
        }
        V.n++;

    }
    else
        cout<<"Vectorul are doar "<<V.n<<" pozitii, incearca din nou."<<endl;

}
///VERIFICAM VECTORUL DACA ESTE GOL
bool Vector::isEmpty()
{
    if(V.n==0)
        return true;
    else
        return false;
}
///VERIFICAM VECTORUL DACA ESTE PLIN
bool Vector::isFull()
{
    if(V.n==NMAX)
        return true;
    else
        return false;
}
///STERGEREA PRIMULUI ELEMENT DIN VECTOR
void Vector::sterge_primul()
{
    if(!isEmpty())
    {
        for(int i=0; i<V.n; i++)
        {
            V.vec[i]=V.vec[i+1];
        }
        V.n--;

    }

}
///STERGEREA ULTIMULUI ELEMENT DIN VECTOR
void Vector::sterge_ultimul()
{
    if(!isEmpty())
    {
        V.n--;

    }

}
///STERGE ELEMENT DE PE O POZITIE DATA DIN VECTOR
void Vector::sterge_v(int poz)
{
    if(poz<=V.n)
    {
        if(!isEmpty())
        {
            for(int i=poz; i<V.n-1; i++)
            {
                V.vec[i]=V.vec[i+1];
            }
            V.n--;

        }
    }
    else
        cout<<"Vectorul are doar "<<V.n<<" elemente!"<<endl;
}
///GET ELEMENT
void Vector::GetElementVec()
{
    int poz;
    cout<<"\nDati pozitia de pe care doriti elementul: \n";
    cin>>poz;
    if(poz>=0&&poz<V.n)
    {
    cout<<"Elementul cautat este: ";
    if(!isEmpty())
    {
        cout<<V.vec[poz]<<endl;
    }
    }
    else
    {
    cout<<"Vectorul nu are pozitia:"<<poz;
    }
}
///SET ELEMENT
int Vector::setElementVec()
{
    int poz,x;
    cout<<"\nDati pozitia de pe care doriti sa setati elementul: \n";
    cin>>poz;
    if(poz>=0&&poz<V.n)
    {
    cout<<"\nDati elementul:\n";
    cin>>x;
    if(!isEmpty())
    {
        V.vec[poz]=x;
        cout<<"Elemntul a fost setat cu succes!"<<endl;
    }
    }
    else
    {
    cout<<"Vectorul nu are pozitia:"<<poz;
    }

}
///CAUTARE VECTOR IN AL DOILEA VECTOR
bool Vector::compara(Vector & v1)
{
    for(int i=0; i<V.n; i++)
        for(int j=0; j<v1.V.n; j++)
            if(V.vec[i]==v1.V.vec[j])
                return true;
    return false;

}
///CAUTARE ELEMENT IN VECTOR
bool Vector::cauta_elem( int k)
{
    for(int i=0; i<V.n; i++)
        if(k==V.vec[i])
        {
            return true;
        }
    return false;

}
///COPIERE
void Vector::copie(Vector &v1)
{
    V.n=v1.V.n;
    for(int i=0; i<v1.V.n; i++)
        V.vec[i]=v1.V.vec[i];
}



///REUNIUNE
void Vector::Reuniunea(Vector & v1, Vector & v2)
{
    Vector v3;
    v3.copie(v1);
    for(int i=0; i<v2.V.n; i++)
        v3.inserare_la_final(v2.V.vec[i]);

    for(int j=0; j<v3.V.n-2; j++)
        for(int k=j+1; k<v3.V.n-1; k++)
        {
            if(v3.V.vec[j]==v3.V.vec[k])
            {
                v3.sterge_v(k);
                k--;
            }
        }
    cout<<"\nA reunit cu B=";
    cout<<v3;

}

///INTERSECTIE
void Vector::Intersectia(Vector & v1, Vector & v2)
{
    Vector v3;
    for(int z=0; z<v2.V.n; z++)
    {
        if(v2.cauta_elem(v1.V.vec[z]))
            v3.inserare_la_final(v1.V.vec[z]);
    }
    if(!v3.isEmpty())
    {
        cout<<"\nA intersectat cu B=";
        cout<<v3;
    }
    else
        cout<<"Multimile nu au elemente comune!"<<endl;
}
///DIFERENTA
void Vector::Diferenta(Vector &v1, Vector & v2)
{
    Vector v3;
    for(int z=0; z<v2.V.n; z++)
    {
        if(!v2.cauta_elem(v1.V.vec[z]))
            v3.inserare_la_final(v1.V.vec[z]);
    }
    if(!v3.isEmpty())
    {
        cout<<"\nA-B=";
        cout<<v3;
    }
    else
        cout<<"Multimile nu au elemente diferite!"<<endl;

}

///DESTRUCTOR

Vector::~Vector()
{
    //dtor
}
