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
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    cout << fixed << setprecision(2);

    int T; cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int n;
        cin>>n;
        point gls[n];
        for(int i=0;i<n;++i){
            cin>>gls[i].x>>gls[i].y;
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
        cout<<sum<<'\n';
    }

   	cout.flush();
   	return 0;
}
