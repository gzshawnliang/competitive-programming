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

const long long INF = INT_MAX/2;

struct node
{
    long long d;
    long long p;
    bool operator < (const node & newnode) const
    {
        if(d>newnode.d)
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
    ifstream cin("Email.in");
    ofstream cout("Email.out");
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    cin>>n;
    for (long long t = 1; t <= n;++t)
    {
        long long N, m, s, T;
        cin >> N >> m >> s >> T;
        vector<vector<long long> > info(N, vector<long long>(N,INF));
        vector<vector<long long> > g(N);
        for (long long i = 0; i < m;++i)
        {
            long long temp1, temp2, l;
            cin >> temp1 >> temp2 >> l;
            if(info[temp1][temp2]>l)
            {
                info[temp1][temp2] = l;
                info[temp2][temp1] = l;
                g[temp1].push_back(temp2);
                g[temp2].push_back(temp1);
            }     
        }
        priority_queue<node> pq;
        node now;
        now.p=s;
        now.d = 0;
        pq.push(now);
        vector<long long> distance(N,INF);
        vector<bool> visit(N, false);
        while (true)
        {
            if(pq.empty()==true)
            {
                break;
            }
            now = pq.top();
            pq.pop();
            if (visit[now.p] == true)
            {
                continue;
            }
            if(now.d>=distance[now.p])
            {
                continue;
            }
            distance[now.p] = now.d;
            visit[now.p] = true;
            if (now.p == T)
            {
                break;
            }
            for (long long i = 0; i < g[now.p].size(); ++i)
            {
                if (visit[g[now.p][i]] == false && distance[g[now.p][i]] > distance[now.p] + info[now.p][g[now.p][i]])
                {
                    int nextP = g[now.p][i];
                    node temp;
                    temp.d = now.d + info[now.p][nextP];
                    temp.p = nextP;
                    pq.push(temp);
                }
            }
        }
        if(distance[T]==INF)
            cout << "Case #" << t << ": unreachable" << '\n';
        else
            cout << "Case #" << t << ": " << distance[T] << '\n';
    }
    //system("pause");
    cout.flush();
    return 0;
}