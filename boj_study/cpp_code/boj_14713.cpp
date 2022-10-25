#include<iostream>
#include<string>
#include <map>
#include<set>
#include<stack>
#include <vector>
#include <functional>
#include <algorithm>
#include<cmath>
#include <cstring>
#include <set>
#include <stdio.h>
//#include <string.h>

using namespace std;
char* arr[102][100002];
char str_char[100004];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    string str;
    string cstr;
    
    cin>>n;
    cin.ignore();
    int j=0;
    
    for(int i =0; i< n; i++)
    {
        
        getline(cin, str);
        cout<<"??\n";
        strcpy(str_char, str.c_str());
         j =0;
        char *ptr = strtok(str_char, " ");
        arr[i][j] = ptr;
       // j++;
        while(ptr != NULL)
        {
            
            ptr = strtok(NULL, " ");
            j++;
            arr[i][j]= ptr;
            //cout<<"arr[i][j] is " << arr[i][j]<<'\n';
        }
    }
    for(int i =0; i< 4; i++)
    {
        cout<<arr[0][j]<<'\n';
    }
    
}
