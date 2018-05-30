#include "finalproyect.h"
#include <fstream>
void planet::print (void)
{
  std::cout << T << "\t"<< pos.x << "\t" << pos.y << "\t"
	    << H << "\t" << L << "\t"
	    << A.x << "\t" << A.y ;

}

void planet::operator= (planet venus)
{
  mass=venus.mass;
  T=venus.T;
  H=venus.H;
  L=venus.L;
  pos.x=venus.pos.x;
  pos.y=venus.pos.y;
  vel.x=venus.vel.x;
  vel.y=venus.vel.y;
  force.x=venus.force.x;
  force.y=venus.force.y;
  velant.x=venus.velant.x;
  velant.y=venus.velant.y;
  posant.x=venus.posant.x;
  posant.y=venus.posant.y;
}

void planet::deltaposeuler (double t)
{
  pos.x=pos.x+vel.x*t;
  pos.y=pos.y+vel.y*t;
}

void planet::deltaveleuler (double t)
{
  vel.x=vel.x+force.x*t;
  vel.y=vel.y+force.y*t;
}

void planet::deltaforce (planet pluto)
{
  force.x=0;
  force.y=0;
  force.x=-(pos.x-pluto.pos.x)/(pow((pos.x-pluto.pos.x)*(pos.x-pluto.pos.x)+(pos.y-pluto.pos.y)*(pos.y-pluto.pos.y),1.5));
  force.y=-(pos.y-pluto.pos.y)/(pow((pos.x-pluto.pos.x)*(pos.x-pluto.pos.x)+(pos.y-pluto.pos.y)*(pos.y-pluto.pos.y),1.5));
}

void planet::initintegrationverlet (double t)
{velant.x=0;
  velant.y=0;
  velant.x= vel.x+t*force.x/(2) ;
  velant.y=vel.y+t*force.y/(2);
}

void planet::deltaposstromerverlet (double t)
{
  pos.x= pos.x+velant.x*t;
  pos.y=pos.y+velant.y*t;
}
void planet::deltavelstromerverlet(double t)
{
  vel.x=velant.x+t*force.x/(2);
  vel.y=velant.y+t*force.y/(2);
}
void planet::deltaposeuler2(double t)
{
  pos.x=pos.x+t*velant.x;
  pos.y=pos.y+velant.y*t;
}
void planet::velmidpoint (double t)
{
  velant.x=vel.x+t*force.x/(2);
  velant.y=vel.y+t*force.y/(2);
}
void planet::invariant ()
{
  H=(vel.x*vel.x+vel.y*vel.y)/2-1/(sqrt((pos.x*pos.x)+(pos.y*pos.y)));
  L=(pos.x*vel.y-pos.y*vel.x);
  A.x=vel.y*(pos.x*vel.y-pos.y*vel.x)-pos.x/(sqrt((pos.x*pos.x)+(pos.y*pos.y)));
  A.y=vel.x*(pos.x*vel.y-pos.y*vel.x)-pos.y/(sqrt((pos.x*pos.x)+(pos.y*pos.y)));
}

