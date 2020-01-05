#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define pb push_back
#define left t<<1
#define right t<<1|1
using namespace std;
const int N=1e5+10;
struct node{
  int max1,max2;
}tree[N<<2];
int max1,max2;
void build(int t,int L,int R){
    if(L==R){
    scanf("%d",&tree[t].max1);
    tree[t].max2=0;
    return;
    }
    int mid=(L+R)>>1;
    build(left,L,mid);
    build(right,mid+1,R);
    if(tree[left].max1>tree[right].max1){
        tree[t].max1=tree[left].max1;
        tree[t].max2=max(tree[left].max2,tree[right].max1);
    }else{
        tree[t].max1=tree[right].max1;
        tree[t].max2=max(tree[right].max2,tree[left].max1);
    }
}
void update(int t,int L,int R,int x,int v){
    if(L==R){
        tree[t].max1=v;
        return;
    }
    int mid=(L+R)>>1;
    if(x<=mid){
        update(left,L,mid,x,v);
    }
    else {
        update(right,mid+1,R,x,v);
    }
    if(tree[left].max1>tree[right].max1){
        tree[t].max1=tree[left].max1;
        tree[t].max2=max(tree[left].max2,tree[right].max1);
    }else{
        tree[t].max1=tree[right].max1;
        tree[t].max2=max(tree[right].max2,tree[left].max1);
    }
}
 
void query(int t,int L,int R,int l,int r){
  if(l<=L && R<=r){
    if(tree[t].max1>max1){
      max2=max(max2,max1);
      max1=tree[t].max1;
      max2=max(max2,tree[t].max2);
    }else{
      max2=max(max2,tree[t].max1);
    }
    return;
  }
  int mid=(L+R)>>1;
  if(l<=mid)query(left,L,mid,l,r);
  if(r>mid)query(right,mid+1,R,l,r);
}
 
int main(){
    // freopen("i.in", "r", stdin);      
    // freopen("i.out", "w", stdout);  
    ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); 
    int n,m,l,r;
    char op[2];
    while(~scanf("%d",&n)){
        memset(tree,0,sizeof(tree));
        build(1,1,n);
        scanf("%d",&m);
        while(m--){
            scanf("%s%d%d",op,&l,&r);
            if(op[0]=='U'){
                update(1,1,n,l,r);
            }else{
                max1=max2=0;
                query(1,1,n,l,r);
                printf("%d\n",max1+max2);
            }
        }
    }
}