#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <set>
#include <bitset>
using namespace std;



int main()
{
    //从大到小优先队列
    priority_queue<int> q;
    srand(time(NULL));

    
    for (int i = 0; i <5 ; ++i)
    {
        q.push(rand());
    }

    while(!q.empty())
    {
        cout << q.top() << endl;
        q.pop();
    }

    cout<<"---------------\n";

    //从小到大优先队列
    priority_queue<int,vector<int>,greater<int> > q2; 
    for (int i = 0; i <5 ; ++i)
    {
        q2.push(rand());
    }

    while(!q2.empty())
    {
        cout << q2.top() << endl;
        q2.pop();
    }


    // for (int i = 0; i < 5; i++)
    // {
    //     cout << q.top() << endl;
    //     q.pop();
    // }

    // set<int> myset;
    // // set some initial values:
    // for (int i = 0; i < 1500; ++i)
    // {
    //     myset.insert(i * 3); // set: 3 6 9 12
    // }
    // cout << myset.count(120) << endl;

    return 0;
}