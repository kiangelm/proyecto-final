#include <iostream>
#include <cmath>

struct planet {
  double mass;
  
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

  void print(void);
  void deltapos (double t);
  void deltavel (double t);
  void deltaforce (planet pluto);
  planet operator= (planet venus);
  
};
