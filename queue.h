#ifndef QUEUE_H
#define QUEUE_H


#include "nodo.h"
#include <iostream>

using namespace std;

template <class T>
class Cola
{
public:
    Nodo<T> * m_phead;
    Nodo<T> * m_plast;
public:
    Cola()
    {
        m_phead = m_plast = 0;
    }

    void Print();
    void Encolar(T d);
    T Desencolar();
    T Front();
    bool IsEmpty();
};

//----------------------------
template <class T>
void Cola<T>::Print()
{
    Nodo<T> *AUX = m_phead;
    while(AUX!=0)
    {
        cout <<  AUX -> m_dato;
        AUX = AUX -> m_psig;
        if(AUX!=0)
            cout << " - ";
    }
    cout << endl;
}

//----------------------------

template <class T>
void Cola<T>::Encolar(T d)
{
    Nodo<T> * Nuevo =new Nodo<T>(d);
    if(m_phead!=0)
        m_plast->m_psig = Nuevo;
    else
        m_phead = Nuevo;
    m_plast = Nuevo;
}

//----------------------------

template <class T>
T Cola<T>::Desencolar()
{
    if(m_phead!=0)
    {
        Nodo<T> * tmp = m_phead;
        m_phead = m_phead -> m_psig;
        T valor = tmp -> m_dato;
        delete tmp;
        return valor;
    }
    return 0;
}

//---------------------------

template <class T>
T Cola<T>::Front()
{
    if(m_phead!=0)
        return m_phead -> m_dato;
    return 0;
}

//---------------------------

template <class T>
bool Cola<T>::IsEmpty()
{
    if(m_phead)
        return false;
    return true;
}

//---------------------------

#endif // QUEUE_H
