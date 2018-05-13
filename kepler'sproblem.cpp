#include <iostream>
#include <cmath>
#include "finalproyect.h"

int main(void)
{
  planet et;
  et.mass=88;
  et.pos.x=1.2;
  et.pos.y=0.5;
  et.vel.x=1.5;
  et.vel.y=3.0;
  et.force.x=2.0;
  et.force.y=2.0;

  for(double time=4.0; time<=20 ; time+=2.0){
   std::cout << et << std::endl;
   et.deltapos (time);
  }
}

