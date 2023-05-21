#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include<cstring>

using namespace std;
int bcheck[100005] = { 0 };

int main()
{

	int n, k;

	cin >> n >> k;

	queue<pair<int,int>>q;

	q.push({ n, 0 });
	bcheck[n] = 1;
	
	while ( !q.empty())
	{
		pair<int, int>cur = q.front();
		
		q.pop();

		bcheck[cur.first] = 1;
		
		if (cur.first == k)
		{
			cout << cur.second;
			return 0;
		}
		if (cur.first + 1 <= 100000 && bcheck[cur.first + 1] != 1)
		{
			q.push({ cur.first + 1, cur.second + 1 });
			bcheck[cur.first +1] = 1;
		}
		if (cur.first - 1 >= 0 && bcheck[cur.first - 1] != 1)
		{
			q.push({ cur.first - 1, cur.second + 1 });
			bcheck[cur.first - 1] = 1;
		}
		if (cur.first * 2 <= 100000 && bcheck[cur.first * 2] != 1)
		{
			q.push({ cur.first * 2, cur.second + 1 });
			bcheck[cur.first * 2] = 1;

		}

	}

	

	return 0;
}
