#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
using LL=long long;
struct seg
{
    LL l;
    LL r;
    LL sum;
    LL lazy;
};
seg tree[400000];
void build(int k,int left,int right)
{
    tree[k].l=left;
    tree[k].r=right;
    tree[k].sum=tree[k].lazy=0;
    if(left==right)
    {
        return;
    }
    int mid=(left+right)>>1;
    build(k*2,left,mid);
    build(k*2+1,mid+1,right);
}
void update(int k,int x,int y,int num)
{
    if(tree[k].lazy!=0)
    {
        tree[k].sum+=(tree[k].r-tree[k].l+1)*tree[k].lazy;
        if(tree[k].l!=tree[k].r)
        {
            tree[k*2].lazy+=tree[k].lazy;
            tree[k*2+1].lazy+=tree[k].lazy;
        }
        tree[k].lazy=0;
    }
    if(tree[k].l>y||tree[k].r<x){
        return;
    }
    if(tree[k].l>=x&&tree[k].r<=y)
    {
        tree[k].sum+=(tree[k].r-tree[k].l+1)*num;
        if(tree[k].l!=tree[k].r)
        {
            tree[k*2].lazy+=num;
            tree[k*2+1].lazy+=num;
        }
        return;
    }
    LL mid=(tree[k].l+tree[k].r)>>1;
    update(k*2,x,y,num);
    update(k*2+1,x,y,num);
    tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
}
LL query(int k,int x,int y)
{
    if(tree[k].r<x||tree[k].l>y){
        return 0;
    }
    if(tree[k].lazy!=0)
    {
        tree[k].sum+=(tree[k].r-tree[k].l+1)*tree[k].lazy;
        if(tree[k].l!=tree[k].r)
        {
            tree[k*2].lazy+=tree[k].lazy;
            tree[k*2+1].lazy+=tree[k].lazy;
        }
        tree[k].lazy=0;
    }
    if(tree[k].l>=x&&tree[k].r<=y)
    {
        return tree[k].sum;
    }
    LL mid=(tree[k].l+tree[k].r)>>1;
    return query(k*2,x,y)+query(k*2+1,x,y);
}
int main(void)
{
//     freopen("HORRIBLE.in", "r", stdin);      
//     freopen("HORRIBLE.out", "w", stdout);  
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);  
    LL testCase; 
    cin >> testCase;
    for (LL t = 1; t <= testCase; ++t)
    {
        LL n = 0, m = 0;
        cin >> n >> m;
        if (n + m == 0)
            break;
        build(1,0,n-1);
        for (LL c = 1; c <= m; ++c)
        {
            bool command; 
            cin >> command;
            if (command == 0)
            {
                LL l, r, v; 
                cin >> l >> r >> v;
                update(1,l-1,r-1,v);

            }
            else
            {
                LL l, r; 
                cin >> l >> r;
                LL ans = query(1,l - 1, r - 1);
                cout << ans << '\n';
            }
        }
    }
    cout.flush();
    return 0;
}