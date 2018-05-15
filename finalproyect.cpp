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

void planet::deltapos (double t)
{
  pos.x=pos.x+vel.x*t;
  pos.y=pos.y+vel.y*t;
}

void planet::deltavel (double t)
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
