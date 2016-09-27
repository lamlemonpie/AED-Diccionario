#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <nodo.h>
#include <iostream>
#include <QDebug>


template<class T>
class AVLTree {
public:
    Nodo<T> * m_pRoot;
public:
    AVLTree<T>()
    {
        m_pRoot = 0;
    }
    void RDD(Nodo<T> *&);
    void RII(Nodo<T> *&);
    void RDI(Nodo<T> *&);
    void RID(Nodo<T> *&);
    int height(Nodo<T> *);
    void FactorEquilibrio(Nodo<T> *);
    void Rebalanceo(Nodo<T> *);
    bool Insertar(T d);
    void In_orden(Nodo<T> *);
    void Pre_orden(Nodo<T> *);
};

//-----------------------------

template<class T>
void AVLTree<T> :: RDD(Nodo<T> *&p)
{
    Nodo<T> * q = p->m_pSon[1];
    p->m_pSon[1] = q -> m_pSon[0];
    q->m_pSon[0] = p;
    p->FE = q->FE = 0;
    q-> m_pParent = p -> m_pParent;
    p = q;
    p->m_pSon[0]->m_pParent = p;
    p->m_pSon[1]->m_pParent = p;

}

//----------------------------

template<class T>
void AVLTree<T> :: RII(Nodo<T> *&p)
{
    Nodo<T> * q = p->m_pSon[0];
    p->m_pSon[0] = q ->m_pSon[1];
    q->m_pSon[1] = p;
    p->FE = q->FE = 0;
    q-> m_pParent = p -> m_pParent;
    p = q;
    p->m_pSon[1]->m_pParent = p;
    p->m_pSon[0]->m_pParent = p;

}

//--------------------------------

template<class T>
void AVLTree<T> :: RDI(Nodo<T> *& p)
{
    Nodo<T> *q = p->m_pSon[1];
    Nodo<T> *r = q->m_pSon[0];
    //cout << "Hijo 0 de " << r->m_dato << " : "<< r->m_pSon[0] << " sera hijo derecho de " << p->m_dato;
    p->m_pSon[1] = r->m_pSon[0];
    //cout << "Hijo 1 de " << r->m_dato << " : "<< r->m_pSon[1] << " sera hijo izquierdo de " << q->m_dato;
    q->m_pSon[0] = r->m_pSon[1];
    //cout << p->m_dato << " sera hijo 0 de " << r->m_dato;
    r->m_pSon[0] = p;
    //cout << q->m_dato << " sera hijo 1 de " << r->m_dato;
    r->m_pSon[1] = q;


    switch(r->FE)
    {
        case 0:
            r->FE=0;
            p->FE=0;
            q->FE=0;
            break;
        case 1:
            r->FE= 0;
            p->FE= -1;
            q->FE= 0;
            break;
        case -1:
            r->FE= 0;
            p->FE= 0;
            q->FE= 1;
            break;
    }
    r -> m_pParent = p -> m_pParent;
    //cout << "El padre de :" << q->m_dato << " sera " << r->m_dato;
    q -> m_pParent = r;
    //cout << "El padre de :" << p->m_dato << " sera " << r->m_dato;
    p -> m_pParent = r;

    p=r;
}

//------------------------------------------------------

template<class T>
void AVLTree<T> :: RID(Nodo<T> *& p)
{
    Nodo<T> *q = p->m_pSon[0];
    Nodo<T> *r = q->m_pSon[1];
    //cout << "Hijo 1 de " << r->m_dato << " : "<< r->m_pSon[1] << " sera hijo 0 de " << p->m_dato;
    p->m_pSon[0] = r->m_pSon[1];
    //cout << "Hijo 0 de " << r->m_dato << " : "<< r->m_pSon[0] << " sera hijo 1 de " << q->m_dato;
    q->m_pSon[1] = r->m_pSon[0];
    //cout << p->m_dato << " sera hijo 1 de " << r->m_dato;
    r->m_pSon[1] = p;
    //cout << q->m_dato << " sera hijo 0 de " << r->m_dato;
    r->m_pSon[0] = q;

    switch(r->FE)
    {
        case 0:
            r->FE=0;
            p->FE=0;
            q->FE=0;
            break;
        case 1:
            r->FE= 0;
            p->FE= 0;
            q->FE= -1;
            break;
        case -1:
            r->FE= 0;
            p->FE= 1;
            q->FE= 0;
            break;
    }
    r -> m_pParent = p -> m_pParent;
    //cout << "El padre de :" << q->m_dato << " sera " << r->m_dato;
    q -> m_pParent = r;
    //cout << "El padre de :" << p->m_dato << " sera " << r->m_dato;
    p -> m_pParent = r;

    p=r;
}

