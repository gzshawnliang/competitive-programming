
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,q,xx;
ll fun(ll num)
{
	ll anx=num/xx;
	ll anx1=num%xx+1;
	return num-anx*b-min(anx1,b);
}
int main()
{
    freopen("ac.in", "r", stdin);
    freopen("ac.out", "w", stdout);

	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>q;
		if(a>b)
		swap(a,b);
		xx=a*b/__gcd(a,b);
		for(int i=1;i<=q;i++)
		{
			ll l,r;
			cin>>l>>r;
			cout<<fun(r)-fun(l-1)<<" ";
		}
		cout <<"\n";
	}
 } 