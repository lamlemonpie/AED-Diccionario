#ifndef NODO_H
#define NODO_H


#include <iostream>

using namespace std;

template <class T>

class Nodo
{
    public:
        T m_dato;
        int FE;
        Nodo<T> *m_pSon[2];
        Nodo<T> * m_pParent;
    public:
        Nodo (T d, Nodo<T> * P)
        {
            m_dato=d;
            FE = 0;
            m_pSon[0]=m_pSon[1]=0;
            m_pParent = P;
        }
};

#endif // NODO_H
