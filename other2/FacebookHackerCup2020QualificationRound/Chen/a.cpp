#include <bits/stdc++.h>

using namespace std;

//ifstream fin("a.in");
//ofstream fout("a.out");

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int t;cin>>t;
    for(int i=0;i<t;++i)
    {
        int n;cin>>n;
        vector<vector<int>> air(n, vector<int> (2));
        string income,outcome;
        cin>>income>>outcome;
        for(int j=0;j<n;++j)
        {
            int state;
            if(income[j]=='Y')
            {
                state=1;
            }
            else
            {
                state=0;
            }
            air[j][0]=state;
            state=-1;
            if(outcome[j]=='Y')
            {
                state=1;
            }
            else
            {
                state=0;
            }
            air[j][1]=state;
        }
        cout<<"Case #"<<i+1<<':'<<'\n';
        for(int j=0;j<n;++j)
        {
            vector<char> ans(n,'N');
            queue<int> pass;
            pass.push(j);
            while(true)
            {
                if(pass.empty())
                {
                    break;
                }
                if(air[pass.front()][1]==1)
                {
                    if(pass.front()-1>=0)
                    {
                        if(air[pass.front()-1][0]==1 && ans[pass.front()-1]=='N')
                        {
                            pass.push(pass.front()-1);
                        }
                    }
                    if(pass.front()+1<n)
                    {
                        if(air[pass.front()+1][0]==1 && ans[pass.front()+1]=='N')
                        {
                            pass.push(pass.front()+1);
                        }
                    }
                }
                ans[pass.front()]='Y';
                pass.pop();
            }
            for(int h=0;h<n;++h)
            {
                cout<<ans[h];
            }
            cout<<'\n';
        }
    }
    return 0;
}