//--------------------------------------------

template<class T>
int AVLTree<T>::height(Nodo<T> * p)
{
    if(!p)
        return -1;
    return (1 + max(height(p->m_pSon[0]) , height(p->m_pSon[1])));
}

//--------------------------------------------------------------

template<class T>
void AVLTree<T>::FactorEquilibrio(Nodo<T> *p)
{
    int faceq;
    faceq = height(p -> m_pSon[1]) - height(p -> m_pSon[0]);
    p -> FE = faceq;
    cout << "Actualizamos el Factor de Equilibrio de " << p-> m_dato << " en " << faceq << endl;
}

//-------------------------------------------------------------

template<class T>
void AVLTree<T>::Rebalanceo(Nodo<T> *p)
{
    FactorEquilibrio(p);
    if(p -> FE == -2)
    {
        cout << "El FE es -2, se rebalanceara" << endl;
        if(height(p->m_pSon[0]->m_pSon[0]) >= height(p->m_pSon[0]->m_pSon[1]))
        {
            cout << " Rebalanceo RII" << endl;
            RII(p);
        }
        else
        {
            cout << "Rebalanceo RID" << endl;
            RID(p);
        }
    }

    else if(p -> FE == 2)
    {
        cout << "El FE es 2, se rebalanceara" << endl;
        if(height(p->m_pSon[1]->m_pSon[1]) >= height(p->m_pSon[1]->m_pSon[0]))
        {
            cout << "Rebalanceo RDD" << endl;
            RDD(p);
        }
        else
        {
            cout << "Rebalanceo RDI" << endl;
            RDI(p);
        }

    }

    if(p-> m_pParent)
        Rebalanceo(p->m_pParent);
    else
        m_pRoot = p;
}

//----------------------------------------------------------------------------

template<class T>
bool AVLTree<T>::Insertar(T d)
{
    cout << "Se intentara insertar " << d << endl;
    if(m_pRoot == NULL)
    {
        m_pRoot = new Nodo<T> (d, NULL);
        cout << "Se crea raiz con " << d << endl;
    }

    else
    {
        Nodo<T>
        *n = m_pRoot,
        *parent;

        while (true)
        {
            if (n->m_dato == d)
                return false;

            parent = n;

            bool goLeft = n->m_dato > d;
            n = goLeft ? n->m_pSon[0] : n->m_pSon[1];
            cout << "goleft es: " << goLeft << " del nodo " << parent -> m_dato << endl;

            if (n == NULL)
            {
                if (goLeft)
                {
                    parent->m_pSon[0] = new Nodo<T>(d, parent);
                    cout << "Se crea nodo hijo izquierdo con: " << d << " con padre " << parent->m_dato << endl;
                }
                else
                {
                    parent->m_pSon[1] = new Nodo<T>(d, parent);
                    cout << "Se crea nodo hijo derecho con: " << d << " con padre " << parent->m_dato << endl;
                }
                cout << "Se Rebalancea al padre " << endl;
                Rebalanceo(parent);
                break;
            }
        }
    }
    return true;
}

//------------------------------------------------------------------------------------------
template<class T>
void AVLTree<T> :: Pre_orden(Nodo<T> *p)
{
    if(!p)
        return;
    cout<<p->m_dato<<" "<<p->FE<<"  ";
    Pre_orden(p->m_pSon[0]);
    Pre_orden(p->m_pSon[1]);
}

//----------------------------------------

template<class T>
void AVLTree<T> :: In_orden(Nodo<T> *p)
{
    if(!p)
        return;
    In_orden(p->m_pSon[0]);
    cout<<p->m_dato<<" "<<p->FE<<"  ";
    In_orden(p->m_pSon[1]);
}

//----------------------------------------




#endif // AVL_TREE_H
