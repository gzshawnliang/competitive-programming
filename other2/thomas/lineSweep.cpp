#include <bits/stdc++.h>

using namespace std;

ifstream fin("lineSweep.in");
ofstream fout("lineSweep.out");

class line 
{
    public:
    double y_start;     //y_start是y轴下顶点坐标
    double y_end;       //y_end是y轴的上顶点坐标
    double x;           //x轴的坐标
    int flag;           //标记，矩形左边是1，右边是-1

    bool operator<(const line & p) const
    {
        return x < p.x;
    }
};

int main()
{
    int N;
    fin >> N;
    vector<line> lines(N*2);
    int k=0;
    for (int i = 0; i <= N - 1; ++i)
    {
        int x1;
        int y1;
        int x2;
        int y2;
        fin >> x1 >> y1 >> x2 >> y2;
        lines[k].flag = 1;
        lines[k+1].flag = -1;
        lines[k].x = x1;
        lines[k+1].x = x2;
        lines[k].y_start = y1;
        lines[k+1].y_start = y1;
        lines[k].y_end = y2;
        lines[k+1].y_end = y2;
        k += 2;
    }

    return 0;
}
