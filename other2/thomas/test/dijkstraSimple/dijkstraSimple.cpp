#include <bits/stdc++.h>

using namespace std;

//ifstream fin("dijkstraSimple.in");
//ofstream fout("dijkstraSimple.out");
/*
ref:
https://vinkle.top/2020/07/13/Dijkstra/
https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/
<Competitive Programming 3 - Steven Halim>
*/

const int INF=INT_MAX/2;

class dijkstra
{
    private:
     vector<vector<pair<int,int>>> g;
     vector<int> parent;

    void reSet(vector<vector<pair<int,int>>> & graph)
    {
        this->g=graph;
        parent=vector<int>(this->g.size(),-1);
    }

    void printPath(int j)
    {
        // Base Case : If j is source
        if (parent[j]==-1)
            return;

        printPath(parent[j]);
        cout << "->" << j ;
    }    

    public:
    dijkstra(vector<vector<pair<int,int>>> & graph)
    {
        reSet(graph);
    }

    int run(int s,int t)
    {
        int n=g.size();
        vector<int> dist(n,INF);
        vector<int> vist(n,0);
        dist[s]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});

        while (!pq.empty()) 
        { 
            pair<int,int> front=pq.top();
            pq.pop();
            
            int d = front.first;
            int u = front.second;

            if (d > dist[u]) 
                continue;         //重要

            // for (int i = 0,size=g[u].size(); i <= size-1 ; ++i)
            // {
            //     pair<int,int> curr=g[u][i];
            //     int distV=curr.first;
            //     int v=curr.second;
                
            //     //u->v
            //     if(dist[u] + distV < dist[v])
            //     {
            //         dist[v]=dist[u]+distV;
            //         pq.push({dist[v],v});
            //     }
            // }

            vist[u]=1;
            for (auto curr:g[u])
            {
                int distV=curr.first;
                int v=curr.second;
                
                //u->v
                if(vist[v]==0 && dist[u] + distV < dist[v])
                {
                    dist[v]=dist[u]+distV;
                    parent[v]=u;

                    pq.push({dist[v],v});
                }
            }

        }
        
        return dist[t];
    }

    int run2(int s,int t)
    {
        int n=g.size();
        vector<int> dist(n,INF);
        vector<int> vist(n,0);
        dist[s]=0;
        priority_queue<pair<int,int>> pq;
        pq.push({0,s});

        while (!pq.empty()) 
        { 
            pair<int,int> front=pq.top();
            pq.pop();
            
            int d = 0 - front.first;
            int u = front.second;

            if (d > dist[u]) 
                continue;         //重要

            vist[u]=1;
            for (auto curr:g[u])
            {
                int distV=curr.first;
                int v=curr.second;
                
                //u->v
                if(vist[v]==0 && dist[u] + distV < dist[v])
                {
                    dist[v]=dist[u]+distV;
                    parent[v]=u;
                    pq.push({0-dist[v],v});
                }
            }
        }
        
        return dist[t];
    }

    void runAndPrint(int s,int t)
    {
        int result=run2(s,t);
        cout << s << " -> " << t << ",shortest paths is:";
        if(result==INF)
            cout << "INF\n";
        else
        {
            cout << result << ",path is:" << s << "";
            printPath(t);
            cout << "\n";
        }
    } 

    void runAndPrint(vector<vector<pair<int,int>>> & graph,int s,int t)
    {
        //this->g = graph;
        reSet(graph);
        runAndPrint(s,t);
    }       
};


int main()
{
    vector<vector<pair<int,int>>> g(5);

    g[0].push_back({1,4});  //0->4:1
    g[1].push_back({3,3});  //1->3:3
    g[1].push_back({6,4});  //1->4:6
    g[2].push_back({2,1});  //2->1:2
    g[2].push_back({7,3});  //2->3:7
    g[2].push_back({6,0});  //2->0:6
    g[3].push_back({5,4});  //3->4:5
                            //4->无
    int s=2;
    int t=4;
    dijkstra dijkstra1(g);
    dijkstra1.runAndPrint(s,t);

    g = vector<vector<pair<int, int>>>(7);
                                //0->无    
    g[1].push_back({1,2});      //1->2:1
    g[1].push_back({12,3});     //1->3:12
    g[2].push_back({9,3});      //2->3:9
    g[2].push_back({3,4});      //2->4:3
    g[3].push_back({5,5});      //3->5:5
    g[4].push_back({4,3});      //4->3:4
    g[4].push_back({13,5});     //4->5:13
    g[4].push_back({15,6});     //4->6:15
    g[5].push_back({4,6});      //5->6:4
                                //6->无
    s=1;
    t=6;
    dijkstra1.runAndPrint(g,s,t);

    return 0;
}



/*
2 1 2
2 3 7
1 3 3
2 0 6
0 4 1
1 4 6
3 4 5
*/