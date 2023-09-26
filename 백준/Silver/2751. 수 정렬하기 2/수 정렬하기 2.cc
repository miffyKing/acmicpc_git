#include <iostream>
#include <string.h>
using namespace std;

//입력 백만, 시간은 2초기 때문에 O(n^2) 못씀.
// O(nlogn) 을 사용한다. -> 병합정렬 해볼게용

long long n;
long long arr[1000002];
long long tmp[1000002];

void merge(int start, int mid, int end)
{
  //memcpy(tmp + start, arr + start, (end - start + 1) * sizeof(int));
  
  long long pointer1 = start;
  long long pointer2 = mid+1;
  long long idx = start;

  while (pointer1 <= mid && pointer2 <= end)
  {
    if (arr[pointer1] <= arr[pointer2])
      tmp[idx++] = arr[pointer1++];
    else 
      tmp[idx++] = arr[pointer2++];
  }

    while (pointer1 <= mid)
      tmp[idx++] = arr[pointer1++];
    while(pointer2 <= end)
      tmp[idx++] = arr[pointer2++];
  for (int i = start; i <= end; i++)
    arr[i] = tmp[i];
}

void mergeSort(int start, int end)
{
  if (start < end)
  {
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid+1, end);
    merge(start, mid, end);
  }
}

int main()
{
  cin>>n;
  for (int i = 0; i < n; i++)
    cin>>arr[i];
  
  mergeSort(0, n-1);

  //merge(0, n/2, n);

  for (int i = 0; i < n; i++)
  {
    cout<<arr[i] << "\n";
  }
  return 0;
}