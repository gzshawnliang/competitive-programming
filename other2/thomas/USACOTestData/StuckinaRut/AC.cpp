#include<bits/stdc++.h>
using namespace std;
const long long N=100010,M=1000010,INF=0x3f3f3f3f;
const long long dx[]={1,0};//E N
const long long dy[]={0,1};
struct node{
	char c;
	long long x,y,ti,id;
	bool operator <(const node &a)const{
		return ti>a.ti;
	}
}a[2010],e[2010],g[2010][2010];
long long head[N],ver[M],Next[M],tot;
long long T,n,m,cnt,num,size2[2010],fa[2010],b[M],st[M];
priority_queue<node> q;
inline long long Max(long long x,long long y){return x>y?x:y;}
inline long long Min(long long x,long long y){return x<y?x:y;}
inline void Swap(long long &x,long long &y){x^=y^=x^=y;}
void add(long long x,long long y){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
}
long long query(long long x){
	return lower_bound(b+1,b+cnt+1,x)-b;
}
void dfs(long long x,long long ffa){
	size2[x]=1;
	for(long long i=head[x];i;i=Next[i]){
		long long y=ver[i];
		if(y==ffa)continue;
		dfs(y,x);
		size2[x]+=size2[y];
	}
}
int main(){
    freopen("StuckinaRut.in", "r", stdin);
    freopen("StuckinaRut.ok", "w", stdout);    
	scanf("%lld",&T);
	for(long long i=1;i<=T;i++){
		cin>>a[i].c;
		scanf("%lld%lld",&a[i].x,&a[i].y);
		b[++num]=a[i].x;
		b[++num]=a[i].y;
	}
	sort(b+1,b+num+1);
	cnt=unique(b+1,b+num+1)-b-1;
	for(long long i=1;i<=T;i++){
		long long x=query(a[i].x);
		long long y=query(a[i].y);
		g[x][y]=e[i]=(node){a[i].c,x,y,0,i};
		st[x]=a[i].x;st[y]=a[i].y;
		n=Max(n,x),m=Max(m,y);
	}
	for(long long i=1;i<=T;i++){
		fa[i]=i;
		long long mt;
		long long x=e[i].x;
		long long y=e[i].y;
		long long dir=(e[i].c=='E')?0:1;
		long long tx=x+dx[dir];
		long long ty=y+dy[dir];
		if(tx<1||tx>n||ty<1||ty>m)continue;
		if(dir&1)mt=st[ty]-st[y];
		else mt=st[tx]-st[x];
		q.push((node){e[i].c,x,y,mt,i});
	}
	while(q.size()){
		char c=q.top().c;
		node t=q.top();q.pop();
		long long dir=(c=='E')?0:1,mt;
		t.x+=dx[dir];
		t.y+=dy[dir];
		if(g[t.x][t.y].id&&g[t.x][t.y].ti<t.ti){
			fa[t.id]=g[t.x][t.y].id;
			continue;
		}
		g[t.x][t.y]=t;
		long long tx=t.x+dx[dir];
		long long ty=t.y+dy[dir];
		if(tx<1||tx>n||ty<1||ty>m)continue;
		if(dir&1)mt=st[ty]-st[t.y];
		else mt=st[tx]-st[t.x];
		q.push((node){t.c,t.x,t.y,t.ti+mt,t.id});
	}	
	for(long long i=1;i<=T;i++)
		if(fa[i]!=i)add(i,fa[i]),add(fa[i],i);
	for(long long i=1;i<=T;i++)
		if(fa[i]==i)dfs(i,0);
	for(long long i=1;i<=T;i++)
		printf("%lld\n",size2[i]-1);
	return 0;
}