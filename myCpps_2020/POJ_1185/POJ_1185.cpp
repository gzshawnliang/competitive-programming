/*
===========================================================
* @Name:            1185 -- 炮兵阵地 
* @Author:          Shawn
* @create Time:     2020/3/16 20:56:28
* @url:             http://poj.org/problem?id=1185
* @Description:     
===========================================================
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

#define ill long long;

const int maxM = 10;

bool g(int c, int x)
{
    bitset<maxM> bc(c), bx(x);
    for (int i = 0; i <= maxM - 1; ++i)
    {
        if (bc[i] == 0 && bx[i] == 1) return false;
    }

    return true;
}

bool canhit(int x, int y, int z)
{
    if ((x & y) > 0) return true;
    if ((x & z) > 0) return true;
    if ((y & z) > 0) return true;

    return false;
}

void upd(int &x, int tmp)
{
    x = max(x, tmp);
}

void solve()
{
    while (true)
    {
        int n = 0, m = 0; cin >> n >> m;
        if (n + m == 0) break;

        vector<int> a(n, 0);
        for (int y = 0; y <= n - 1; ++y)
        {
            for (int x = 0; x <= m - 1; ++x)
            {
                char tmp; cin >> tmp;
                if (tmp == 'P') a[y] += (1 << x);
            }
        }

        vector<int> allRows;
        for (int i = 0; i <= (1 << m) - 1; ++i)
        {
            bitset<maxM> b(i);

            bool flg = true;
            int lst = -maxM;
            for (int i = 0; i <= m - 1; ++i)
            {
                if (b[i] == 1)
                {
                    if (i - lst <= 2)
                    {
                        flg = false; break;
                    }

                    lst = i;
                }
            }

            if (flg == true) allRows.push_back(i);
        }
        int sizR = allRows.size();

        // for (int i = 0; i <= sizR - 1; ++i)
        // {
        //     for (int j = 0; j <= sizR - 1; ++j)
        //     {
        //         for (int k = 0; k <= sizR - 1; ++k)
        //         {
        //             bool flg = true;
        //             if ((allRows[i] & allRows[j]) > 0) flg = false;
        //             if ((allRows[i] & allRows[k]) > 0) flg = false;
        //             if ((allRows[j] & allRows[k]) > 0) flg = false;

        //             if (flg == 1)
        //             {
        //                 bitset<maxM> tmpI(allRows[i]);
        //                 cout << tmpI.to_string() << '\n';

        //                 bitset<maxM> tmpJ(allRows[j]);
        //                 cout << tmpJ.to_string() << '\n';

        //                 bitset<maxM> tmpK(allRows[k]);
        //                 cout << tmpK.to_string() << '\n';

        //                 cout << "----------\n";
        //             }
        //         }
        //     }
        // }
        
        int ans = 0;
        if (n == 1)
        {
            for (int i = 0; i <= sizR - 1; ++i)
            {
                if (g(a[0], allRows[i]) == false) continue;

                bitset<maxM> tmpI(allRows[i]);
                upd(ans, tmpI.count());
            }
            cout << ans << '\n';

            continue;
        }
        else if (n == 2)
        {
            for (int i = 0; i <= sizR - 1; ++i)
            {
                if (g(a[0], allRows[i]) == false) continue;
                for (int j = 0; j <= sizR - 1; ++j)
                {
                    if (g(a[1], allRows[j]) == false) continue;

                    if ((allRows[i] & allRows[j]) == 0)
                    {
                        bitset<maxM> tmpI(allRows[i]), tmpJ(allRows[j]);
                        upd(ans, tmpI.count() + tmpJ.count());
                    }
                }
            }
            cout << ans << '\n';

            continue;
        }

        vector<vector<int>> allPosRows(n);
        for (int y = 0; y <= n - 1; ++y)
        {
            for (int i = 0; i <= sizR - 1; ++i)
            {
                if (g(a[y], allRows[i])) allPosRows[y].push_back(i);
            }
        }

        vector<vector<vector<int>>> f(n, vector<vector<int>>(sizR, vector<int>(sizR, 0)));
        for (int y = 2; y <= n - 1; ++y)
        {
            for (vector<int>::iterator itI = allPosRows[y - 2].begin(); itI != allPosRows[y - 2].end(); ++itI)
            {
                int i = *itI;
                for (vector<int>::iterator itJ = allPosRows[y - 1].begin(); itJ != allPosRows[y - 1].end(); ++itJ)
                {
                    int j = *itJ;
                    for (vector<int>::iterator itK = allPosRows[y].begin(); itK != allPosRows[y].end(); ++itK)
                    {
                        int k = *itK;
                        if (canhit(allRows[i], allRows[j], allRows[k])) continue;

                        if (y == 2)
                        {
                            bitset<maxM> tmpI(allRows[i]), tmpJ(allRows[j]), tmpK(allRows[k]);
                            upd(f[y][k][j], tmpI.count() + tmpJ.count() + tmpK.count());
                        }
                        else
                        {
                            bitset<maxM> tmpK(allRows[k]);
                            upd(f[y][k][j], f[y - 1][j][i] + tmpK.count());
                        }

                        upd(ans, f[y][k][j]);
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("POJ_1185.in", "r", stdin);
        freopen("POJ_1185.out", "w", stdout);
    #endif    

    solve();

    cout.flush();    
    return 0;
}
