#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int arrs[5][9];

void get_new_arr(int arr[5])
{
  int tmp[9];
  for (int idx = 1; idx<= 4; idx++)
  {
    if (arr[idx] == 0) {}
    else 
    {
      for (int i = 1; i <= arr[idx]; i++)
      {
        tmp[i] = arrs[idx][i];
      }
      for (int i = arr[idx]; i <= 8; i++)
      {
        arrs[idx][i - arr[idx] + 1] = arrs[idx][i];
      }
      for (int i = 1; i <= arr[idx]; i++)
      {
        arrs[idx][8 - arr[idx] + i] = tmp[i];
      }
    }
    

  }
}

void cal_newarr(int arr[5] )
{
  //cout <<"\n" << arr[1] <<" " <<arr[2] <<" " << arr[3] << " " <<  arr[4] <<"\n"; 
  for (int i = 1; i <= 4; i++)
  {
    if (arr[i] < 0)
    {
      arr[i] = 8+arr[i];
    }
  }
  // cout<<"!!!!!! : ";
  // for (int i = 1; i<=4; i++)
  // {
  //   cout << arr[i] << " ";
  // }cout<<"\n";
  get_new_arr(arr);

  for (int i = 1; i <= 4; i++)
  {
    for (int j = 1; j <= 8; j++)
    {
      cout<<arrs[i][j];
    }
    cout<<"\n";
  }
}

void begin_one(int rotate_cnt)
{
  int rot_arr[5];
  memset(rot_arr,0, sizeof(int)*5 );
  if (arrs[1][5] == arrs[2][1])
  {
    rot_arr[1] = rotate_cnt;
  } 
  else 
  {
    rot_arr[1] = rotate_cnt;
    rot_arr[2] = -1*rot_arr[1];
    if (arrs[2][5] == arrs[3][1]) {}ㄹ
    else 
    {
      rot_arr[3] = -1*rot_arr[2];
      if (arrs[3][5] == arrs[4][1]) {}
      else
        rot_arr[4] = -1*rot_arr[3];
    }
  }
  cal_newarr(rot_arr);
}

void begin_two(int rotate_cnt)
{
  int rot_arr[5];
  memset(rot_arr,0, sizeof(int)*5 );
  if (arrs[2][1] == arrs[1][5])
  {
    rot_arr[2] = rotate_cnt;
  } else 
  {
    rot_arr[2] = rotate_cnt;
    rot_arr[1] = -1 * rot_arr[2];
    
  }

  if (arrs[2][5] == arrs[3][1])
  {
    rot_arr[3] = 0;
  }
  else 
  {
    rot_arr[3] = -1*rot_arr[2];
    if (arrs[3][5] == arrs[4][1]) {
      rot_arr[4] = 0;
    }
    else 
      rot_arr[4] = -1*rot_arr[3];
  }
  cal_newarr(rot_arr);
}

void begin_three(int rotate_cnt)
{
  int rot_arr[5];
  memset(rot_arr,0, sizeof(int)*5 );
  if (arrs[3][1] == arrs[2][5])
  {
    rot_arr[3] = rotate_cnt;
  } else 
  { 
    rot_arr[3] = rotate_cnt;
    rot_arr[2] = -1*rot_arr[3];
    if (arrs[2][1] == arrs[1][5])
    {
    }
    else
    {
      rot_arr[1] = -1 * rot_arr[2];
    }
  }
  if (arrs[3][5] == arrs[4][1])
  { }
  else {rot_arr[4] = -1*rot_arr[3];};
  cal_newarr(rot_arr);
}

void begin_four(int rotate_cnt)
{
  int rot_arr[5];
  memset(rot_arr,0, sizeof(int)*5 );
  if (arrs[4][1] == arrs[3][5])
  {
    rot_arr[4] = rotate_cnt;
  }
  else 
  {
    rot_arr[4] = rotate_cnt;
    rot_arr[3] = -1* rot_arr[4];
    if(arrs[3][1] == arrs[2][5])
    {} 
    else 
    {
      rot_arr[2] = -1 * rot_arr[3];
      if (arrs[2][1] == arrs[1][5])
      {}
      else 
      {
        rot_arr[1] = -1 * rot_arr[2];
      }
    }
  }
  cal_newarr(rot_arr);
}




int main()
{
  
  for (int i = 1; i <= 4; i++)
  {
    string str;
    cin>>str;
    for (int j = 1; j <= 8; j++)
    {
      int num = str[j-1] - '0';
      arrs[i][j] = num;
    }
  }
  int k;
  cin>>k;
  for (int idx = 0; idx < k; idx++)
  {
    int rotate_num, rotate_cnt;
    cin>>rotate_num >> rotate_cnt;
    switch(rotate_num)
    {
      case 1:
        begin_one(rotate_cnt);
        break;
      case 2:
        begin_two(rotate_cnt);
        break;
      case 3:
        begin_three(rotate_cnt);
        break;
      case 4:
        begin_four(rotate_cnt);
        break;
    } 
  }

  int cnt = 0;
    if (arrs[1][3] == 1)
    {
      cnt+=1;
    }
    if (arrs[2][3] == 1)
    {
      cnt+=2;
    }
    if (arrs[3][3] == 1)
      cnt+=4;
    if(arrs[4][3] == 1)
      cnt+=8;
  // 이 짓 하고 나면 최종적으로 바뀐 맵ㅣ 나올 것.
  cout<<"\n"<<cnt<<"\n";

  return 0;
}