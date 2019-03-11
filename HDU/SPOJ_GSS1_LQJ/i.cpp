#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[200000]={};
struct seg{
    int l,r,num;
};
seg tree[800000];
vector<int> p;
void build(int k,int left,int right){
    tree[k].l=left;
    tree[k].r=right;
    if(left==right){
        tree[k].num=a[left];
        return;
    }
    int mid=(left+right)>>1;
    build(k*2,left,mid);
    build(k*2+1,mid+1,right);
    tree[k].num=max(tree[k*2].num,tree[k*2+1].num);
}
int check(int k,int x,int y){
    if(tree[k].l>y||tree[k].r<x){
        return 0;
    }
    if(tree[k].l>=x && tree[k].r<=y){
        p.push_back(tree[k].num);
        return tree[k].num;
    }
    int temp=max(check(k*2,x,y),check(k*2+1,x,y));
    p.push_back(temp);
    return temp;
}
void query(int x,int y){
    int ans1=check(1,x,y);
    reverse(p.begin(),p.end());
    cout<<p[0]<<" "<<p[1]<<'\n';
    cout<<ans1+p[1]<<'\n';
    p.empty();
}
void change(int k,int side,int nn){
    if(tree[k].l>side||tree[k].r<side){
        return;
    }
    if(tree[k].l==tree[k].r && tree[k].l==side){
        tree[k].num=nn;
        return;
    }
    
    change(k*2,side,nn);
    change(k*2+1,side,nn);
    tree[k].num=max(tree[k*2].num,tree[k*2+1].num);
}
int main(){

    freopen("i.in", "r", stdin);      
    freopen("i.out", "w", stdout);  
    ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);  
    int n,m;
    char c;
    int a1,b1;
    while(cin>>n){
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        build(1,0,n-1);
        cin>>m;
        for(int test=0;test<m;++test){
            cin>>c;
            if(c=='Q'){
                cin>>a1>>b1;
                query(a1-1,b1-1);
            }else if(c=='U'){
                cin>>a1>>b1;
                change(1,a1-1,b1);
            }
        }
    }
    cout.flush();
    return 0;
}