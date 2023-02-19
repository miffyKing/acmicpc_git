#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> v_50(50);
    
    cout<<v_50.size()<<"\n";
    
    cout<<"before initializing vlues\n";
    for (int i = 0; i < 50 ;i++)
    {
        cout<< v_50[i] << " ";
    }cout<<"\n";            //초기화를 따로 안해주면 0으로 초기화 되네요
    
    cout<< "after insert values\n";
    for (int i = 0; i < 50; i++)
    {
        v_50[i] = i;
    }
    for (int i = 0; i < 50; i++)
    {
        cout << v_50[i]<< " ";
    } cout<<"\n";
    
    
    
    cout<< " after inserting values to size 50 vector, size is    : " << v_50.size() << "\n";
    v_50[52] = 52;
    cout<<v_50[52]<<"\n";       //왜 되노
    cout<< " after inserting value to 52th place, why no error and vector's size is    :  " << v_50.size() << "\n";
    
    
    cout<<"capacity is    "   << v_50.capacity() << "\n";
    
    v_50[100] = 100;
    cout<<v_50[100] << "\n";
    
    cout<<"after erasing value of 20 \n";
    v_50.erase(v_50.begin() + 20);
    
    cout<< v_50.size() << "\n";
    for (int i = 0; i < 50; i++)
    {
        cout << v_50[i]<< " ";
    } cout<<"\n";
    
    cout<< "after inserting 10 values to v50\n";
    v_50.insert(v_50.begin() + 10, -5);
    v_50.insert(v_50.begin() + 11, -5);
    v_50.insert(v_50.begin() + 12, -5);
    cout<< "v50 size is  " << v_50.size() << "\n";
    
    cout<< "||||||||||| from 1 ~ 100 |||||||||||\n";
    for (int i = 0; i < 102; i++)
    {
        cout<<v_50[i] << " ";
    }
    cout<<"\n";
    
    cout << v_50.capacity();
    cout<<"\n";
    
    v_50.reserve(100);
    
    v_50[200] = 202;
    cout<< v_50[200] << "\n";
    cout<< v_50.size()<<"\n";
    

    
    //주의할 부분//
    vector <int> v;
    v.push_back(1);
    v.resize(100);
    v.push_back(100);
    
    cout<<v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i] << " ";
    }
    cout<<"\n";
    
    
    return 0;
}
