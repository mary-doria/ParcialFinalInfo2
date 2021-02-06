#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <iostream>
#include <string>
#include "bala.h"
#include "objetofisico.h"
using namespace std;
//Estudiante: Mary Andrea Doria Gomez
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Creacion de la escena donde iran los objetos
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,400,400);
    //Inicialmente se esconden los botones de los casos
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
//Funcion actualizar caso 1
void MainWindow::caso1()
{

    balasGuia.clear();//Se limpia la lista de balas
    BalaOfensiva->recorrerDistancia();
    //Se obtienen los atributos para las bala,algunos dados por el usuario otros predeterminados
    BalaGuia = new Bala(BalaOfensiva->getX(),BalaOfensiva->getY(),BalaOfensiva->getR(),BalaOfensiva->getVelocidad(),BalaOfensiva->getAngulo(),BalaOfensiva->getK(),BalaOfensiva->getDt(),BalaOfensiva->getDistancia(),BalaOfensiva->getTipoObjeto());
    balasGuia.push_back(BalaGuia);//Se agregan los objetos a una lista la cual servira para visualizar el recorrido
    scene->addItem(BalaGuia);//Se van agregando los objetos a escena
    //Se obtienen los 3 disparos en escena
    if(BalaOfensiva->getX()>=CannonDefensivo->getX()){
        balasMostradas +=1;
        if(balasMostradas<3){//Condicion para generar el maximo de disparos
            timerEnemigos->stop();//Se reinicia el timer para cada disparo
            balasMostradas =0;//Las balas mostradas en pantalla se reinician para cada disparo
            on_Caso1_clicked();//Dado que el boton es un slot ,se ejecuta lo que hay dentro de el para cada disparo
        }
    }

    cout<<BalaOfensiva->getX()<<", "<<BalaOfensiva->getY()<<endl;//Se obtiene la posicion en x y y de la bala en consola
}
//Funcion actualizar caso 2
void MainWindow::caso2()
{
    balasGuia.clear();//Se limpia la lista de balas
    BalaDefensiva->recorrerDistancia();//Recorrido de la Bala
    //Se obtienen los atributos para la bala,algunos dados por el usuario otros predeterminados
    BalaGuia = new Bala(BalaDefensiva->getX(),BalaDefensiva->getY(),BalaDefensiva->getR(),BalaDefensiva->getVelocidad(),BalaDefensiva->getAngulo(),BalaDefensiva->getK(),BalaDefensiva->getDt(),BalaDefensiva->getDistancia(),BalaDefensiva->getTipoObjeto());
    balasGuia.push_back(BalaGuia);//Se agregan los objetos a una lista la cual servira para visualizar el recorrido
    scene->addItem(BalaGuia);//Se van agregando los objetos a escena
    //Se obtienen los 3 disparos en escena
    if(BalaDefensiva->getX()<=CannonOfensivo->getX()){
        balasMostradas +=1;
        if(balasMostradas<3){//Condicion para generar el maximo de disparos
            timerEnemigos->stop();//Se reinicia el timer para cada disparo
            on_Caso2_clicked();//Dado que el boton es un slot ,se ejecuta lo que hay dentro de el para cada disparo
            balasMostradas =0;//Las balas mostradas en pantalla se reinician para cada disparo
        }
    }
    cout<<BalaDefensiva->getX()<<", "<<BalaDefensiva->getY()<<endl;//Se obtiene la posicion en x y y de la bala en consola

}

