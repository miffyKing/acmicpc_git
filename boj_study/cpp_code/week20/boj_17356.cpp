#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
  float a, b;
  cin>>a>>b;
  
  float m = (b-a)/400;
  //printf("%f\n", m);
  float x  = pow(10, m) +1.0f;
  printf("%f\n", 1/x);
  return 0;
}