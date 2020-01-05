/*
*  Author : pritish.thakkar 
*/
 
#include<bits/stdc++.h>
#define     rep(i,n)                for(int i=0;i<n;i++)
#define     clr(a)                  memset(a,0LL,sizeof a);
#define     gc                      getchar
 
using       namespace               std;
 
typedef     unsigned long long      ull;
typedef     long long               ll;
typedef     vector<ll>              vi;
typedef     pair<ll,ll>             ii;
typedef     vector<ii>              vii;
 
//Fast Reader : 
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}
 
//_____________________________
 
ll n;
const ll N = 5*(1e5);
ll a[N<<4];
struct node{
    ll sum, maxSum, left, right;
};
 
node st[N<<4];
 
ll getMid(ll a , ll b){
    return a + (b - a) / 2;
}
 
void fillVal(ll index){
    ll L = index*2+1;
    ll R = index*2+2;
    st[index].sum = st[L].sum + st[R].sum;
    st[index].left = max(st[L].left, st[L].sum + st[R].left);
    st[index].right = max(st[R].right, st[R].sum + st[L].right);
    st[index].maxSum = max(max(st[L].maxSum, st[R].maxSum), st[R].left + st[L].right); 
}
 
void build(ll from , ll to, ll index){
    if(from == to){
        st[index].sum = st[index].maxSum = st[index].left = st[index].right = a[from];
        return;
    }
 
    ll mid = getMid(from , to);
    build(from, mid, index*2+1);
    build(mid+1, to, index*2+2);
    fillVal(index);
}
 
node emptyNode(){
    node ret;
    ret.left = ret.right = ret.sum = ret.maxSum = 0;
    return ret;
}
 
node Combination(node a, node b){
    node ret;
    ret.sum = a.sum + b.sum;
    ret.left = max(a.left, a.sum + b.left);
    ret.right = max(b.right, b.sum + a.right);
    ret.maxSum = max(max(a.maxSum, b.maxSum), b.left + a.right); 
    return ret;
}
 
node query(ll index, ll from , ll to, ll l, ll r){
    if(r < from || l > to){
        return emptyNode();
    }
    if(from >= l && to <= r){
        return st[index];
    }
    ll mid = getMid(from, to);
    if(r <= mid){
        return query(index*2+1, from , mid, l, r);
    }
    if(l > mid){
        return query(index*2+2, mid+1, to, l, r); 
    }
    node LChild = query(index*2+1, from, mid, l, r);
    node RChild = query(index*2+2, mid+1, to, l, r);
    return Combination(LChild, RChild);
}
 
void solve(){
    read(n);
    ll i;
    rep(i,n){
        read(a[i]);
    }    
    build(0,n-1, 0);
    ll Q;
    read(Q);
    while(Q--){
        ll l, r;
        read(l);
        read(r);
        printf("%lld\n",  query(0, 0, n-1, l-1, r-1).maxSum);
    }
}
//___________________________
 
int main(int argc, char *argv[]){
    freopen("GSS1_AC2.in", "r", stdin);      
    freopen("GSS1_AC2.out", "w", stdout); 

    std::ios::sync_with_stdio(0);
    solve();
}