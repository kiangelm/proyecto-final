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

  for(double time=0.0; time<=0.25 ; time+=deltaT){
    
    //Comentadas las lineas para evitar al planeta "Marte moverse"
    //marte.deltaforce(et);
    //marte.deltavel(time);
    //marte.deltapos(time);
    et.deltaforce(marte);
    et.deltavel (time);
    et.deltapos (time);
    //et.print();
    //marte.print();
    std::cout << std::endl;
  }

  et.mass=80;
  et.pos.x=0.4;
  et.pos.y=0.0;
  et.vel.x=0.0;
  et.vel.y=sqrt(1.6/0.4);
  et.force.x=0.0;
  et.force.y=0.0;
  for(double time=0.0; time<=0.25 ; time+=deltaT){
    et.deltaforce (marte);
    et.deltaveleulerverlet2 (time);
    et.deltaposeulerverlet (time);
    et.deltaveleulerverlet (time)
    et.print();
    marte.print();
  }
}
