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
#include <climits>

using namespace std;

bool out(long long X, long long Y, long long N, long long M)
{
    if (X < 0 || X >= N || Y < 0 || Y >= M)
    {
        return true;
    }
    return false;
}

struct point
{
    long long X;
    long long Y;
    long long Value;
    bool operator < (const point & NP) const
    {
        if(Value>NP.Value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    ifstream cin("Maze.in");
    ofstream cout("Maze.out");
    long long n;
    cin>>n;
    for (long long i = 0;i<n;++i)
    {
        long long x, y;
        cin >> x >> y;
        vector <vector<long long>> maze(x,vector<long long> (y));
        for(long long h=0;h<x;++h)
        {
            for(long long a=0;a<y;++a)
            {
                long long temp;
                cin>>temp;
                maze[h][a]=temp;
            }
        }
        priority_queue<point> pq;
        point TQ;
        TQ.Value = maze[0][0];
        TQ.X = 0;
        TQ.Y = 0;
        vector<vector<long long>> value(x,vector<long long> (y,INT_MAX/2));
        //vector<vector<bool> > arrived(x, vector<bool>(y, false));
        value[0][0] = maze[0][0];
        pq.push(TQ);
        while(true)
        {
            if(pq.empty()==true)
            {
                break;
            }
            TQ = pq.top();
            pq.pop();
            if (TQ.Value > value[TQ.X][TQ.Y])
                continue;

            //arrived[TQ.X][TQ.Y] = true;
            if (out(TQ.X - 1, TQ.Y, x, y) == false)
            {
                point temp;
                temp.X = TQ.X - 1;
                temp.Y = TQ.Y;
                temp.Value = maze[temp.X][temp.Y]+value[TQ.X][TQ.Y];
                if(temp.Value < value[temp.X][temp.Y])
                {
                    value[temp.X][temp.Y] = temp.Value;
                    pq.push(temp);
                }
            }
            if (out(TQ.X + 1, TQ.Y, x, y) == false )
            {
                point temp;
                temp.X = TQ.X + 1;
                temp.Y = TQ.Y;
                temp.Value = maze[temp.X][temp.Y]+value[TQ.X][TQ.Y];
                if(temp.Value < value[temp.X][temp.Y])
                {
                    value[temp.X][temp.Y] = temp.Value;
                    pq.push(temp);
                }

            }
            if (out(TQ.X, TQ.Y - 1, x, y) == false)
            {
                point temp;
                temp.X = TQ.X;
                temp.Y = TQ.Y-1;
                temp.Value = maze[temp.X][temp.Y]+value[TQ.X][TQ.Y];
                if(temp.Value < value[temp.X][temp.Y])
                {
                    value[temp.X][temp.Y] = temp.Value;
                    pq.push(temp);
                }

            }
            if (out(TQ.X, TQ.Y + 1, x, y) == false)
            {
                point temp;
                temp.X = TQ.X;
                temp.Y = TQ.Y+1;
                temp.Value = maze[temp.X][temp.Y]+value[TQ.X][TQ.Y];
                if(temp.Value < value[temp.X][temp.Y])
                {
                    value[temp.X][temp.Y] = temp.Value;
                    pq.push(temp);
                }

            }
        }
        cout << value[x - 1][y - 1]<<'\n';
    }
    //system("pause");
    return 0;
}