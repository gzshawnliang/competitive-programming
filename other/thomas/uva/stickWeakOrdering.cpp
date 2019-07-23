#include <bits/stdc++.h>
#include "MyRandom.h"

using namespace std;

//ifstream fin("1.in");
//ofstream fout("1.out");

struct node
{
    int x;
    int y;

    bool operator < (const node & p) const
    {
        if(x==p.x)
        {
            return y<p.y;
        }
        else
        {
            return x<p.x;
        }
    }

public:
    node(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
};


int main()
{
    vector<int> vx{0,1,2};
    vector<int> vy{4,5,6};

    set<node> set1;
    random rdNum; 

    for (int i = 0; i <= 3-1 ; ++i)
    {
        for (int j = 0; j <= 3-1 ; ++j)
        {
            node t(vx[i],vy[j]);
            set1.insert(t);
        }
        
    }
    int i=1;
    for(auto it=set1.begin();it!=set1.end();++it)
    {
        cout<< i <<": " << it->x << " " << it->y << "\n";
        ++i;
    }
    
    // if(set1.count(a)==0)
    // {
    //     cout << "true" <<'\n';
    // }
    // else
    // {
    //     cout << "false" <<'\n';
    // }
    
    return 0;
}
