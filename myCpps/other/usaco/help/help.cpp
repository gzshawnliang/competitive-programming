#include <bits/stdc++.h>

using namespace std;

using ll=long long;

ifstream fin("help.in");
ofstream fout("help.out");

int main2()
{
    cout << (1<<4) << "\n";
    return 0;
}

void printPair(const pair<int,int> & p)
{
    cout << p.first << "-" << p.second << " ";
}

int main()
{
    vector<pair<int,int>> p;
    int n;
    fin >>n;

    for (int i = 0; i <= n - 1; ++i)
    {
        int l,r;
        fin >> l >>r;
        p.push_back({l,r});
    }
    sort(p.begin(),p.end());

    auto checkIsUnion = [](pair<int, int> & a, pair<int, int> & b) -> bool
    {
        if(a.first>b.first)
            swap(a,b);

        if (a.second >= b.first)
            return true;

        return false;
    };

    auto merge = [](pair<int, int> & a, pair<int, int> & b) -> pair<int, int> 
    {
        if(a.first>b.first)
            swap(a,b);
        
        return {a.first,max(a.second,b.second)};
    };

    vector<vector<pair<int,int>>> ans;

    //求所有的组合    
    ll totalAns=0;
    for(int i = 0; i <= (1<<n)-1; ++i)
    {
        vector<pair<int,int>> tt;
        
        for (int j = 0; j <= n-1; ++j)
        {
            if (((i >> j) & 1) == 1)
            {
                tt.push_back({p[j].first,p[j].second});
            }
        }
        int n3=tt.size();

        if(n3==0)
        {
            continue;
        }
        else
        {
            int j=1;
            int currTotal=1;
            pair<int,int> lastMerge=tt[0];
            printPair(lastMerge);
            while (j<=n3-1)
            {
                if(checkIsUnion(lastMerge,tt[j]))
                {
                    lastMerge = merge(lastMerge,tt[j]);
                    printPair(tt[j]);
                }
                else
                {
                    ++currTotal;
                    lastMerge = tt[j];
                    printPair(tt[j]);
                }
                ++j;
            }
            totalAns +=currTotal;
            
            cout << ":" << currTotal << "\n";           
        }
        //cout << "\n";
    } 
    std::cout << totalAns << "\n";

    return 0;
}
