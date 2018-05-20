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
  void deltaveleulerverlet (double t);
  void deltaposeulerverlet (double t);
  void deltaveleulerverlet2 (double t);
  void deltaveleuler2 (double t);
  void deltaposeuler2 (double t);
  void operator= (planet venus);

};
