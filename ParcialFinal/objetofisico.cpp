#include "objetofisico.h"

ObjetoFisico::ObjetoFisico(float x_,float y_,float r_)
{
this->x=x_;
this->y=350-y_;
this->r=r_;
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
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}
