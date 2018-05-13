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
  friend std::ostream & operator<< (std::ostream & os, const planet & marte);
  void deltapos (double t);
  
};
