#include <iostream>
#include <cmath>

struct planet {
  /**
   * Definidas las propiedades del planeta
   */
  double mass;
  double H;
  double L;

  struct {
    double x;
    double y;
  } pos;

  struct {
    double x;
    double y;
  } vel;

  struct {
    double x;
    double y;
  } force;

  struct {
    double x;
    double y;
  } A;
  
  /**
   * Auxiliares
   */
  struct {
    double x;
    double y;
  } posant;
  
  struct {
    double x;
    double y;
  } velant;

  


  
  /**
   * Subrutinas  para el  manejo e  interaccion de
   * los planetas.
   */

  /**
   * Constructores
   */
  planet();
  planet(const double Mass,
	 const double pos_x,
	 const double pos_y,
	 const double vel_x,
	 const double vel_y,
	 const double force_x,
	 const double force_y);
  
  /**
   * Impresión
   */
  void print(void);
  friend std::ostream & operator<<(std::ostream & os, const planet & Planet);

  /**
   * Operadores
   */
  void operator= (planet venus);


  
  /**
   * Interacciones entre planetas
   */
  
  /**
   * Cambio de fuerza
   */
  void deltaforce(planet pluto);

  /**
   * Euler
   */
  void euler_deltapos(double t);
  void euler_deltavel(double t);

  /**
   * Stromer-Verlet
   */
  void verlet_initintegration(double t);
  void verlet_deltavel(double t);
  void verlet_deltapos(double t);

  /**
   * Euler 2
   */
  void euler2_deltaposant(double t);
  void euler2_deltapos(double t);




  /**
   * Invariantes
   */
  double energy();
  double momentum();
  void invariant ();

/*
Condiciones iniciales
*/

void initialconditions(planet &b);
};
