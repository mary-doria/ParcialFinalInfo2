#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <iostream>
#include <string>
#include "bala.h"
#include "objetofisico.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,400,400);
    //BalaOfensiva=new Bala(250,250,10,5,1,1,1,300,"Ofensivo");scene->addItem(BalaOfensiva);
    //BalaDefensiva=new Bala(300,300,10,5,1,1,1,300,"Defensivo");scene->addItem(BalaDefensiva);

    ui->Caso1->hide();
    ui->Caso2->hide();
    ui->Caso3->hide();
    ui->Caso4->hide();
    ui->Caso5->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::caso1()
{
    BalaOfensiva->recorrerDistancia();
    BalaGuia = new Bala(BalaOfensiva->getX(),BalaOfensiva->getY(),BalaOfensiva->getR(),BalaOfensiva->getVelocidad(),BalaOfensiva->getAngulo(),BalaOfensiva->getK(),BalaOfensiva->getDt(),BalaOfensiva->getDistancia(),BalaOfensiva->getTipoObjeto());
    scene->addItem(BalaGuia);
    cout<<BalaOfensiva->getX()<<", "<<BalaOfensiva->getY()<<endl;
}

//Funcion Caso1
void MainWindow::on_Caso1_clicked()
{
 QList<QList<float>> parametros = CannonOfensivo->generarDisparo(CannonDefensivo, 0.05, true);
 QList<float> parametrosActuales = parametros.at(2);
 cout<<"Angulo fue:"<<parametrosActuales.at(4)<<endl;
 cout<<"Velocidad fue:"<<parametrosActuales.at(3)<<endl;
 //cout<<"Tiempo es :"<<bullet->getT()<<endl;
 cout<<"Y es: "<<parametrosActuales.at(1)<<endl;//ALTURA DE LA BALA OFENSIVA
 cout<<"X es: "<<parametrosActuales.at(0)<<endl;//DISTANCIA RECORRIDA DE LA BALA OFENSIVA
 if(parametrosActuales.at(8)==1){
     BalaOfensiva = new Bala(parametrosActuales.at(0),parametrosActuales.at(1),parametrosActuales.at(2),parametrosActuales.at(3),parametrosActuales.at(4),parametrosActuales.at(5),parametrosActuales.at(6),parametrosActuales.at(7),"Ofensivo");scene->addItem(BalaOfensiva);
 } else {
     BalaDefensiva = new Bala(parametrosActuales.at(0),parametrosActuales.at(1),parametrosActuales.at(2),parametrosActuales.at(3),parametrosActuales.at(4),parametrosActuales.at(5),parametrosActuales.at(6),parametrosActuales.at(7),"Defensivo");scene->addItem(BalaDefensiva);
 }
 QTimer *timerEnemigos = new QTimer();
 connect(timerEnemigos,SIGNAL(timeout()),this,SLOT(caso1()));
 timerEnemigos->start(1000);
}
//Funcion Caso2
void MainWindow::on_Caso2_clicked()
{

}
//Funcion Caso3
void MainWindow::on_Caso3_clicked()
{

}
//Funcion Caso4
void MainWindow::on_Caso4_clicked()
{

}
//Funcion Caso5
void MainWindow::on_Caso5_clicked()
{

}
//Para el primer Punto ,Configurar el frente de batalla(Posiciones de los cañones)
//HO
void MainWindow::on_pushButton_clicked()
{
    alturaOfensor=ui->HO->text().toFloat();

}
//HD
void MainWindow::on_pushButton_2_clicked()
{
   alturaDefensor=ui->HD->text().toFloat();
}
//Distancia entre cañones
void MainWindow::on_pushButton_3_clicked()
{
  Distancia=ui->D->text().toFloat();

}
//Funcion confirmar
void MainWindow::on_pushButton_4_clicked()
{
    if(alturaOfensor>=0 && alturaDefensor<300){
    if(alturaDefensor>=0 && alturaDefensor<300){
    if(Distancia>=100 && Distancia<350){
    CannonOfensivo=new ObjetoFisico(0,alturaOfensor,30,Distancia,"Ofensivo");scene->addItem(CannonOfensivo);
    CannonDefensivo=new ObjetoFisico(Distancia,alturaDefensor,30,Distancia,"Defensivo");scene->addItem(CannonDefensivo);

    ui->pushButton_4->hide();//Boton Confirmar
    ui->pushButton->hide();
    ui->HO->hide();
    ui->pushButton_2->hide();
    ui->HD->hide();
    ui->pushButton_3->hide();
    ui->D->hide();
    ui->Caso1->show();
    ui->Caso2->show();
    ui->Caso3->show();
    ui->Caso4->show();
    ui->Caso5->show();
    }
    else{
    Mensaje.setText("Coloca una Distancia dentro del Rango(Distancia>100 y Distancia<300)");
    Mensaje.setInformativeText("");
    Mensaje.exec();}

    }
    else{
    Mensaje.setText("Coloca una altura Defensor dentro del Rango(alturaDefensor>50 y alturaDefensor<350)");
    Mensaje.setInformativeText("");
    Mensaje.exec();}
    }
    else{
    Mensaje.setText("Coloca una altura Ofensor dentro del Rango(alturaOfensor>50 y alturaOfensor<350)");
    Mensaje.setInformativeText("");
    Mensaje.exec();}
}

//Las siguientes funciones no se usaran,estaran aqui para que aparezcan los cuadros de texto y graphicsview
void MainWindow::on_graphicsView_windowTitleChanged(const QString &title)
{

}

void MainWindow::on_HO_windowTitleChanged(const QString &title)
{

}

void MainWindow::on_HD_windowTitleChanged(const QString &title)
{

}

void MainWindow::on_D_windowTitleChanged(const QString &title)
{

}

