#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int cnt = 0;
int n,m;
vector<int> arr;
int isused[10];
int isused_num[10];
int buffer[10];
  set <int> tmp;
void func(int cur)
{
	if (cur == m)
	{
		for(int i =0; i< m; i++)
		{
			cout<<buffer[i]<< ' ';
		}
		cout<<'\n';
		return;
	}
  int before = 0;
	for(int i = 0; i< tmp.size(); i++)
	{
    if(cur != 0 && buffer[cur-1] <= arr[i])
    {
      buffer[cur] = arr[i];
      before = buffer[cur];
      func(cur+1);
    }
    else if (cur == 0)
    {
      buffer[cur] = arr[i];
      before = buffer[cur];
      func(cur+1);
      
    }
  }
}

int main()
{

	cin>>n>>m;
  int x;
	for(int i =0; i< n; i++)
  {
    cin>>x;
    tmp.insert(x);    
  }
  set<int>::iterator  iter;
  for(iter = tmp.begin(); iter!= tmp.end(); iter++)
      arr.push_back(*iter);
	sort(arr.begin(), arr.end());
	func(0);
	return 0;
}
