#include "MyRandom.h"
#include <bits/stdc++.h>

using namespace std;

class Graph
{

    vector<pair<int,int>> edge;
    set<pair<int,int>> edge2;

    int totalNodeCount;
    int totalEdgeCount;
    string fileName;

    void CreateGraphvizFile()
    {
        ofstream fout(fileName+".dot");
        fout << "digraph {node [shape=circle]\n";
        if(multipleEdges==false)
        {
            for(auto e : edge2)
                fout<< e.first << " -> " << e.second << "\n";
        }
        else
        {
            for(auto e : edge)
                fout<< e.first << " -> " << e.second << "\n";
        }
        fout << "}\n";
        fout.close();
    }

    void CreateInFile()
    {
        ofstream fout(fileName+".in");
        
        
        if(multipleEdges==false)
        {
            fout << totalNodeCount << " " << edge2.size() << "\n";
            for(auto e : edge2)
                fout<< e.first << " " << e.second << "\n";
        }
        else
        {
            fout << totalNodeCount << " " << edge.size() << "\n";
            for(auto e : edge)
                fout<< e.first << " " << e.second << "\n";
        }
        fout.close();
    }

  public:
    bool itSelfEdge     =  false;           //the graph do not contain self-loops (i.e. edges from the vertex to itself) 
    bool multipleEdges  =  false;           //multiple edges (i.e. for each edges (xi,yi) there are no other edges (xi,yi).
    bool reverseEdges  =  false;             //reverse edges (i.e. for each edges (xi,yi) there are no other edges (yi,xi)).  
    bool circle  =  true;                    //graph has circle.  

    Graph(string file)
    {
        this->fileName = file;
        srand((unsigned)time(NULL)); 
    }
    void GenerateGraph(int nodeCount,int edgeCount)
    {
        totalNodeCount=nodeCount;
        totalEdgeCount=edgeCount; 

        int edgeCnt=0;
        int loopCount=0;
        while (edgeCnt < edgeCount)
        {
            int a = rand() % totalNodeCount + 1;
            int b = rand() % totalNodeCount + 1;

            bool tag1=true;
            if(itSelfEdge==false)
                if(a==b)
                    tag1=false;

            bool tag2=true;
            if(reverseEdges==false)
                if(edge2.count({b,a})==1)
                    tag2=false;

            bool tag3=true;
            if(circle==false)
                if(a>b)
                    tag3=false;

            if(tag1 && tag2 && tag3)
            {
                if(multipleEdges==false)
                {
                    edge2.insert({a, b});
                    edgeCnt = edge2.size();
                }
                else
                {
                    edge.push_back({a, b});
                    edgeCnt = edge.size();
                }
            }
            ++loopCount;
            if(multipleEdges==false && loopCount>10*edgeCount)
                break;
        }
        
        CreateInFile();
        CreateGraphvizFile();
    }

};


int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    //freopen("GenerateRandomGraphs.in", "r", stdin);
    freopen("GenerateRandomGraphs.in", "w", stdout);
    
#endif

    random rdNum;
    Graph graph1("GenerateRandomGraphs");
    graph1.circle = false;

    int N=rdNum.GetRand(2, 30);
    int E=rdNum.GetRand(2, 45);

    graph1.GenerateGraph(N,E);

    return 0;
}