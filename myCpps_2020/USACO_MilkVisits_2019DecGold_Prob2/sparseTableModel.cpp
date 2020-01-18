/*
===========================================================
* @Name:           Problem 2. Milk Visits 
* @Author:         Shawn
* @create Time:    2020/1/18 18:21:23
* @url:            http://www.usaco.org/index.php?page=viewproblem2&cpid=970&lang=zh
* @Description:    USACO 2019 December Contest, Gold
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("milkvisits.in");
ofstream fout("milkvisits.out");

int quickPow(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans *= a;
        }
        a *= a;

        b /= 2;
    }

    return ans;
}

int query(int i, int j, vector<int> & treNod, vector<vector<int>> & sta)
{
    int l = j - i + 1,
        log2L = log2(l);

    return min(treNod[sta[i][log2L]], treNod[sta[j - quickPow(2, log2L) + 1][log2L]]);
}

int main()
{
    vector<int> treNod = {2, 4, 3, 1, 6, 7, 8, 9, 1, 7};

    int sizeTreNod = treNod.size(),
        log2SizeTreNod = log2(sizeTreNod);

    vector<vector<int>> sta(sizeTreNod, vector<int>(log2SizeTreNod + 1, -1));

    int pow2J = 1;
    for (int j = 0; j <= log2SizeTreNod; ++j)
    {
        for (int i = 0; i + pow2J - 1 <= sizeTreNod - 1; ++i)
        {
            if (j == 0) sta[i][j] = i;
            else
            {
                if (treNod[sta[i][j - 1]] > treNod[sta[i + pow2J / 2][j - 1]])
                {
                    sta[i][j] = sta[i + pow2J / 2][j - 1];
                }
                else
                {
                    sta[i][j] = sta[i][j - 1];
                }
            }
        }

        pow2J *= 2;
    }

    fout << query(4, 7, treNod, sta) << '\n';

    return 0;
}
