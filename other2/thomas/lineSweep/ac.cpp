#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2222;
#define lson i*2,l,m
#define rson i*2+1,m+1,r
#define root 1,1,k-1
double X[MAXN];
struct node
{
    double l,r,h;
    int d;
    node(){}
    node(double a,double b,double c,int d): l(a),r(b),h(c),d(d){}
    bool operator <(const node &b)const
    {
        return h<b.h;
    }
}nodes[MAXN];
int cnt[MAXN*4];
double sum[MAXN*4];
void PushDown(int i,int l,int r)
{
    int m=(l+r)/2;
    if(cnt[i]!=-1)
    {
        cnt[i*2]=cnt[i*2+1]=cnt[i];
        sum[i*2]= (cnt[i]?(X[m+1]-X[l]):0) ;
        sum[i*2+1]= (cnt[i]?(X[r+1]-X[m+1]):0) ;
    }
}
void PushUp(int i,int l,int r)
{
    if(cnt[i*2]==-1 || cnt[i*2+1]==-1)
        cnt[i]=-1;
    else if(cnt[i*2] != cnt[i*2+1])
        cnt[i]=-1;
    else
        cnt[i]=cnt[i*2];
    sum[i]=sum[i*2]+sum[i*2+1];
}
void build(int i,int l,int r)
{
    if(l==r)
    {
        cnt[i]=0;
        sum[i]=0.0;
        return ;
    }
    int m=(l+r)/2;
    build(lson);
    build(rson);
    PushUp(i,l,r);
}
void update(int ql,int qr,int v,int i,int l,int r)
{
    if(ql<=l && r<=qr)
    {
        if(cnt[i]!=-1)
        {
            cnt[i]+=v;
            sum[i] = (cnt[i]? (X[r+1]-X[l]):0);
            return ;
        }
    }
    PushDown(i,l,r);
    int m=(l+r)/2;
    if(ql<=m) update(ql,qr,v,lson);
    if(m<qr) update(ql,qr,v,rson);
    PushUp(i,l,r);
}
int bin(double key,int n,double d[])
{
    int l=1,r=n;
    while(r>=l)
    {
        int m=(r+l)/2;
        if(d[m]==key)
            return m;
        else if(d[m]>key)
            r=m-1;
        else
            l=m+1;
    }
    return -1;
}
int main()
{
    freopen("lineSweep.in", "r", stdin);      
    freopen("ac.out", "w", stdout);    
    int q;
    int kase=0;
    while(scanf("%d",&q)==1&&q)
    {
        int n=0,m=0;
        for(int i=1;i<=q;i++)
        {
            double x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            X[++n]=x1;
            nodes[++m]=node(x1,x2,y1,1);
            X[++n]=x2;
            nodes[++m]=node(x1,x2,y2,-1);
        }
        sort(X+1,X+n+1);
        sort(nodes+1,nodes+m+1);
        int k=1;//共k个不同的x坐标,组成了k-1个不同的区域
        for(int i=2;i<=n;i++)
            if(X[i]!=X[i-1]) X[++k]=X[i];
        build(1,1,k-1);//少了build就WA
        double ret=0.0;//最终面积
        for(int i=1;i<m;i++)
        {
            int l=bin(nodes[i].l,k,X);
            int r=bin(nodes[i].r,k,X)-1;
            if(l<=r) update(l,r,nodes[i].d,root);
            ret += sum[1]*(nodes[i+1].h-nodes[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",++kase,ret );
    }
}
