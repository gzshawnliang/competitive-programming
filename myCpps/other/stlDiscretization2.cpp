#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    freopen("stlDiscretization.in", "r", stdin);    
    ll n,m;
    cin>>n; 
    ll a[1000],b[1000],sub[1000];//a[n]是即将被离散化的数组，sub用于排序去重后提供离散化后的值
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        sub[i]=a[i];//先赋值 
    }
    cin>>m; 
    sort(sub+1,sub+n+1);//STL_SORT 排序 
    ll size=unique(sub+1,sub+n+1)-sub-1;//STL_UNQUE 去重，注意要减1，个数=sub+n+1-(sub+1)+1=n+1,故最后要把1减掉。 
    for(ll i=1;i<=size;i++)
        cout<<sub[i]<<" ";
    cout<<endl;
    for(ll i=1;i<=n;i++)
        a[i]=lower_bound(sub+1,sub+size+1,a[i])-sub; //即a[i]为b[i]离散化后对应的值 STL_LOWER 查询。 

    for(ll i=1;i<=n;i++)
        cout<<a[i]<<' ';//输出离散化后的数。 
        
    ll x=lower_bound(b+1,b+size+1,m)-b;//知道离散前的值m，求离散后的值。 同样用lower查找。 
    cout<<a[x];
    return 0;
}