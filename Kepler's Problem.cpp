#include <iostream>
#include <cmath>
#include <fstream>
#include "finalproyect.h"

const char * filename[] = {"Euler.dat",
			   "Implicit.dat",
			   "Verlet.dat"};

std::ofstream outputFile[3];

int main (void)
{
  double deltaT = 0.00005;

  /*initial conditions */

  planet alpha;
  planet beta;
  alpha.initialconditions(beta);
  
       
  /* Abrir todos los archivos de datos
   */
  for (int i = 0; i < 3; i++)
    {
      outputFile[i].open(filename[i]);
    }



  /**
   * Euler
   */
  for(double time=0.0 ; time<=0.1 ; time+=deltaT) {
    alpha.deltaforce(beta);
    alpha.euler_deltavel(time);
    alpha.euler_deltapos(time);

    outputFile[0] << time << "\t" << alpha << "\n";
  }



  /**
   * Euler 2
   */
  alpha.initialconditions(beta);
  for(double time=0.0 ; time<=0.5 ; time+=deltaT) {
    alpha.euler2_deltaposant(time);
    alpha.deltaforce(beta);
    alpha.euler_deltavel(time);
    alpha.euler2_deltaposant(time);
    alpha.euler2_deltapos(time);

    //alpha.print();
    //beta.print();
    outputFile[1] << time << "\t" << alpha << "\n";
  }

  /**
   * Metodo Stromer-Verlet
   */
  alpha.initialconditions(beta);
  for(double time=0.0 ; time<=0.5 ; time+=deltaT) {
    alpha.verlet_initintegration(time);
    alpha.deltaforce(beta);
    alpha.verlet_deltapos(time);

    //alpha.print();
    //beta.print();
    outputFile[2] << time << "\t" << alpha << "\n";
  }

  for (int i = 0; i < 3; i++)
    {
      outputFile[i].close();
    }
}