//Funcion Caso1
void MainWindow::on_Caso1_clicked()
{
 //Se crea una lista de lista para almacenar cada objeto(bala) con sus atributos
 QList<QList<float>> parametros = CannonOfensivo->generarDisparo(CannonDefensivo, 0.05, true);
 //Se crea una lista para obtener los atributos (esto para cada objeto)
 QList<float> parametrosActuales = parametros.at(balasMostradas);
 //Codigo Reutilizado del parcial2(Se comprueban los parametros de salida)
 cout<<"Angulo fue:"<<parametrosActuales.at(4)<<endl;
 cout<<"Velocidad fue:"<<parametrosActuales.at(3)<<endl;
 cout<<"Y es: "<<parametrosActuales.at(1)<<endl;//ALTURA DE LA BALA OFENSIVA
 cout<<"X es: "<<parametrosActuales.at(0)<<endl;//DISTANCIA RECORRIDA DE LA BALA OFENSIVA
 //Se escoge la bala segun el caso
 if(parametrosActuales.at(8)==1){
     BalaOfensiva = new Bala(parametrosActuales.at(0),parametrosActuales.at(1),parametrosActuales.at(2),parametrosActuales.at(3),parametrosActuales.at(4),parametrosActuales.at(5),parametrosActuales.at(6),parametrosActuales.at(7),"Ofensivo");scene->addItem(BalaOfensiva);
 } else {
     BalaDefensiva = new Bala(parametrosActuales.at(0),parametrosActuales.at(1),parametrosActuales.at(2),parametrosActuales.at(3),parametrosActuales.at(4),parametrosActuales.at(5),parametrosActuales.at(6),parametrosActuales.at(7),"Defensivo");scene->addItem(BalaDefensiva);
 }
 //Timer que actualiza en n tiempo la posicion de la bala
 timerEnemigos = new QTimer();
 connect(timerEnemigos,SIGNAL(timeout()),this,SLOT(caso1()));
 timerEnemigos->start(1000);
}
//Funcion Caso2
void MainWindow::on_Caso2_clicked()
{
    balasMostradas=1;
    //Se crea una lista de lista para almacenar cada objeto(bala) con sus atributos
    QList<QList<float>> parametros = CannonDefensivo->generarDisparo(CannonOfensivo, 0.025, false);
    //Se crea una lista para obtener los atributos (esto para cada objeto)
    QList<float> parametrosActuales = parametros.at(balasMostradas);
   //Codigo Reutilizado del parcial2(Se comprueban los parametros de salida)
    cout<<"Angulo fue:"<<parametrosActuales.at(4)<<endl;
    cout<<"Velocidad fue:"<<parametrosActuales.at(3)<<endl;
    //cout<<"Tiempo es :"<<bullet->getT()<<endl;
    cout<<"Y es: "<<parametrosActuales.at(1)<<endl;//ALTURA DE LA BALA OFENSIVA
    cout<<"X es: "<<parametrosActuales.at(0)<<endl;//DISTANCIA RECORRIDA DE LA BALA OFENSIVA
     //Se escoge la bala segun el caso
    if(parametrosActuales.at(8)==1){
        BalaOfensiva = new Bala(parametrosActuales.at(0),parametrosActuales.at(1),parametrosActuales.at(2),parametrosActuales.at(3),parametrosActuales.at(4),parametrosActuales.at(5),parametrosActuales.at(6),parametrosActuales.at(7),"Ofensivo");scene->addItem(BalaOfensiva);
    } else {
        BalaDefensiva = new Bala(parametrosActuales.at(0),parametrosActuales.at(1),parametrosActuales.at(2),-parametrosActuales.at(3),parametrosActuales.at(4),parametrosActuales.at(5),parametrosActuales.at(6),parametrosActuales.at(7),"Defensivo");scene->addItem(BalaDefensiva);
    }
    //Timer que actualiza en n tiempo la posicion de la bala
    timerEnemigos = new QTimer();
    connect(timerEnemigos,SIGNAL(timeout()),this,SLOT(caso2()));
    timerEnemigos->start(1000);
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
    alturaOfensor=ui->HO->text().toFloat();//Se convirte en float lo que esta en el cuadro de texto

}
//HD
void MainWindow::on_pushButton_2_clicked()
{
   alturaDefensor=ui->HD->text().toFloat();//Se convirte en float lo que esta en el cuadro de texto
}
//Distancia entre cañones
void MainWindow::on_pushButton_3_clicked()
{
  Distancia=ui->D->text().toFloat();//Se convirte en float lo que esta en el cuadro de texto

}
//Funcion confirmar
void MainWindow::on_pushButton_4_clicked()
{
    //Condiciones para poder simular
    if(alturaOfensor>=0 && alturaDefensor<300){
    if(alturaDefensor>=0 && alturaDefensor<300){
    if(Distancia>=100 && Distancia<350){
    //Se crea los punteros y se agregan a escena
    CannonOfensivo=new ObjetoFisico(0,alturaOfensor,30,Distancia,"Ofensivo");scene->addItem(CannonOfensivo);
    CannonDefensivo=new ObjetoFisico(Distancia,alturaDefensor,30,Distancia,"Defensivo");scene->addItem(CannonDefensivo);
    //Se esconden los botones de parametros iniciales
    ui->pushButton_4->hide();//Boton Confirmar
    ui->pushButton->hide();
    ui->HO->hide();
    ui->pushButton_2->hide();
    ui->HD->hide();
    ui->pushButton_3->hide();
    ui->D->hide();
    //Se muestran los botones de los casos
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

