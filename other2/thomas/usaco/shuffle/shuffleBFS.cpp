#include <bits/stdc++.h>

using namespace std;

ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

struct cow
{
    int to;
    int in;
};


int main()
{
    int N;
    fin >> N;
    vector<cow> a(N + 1);
    
    for (int i = 1; i <= N; ++i)
    {
        fin >> a[i].to;
        ++a[a[i].to].in;
    }
    
    queue<cow> q;
    for (int i = 1; i <= N; ++i)
        if (a[i].in == 0)
            q.push(a[i]);

    while (!q.empty())
    {
        cow t = q.front();
        q.pop();

        int next=t.to;
        --a[next].in;
        if (a[next].in == 0)
            q.push(a[next]);
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i)
        if (a[i].in > 0)
            ++ans;

    fout << ans << "\n";
    return 0;
}
