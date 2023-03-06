#include <string>
#include <vector>
#include <iostream>

using namespace std;


long long years_allday = 0;
int privacies_array[27];
int terms_array[27];

long long years_to_days(string input)
{
    string year = input.substr(0, 4);
    string month = input.substr(5,2);
    string day = input.substr(8,2);
    
    int year_num = atoi(year.c_str());
    int month_num = atoi(month.c_str());
    int day_num = atoi(day.c_str());
    
    //cout<<"year num is " << (year_num*years_allday + month_num*28 + day_num)<< "\n";
    return ((year_num* 12*28) + month_num*28 + day_num);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    
    long long today_num;
    vector<long long> terms_num;
    vector<long long> privacies_num;
    
   
    vector<int> answer;
    
    for (int i = 0; i < 12; i++)
    {
        years_allday+=28;
    }

    today_num = years_to_days(today);       //today 를 총 일수로 나타낸것
    
    for (int i = 0; i < terms.size(); i++)
    {
        string monthes;
        if (terms[i].size() == 3)
        {
            monthes = terms[i].substr(2,1);    
        }
        else if (terms[i].size() ==4)
        {
           // cout<<"??????\n";
            monthes = terms[i].substr(2,2);
        }
        else 
        {
            monthes = terms[i].substr(2,3);
        }
        int monthes_toint = atoi(monthes.c_str());
        terms_array[terms[i][0] - 'A'] = monthes_toint*28;
    }
    
    
    for (int i = 0; i < privacies.size(); i++)
    {
        
        int compares = years_to_days(privacies[i]);
       // cout<< "i is    " << i << "\n";
        if (compares  + terms_array[privacies[i][11] - 'A'] <= today_num)
        {
         //   cout<<"!!!!!!!!!!!   << "<< i<< "\n";
            answer.push_back(i+1);
        }
    }
    //cout<<"\n";
    
    // for (int i = 0; i < 27; i++)
    // {
    //     cout<< terms_array[i] << "   ";
    // }
    // cout<<"\n";
    // for (int i = 0; i < 27; i++)
    // {
    //     cout<< privacies_array[i] << "   ";
    // }
    
    
    
 
    //answer.push_back(1);
    return answer;
}