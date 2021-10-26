#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct node
{
    int a;
    int b;
    int sum;

    // bool operator==(const node newNode) const  
    // {  
    //     return this->sum == newNode.sum;  
    // }

    // bool operator<=(const node newNode) const  
    // {  
    //     return this->sum <= newNode.sum;  
    // }    

    bool operator<(const node newNode) const  
    {  
        return this->sum < newNode.sum;  
    }  
};

bool bFind(vector<int> & v,int value)
{
    return binary_search (v.begin(), v.end(), value);
}

//产生min-max的随机数
int genRand(int min,int max)
{
    //要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
    return (rand() % (max - min + 1)) + min;
}

int search_struct()
{

    //产生随机数
    srand(time(NULL));

    int dataCount=1e7;
    vector<node> nodeData;
    while(dataCount--)
    {
        int v1=genRand(1,1000);
        int v2=genRand(1,1000);
        node data{v1,v2,v1+v2};
        nodeData.push_back(data);

        // if(genRand(1,(int)1e7)==1e6)
        // {
        //     node tempValue{100,200,100+200};        
        //     nodeData.push_back(tempValue);
        // }
    }
    node tempValue{10001,20001,10001+20001};        
    nodeData.push_back(tempValue);
    sort(nodeData.begin(), nodeData.end());

    node findValue{10001,20001,10001+20001};        
    
    bool result=binary_search(nodeData.begin(), nodeData.end(), findValue);
    if (result)
    {
        cout << "found!\n"; 
        auto it = lower_bound(nodeData.begin(), nodeData.end(), findValue);
        std::cout << "lower_bound at position " << (it- nodeData.begin()) << '\n';
    }
    else 
    {
        cout << "not found.\n";    
    }

    // auto it=find(nodeData.begin(), nodeData.end(), findValue);
    // if( it!=nodeData.end())
    // {
    //     std::cout << "found at position " << (it- nodeData.begin()) << '\n';
    // }
    // else
    // {
    //     cout << "not found.\n";    
    // }




    // int myints[] = {1,2,3,4,5,4,3,2,1};
    // vector<int> v(myints,myints+9);                         // 1 2 3 4 5 4 3 2 1
    // sort (v.begin(), v.end());
    // cout << "looking for a 3... ";
    // if (bFind (v, 3))
    // {
    //     cout << "found!\n"; 
    // }
    // else 
    // {
    //     cout << "not found.\n";    
    // }
    
    // cout << "\nlooking for a 13... ";

    // if (bFind (v, 13))
    // {
    //     cout << "found!\n"; 
    // }
    // else 
    // {
    //     cout << "not found.\n";    
    // }



    return 0;
}

int search_vector()
{
    int myints[] = {1,2,3,4,5,8,4,3,2,1};
    vector<int> v(myints,myints+9);                         
    sort (v.begin(), v.end());
    int value=6;
    auto it = lower_bound(v.begin(), v.end(), value);

    if(it==v.end())
    {
        cout << "not found.\n";    
    }
    else if((*it)!=value)
    {
        cout << "not found.\n";    
    }
    else
    {
        cout << *it << "\n";    
    }
    
}

int main()
{
    //search_vector();
    search_struct();
    return 0;
}