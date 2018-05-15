#include <iostream>
#include <cmath>
#include "finalproyect.h"

int main(void)
{
  double deltaT = 0.0005;
  
  planet et;
  et.mass=88;
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

  for(double time=0.0; time<=5 ; time+=deltaT){
    et.deltaforce(marte);
    marte.deltaforce(et);
    marte.deltavel(time);
    marte.deltapos(time);
    et.deltavel (time);
    et.deltapos (time);
    et.print();
    //marte.print();
  }
}


