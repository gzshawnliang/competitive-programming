#include <cmath>
#include <cstring>
#include <vector>
#include <iostream>
 
using namespace std;
struct list
{
    long sum,bestsum,left,right;
};
 
list* make_new_node(long s,long bs,long l,long r)
{
    list* temp=new list();
    temp->sum=s;
    temp->bestsum=bs;
    temp->left=l;
    temp->right=r;
    return temp;
}
 
void build(long arr[],list* tree[],int node,int low,int high)
{
    if(low>high)
        return;
    if(low==high)
    {
        tree[node]=make_new_node(arr[low],arr[low],arr[low],arr[low]);
        return;
    }
 
    build(arr,tree,2*node+1,low,(high+low)/2);
    build(arr,tree,2*node+2,(high+low)/2+1,high);
 
//    tree[node]=NULL;
    long a=tree[2*node+1]->sum+tree[2*node+2]->sum;
    long b=max(max(tree[2*node+1]->bestsum,tree[2*node+2]->bestsum),tree[2*node+1]->right+tree[2*node+2]->left);
    long c=max(tree[2*node+1]->left,tree[2*node+1]->sum+tree[2*node+2]->left);
    long d=max(tree[2*node+1]->right+tree[2*node+2]->sum,tree[2*node+2]->right);
 
    tree[node]=make_new_node(a,b,c,d);
}
 
list* query(list* tree[],int node,int low,int high,int l,int r)
{
    if(low==l && high==r)
        return tree[node];
    int p1 = 2*node+1, p2 = 2*node+2, mid = (low+high)/2;
    if(r<=mid) 
    	return query(tree,p1,low,mid,l,r);
 	if(l>mid)
 		return query(tree,p2,mid+1,high,l,r);
    list *a=query(tree,2*node+1,low,(high+low)/2,l,mid);
    list *b=query(tree,2*node+2,(high+low)/2+1,high,mid+1,r);
 	list *n;
    long w=a->sum+b->sum;
    long x=max(max(a->bestsum,b->bestsum),a->right+b->left);
    long y=max(a->left,a->sum+b->left);
    long z=max(a->right+b->sum,b->right);
    n=make_new_node(w,x,y,z);
 
    return n;
}
 
int main() 
{
    freopen("GSS1_AC1.in", "r", stdin);      
    freopen("GSS1_AC1.out", "w", stdout); 

    //ios_base::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
//    cin>>n;
    long arr[n];
    list* tree[5*n];
    for(int i=0;i<n;i++)
        scanf("%ld",&arr[i]);
//        cin>>arr[i];
    build(arr,tree,0,0,n-1);
 
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
//        cout<<query(tree,0,0,n-1,l-1,r-1)->bestsum<<endl;
        printf("%ld\n",query(tree,0,0,n-1,l-1,r-1)->bestsum);
    }
    return 0;
}