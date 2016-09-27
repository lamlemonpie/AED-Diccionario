#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "avl_tree.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    AVLTree<int> Arbol;
   // Arbol.Insert(11);
    Arbol.Insertar(8);
    Arbol.Insertar(9);
    Arbol.Insertar(10);
   // Arbol.Insert(12);
    //Arbol.Insert(9);
    //Arbol.Insert(5);
    //Arbol.Insert(7);
    //Arbol.Insert(4);
    //Arbol.Insert(6);
    Arbol.In_orden(Arbol.m_pRoot);

}
