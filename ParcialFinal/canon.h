#ifndef CANON_H
#define CANON_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>
#include "objetofisico.h"


class Canon: public QGraphicsItem
{
protected:
    float x,y,r;
public:
    Canon(float x_,float y_,float r_);
    /*bool generarDisparo(Canon *cannonObjetivo, float radio, bool ofensivo);
    bool generarDisparo3(Canon *cannonObjetivo, float radioO, float radioD, bool ofensivo);
    bool generarDisparo5(Canon *cannonObjetivo, float radioO, float radioD, bool ofensivo);*/
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
};

#endif // CANON_H
