#include <bits/stdc++.h>

using namespace std;

ifstream fin("fill_UVA10603.in");
ofstream fout("fill_UVA10603.out");

const int inf = INT_MAX / 2;

struct segment
{
    int j1;
    int j2;
    int j3;
    int total;

    bool operator<(const segment & temp) const
    {
        return total > temp.total;
    }
};
segment _segment(int j1, int j2, int j3, int total)
{
    segment temp{j1, j2, j3, total}; return temp;
}

int pour(int jm1, int & j1, int jm2, int & j2)
{
    if (jm2 - j2 <= j1)
    {
        int res = jm2 - j2;

        j1 -= (jm2 - j2);
        j2 = jm2;

        return res;
    }
    else
    {
        int res = j1;

        j2 += j1;
        j1 = 0;

        return res;
    }
}

int main()
{
    int testCase; fin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        int a, b, c, d; fin >> a >> b >> c >> d;

        vector<vector<vector<int>>> dp(a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1, inf)));   
        dp[0][0][c] = 0;

        vector<int> ans(max(a, max(b, max(c, d))) + 1, inf);
        priority_queue<segment> pq; pq.push(_segment(0, 0, c, 0));
        while (pq.empty() == false)
        {
            segment now = pq.top(); pq.pop();

            if (now.total >= dp[now.j1][now.j2][now.j3] && now.total > 0)
            {
                continue;
            }

            dp[now.j1][now.j2][now.j3] = now.total;

            ans[now.j1] = min(ans[now.j1], now.total);
            ans[now.j2] = min(ans[now.j2], now.total);
            ans[now.j3] = min(ans[now.j3], now.total);


            segment temp;

            if (now.j1 > 0)
            {
                if (now.j2 < b)
                {
                    temp = now; // 1 -> 2
                    temp.total += pour(a, temp.j1, b, temp.j2);
                    pq.push(temp);
                }

                if (now.j3 < c)
                {
                    temp = now; // 1 -> 3
                    temp.total += pour(a, temp.j1, c, temp.j3);
                    pq.push(temp);
                }
            }

            if (now.j2 > 0)
            {
                if (now.j1 < a)
                {
                    temp = now; // 2 -> 1
                    temp.total += pour(b, temp.j2, a, temp.j1);
                    pq.push(temp);
                }

                if (now.j3 < c)
                {
                    temp = now; // 2 -> 3
                    temp.total += pour(b, temp.j2, c, temp.j3);
                    pq.push(temp);
                }
            }

            if (now.j3 > 0)
            {
                if (now.j1 < a)
                {
                    temp = now; // 3 -> 1
                    temp.total += pour(c, temp.j3, a, temp.j1);
                    pq.push(temp);
                }

                if (now.j2 < b)
                {
                    temp = now; // 3 -> 2
                    temp.total += pour(c, temp.j3, b, temp.j2);
                    pq.push(temp);
                }
            }
        }

        int _d = d;
        while (_d >= 0 && ans[_d] == inf)
        {
            --_d;
        }

        fout << ans[_d] << ' ' << _d << '\n';
    }

    return 0;
}
