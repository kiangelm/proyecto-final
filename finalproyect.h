#include <iostream>
#include <cmath>
#include <vector>
#include <string>

struct planet {
  double mass;
  double T;
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
  //auxiliares
  struct {
      double x;
      double y;
    } posant;
  struct {
      double x;
      double y;
    } velant;

  void print(void);
  void deltaforce (planet pluto);
  void deltaposstromerverlet (double t);
  void deltavelstromerverlet (double t);
  void deltaveleuler (double t);
  void deltaposeuler (double t);
  void midpoint(double t,planet &a);
  void deltaposeuler2(double t, const planet &a);
  void invariant ();
  void operator= (planet venus);
  void initintegrationverlet (double t);
};
