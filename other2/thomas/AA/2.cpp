
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <ctime>
#include <map>
#include <set>
using namespace std;
// #pragma comment(linker, "/stck:1024000000,1024000000")
#define lowbit(x) (x&(-x))
#define max(x,y) (x>=y?x:y)
#define min(x,y) (x<=y?x:y)
#define MAX 100000000000000000
#define MOD 1000000007
#define pi acos(-1.0)
#define ei exp(1)
#define PI 3.1415926535897932384626433832
#define ios() ios::sync_with_stdio(true)
#define INF 0x3f3f3f3f
#define mem(a) (memset(a,0,sizeof(a)))
typedef long long ll;
const int s=8;
char ch[26];
ll mult_mod(ll a,ll b,ll c)
{
    a%=c;
    b%=c;
    ll ret=0;
    ll tmp=a;
    while(b)
    {
        if(b&1){
            ret+=tmp;
            if(ret>c) ret-=c;
        }
        tmp<<=1;
        if(tmp>c) tmp-=c;
        b>>=1;
    }
    return ret;
}
ll pow_mod(ll a,ll n,ll mod)
{
    ll ans=1;
    ll tmp=a%mod;
    while(n)
    {
        if(n&1) ans=mult_mod(ans,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod);
        n>>=1;
    }
    return ans;
}
bool check(ll a,ll n,ll x,ll t)
{
    ll ret=pow_mod(a,x,n);
    ll last=ret;
    for(int i=1;i<=t;i++)
    {
        ret=mult_mod(ret,ret,n);
        if(ret==1 && last!=1 && last!=n-1) return true;
        last=ret;
    }
    if(ret!=1) return true;
    else return false;
}
bool miller_pabin(ll n)
{
    if(n<2) return false;
    if(n==2) return true;
    if((n&1)==0) return false;
    ll x=n-1;
    ll t=0;
    while((x&1)==0) {x>>=1;t++;}
    srand(time(NULL));
    for(int i=0;i<s;i++){
        ll a=rand()%(n-1)+1;
        if(check(a,n,x,t)) return false;
    }
    return true;
}
ll factor[110];
int tol=0;
ll gcd(ll a,ll b)
{
    ll t;
    while(b)
    {
        t=a;
        a=b;
        b=t%b;
    }
    if(a>=0) return a;
    else return -a;
}
ll pollard_rho(ll x,ll c)
{
    ll i=1,k=2;
    srand(time(NULL));
    ll x0=rand()%(x-1)+1;
    ll y=x0;
    while(1)
    {
        i++;
        x0=(mult_mod(x0,x0,x)+c)%x;
        ll d=gcd(y-x0,x);
        if(d!=1 && d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
    }
}
void findfac(ll n,ll k)
{
    if(n==1) return ;
    if(miller_pabin(n))
    {
        factor[tol++]=n;
        return ;
    }
    ll p=n;
    ll c=k;
    while(p>=n) p=pollard_rho(p,c--);
    findfac(p,k);
    findfac(n/p,k);
}
int main()
{
    ll n=294053760ll;
    //scanf("%lld",&n);
    if(miller_pabin(n)) printf("2\n");
    else
    {
        findfac(n,107);
        ll ans=1;
        for(int i=0;i<tol;i++)
        {
            //printf("%lld ",factor[i]);
            ll pos=0;
            while(n>0 && (n%factor[i]==0))
            {
                pos++;
                n/=factor[i];
            }
//            printf("%lld %lld\n",factor[i],pos);
            if(pos) ans*=(pos+1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}