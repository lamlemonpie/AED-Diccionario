#ifndef NODE_SIMPLE_H
#define NODE_SIMPLE_H

#include <iostream>

using namespace std;

template <class T>

class Node_Simple
{
public:
    T m_dato;
    Node_Simple<T> *m_psig;
    Node_Simple<T> *m_pant;
public:
    Node_Simple(T d)
    {
        m_dato = d;
        m_psig = 0;
        m_pant = 0;
    }
    //Nodo2(T d):m_dato(d),m_psig(0){};

private:
   /* T m_dato;
    Nodo<T> *m_psig;
    */
};

#endif // NODE_SIMPLE_H
