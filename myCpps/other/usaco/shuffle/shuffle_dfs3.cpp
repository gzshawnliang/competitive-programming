#include <bits/stdc++.h>

using namespace std;

ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

vector<int> a;
vector<int> visited;
vector<int> excluded;
unordered_set<int> circle;

void dfs(int start, int curr)
{
    if (visited[curr] == 1 || circle.count(curr) == 1)
    {
        for (auto i : excluded)
        {
            visited[i] = 0;
        }
        return;
    }
    else
    {
        visited[curr] = 1;
    }

    excluded.push_back(curr);

    if (start == curr)
    {
        for (auto i : excluded)
        {
            circle.insert(i);
        }
        return;
    }
    else
    {
        dfs(start, a[curr]);
    }
}

int main()
{
    int N;
    fin >> N;
    a.assign(N + 1, 0);

    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        fin >> a[i];
        if (i == a[i])
            ++ans;
    }

    visited.assign(N + 1, 0);

    for (int i = 1; i <= N; ++i)
    {
        if (i != a[i] && circle.count(i) == 0)
        {

            excluded.clear();
            dfs(i, a[i]);
        }
    }
    ans += circle.size();
    fout << ans << "\n";
    //cout << icount << "\n";
    return 0;
}
