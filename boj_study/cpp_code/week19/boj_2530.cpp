#include <iostream>

using namespace std;

int main()
{
  int a, b, c;
  int d;
  cin>>a>>b>>c;
  cin>>d;

  int total = a*3600 + b*60 + c;
  
  total += d;
  int hour, min, sec;
  sec = total % 60;
  min = (total / 60) % 60;
  hour = (total / 60) / 60;
  if (hour >= 24)
  {
    hour %= 24;
  }
  cout<<hour << ' ' << min << ' ' << sec << "\n";
  return 0;
}