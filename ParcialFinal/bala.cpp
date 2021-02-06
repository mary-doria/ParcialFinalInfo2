#include "bala.h"
#include "math.h"
#include "QDebug"

float Bala::getX() const
{
    return x;
}

void Bala::setX(float value)
{
    x = value;
}

float Bala::getY() const
{
    return y;
}

void Bala::setY(float value)
{
    y = value;
}

float Bala::getVelocidad() const
{
    return velocidad;
}

void Bala::setVelocidad(float value)
{
    velocidad = value;
}

float Bala::getAngulo() const
{
    return angulo;
}

void Bala::setAngulo(float value)
{
    angulo = value;
}

float Bala::getG() const
{
    return g;
}

void Bala::setG(float value)
{
    g = value;
}

float Bala::getDt() const
{
    return dt;
}

void Bala::setDt(float value)
{
    dt = value;
}


float Bala::getK() const
{
    return K;
}

void Bala::setK(float value)
{
    K = value;
}

QRectF Bala::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(tipoObjeto=="Ofensivo"){
        painter->setBrush(Qt::magenta);
        painter->drawEllipse(-(r+0.025*distancia),-(r+0.025*distancia),2*(r+0.025*distancia),2*(r+0.025*distancia));}
        else if(tipoObjeto=="Defensivo"){
            painter->setBrush(Qt::cyan);
            painter->drawEllipse(-(r+0.05*distancia),-(r+0.05*distancia),2*(r+0.05*distancia),2*(r+0.05*distancia));

        }
        if(tipoObjeto=="Ofensivo"){
        painter->setBrush(Qt::gray);
        painter->drawEllipse(boundingRect());}
        else if(tipoObjeto=="Defensivo"){
        painter->setBrush(Qt::gray);
        painter->drawEllipse(boundingRect());

        }
}

float Bala::getDistancia() const
{
    return distancia;
}

void Bala::setDistancia(float value)
{
    distancia = value;
}

string Bala::getTipoObjeto() const
{
    return tipoObjeto;
}

void Bala::setTipoObjeto(const string &value)
{
    tipoObjeto = value;
}

float Bala::getR() const
{
    return r;
}

void Bala::setR(float value)
{
    r = value;
}

Bala::Bala(float x_, float y_, float r_, float velocidad_, float angulo_,float K_,float dt_,float distancia_,string tipoObjeto_)
{
    this->x=x_;
    this->y=y_;
    this->r=r_;
    this->velocidad=velocidad_;
    this->angulo=angulo_;
    this->K=K_;
    this->dt=dt_;
    this->distancia=distancia_;
    this->tipoObjeto=tipoObjeto_;
    this->t=0;

    setPos(x,350-y);

}


bool Bala::detectarColision(float cannonY, float radio, float d)
{
    if(cannonY < y+ (radio*d) & cannonY > y-(radio*d)){
        return true;
    } else {
        return false;
    }
}

void Bala::recorrerDistanciaX(float d){
    this->x = d;
    this->t = d/(this->velocidad*cos(this->angulo));//PARA HALLAR EL TIEMPO EN LA COMPONENTE X SEGUN LA FORMULA DEL MOVIEMIENTO PARABOLICO
    qDebug()<<"t es"<<t;
    this->y = this->getY() +(this->velocidad*sin(this->angulo)*this->t) - (this->t*this->t*(g/2));//COMPONENTE EN Y DE LA FORMULA DEL TIRO PARABOLICO
    qDebug()<<"y es"<<y;
}

void Bala::recorrerDistancia()
{
    t += dt;
    this->x = x + velocidad*cos(angulo);
    this->y = y + (velocidad*sin(angulo) - g*t);
    setPos(x,350-y);
}
