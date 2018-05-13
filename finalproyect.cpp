#include "finalproyect.h"

std::ostream & operator<< (std::ostream & os, const planet & marte)
{
  os << marte.pos.x << "\t" << marte.pos.y << "\t" 
     << marte.vel.x << "\t" << marte.vel.y << "\t"
     << marte.force.x << "\t" << marte.force.y  ;
}

void planet::deltapos (double t)
{
  pos.x=pos.x+vel.x*t;
  pos.y=pos.y+vel.y*t;
}
