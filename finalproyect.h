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
  void deltavelstromerverlet (double t);
  void deltaposstromerverlet (double t);
  void deltavelstromerverlet2 (double t);
  void deltaveleuler (double t);
  void deltaposeuler (double t);
  void midpoint(planet tau);
  void invariant ();
  void operator= (planet venus);
  void initintegrationverlet (double t);
};
