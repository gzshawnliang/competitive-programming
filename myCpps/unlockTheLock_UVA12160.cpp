#include <bits/stdc++.h>

using namespace std;

ifstream fin("unlockTheLock_UVA12160.in");
ofstream fout("unlockTheLock_UVA12160.out");

struct result
{
    int num;
    int tries;
};

result _result(int num, int tries)
{
    result temp{num, tries}; return temp;
}

int main()
{
    int t = 0;
    while (true)
    {
        int l = 0, u = 0, r = 0; fin >> l >> u >> r;
        if (l + u + r == 0) break;

        ++t;
        fout << "Case " << t << ": ";

        vector<int> buttoms(r);
        for (int i = 0; i <= r - 1; ++i)
        {
            fin >> buttoms[i];
        }

        vector<bool> visit(10000, false);
        queue<result> q; q.push(_result(l, 0));
        

        int ans = -1;
        while (!q.empty() && ans == -1)
        {
            result now = q.front();

            q.pop();

            if (now.num == u)
            {
                ans = now.tries;
                break;
            }
            else if (visit[now.num] == true)
            {
                continue;
            }
            else
            {
                visit[now.num] = true;
            }
            
            for (int i = 0; i <= r - 1; ++i)
            {
                q.push(_result((now.num + buttoms[i]) % 10000, now.tries + 1));
            }
        }

        if (ans == -1)
        {
            fout << "Permanently Locked\n";
        }
        else
        {
            fout << ans << '\n';
        }
    }

    return 0;
}
