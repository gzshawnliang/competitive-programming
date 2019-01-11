#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

//深度搜索
//v:                    顶点编号
//edgeInfo:             边的信息
//vertexVisitedInfo:    访问过顶点的信息
void dfs(int v, const vector<vector<bool>> & edgeInfo, vector<bool> & vertexVisitedInfo)
{
    if(vertexVisitedInfo[v] == true)           //访问过
    {
        return;
    }

    //未访问过

    cout << v << " ";
    vertexVisitedInfo[v] = true;

    //遍历边信息
    for (int j = 1; j <= edgeInfo[v].size()-1; j++)
    {
        if (edgeInfo[v][j] == true)           //有路可走
        {
            dfs(j,edgeInfo,vertexVisitedInfo);
        }
    }    
}

int main()
{

    freopen("TarjanArticulationVertex.in", "r", stdin);
    //freopen("TarjanArticulationVertex.out", "w", stdout);

    int vertexCount = 0;                        //顶点的数量
    int edgeCount = 0;                          //边的数量

    cin >> vertexCount >> edgeCount;

    if(vertexCount==0)
    {
        return 0;
    }

    //使用二位数组存储边的信息（邻接矩阵），true代表有边,false代表无边
    vector<vector<bool>> edgeInfo(vertexCount + 1, vector<bool>(vertexCount + 1, false));

    vector<bool> vertexVisitedInfo(vertexCount + 1, false);

    //读入图的信息
    for (int i = 0; i <= edgeCount - 1; ++i)
    {
        int vertexNum1;
        int vertexNum2;
        cin >> vertexNum1 >> vertexNum2;
        edgeInfo[vertexNum1][vertexNum2] = true;
    }

    //深度搜索图
    for (int i = 1; i <= vertexCount; ++i)
    {
        dfs(i, edgeInfo,vertexVisitedInfo);
    }

    return 0;
}