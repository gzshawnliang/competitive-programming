#include<bits/stdc++.h>
using namespace std;
 
#define ll 				long long int
#define gof 			for(long long int i = 0 ; i < n ; i++)
#define for1(i,s,e) 	for(long long int i = s ; i < e ; i++)
#define forr(i,e,s) 	for(long long int i = e ; i >= s; i--)
#define vi 				vector<long long int>
#define all(x) 			x.begin(), x.end()
#define pb(x) 			push_back(x)
#define maxv(x) 		*max_element(x)
#define minv(x) 		*min_element(x)
#define mkvec(type,a,n) vector<type> a(n)
 
const ll ARR = 1e5;
const ll INF = 1e9;
const ll mod = 1e9+7;
 
void IO()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("CF_1385B_RestorethePermutationbyMerger.in", "r", stdin);
    freopen("CF_1385B_RestorethePermutationbyMerger.out", "w", stdout);
#endif
}
 
void solve(){
 
    ll n;
    cin >> n;
    ll a[200];
    for1(i,0,2*n) cin >> a[i];
 
    vector<ll> v;
    ll hp[1000] = {0};
    
    for1(i,0,2*n){
        if(!hp[a[i]-1]){
            v.pb(a[i]);
            hp[a[i] - 1]++;
        }
    }
 
    for(auto i : v){
        cout << i << " ";
    }
 
    cout << "\n";
 
    return;
 
}
 
int main(){
	IO();
    ll t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
 