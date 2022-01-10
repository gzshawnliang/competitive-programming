#include <bits/stdc++.h>

using namespace std;

/**
 * catch up and win
 **/
using namespace std;
using ill = long long;
const int INF = INT_MAX / 2;

class ShortestPath
{
    map<pair<int,int>,vector<pair<int,int>>> g;
    int hash(pair<int,int> p)
    {
        return p.first *10 + p.second;
    }
  public:
    ShortestPath(const map<pair<int,int>,vector<pair<int,int>>> & data)
    {
        this->g=data;
    }

    int run(pair<int,int> start, pair<int,int> target)
    {
        vector<int> distance(12*12, INF);
        int S=hash(start);

        distance[S] = 0;
        queue<pair<int,int>> pq;
        pq.push(start);

        while (!pq.empty())
        {
            pair<int,int> now= pq.front();
            pq.pop(); 

            for(auto neighbour:g[now])
            {
                int v= hash(neighbour);
                int u=hash(now);
                if(distance[v]>distance[u]+1)
                {
                    distance[v]=distance[u]+1;
                    pq.push(neighbour);
                }
            }
        }
        int T=hash(target);
        return distance[T];
    }
};

int main()
{
    int k; // representing after how many turns the sus man will make another move
    cin >> k; cin.ignore();

    map<pair<int,int>,vector<pair<int,int>>> g;
    vector<string> a(12);
    a[0]="************";
    for (int i = 1; i <= 10; i++) {
        string s;
        cin>>s; // the map
        cerr << s << '\n';
        a[i]="*" + s + "*";
    }
    a[11]="************";
    

    auto getDirection=[&](pair<int,int> curr)
    {
        int x=curr.first;
        int y=curr.second;
        vector<pair<int,int>> dir;
        if(a[y-1][x] !='*')  //U
            dir.push_back({x,y-1});

        if(a[y+1][x] !='*')  //D
            dir.push_back({x,y+1});

        if(a[y][x-1] !='*')  //L
            dir.push_back({x-1,y});

        if(a[y][x+1] !='*')  //R
            dir.push_back({x+1,y});
       
        return dir;                     
    };

    //create graph
    pair<int,int> P;
    pair<int,int> E;
   
    for (int y = 1; y <= 10; ++y) 
    {
        for (int x = 1; x <= 10; ++x) 
        {
            if (a[y][x] == 'P')
                P = {x,y};
            else if (a[y][x] == 'E')
                E = {x,y};
            else if (a[y][x] == '*')
                continue;

            vector<pair<int,int>> dir=getDirection({x,y});
            for(auto c:dir)
                g[{x,y}].push_back(c);
        }
    }

    ShortestPath shortestPath1(g);

    //cout << dijkstra1.run(P,E) << "\n";
    //cerr << P.first << "," << P.second << "->" << E.first << "," << E.second  << "\n";

    srand((unsigned)time(NULL));
    // game loop
    while (1) {
        int ene_y; // the sus man's coordinate
        cin >> ene_y; cin.ignore();
        int ene_x; // the sus man's coordinate
        cin >> ene_x; cin.ignore();
        ++ene_y;
        ++ene_x;

        pair<int,int> E2={ene_x,ene_y};
        cerr << P.first << "," << P.second << "->"  << ene_y << "," << ene_x << ":";

        vector<pair<int,int>> dir=getDirection(P);
        //cerr << P.first << "," << P.second << "\n";
        vector<pair<int,char>> result;
        for(auto c:dir)
        {
            int dist = shortestPath1.run(c,E2);
            char currDir;
            if(c.first==P.first)
            {
                if(c.second<P.second)
                    currDir='U';
                else
                    currDir='D';
            }
            else 
            {
                if(c.first<P.first)
                    currDir='L';
                else
                    currDir='R';            
            }
            result.push_back({dist,currDir});
        }
        sort(result.begin(),result.end());

        //cerr << dis_U << "," << dis_D << "," << dis_L << "," << dis_R << " :";
        int currId=0;
        if(result.size()==1 || result[0].first < result[1].first)
        {
            cout << result[0].second << endl;
        }
        else 
        {
        //     bool randbool = rand() & 1;
        //     cerr << randbool << "\n";
        //     if(randbool)
        //         cout << dir2[0].second << endl;
        //     else 
        //         cout << dir2[1].second << endl;
            if(abs(P.first-E2.first) <abs(P.second-E2.second))
            {
                currId=1;
                cout << result[1].second << endl;
            }
            else
            {
                cout << result[0].second << endl;
            }
        }

        //update P 
        if(result[currId].second=='U')
            P = {P.first,P.second-1};
        else if(result[currId].second=='D')
            P = {P.first,P.second+1};
        else if(result[currId].second=='L')
            P = {P.first-1,P.second};
        else if(result[currId].second=='R')
            P = {P.first+1,P.second};

    }
}