#include "mainwindow.h"
#include <QApplication>

#include <iostream>
#include "list.h"
#include "nodo.h"
#include "queue.h"
#include "stack.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    /*
    Pila<int> B;
    B.Push(2);
    B.Push(3);
    B.Push(12);
    B.Print();
    cout << "Se saca el elemento: " << B.Pop() << endl;
    B.Print();
    cout << B.Top() << endl;
    cout << "¿Está vacío?: " << B.IsEmpty() << endl;
    */

    /*
    Cola<int> C;
    C.Encolar(3);
    C.Print();
    C.Encolar(7);
    C.Print();
    cout << "Se desencola el valor: " << C.Desencolar() << endl;
    C.Print();
    cout << "La cabeza es: " << C.Front() << endl;
    cout << "¿Está vacío?: " << C.IsEmpty() << endl;
    */

    /*
    ListaDobleEnlazada<int> LDE;
    LDE.Add_Last(1);
    LDE.Print();
    LDE.Add_Front(3);
    LDE.Print();
    LDE.Add_Front(10);
    LDE.Print();
    LDE.Add_Last(2);
    LDE.Print();
    cout << "El máximo es: " << LDE.Max() << endl;
    cout << "El mínimo es: " << LDE.Min() << endl;
    LDE.Remove_Front();
    LDE.Print();
    LDE.Remove_Last();
    LDE.Print();
    cout << "¿Está el numero 1?: " << LDE.Find(1) << endl;
    cout << "¿Está el numero 10? " << LDE.Find(10) << endl;
    */
    /*
    ListaCircular<int> LC;
    LC.Add(10);
    LC.Print();
    LC.Add(19);
    LC.Print();
    LC.Add(5);
    LC.Print();

    Nodo<int> **pos;
    cout << "¿Está el numero 2?: " << LC.Find(2,pos) << endl;
    cout << "¿Está el numero 5?: " << LC.Find(5,pos) << endl;

    LC.Remove(5);
    LC.Print();
    cout << LC.m_plast -> m_dato << endl;

    */

    /*
    ListaDobleEnlazadaCircular<int> LDC;
    LDC.Add(6);
    LDC.Add(23);
    LDC.Add(8);
    LDC.Print();
    LDC.Remove(23);
    LDC.Print();
    cout << "Last: " << LDC.m_plast -> m_dato << endl;
    cout << "First: " << LDC.m_phead -> m_dato << endl;
  */



    return a.exec();
}
