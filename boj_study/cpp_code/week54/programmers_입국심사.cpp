#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times)
{

  sort(times.begin(), times.end());

  long long minval = 0;
  long long maxval = (long long)times[times.size() - 1] * n;

  while (minval <= maxval)
  {
    long long avg = (minval + maxval) / 2;
    long long cnt = 0;
    for (int i = 0; i < times.size(); i++)
      cnt += (avg / (long long)times[i]);
    if (cnt >= n)
      maxval = avg - 1;
    else
      minval = avg + 1;
  }
  return maxval + 1;
}