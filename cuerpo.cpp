#include "cuerpo.h"
#include <math.h>
#include <cmath>
cuerpo::cuerpo(float PX_, float PY_, float VX_, float VY_, float mass, float R_){  //se asignan los atributos.
    PX = PX_;
    PY = PY_;
    VX = VX_;
    VY = VY_;
    masa = mass;
    AX = 0;
    AY =0;
    G = 6.67384*(pow(10, -11));
    R = R_;
}

float cuerpo::getX(){     //retorna la posicion en x
    return PX;
}

float cuerpo::getY(){      //retorna la posicion y.
    return PY;
}

float cuerpo::get_mass(){     //retorna la masa.
    return masa;
}

float cuerpo::getR(){
    return R;
}

void cuerpo::acelerar(float px2_, float py2_, float mass2){        //requiere posiciones tomadas de otro cuerpo y asigna las aceleraciones.
    angulo = atan2((py2_-PY), (px2_-PX));
    radio = pow((pow((px2_-PX), 2) + pow((py2_-PY),2)),1/2);
    AX =AX + (((G*mass2)/(radio*radio))*cos(angulo));
    AY =AY + (((G * mass2)/(radio*radio))* sin(angulo));
}

void cuerpo::actualizar(float dt){                             //calcula las posiciones en x y y de los cuerpos.
    VX = VX + (AX*dt);
    VY = VY + (AY*dt);
    PX = PX + (VX*dt) + ((AX*(dt*dt))/2);
    PY = PY + (VY*dt) + ((AY*(dt*dt))/2);
}
