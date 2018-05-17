#include "finalproyect.h"

void planet::print (void)
{
  std::cout << pos.x << "\t" << pos.y << "\t" 
	    << vel.x << "\t" << vel.y << "\t"
	    << force.x << "\t" << force.y << std::endl;

}

planet planet::operator= (planet venus)
{
  mass=venus.mass;
  pos.x=venus.pos.x;
  pos.y=venus.pos.y;
  vel.x=venus.vel.x;
  vel.y=venus.vel.y;
  force.x=venus.force.x;
  force.y=venus.force.y;
}

void planet::deltaposeuler (double t)
{
  pos.x=pos.x+vel.x*t;
  pos.y=pos.y+vel.y*t;
}

void planet::deltaveleuler (double t)
{
  vel.x=vel.x+force.x/mass*t;
  vel.y=vel.y+force.y/mass*t;
}

void planet::deltaforce (planet pluto)
{
  force.x=0;
  force.y=0;
  force.x=-(pos.x-pluto.pos.x)/(pow((pos.x-pluto.pos.x)*(pos.x-pluto.pos.x)+(pos.y-pluto.pos.y)*(pos.y-pluto.pos.y),1.5))*mass;
  force.y=-(pos.y-pluto.pos.y)/(pow((pos.x-pluto.pos.x)*(pos.x-pluto.pos.x)+(pos.y-pluto.pos.y)*(pos.y-pluto.pos.y),1.5))*mass;
}
void planet::deltaposeuler2 (double t)
{
  pos.x=pos.x+vel.x*t;
  pos.y=pos.y+vel.y*t;
}
void planet::deltaveleuler2 (double t)
{
  vel.x=vel.x+force.x/mass*t;
  vel.y=vel.y+force.y/mass*t;
}
void planet::deltaposeulerverlet (double t)
{
  pos.x=pos.x+(vel.x+t/2.0*force.x/mass)*t;
  pos.y=pos.y+(vel.y+t/2.0*force.y/mass)*t;
}
void planet::deltaveleulerverlet (double t, planet beta)
{
	double Fx = -(pos.x-pluto.pos.x)/(pow((pos.x-pluto.pos.x)*(pos.x-pluto.pos.x)+(pos.y-pluto.pos.y)*(pos.y-pluto.pos.y),1.5))*mass;
	double Fy = -(pos.y-pluto.pos.y)/(pow((pos.x-pluto.pos.x)*(pos.x-pluto.pos.x)+(pos.y-pluto.pos.y)*(pos.y-pluto.pos.y),1.5))*mass;
  vel.x=vel.x+force.x/mass*t/2.0+t/2.0*Fx/mass;
  vel.y=vel.y+force.y/mass*t/2.0+t/2.0*Fy/mass;
}