#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
//#include <windows.h>
#include <map>

using namespace std;

bool caculate(int side,vector<vector<int>> & yard,int low,int high)
{
    if(yard.size()<side || yard[0].size()<side)
    {
        return false;
    }
    for (int h = 0; h <= yard[0].size()-side;++h)
    {
        for(int i=0;i<=yard.size()-side;++i)
        {
            if(yard[i][h]>=low && yard[i][h]<=high)
            {
                if (yard[i + side - 1][h + side - 1] <= high)
                {
                    return true;
                }
                // if (i + side <= yard.size() && h + side <= yard[0].size())
                // {
                    
                // }
            }
        }
    }
    return false;
}

int main()
{
    ifstream cin("Grapevine.in");
    ofstream cout("Grapevine.out");
    while(true)
    {
        int n,m;
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }
        vector<vector<int> > yard(n, vector<int> (m));
        for(int i=0;i<n;++i)
        {
            for(int h=0;h<m;++h)
            {
                int temp;
                cin >> temp;
                yard[i][h] = temp;
            }
        }
        int q;
        cin>>q;
        vector<vector<int> > question(q, vector<int>(2));
        for(int i=0;i<q;++i)
        {
            int temp1,temp2;
            cin >> temp1 >> temp2;
            question[i][0] = temp1;
            question[i][1] = temp2;
        }
        for (int i = 0; i < q;++i)
        {
            int l = 0, r = 501,side;
            side = (r - l) / 2;
            while(true)
            {
                if(caculate(side,yard,question[i][0],question[i][1])==true)
                {
                    if(r-l>1)
                    {
                        l=side;
                        side += (r - l) / 2;
                    }
                    else
                    {
                        if (caculate(r, yard, question[i][0], question[i][1]) == true)
                        {
                            side = r;
                        }
                        break;
                    }
                }
                else
                {
                    if (r - l > 1)
                    {
                        r=side;
                        side -= (r - l) / 2;
                    }
                    else
                    {
                        if(l==0)
                        {
                            side = 0;
                        }
                        else if (caculate(l, yard, question[i][0], question[i][1]) == true)
                        {
                            side = l;
                        }
                        break;
                    }
                }
            }
            cout << side << '\n';
        }
        cout << '-' << '\n';
    }
    //system("pause");
    return 0;
}