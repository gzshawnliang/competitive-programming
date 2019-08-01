#include<iostream>
#include<stdio.h>
using namespace std;
int a[200000]={};
struct seg{
    int l,r,num;
};
seg tree[800000];
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
        return -1;
    }
    if(tree[k].l>=x && tree[k].r<=y){
        return tree[k].num;
    }
    return max(check(k*2,x,y),check(k*2+1,x,y));
}
void change(int k,int side,int nn){
    if(tree[k].l>side||tree[k].r<side){
        return;
    }
    if(tree[k].l==tree[k].r && tree[k].l==side){
        tree[k].num=nn;
        a[side]=nn;
        return;
    }
    tree[k].num=max(tree[k].num,nn);
    change(k*2,side,nn);
    change(k*2+1,side,nn);
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    build(1,0,n-1);
    char c;
    int a,b;
    while(c=getchar()){
        if(c==EOF){
            return 0;
        }
        if(c=='Q'){
            cin>>a>>b;
            cout<<check(1,a-1,b-1)<<'\n';
        }else if(c=='U'){
            cin>>a>>b;
            change(1,a-1,b);
        }
    }
    return 0;
}