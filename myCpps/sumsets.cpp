/***********************************************************
 * @名称:		sumset
 * @作者:		Shawn 
 * @创建时间: 2018-02-10 20:48:46 
 * @修改人:   Shawn 
 * @修改时间: 2018-02-10 20:48:46 
 * @备注:		用了二分查找，不过由于返回值不合意，所以要用两次。
 * @题目来源： https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1066
***********************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("sumsets.in");
ofstream fout("sumsets.out");

void solve1()
{
    while(true)
    {
        int size;
        fin >> size;
        if (size == 0)
        {
            break;
        }

        vector<int> a(size);
        for (int i = 0; i <= size - 1; ++i)
        {
            fin >> a[i];
        }

        int maxNum = -536870913;
        for (int i0 = 0; i0 <= size - 1; ++i0)
        {
            for (int i1 = 0; i1 <= size - 1; ++i1)
            {
                if (i1 == i0)
                {
                    continue;
                }
                for (int i2 = 0; i2 <= size - 1; ++i2)
                {
                    if (i2 == i0 || i2 == i1)
                    {
                        continue;
                    }
                    auto p = find(a.begin(), a.end(), a[i0] + a[i1] + a[i2]);
                    if (p != a.end())
                    {
                        int pos = p - a.begin();
                        if (pos != i0 && pos != i1 && pos != i2)
                        {
                            maxNum = max(maxNum, a[i0] + a[i1] + a[i2]);
                        }
                    }
                }
            }
        }

        if (maxNum == -536870913)
        {
            fout << "no solution\n";
        }
        else
        {
            fout << maxNum << '\n';
        }
    }
}

void solve2()
{
    struct nums
    {
        int sum;
        int a;
        int b;
        bool operator == (const nums & i) const  //用于查找
        {
            return sum == i.sum;
        }

        bool operator<=(const nums & i) const  //用于二分
        {
            return sum <= i.sum;
        }

        bool operator<(const nums & i) const  //用于排序
        {
            return sum < i.sum;
        }        

    };

    while(true)
    {
        int size;
        fin >> size;
        if (size == 0)
        {
            break;
        }

        vector<int> a(size);
        vector<nums> store;

        for (int i = 0; i <= size - 1; ++i)
        {
            fin >> a[i];
        }

        for (int i0 = 0; i0 <= size - 1; ++i0)
        {
            for (int i1 = 0; i1 <= size - 1; ++i1)
            {
                if (i1 == i0)
                {
                    continue;
                }
                nums temp{a[i0] + a[i1],i0,i1,};
                store.push_back(temp);
            }
        }

        sort(a.begin(), a.end());
        sort(store.begin(), store.end());

        bool found = false;
        for (int i0 = size - 1; i0 >= 0 && found == false; --i0)
        {
            for (int i1 = 0; i1 <= size - 1 && found == false; ++i1)
            {
                if (i1 == i0)
                {
                    continue;
                }
                nums temp{a[i0] - a[i1], 0, 0};
                
                if (binary_search(store.begin(), store.end(), temp) == true)
                {
                    auto p = lower_bound(store.begin(), store.end(), temp);
                    int pos = p - store.begin();
                    if (i0 != store[pos].a && i0 != store[pos].b && i1 != store[pos].a && i1 != store[pos].b)
                    {
                        fout << a[i0] << '\n';
                        found = true;
                    }
                }
            }
        }

        if (found == false)
        {
            fout << "no solution\n";
        }
    }
}

int main()
{
    solve2();

    return 0;
}
