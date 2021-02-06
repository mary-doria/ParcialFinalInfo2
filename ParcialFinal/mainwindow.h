#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <string>
#include <QMessageBox>
//Clase donde se dibujan las balas y su trayectoria
#include "bala.h"
//Clase donde se dibujan los cañones
#include "objetofisico.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene *scene;
    ObjetoFisico *CannonOfensivo,*CannonDefensivo;
    Bala *BalaDefensiva,*BalaOfensiva,*BalaNeutralizadora;


private slots:
    void on_Caso1_clicked();

    void on_Caso2_clicked();

    void on_Caso3_clicked();

    void on_Caso4_clicked();

    void on_Caso5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_graphicsView_windowTitleChanged(const QString &title);

    void on_HO_windowTitleChanged(const QString &title);

    void on_HD_windowTitleChanged(const QString &title);

    void on_D_windowTitleChanged(const QString &title);

    void on_pushButton_4_clicked();//Boton confirmar

private:
    Ui::MainWindow *ui;
    //Valores estandar en el caso si el usuario no ingresa valores
float alturaOfensor=350,alturaDefensor=350,Distancia=100;
QMessageBox Mensaje;

};
#endif // MAINWINDOW_H
