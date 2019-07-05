#include <bits/stdc++.h>


using namespace std;

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/



using ll = long long;
const ll INF = LLONG_MAX / 2;

struct data
{
    int u;
    int cost;
    data(int a, int b)
    {
        u = a;
        cost = b;
    }
    bool operator<(const data & p) const
    {
        return cost > p.cost;
    }
};


class solution
{
  private:
    vector<vector<int>> graph;
    vector<vector<int>> cost;
    set<int> existingFireStationSet;
    
  public:
    solution(vector<vector<int>> & graph, vector<vector<int>> & cost, set<int> & existingFireStationSet)
    {
        this->graph = graph;
        this->cost = cost;
        this->existingFireStationSet = existingFireStationSet;
    }

    ll dijkastra(int src, int k)
    {
        vector<ll> dis(k + 1, INF);
        priority_queue<data> Q;

        for (auto it = existingFireStationSet.begin(); it != existingFireStationSet.end(); ++it)
        {
            dis[*it] = 0;
            Q.push(data(*it, 0));
        }

        Q.push(data(src, 0));
        dis[src] = 0;
        ll ret = 0;

        while (!Q.empty())
        {
            data u = Q.top();
            Q.pop();
            int size1 = graph[u.u].size();
            for (int i = 0; i < size1; i++)
            {
                int v = graph[u.u][i];
                if (cost[u.u][v] > 0)
                {
                    if (u.cost + cost[u.u][v] < dis[v])
                    {
                        dis[v] = u.cost + cost[u.u][v];
                        Q.push(data(v, dis[v]));
                    }
                }
            }
        }

        for (int i = 1; i <= k; ++i)
        {
            ret = max(ret, dis[i]);
        }
        return ret;
    }


};

int main()
{

    freopen("UVA-10278-FireStation.in", "r", stdin);
    freopen("UVA-10278-FireStation.out", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        int f, k;
        cin >> f >> k;

        vector<vector<int>> graph(k + 1);
        vector<vector<int>> cost(k + 1, vector<int>(k + 1, 0));
        vector<ll> existingFireStations(k + 1, 0);
        set<int> existingFireStationSet;

        for (int i = 0; i <= f - 1; ++i)
        {
            int a;
            cin >> a;

            existingFireStationSet.insert(a);
            existingFireStations[a] = 1;
        }

        string str;
        getline(cin, str);

        while (true)
        {
            str.clear();
            getline(cin, str);
            stringstream ss(str);
            if (str.empty())
            {
                break;
            }

            int a, b, c;
            ss >> a >> b >> c;
            graph[a].push_back(b);
            graph[b].push_back(a);
            cost[a][b] = c;
            cost[b][a] = c;
        }

        ll ans = 1, maxi = INF;
        solution sln1(graph, cost, existingFireStationSet);

        for (int i = 1; i <= k; ++i)
        {
            // if (existingFireStations[i] == 0)
            // {
                ll temp = sln1.dijkastra(i, k);
                if (temp < maxi)
                {
                    maxi = temp;
                    ans = i;
                }
            //}
        }

        cout << ans << '\n';
        if (t > 0)
            cout << '\n';
    }

    return 0;
}