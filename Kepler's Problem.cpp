#include <iostream>
#include <cmath>
#include "finalproyect.h"
#include <fstream>
#include <string>

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
  //ofstream objects
  std::string filename[6] = {"Euleralpha.txt", "Eulerbeta.txt", "Implisitalpha.txt", "Implisitbeta.txt", "Velvetalpha.txt", "Velverbeta.txt"};
	std::ofstream outputFile[6];
	for (int i = 0; i < 6; i++)
	{
		outputFile[i].open(filename[i].c_str());
	}
//metodo de euler
  for(double time=0.0; time<=0.1 ; time+=deltaT){

    //Comentadas las lineas para evitar al planeta "Marte moverse"
    beta.deltaforce(alpha);
    beta.deltaveleuler(time);
    beta.deltaposeuler(time);
    alpha.deltaforce(beta);
    alpha.deltaveleuler (time);
    alpha.deltaposeuler (time);
    alpha.invariant();
    beta.invariant();
    alpha.T=time;
    beta.T=time;
    outputFile[0] << alpha.T << "\t"<< alpha.pos.x << "\t" << alpha.pos.y
                  << "\t" << alpha.H << "\t" << alpha.L << "\t"
                	<< beta.A.x << "\t" << beta.A.y << "\n";;
    outputFile[1] << beta.T << "\t"<< beta.pos.x << "\t" << beta.pos.y
                  << "\t" << beta.H << "\t" << beta.L << "\t"
                	<< beta.A.x << "\t" << beta.A.y << "\n";
    }
  alpha = et;
  beta = marte;
//metodo de euler implicito
  for(double time=0.0; time<=0.5 ; time+=deltaT){

    //Comentadas las lineas para evitar al planeta "Marte moverse"
    planet tau=beta;
    beta.deltaforce(alpha);
    beta.deltaveleuler(time);
    beta.deltaposeuler(time);
    beta.midpoint(tau);
    alpha.deltaforce(beta);
    alpha.deltaveleuler(time);
    alpha.deltaposeuler(time);
    alpha.invariant();
    beta.invariant();
    alpha.T=time;
    beta.T=time;
    outputFile[2] << alpha.T << "\t"<< alpha.pos.x << "\t" << alpha.pos.y
                  << "\t" << alpha.H << "\t" << alpha.L << "\t"
                  << beta.A.x << "\t" << beta.A.y << "\n";;
    outputFile[3] << beta.T << "\t"<< beta.pos.x << "\t" << beta.pos.y
                  << "\t" << beta.H << "\t" << beta.L << "\t"
                  << beta.A.x << "\t" << beta.A.y << "\n";
  }
//metodo storm velvet
for(double time=0.0; time<=0.5 ; time+=deltaT){

  //Comentadas las lineas para evitar al planeta "Marte moverse"
  beta.deltaforce(alpha);
  beta.initintegrationverlet(time);
  beta.deltaposstromerverlet(time);
  beta.deltaforce(alpha);
 beta.deltavelstromerverlet(time);
  //alpha.deltaforce(beta);
  //alpha.deltaposstromerverlet (t);
  //alpha.print();
  //beta.print();
}
}
