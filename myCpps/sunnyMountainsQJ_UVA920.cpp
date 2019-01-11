#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <climits>

using namespace std;

ifstream fin("sunnyMountainsQJ_UVA920.in");
ofstream fout("sunnyMountainsQJ_UVA920.out");
struct point
{
    int x,y;

    
};

double dis(point c,point j){
    int a=j.x-c.x,b=c.y-j.y;
    return sqrt(double(a*a+b*b));
}

bool cmp(point a,point b){
    return a.x<b.x;
}

int main()
{
    fout << fixed << setprecision(2);

    int T; fin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int n;
        fin>>n;
        point gls[n];
        for(int i=0;i<n;++i){
            fin>>gls[i].x>>gls[i].y;
        }
        sort(gls,gls+n,cmp);
        int now=0;
        double sum=0.0;
        for(int i=n-2;i>=0;--i){
            if(gls[i].y>now){
                sum+=dis(gls[i],gls[i+1])*(gls[i].y-now)/(gls[i].y- gls[i + 1].y);
                now=gls[i].y;
            }
        }
        fout<<sum<<'\n';
    }

    return 0;
}