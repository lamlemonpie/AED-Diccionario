#ifndef STACK_H
#define STACK_H


#include <iostream>
#include "nodo.h"

using namespace std;

template <class T>

class Pila
{
public:
    Nodo<T> * m_ptope;
public:
    Pila()
    {
        m_ptope = 0;
    }
    void Print();
    void Push(T d);
    T Pop();
    T Top();
    bool IsEmpty();
};

//------------------------

template <class T>
void Pila<T>::Print()
{

    Nodo<T> *AUX = m_ptope;
    while(AUX!=0)
    {
        cout <<  AUX -> m_dato;
        AUX = AUX -> m_psig;
        if(AUX!=0)
            cout << " - ";
    }
    cout << endl;
}

//-------------------------

template <class T>
void Pila<T>::Push(T d)
{
    Nodo<T> *Nuevo = new Nodo<T>(d);
    if(m_ptope==0)
    {
        m_ptope = Nuevo;
    }
    else
    {
        Nuevo -> m_psig = m_ptope;
        m_ptope = Nuevo;
    }
}

//-----------------------------------

template <class T>
T Pila<T>::Pop()
{
    if(m_ptope != 0)
    {
        Nodo<T> *tmp = m_ptope;
        m_ptope = m_ptope -> m_psig;
        T valor = tmp -> m_dato;
        delete tmp;
        return valor;
    }
    return 0;
}

//-----------------------------------

template <class T>
T Pila<T>::Top()
{
    return m_ptope -> m_dato;
}

//--------------------------------

template <class T>
bool Pila<T>::IsEmpty()
{
    if (m_ptope)
        return false;
    return true;
}

#endif // STACK_H
