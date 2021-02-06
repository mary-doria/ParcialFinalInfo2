#include "objetofisico.h"
#include "qdebug.h"

using namespace std;


string ObjetoFisico::getTipoObjeto() const
{
    return tipoObjeto;
}

void ObjetoFisico::setTipoObjeto(const string &value)
{
    tipoObjeto = value;
}

QList<QList<float> > ObjetoFisico::generarDisparo(ObjetoFisico *cannonObjetivo, float radio, bool ofensivo)
{
    QList<QList<float>> listaParametros;
    QList<float> parametrosCorrectos;
    Bala *bullet;
    float a, v, d;
    int contador1=0;
    for(float i=0;i<20;i+=1){
      a = (3.1416/2)*(i/20);//ANGULO DEL CAÑON ATACANTE ENTRE 0 Y 90° CON INCREMENTOS DE 5°
      for(float j=0;j<20;j+=1){
      v = (100/50)*j;//VELOCIDAD INICIAL DE LA BALA OFENSIVA-COGER UNA VELOCIDAD MENOR QUE 100METROS CON INCREMENTOS DE 5METROS
      if(contador1<3){
        d = abs(this->getX()-cannonObjetivo->getX());
        qDebug()<<"d es"<<d;
        //bullet = new Bala(this->getX(), this->getY(), 20, v, a, 1, 1,distancia,"Ofensivo");
        Bala *bulletSimulada = new Bala(this->getX(), this->getY(), radio, v, a, 1, 0.1,distancia,"Ofensivo");
        bulletSimulada->recorrerDistanciaX(d);
        qDebug()<<"X es"<<bulletSimulada->getX();
        qDebug()<<"Y es"<<bulletSimulada->getY();
            if(bulletSimulada->detectarColision(cannonObjetivo->getY(), radio, d)){//SI LA ALTURA DE LA BALA SE ENCUENTRA ENTRE (HD-0.05d y HD+0.05d) o (HD-0.025d y HD+0.025d)
            //SE DA A ENTENDER SI LA ALTURA DE LA BALA ESTA A (0.05*d o 0.025*d) O MENOS DEL CAÑON DEFENSOR
            contador1 += 1;
            qDebug()<<"Colisiona";
            qDebug()<<"Cannon y"<<cannonObjetivo->getY();
            qDebug()<<"Bala y"<<bulletSimulada->getY();
            parametrosCorrectos.clear();
            parametrosCorrectos.push_back(this->getX());
            parametrosCorrectos.push_back(this->getY());
            parametrosCorrectos.push_back(5);
            parametrosCorrectos.push_back(v);
            parametrosCorrectos.push_back(a);
            parametrosCorrectos.push_back(1);
            parametrosCorrectos.push_back(0.1);
            parametrosCorrectos.push_back(distancia);
            parametrosCorrectos.push_back(1);
            listaParametros.push_back(parametrosCorrectos);

            }
        }
        if(contador1==3){
          break;
        }
        }
      if(contador1==30){
        break;
      }}
    return listaParametros;
}

ObjetoFisico::ObjetoFisico(float x_,float y_,float r_,float distancia_,string tipoObjeto_)
{
    this->x=x_;
    this->y=y_;
    this->r=r_;
    this->distancia=distancia_;
    this->tipoObjeto=tipoObjeto_;
    setPos(x,350-y);

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

