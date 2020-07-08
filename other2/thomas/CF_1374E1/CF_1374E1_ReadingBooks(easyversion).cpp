/*
-------------------------------------------------------------------
# @Name:           1374E1 Reading Books (easy version)
# @By:             yanan
# @Create Time:    2020/6/28 22:35:30  (UTC+08:00)
# @Url:            https://codeforces.com/gym/1374/problem/E1
# @Description:    
-------------------------------------------------------------------

*/

#include <bits/stdc++.h>

using namespace std;

//ifstream fin("CF_1374E1_ReadingBooks(easyversion).in");
//ofstream fout("CF_1374E1_ReadingBooks(easyversion).out");

int main()
{
#ifndef ONLINE_JUDGE
    freopen("CF_1374E1_ReadingBooks(easyversion).in", "r", stdin);
    freopen("CF_1374E1_ReadingBooks(easyversion).out", "w", stdout);
#endif
    
    int n,k;
    cin>>n>>k;
    vector<int> reada,readb,read;
    int an=0,bn=0,A=0,B=0;
    for(int i=0;i<n;++i)
    {
        int t;
        int a=0,b=0;
        cin>>t>>a>>b;
        if(a==1 && b==1)
        {
            read.push_back(t);
            ++A;
            ++B;
        }
        else if(a)
        {
            ++an;
            ++A;
            reada.push_back(t);
        }
        else 
        {
            ++bn;
            ++B;
            readb.push_back(t);
        }
    }
    if(A<k || B<k)
    {
        cout<<-1<<'\n';
        return 0;
    }
    sort(reada.begin(),reada.end());
    sort(readb.begin(),readb.end());
    //sort(readc.begin(),readc.end());
    int tempk;
    if(an<=bn)
    {
        tempk=an;
    }   
    else
    {
        tempk=bn;
    }
    for(int i=0;i<tempk;++i)
    {
        read.push_back(reada[i]+readb[i]);
    }
    sort(read.begin(),read.end());
    int ans=0;
    if(read.size()<k)
    {
        cout<<-1<<'\n';
        return 0;
    }
    for(int i=0;i<k;++i)
    {
        ans+=read[i];
    }
    cout<<ans<<'\n';
    return 0;
}
