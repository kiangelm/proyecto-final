#include <iostream>
#include <cmath>
#include "finalproyect.h"
#include <fstream>
#include <string>

int main(void)
{
  double deltaT = 0.0005;
  double h=0.005;
  double hb=0.05;
  planet et;
  et.mass=1;
  et.pos.x=0.4;
  et.pos.y=0.0;
  et.vel.x=0.0;
  et.vel.y=sqrt(1.6/0.4);
  et.force.x=0.0;
  et.force.y=0.0;

  planet marte;
  marte.mass=1;
  marte.pos.x=0.0;
  marte.pos.y=0.0;
  marte.vel.x=0.0;
  marte.vel.y=0.0;
  marte.force.x=0.0;
  marte.force.y=0.0;
  planet alpha = et;
  planet beta = marte;
  //ofstream objects
  std::string filename[4] = { "Euler.txt","Implisit.txt","Velvet10.txt", "Velvet100.txt"};
	std::ofstream outputFile[4];
	for (int i = 0; i < 4; i++)
	{
		outputFile[i].open(filename[i].c_str());
	}
//metodo de euler
  for(double time=0.0; time<=10 ; time+=deltaT){

    alpha.deltaforce(beta);
    alpha.deltaveleuler (deltaT);
    alpha.deltaposeuler (deltaT);
    alpha.invariant();
    alpha.T=time;
    outputFile[0] << alpha.T << "\t"<< alpha.pos.x << "\t" << alpha.pos.y
                  << "\t" << alpha.H << "\t" << alpha.L << "\t"
                	<< alpha.A.x << "\t" << alpha.A.y << "\n";;
    }
  alpha = et;
  beta = marte;

//metodo de euler implicito
  for(double time=0.0; time<=20*M_PI ; time+=deltaT){
    alpha.deltaforce(beta);
    alpha.velmidpoint(deltaT);
    alpha.deltaposeuler2(deltaT);
    alpha.deltaveleuler(deltaT);
    //Comentadas las lineas para evitar al planeta "Marte moverse
    //alpha.deltaveleuler2(deltaT,tau);
    alpha.invariant();
    alpha.T=time;
    outputFile[1] << alpha.T << "\t" << alpha.pos.x << "\t" << alpha.pos.y
		 << "\t" << alpha.H << "\t" << alpha.L << "\t"
     << alpha.A.x << "\t" << alpha.A.y << "\n";;
  }
  alpha=et;
  beta=marte;
//metodo storm velvet
for(double time=0.0; time<=20*M_PI ; time+=h){

  //Comentadas las lineas para evitar al planeta "Marte moverse"

  outputFile[2] << alpha.T << "\t"<< alpha.pos.x << "\t" << alpha.pos.y
                << "\t" << alpha.H << "\t" << alpha.L << "\t"
                << alpha.A.x << "\t" << alpha.A.y << "\n";;
  alpha.deltaforce(beta);
  alpha.initintegrationverlet(h);
  alpha.deltaposstromerverlet(h);
  alpha.deltaforce(beta);
  alpha.deltavelstromerverlet(h);
  alpha.invariant();
  alpha.T=time;
}
for(double time=0.0; time<=20*M_PI ; time+=hb){

  //Comentadas las lineas para evitar al planeta "Marte moverse"

  outputFile[3] << alpha.T << "\t"<< alpha.pos.x << "\t" << alpha.pos.y
                << "\t" << alpha.H << "\t" << alpha.L << "\t"
                << alpha.A.x << "\t" << alpha.A.y << "\n";;
  alpha.deltaforce(beta);
  alpha.initintegrationverlet(h);
  alpha.deltaposstromerverlet(h);
  alpha.deltaforce(beta);
  alpha.deltavelstromerverlet(h);
  alpha.invariant();
  alpha.T=time;
}
}
