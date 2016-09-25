#ifndef NODO_H
#define NODO_H


#include <iostream>

using namespace std;

template <class T>

class Nodo
{
    public:
        T m_dato;
        Nodo<T> *m_pSon[2];
    public:
        Nodo (T d)
        {
            m_dato=d;
            m_pSon[0]=m_pSon[1]=0;
        }
};

#endif // NODO_H
