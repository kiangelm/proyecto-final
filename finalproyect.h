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
  void deltaforce (planet pluto);
  void deltavelstromerverlet (double t);
  void deltaposstromerverlet (double t);
  void deltavelstromerverlet2 (double t);
  void deltaveleuler2 (double t);
  void deltaposeuler2 (double t);
  void deltaveleuler (double t);
  void deltaposeuler (double t);
  void operator= (planet venus);
  void initintegrationverlet (double t);

  struct {
    double x;
    double y;
  } posant;
  
};
