#include <iostream>
#include <cmath>
#include "finalproyect.h"

int main(void)
{
  double deltaT = 0.00005;

  planet et;
  et.mass=80;
  et.pos.x=0.4;
  et.pos.y=0.0;
  et.vel.x=0.0;
  et.vel.y=sqrt(1.6/0.4);
  et.force.x=0.0;
  et.force.y=0.0;

  planet marte;
  marte.mass=9000;
  marte.pos.x=0.0;
  marte.pos.y=0.0;
  marte.vel.x=0.0;
  marte.vel.y=0.0;
  marte.force.x=0.0;
  marte.force.y=0.0;
  planet alpha = et;
  planet beta = marte;
//metodo de euler
  for(double time=0.0; time<=0.05 ; time+=deltaT){

    //Comentadas las lineas para evitar al planeta "Marte moverse"
    beta.deltaforce(et);
    beta.deltaveleuler(time);
    beta.deltaposeuler(time);
    alpha.deltaforce(marte);
    alpha.deltaveleuler (time);
    alpha.deltaposeuler (time);
    alpha.print();
    //beta.print();
    std::cout << std::endl;
  }
  alpha = et;
  beta = marte;
//metodo de euler implisito
for(double time=0.0; time<=0.25 ; time+=deltaT/10){

    //Comentadas las lineas para evitar al planeta "Marte moverse"
    //beta.deltaforce(et);
    //beta.deltaveleuler(time);
    //beta.deltaposeuler(time);
    alpha.deltaforce(marte);
    alpha.deltaveleuler (time);
    alpha.deltaposeulernxt2  (time);
    alpha.deltaposeuler2  (time);
    alpha.print();
    //beta.print();
    std::cout << std::endl;
  }
//metodo storm velvet

}
