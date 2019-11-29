#include <bits/stdc++.h>

using namespace std;

ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

vector<int> a;
vector<int> visted;
vector<int> excludedCurr;
unordered_set<int> excludedAll;

int N;

void dfs(int start,int curr)
{
    if(visted[curr]==1)
        return ;
    else
        visted[curr]=1;

    excludedCurr.push_back(curr);

    if(start==curr)
    {
        for(auto i:excludedCurr)
            excludedAll.insert(i);

        //excludedAll.insert(excludedAll.end(),excludedCurr.begin(),excludedCurr.end());
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
    for (int i = 1; i <= N; ++i)
    {
        fin >> a[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        visted.assign(N + 1, 0);
        excludedCurr.clear();
        dfs(i, a[i]);
    }

    fout << excludedAll.size() << "\n";
    return 0;
}
