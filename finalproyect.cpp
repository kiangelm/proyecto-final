#include "finalproyect.h"

/**
 * Constructores
 */
planet::planet() {}
planet::planet(const double Mass,
	       const double pos_x,
	       const double pos_y,
	       const double vel_x,
	       const double vel_y,
	       const double force_x,
	       const double force_y)
{
  mass = Mass;
  pos.x = pos_x;
  pos.y = pos_y;
  vel.x = vel_x;
  vel.y = vel_y;
  force.x = force_x;
  force.y = force_y;
}




/**
 * Impresión
 */
void planet::print (void)
{
  std::cout << pos.x << "\t" << pos.y << "\t"
	    << vel.x << "\t" << vel.y << "\t"
	    << force.x << "\t" << force.y;
}

std::ostream & operator<<(std::ostream & os, const planet & Planet)
{
  os << Planet.pos.x << "\t" << Planet.pos.y << "\t"
     << Planet.vel.x << "\t" << Planet.vel.y << "\t"
     << Planet.force.x << "\t" << Planet.force.y;
}

/**
 * Operadores
 */
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




 
/**
 * Interacciones entre planetas
 */

/**
 * Cambio de fuerza
 */
void planet::deltaforce (planet pluto)
{
  force.x=-(pos.x-pluto.pos.x)/(pow((pos.x-pluto.pos.x)*(pos.x-pluto.pos.x)+(pos.y-pluto.pos.y)*(pos.y-pluto.pos.y),1.5))*mass;
  force.y=-(pos.y-pluto.pos.y)/(pow((pos.x-pluto.pos.x)*(pos.x-pluto.pos.x)+(pos.y-pluto.pos.y)*(pos.y-pluto.pos.y),1.5))*mass;
}

/**
 * Euler
 */
void planet::euler_deltapos (double t)
{
  pos.x=pos.x+vel.x*t;
  pos.y=pos.y+vel.y*t;
}

void planet::euler_deltavel (double t)
{
  vel.x=vel.x+force.x/mass*t;
  vel.y=vel.y+force.y/mass*t;
}


/**
 * Stromer-Verlet
 */
void planet::verlet_initintegration (double t)
{
  posant.x = pos.x-vel.x*t+t*t*force.x/2*mass;
  posant.y = pos.y-vel.y*t+t*t*force.y/2*mass;
}

void planet::verlet_deltapos (double t)
{
  pos.x = 2*pos.x-posant.x+t*t*force.x;
  pos.y = 2*pos.y-posant.y+t*t*force.y;
}



/**
 * Euler 2
 */
void planet::euler2_deltaposant (double t)
{
 velant.x= vel.x- force.x/mass*t;
 velant.y= vel.y- force.y/mass*t;
}

void planet::euler2_deltapos(double t)
{
  pos.x=pos.x+t*(vel.x+velant.x)/2;
  pos.y=pos.y+t*(vel.y+velant.y)/2;
}




/**
 * Invariantes
 */
double planet::energy()
{
  return mass*mass*(vel.x*vel.x+vel.y*vel.y)/2-1/(sqrt((pos.x*pos.x)+(pos.y*pos.y)));
}
double planet::momentum()
{
  return mass*(pos.x*vel.y-pos.y*vel.x);
}
void planet::invariant ()
{
  A.x=mass*mass*vel.y*(pos.x*vel.y-pos.y*vel.x)-pos.x/(sqrt((pos.x*pos.x)+(pos.y*pos.y)));
  A.y=mass*mass*vel.x*(pos.x*vel.y-pos.y*vel.x)-pos.y/(sqrt((pos.x*pos.x)+(pos.y*pos.y)));
}

void planet::initialconditions( planet &b)
{
  mass=80;
  pos.x=0.4;
  pos.y=0;
  vel.x=0;
  vel.y=sqrt(1.6/0.4);
  force.x=0;
  force.y=0;
  
  b.mass=90000000;
  b.pos.x=0;
  b.pos.y=0;
  b.vel.x=0;
  b.vel.y=0;
  b.force.x=0;
  b.force.y=0;
}

       
