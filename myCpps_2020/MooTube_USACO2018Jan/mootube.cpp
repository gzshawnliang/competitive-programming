#include <bits/stdc++.h>

using namespace std;

ifstream fin("mootube.in");
ofstream fout("mootube.out");

struct comp
{
    int u;
    int v;
    int r;

    bool operator < (const comp & temp) const
    {
        return r > temp.r;
    }
};
comp _comp(int u, int v, int r)
{
    comp temp{u, v, r}; return temp;
}

struct question
{
    int k;
    int v;
    int id;

    bool operator < (const question & temp) const
    {
        return k > temp.k;
    }
};
question _question(int u, int v, int r)
{
    question temp{u, v, r}; return temp;
}


int findF(int x, vector<int> &f)
{
    if (f[x] == x)
    {
        return x;
    }
    else
    {
        int ans = findF(f[x], f);

        f[x] = ans;
        return ans;
    }
}

int main()
{
    int n, q; fin >> n >> q;

    vector<comp> compares(n - 1);
    for (int i = 0; i <= n - 2; ++i)
    {
        fin >> compares[i].u >> compares[i].v >> compares[i].r;
    }

    vector<question> questions(q);
    for (int i = 0; i <= q - 1; ++i)
    {
        fin >> questions[i].k >> questions[i].v;

        questions[i].id = i;
    }

    sort(compares.begin(), compares.end());
    sort(questions.begin(), questions.end());

    vector<int> ans(q), f(n + 1), countG(n + 1, 1);
    for (int u = 1; u <= n; ++u) f[u] = u;

    int i = 0;
    for (int j = 0; j <= q - 1; ++j)
    {
        while (compares[i].r >= questions[j].k && i <= n - 2)
        {
            int fU = findF(compares[i].u, f),
                fV = findF(compares[i].v, f);

            f[fU] = fV;
            countG[fV] += countG[fU];

            ++i;
        }

        ans[questions[j].id] = countG[findF(questions[j].v, f)] - 1;
    }

    for (int i = 0; i <= q - 1; ++i)
    {
        fout << ans[i] << '\n';
    }

    return 0;
}
