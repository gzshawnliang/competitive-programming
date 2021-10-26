#include <bits/stdc++.h>

using namespace std;

ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

vector<int> a;
vector<int> visitedCurr;
vector<int> excludedCurr;
unordered_set<int> excludedAll;

int N;

void dfs(int start,int curr)
{
    if(visitedCurr[curr]==1 || excludedAll.count(curr)==1)
        return ;
    else
        visitedCurr[curr]=1;

    excludedCurr.push_back(curr);

    if(start==curr)
    {
        for(auto i:excludedCurr)
            excludedAll.insert(i);

        return ;
    }
    else
    {
        dfs(start,a[curr]);
    }

}

int main()
{
    fin >> N;
    a.assign(N + 1, 0);
    vector<int> in(N + 1, 0);
    int ans=0;
    for (int i = 1; i <= N; ++i)
    {
        fin >> a[i];
        if(i==a[i])
            ++ans;
    }

    for (int i = 1; i <= N; ++i)
    {
        if(i!=a[i] && excludedAll.count(i)==0)
        {
            visitedCurr.assign(N + 1, 0);
            excludedCurr.clear();
            dfs(i, a[i]);
        }
    }
    ans +=excludedAll.size();
    fout << ans << "\n";
    return 0;
}
