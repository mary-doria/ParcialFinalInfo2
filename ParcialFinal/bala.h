#ifndef BALA_H
#define BALA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <string>
#include "string.h"
#include "objetofisico.h"

using namespace std;

class Bala: public QGraphicsItem
{
private:
    float x,y,r,velocidad,angulo,distancia,t;
    string tipoObjeto;
    float g=1; //Gravedad
    float K; //Resistencia del aire
    float dt; //Delta de tiempo

public:
    Bala(float x_,float y_,float r_,float velocidad_,float angulo_,float K_,float dt_,float distancia_,string tipoObjeto_);
    //Posicion en x
    float getX() const;//Retorna el valor de x
    void setX(float value);//Actualiza el valor de la posicion en x
    //Posicion en y
    float getY() const;//Retorna el valor de y
    void setY(float value);//Actualiza el valor de la posicion en y
    //Velocidad la cual va a variar
    float getVelocidad() const;//Retorna el valor de la velocidad
    void setVelocidad(float value);//Actualiza el valor de la velocidad
    //Angulo el cual va a variar
    float getAngulo() const;//Retorna el valor del angulo
    void setAngulo(float value);//Actualiza el valor del angulo
    //Gravedad
    float getG() const;//Retorna el valor de la gravedad
    void setG(float value);//Actualiza el valor de la gravedad
    //Delta de tiempo
    float getDt() const;//Retorna el valor del delta de tiempo
    void setDt(float value);//Actualiza el delta de tiempo
    //Resistencia del aire
    float getK() const;//Retorna el valor de la resistencia al aire
    void setK(float value);//Actualiza la resistencia al aire
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    bool detectarColision(float cannonY, float radio, float d);
    void recorrerDistanciaX(float d);

    void recorrerDistancia();
    float getDistancia() const;
    void setDistancia(float value);
    string getTipoObjeto() const;
    void setTipoObjeto(const string &value);
    float getR() const;
    void setR(float value);
};

#endif // BALA_H
