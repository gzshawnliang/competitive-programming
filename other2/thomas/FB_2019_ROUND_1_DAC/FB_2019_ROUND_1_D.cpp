// Connect the Dots
// Solution by Jacob Plachta

#define DEBUG 0

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }
string plural(string s) { return(Sz(s) && s[Sz(s)-1]=='x' ? s+"en" : s+"s"); }

const int INF = (int)1e9;
const LD EPS = 1e-12;
const LD PI = acos(-1.0);

#if DEBUG
#define GETCHAR getchar
#else
#define GETCHAR getchar
#endif

bool Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if ((c<0) && (!r))
					return(0);
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
	return(1);
}

#define LIM 800001

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("FB_2019_ROUND_1_D.in", "r", stdin);
        freopen("FB_2019_ROUND_1_D.out", "w", stdout);
    #endif
	// vars
	int T,t;
	int N,H,V;
	int i,j,si,a,b,c,d;
	static int G[2][LIM];
	static PR P[LIM];
	static int maxY[LIM];
	set<PR> S;
	set<PR>::iterator I;
	// testcase loop
	Read(T);
		Fox1(t,T)
		{
			// input, and generate coordinates
			Read(N),Read(H),Read(V);
				Fox(i,2)
				{
					Read(G[i][0]),Read(G[i][1]),Read(a),Read(b),Read(c),Read(d);
						FoxI(j,2,N-1)
							G[i][j]=((LL)a*G[i][j-2] + (LL)b*G[i][j-1] + c)%d+1;
				}
			// impossible?
			int ans=-1;
				if (H+V<N)
					goto Done;
			// sort dots by X
				Fox(i,N)
					P[i]=mp(G[0][i],G[1][i]);
			sort(P,P+N);
			// precompute Y values' suffix maxes
			maxY[N]=0;
				FoxR(i,N)
					maxY[i]=max(maxY[i+1],P[i].y);
			// consider each possible max horiz. segment length
			ans=2*INF;
			S.clear();
			S.insert(mp(0,-1));
			I=S.begin(),si=0;
				Fox(i,N+1)
				{
					// update set of dots so far
						if (i)
						{
							S.insert(mp(P[i-1].y,i));
								if (mp(P[i-1].y,i)<*I)
									si++;
						}
					// last f dots must use vert. segments
					int f=N-i;
						if (f>V)
							continue;
					// g of the dots so far must also use vert. segments
					int g=max(0,min(N-H,V)-f);
						while (si>g)
							I--,si--;
						while (si<g)
							I++,si++;
					Min(ans,(i?P[i-1].x:0)+max(I->x,maxY[i]));
				}
			// output
Done:;
			printf("Case #%d: %d\n",t,ans);
		}
	return(0);
}