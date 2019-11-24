#include <bits/stdc++.h>

using namespace std;

ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

int main()
{
    int N;
    fin >> N;
    vector<int> a(N + 1, 0);
    vector<int> in(N + 1, 0);
    queue<int> q;
    for (int i = 1; i <= N; ++i)
    {
        fin >> a[i];
        ++in[a[i]];
    }

    for (int i = 1; i <= N; ++i)
        if (in[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        --in[a[t]];
        if (in[a[t]] == 0)
            q.push(a[t]);
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i)
        if (in[i] > 0)
            ++ans;

    fout << ans << "\n";
    return 0;
}
