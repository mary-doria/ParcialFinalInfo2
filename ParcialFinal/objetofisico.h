#ifndef OBJETOFISICO_H
#define OBJETOFISICO_H
#include <QGraphicsItem>
#include <QPainter>
using namespace std;

class ObjetoFisico: public QGraphicsItem
{
private:
 float x,y,r,distancia;

 string tipoObjeto;

public:
ObjetoFisico(float x_,float y_,float r_,float distancia_,string tipoObjeto_);//Atributos de la clase ,posicion en x y
//Posicion en x
float getX() const;//Retorna posicion en x
void setX(float value);//Actualiza la posicion en x
//Posicion en y
float getY() const;//Retorna posicion en y
void setY(float value);//Actualiza la posicion en y
QRectF boundingRect() const;
void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

string getTipoObjeto() const;
void setTipoObjeto(const string &value);
};

#endif // OBJETOFISICO_H
