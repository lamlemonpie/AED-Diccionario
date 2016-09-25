#ifndef LIST_H
#define LIST_H


#include "node_simple.h"
#include <iostream>

using namespace std;

template <class T>

class List
{
private:
    Node_Simple<T> * m_phead;
public:
    List():m_phead(0){}

    bool find(T d, Node_Simple<T> **&p);
    bool Add(T d);
    bool Remove(T d);
    void Print();
};

//--------------------------------

template <class T>

void List<T>::Print()
{
    Node_Simple<T> *AUX = m_phead;
    while(AUX !=0 )
    {
        cout <<  AUX -> m_dato;
        AUX = AUX -> m_psig;
        if(AUX!=0)
            cout << " - ";
    }
    cout << endl;
}

//-------------------------------------

template <class T>

bool List<T>::find(T d, Node_Simple<T> **&p)
{
    p = &m_phead;
    while(*p)
    {
        if((*p)->m_dato == d) return true;
        if((*p)-> m_dato > d) return false;
        p= &((*p)-> m_psig);
    }
    return false;
}

//------------------------------------

template <class T>

bool List<T>::Add(T d)
{
    Node_Simple<T> **q;
    if( find(d,q)) return false;
    Node_Simple<T> *Nuevo = new Node_Simple<T>(d);
    Nuevo -> m_psig = *q;
    *q = Nuevo;
    return true;
}

//----------------------------------

template <class T>

bool List<T>::Remove(T d)
{
    Node_Simple<T> **q;
    if(!find(d,q)) return false;
    Node_Simple<T> *tmp = *q;
    *q = tmp -> m_psig;
    delete tmp;
    return true;
}

//-------------------------------------


#endif // LIST_H
