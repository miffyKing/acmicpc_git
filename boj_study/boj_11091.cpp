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
using namespace std;

int arr[27];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char sentence[102];
    int n;
    cin>>n;
    cin.ignore();
    for(int i =0; i< n; i++)
    {
        cin.getline(sentence, sizeof(sentence));
        string answer;
        //cout<<strlen(sentence)<<'\n';
        fill(arr, arr+26, 0);
        for(int j=0; j< strlen(sentence); j++)
        {
            if(sentence[j] >= 'a' && sentence[j] <= 'z')
            {
                arr[(int)(sentence[j]) - (int)'a']++;
            }
            else if(sentence[j] >= 'A' && sentence[j] <= 'Z')
            {
                arr[(int)(sentence[j]) - (int)'A']++;
            
            }
        }
        int flag = 0;
        for(int j=0; j< 26; j++)
        {
            if(arr[j] == 0)
            {
                flag++;
                answer += (char)(j + 'a');
            }
        }
        if(flag == 0)
            cout<<"pangram\n";
        else
        {
            cout<<"missing " << answer <<'\n';
        }
    }
  
}
    
