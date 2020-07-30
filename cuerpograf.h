#ifndef CUERPOGRAF_H
#define CUERPOGRAF_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "cuerpo.h"
class cuerpograf: public QGraphicsItem          //Clase para graficar las esferas
{
public:
    cuerpograf(float x, float y, float vx, float vy, float m, float r);
    ~cuerpograf();
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto
    void setEscala(float s);
    void actualizar(float dt);
    cuerpo* getEsf();
private:
    cuerpo* esf;
    float escala;
};

#endif // CUERPOGRAF_H
