#include <iostream>
#include <vector>
#include <string.h>


using namespace std;

int main()
{
  int n;
  cin>>n;
  int mok = n/14;
  int nam = n%14;

  vector <string> arr;
  arr.push_back(" ");
  arr.push_back("baby");
  arr.push_back("sukhwan");
  arr.push_back("tururu");
  arr.push_back("turu");
  arr.push_back("very");
  arr.push_back("cute");
  arr.push_back("tururu"); 
  arr.push_back("turu");
  arr.push_back("in");
  arr.push_back("bed");
  arr.push_back("tururu"); arr.push_back("turu");
  arr.push_back("baby"); arr.push_back("sukhwan");

  
  
  if (n % 14 == 0)
  {
    cout<<"sukhwan";
    return (0);
  }
    
    if (nam == 3|| nam == 7 || nam == 11 )
    {
      if (mok > 2)
      {
        cout<<"tu+ru*"<<mok+2;
      }
      else 
      {
        cout<<"tururu";
        for (int i = 0; i < mok; i++)
        {
          cout<<"ru";
        }
      }
    }
    else if (nam == 4 || nam == 8 || nam == 12)
    {
      if (mok > 3)
      {
        cout<<"tu+ru*"<<mok+1;
      }
      else 
      {
        cout<<"turu";
        for (int i = 0; i < mok; i++)
        {
          cout<<"ru";
        }
      }
    }
    else
    {
      cout<<arr[nam];
    }
    
  

  return 0;
}