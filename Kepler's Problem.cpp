#include <iostream>
#include <cmath>
#include "finalproyect.h"
#include<fstream>

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
  //for(double time=0.0; time<=0.1 ; time+=deltaT){

    //Comentadas las lineas para evitar al planeta "Marte moverse"
    //beta.deltaforce(alpha);
    //beta.deltaveleuler(time);
    //beta.deltaposeuler(time);
    //alpha.deltaforce(beta);
    //alpha.deltaveleuler (time);
    //alpha.deltaposeuler (time);
    //alpha.print();
    //beta.print();
    //std::cout << std::endl;
  //}
  alpha = et;
  beta = marte;
//metodo de euler implisito
  //for(double time=0.0; time<=0.5 ; time+=deltaT){

    //Comentadas las lineas para evitar al planeta "Marte moverse"
    //beta.deltaforce(alpha);
    //beta.deltaveleuler(time);
    //alpha.deltaposeulerant2  (time);
    //beta.deltaposeuler2(time);
    //alpha.deltaforce(beta);
    //alpha.deltaveleuler(time);
    //alpha.deltaposeulerant2  (time);
    //alpha.deltaposeuler2  (time);
    //alpha.print();
    //beta.print();
    //std::cout << std::endl;
  //}
//metodo storm velvet
   std::ofstream fout("laplacerunge.txt");
for(double time=0.0; time<=0.5 ; time+=deltaT){

  //Comentadas las lineas para evitar al planeta "Marte moverse"
  beta.deltaforce(alpha);
  beta.deltaposstromerverlet(time);
  alpha.deltaforce(beta);
  alpha.deltaposstromerverlet (time);
  alpha.print();
  //beta.print();
  fout<<alpha.laplacerunge()[0]<<" "<<alpha.laplacerunge()[1]<<" \n";
  
  
}
}
