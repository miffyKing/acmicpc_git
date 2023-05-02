#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int d1, d2;
  float circle;

  cin>>d1>>d2;
  circle = d2*3.141592*2;
  printf("%.6f", 2*d1 + circle);
  
  return 0;
}