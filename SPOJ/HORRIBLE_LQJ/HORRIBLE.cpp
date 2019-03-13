#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<queue>
#include<stack>
#include<map>
#include<math.h>
using namespace std;
typedef long long LL;
LL tree[6*100005];
LL cnt[6*100005];
LL aa[100005];
void down(int k);
void up(int k,int v);
LL  ask(int l,int r,int k,int n,int m);
void  in(int l,int r,int k,int n,int m,int u);
int main(void)
{
    freopen("HORRIBLE.in", "r", stdin);      
    freopen("HORRIBLE.out", "w", stdout);  
    ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);  
    int i,j,k;
    scanf("%d",&k);
    int s;
    int n,m;
    for(s=1; s<=k; s++)
    {
        scanf("%d %d",&n,&m);
        memset(tree,0,sizeof(tree));
        memset(cnt,0,sizeof(cnt));
        int flag=0;
        while(m--)
        {
            int x,y;
            int xx,yy,zz;
            scanf("%d",&x);
            if(x==0)
            {
                scanf("%d %d %d",&xx,&yy,&zz);
                in(xx,yy,0,0,n-1,zz);
            }
            else
            {
                scanf("%d %d",&xx,&yy);
                LL as=ask(xx,yy,0,0,n-1);
                aa[flag++]=as;
            }

        }
        for(i=0; i<flag; i++)
            printf("%lld\n",aa[i]);
    }
    cout.flush();
}
void down(int k)
{
        cnt[2*k+1]+=cnt[k];
        cnt[2*k+2]+=cnt[k];
        cnt[k]=0;
}
void up(int k,int v)
{
        int cc=k;
        tree[cc]+=cnt[k]*v;
        if(cc==0)return ;
        while(cc>=0)
        {
                cc=(cc-1)/2;
                tree[cc]=tree[2*cc+1]+tree[2*cc+2];
                if(cc==0)
                        return ;
        }
}
LL  ask(int l,int r,int k,int n,int m)
{
        if(l>m||r<n)
        {
                if(cnt[k]>0)
                {
                        up(k,m-n+1);
                        down(k);
                }
                return 0;
        }
        else if(l<=n&&r>=m)
        {
                if(cnt[k]>0)
                {
                        up(k,m-n+1);
                        down(k);
                        return tree[k];
                }
                else return tree[k];
        }
        else
        {
                if(cnt[k]>0)
                {

                        down(k);
                }
                LL nx=ask(l,r,2*k+1,n,(n+m)/2);
                LL ny=ask(l,r,2*k+2,(n+m)/2+1,m);
                return nx+ny;
        }
}
void  in(int l,int r,int k,int n,int m,int u)
{
        if(l>m||r<n)
        {
                if(cnt[k]>0)
                {
                        up(k,m-n+1);
                        down(k);
                }
                return ;
        }
        else if(l<=n&&r>=m)
        {
                cnt[k]+=u;
                up(k,m-n+1);
                down(k);
                return ;
        }
        else
        {
                if(cnt[k]>0)
                {

                        down(k);
                }
                in(l,r,2*k+1,n,(n+m)/2,u);
                in(l,r,2*k+2,(n+m)/2+1,m,u);
        }
}