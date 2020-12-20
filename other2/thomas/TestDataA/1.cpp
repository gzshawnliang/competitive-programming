#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
const int INF=0x3f3f3f3f;
typedef long long LL;
const int mod=1e9+7;
const double PI = acos(-1);
const double eps =1e-8;
#define Bug cout<<"---------------------"<<endl
const int maxn=1e5+10;
using namespace std;
const int prime[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

LL n;
int ans_t;//答案的因子个数
LL ans;//答案

void DFS(int step,int lim,int num,LL sum)//step表示第几个质数,lim表示该质数最高次幂,num表示因子个数,sum表示总和
{
    if(num>ans_t)//找因子个数最大的答案
    {
        ans_t=num;
        ans=sum;
    }
    else if(ans_t==num&&sum<ans)//找数字最小的答案
        ans=sum;
    if(step>=15) return;//递归出口
    for(int i=0;i<=lim;i++)
    {
        if(i!=0) sum*=prime[step];
        if(sum>n) break;
        DFS(step+1,i,num*(i+1),sum);
    }
}

int main()
{
    //#ifdef DEBUG
    freopen("1.in","r",stdin);
    //#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        ans_t=0;
        DFS(0,60,1,1);
        printf("%lld\n",ans);
    }

    return 0;
}