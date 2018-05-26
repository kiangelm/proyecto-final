#include "finalproyect.h"
#include<fstream>
void planet::print (void)
{
  std::cout << pos.x << "\t" << pos.y << "\t"
	    << vel.x << "\t" << vel.y << "\t"
	    << force.x << "\t" << force.y << "\t";

}

void planet::operator= (planet venus)
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

void planet::initintegrationverlet (double t)
{
  posant.x= pos.x-vel.x*t+t*t*force.x/2*mass ;
  posant.y= pos.y-vel.y*t+t*t*force.y/2*mass ;
}

void planet::deltaposstromerverlet (double t)
{
  pos.x= 2*pos.x-posant.x+t*t*force.x;
  pos.y= 2*pos.y-posant.y+t*t*force.y;
}
void planet::deltaposeulerant2 (double t)
{
 velant.x= vel.x- force.x/mass*t;
 velant.y= vel.y- force.y/mass*t;
}
void planet::deltaposeuler2 (double t)
{
  pos.x=pos.x+t*(vel.x+velant.x)/2;
  pos.y=pos.y+t*(vel.y+velant.y)/2;
}
std::vector<double> planet::laplacerunge(void)
{std::vector<double> a(2);
  a[0]=mass*mass*vel.y*(pos.x*vel.y-pos.y*vel.x)-pos.x/(sqrt((pos.x*pos.x)+(pos.y*pos.y)));
  a[1]=mass*mass*vel.x*(pos.x*vel.y-pos.y*vel.x)-pos.y/(sqrt((pos.x*pos.x)+(pos.y*pos.y)));
  return a;
}
