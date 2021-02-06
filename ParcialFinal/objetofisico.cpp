#include "objetofisico.h"

string ObjetoFisico::getTipoObjeto() const
{
    return tipoObjeto;
}

void ObjetoFisico::setTipoObjeto(const string &value)
{
    tipoObjeto = value;
}

ObjetoFisico::ObjetoFisico(float x_,float y_,float r_,float distancia_,string tipoObjeto_)
{
    this->x=x_;
    this->y=350-y_;
    this->r=r_;
    this->distancia=distancia_;
    this->tipoObjeto=tipoObjeto_;
    setPos(x,y);

}

float ObjetoFisico::getX() const
{
    return this->x;
}

void ObjetoFisico::setX(float value)
{
    this->x = value;
}

float ObjetoFisico::getY() const
{
    return this->y;
}

void ObjetoFisico::setY(float value)
{
    this->y = value;
}

QRectF ObjetoFisico::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);

}

void ObjetoFisico::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{   if(tipoObjeto=="Ofensivo"){
    painter->setBrush(Qt::red);
    painter->drawEllipse(-(r+0.025*distancia),-(r+0.025*distancia),2*(r+0.025*distancia),2*(r+0.025*distancia));}
    else if(tipoObjeto=="Defensivo"){
        painter->setBrush(Qt::yellow);
        painter->drawEllipse(-(r+0.05*distancia),-(r+0.05*distancia),2*(r+0.05*distancia),2*(r+0.05*distancia));

    }
    if(tipoObjeto=="Ofensivo"){
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());}
    else if(tipoObjeto=="Defensivo"){
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());

    }

}
