#include <bits/stdc++.h>

using namespace std;

ifstream fin("measurement.in");
ofstream fout("measurement.out");

struct measurement
{
    int day;
    int id;
    int change;
};

/*检查两个set是否一样 */
bool isEqual(const set<int> & set1, const set<int> & set2)
{
    if (set1.size() != set2.size())
        return false;

    auto it1 = set1.begin();
    auto it2 = set2.begin();
    while (it1 != set1.end())
    {
        if ((*it1) != (*it2))
            return false;

        ++it1;
        ++it2;
    }
    
    return true;
}

int main()
{
    int N, G;
    fin >> N >> G;
    vector<measurement> a(N);           //产量日志

    for (int i = 0; i <= N - 1; ++i)
    {
        fin >> a[i].day >> a[i].id >> a[i].change;
    }

    //产量日志按时间排序（天）
    sort(a.begin(), a.end(), [](const measurement & x, const measurement & y) {
        return x.day < y.day;
    });

    map<int, int> cowMp;                       //cowMp[i]=j,第i头牛的当前产量是j
    map<int, set<int>, greater<int>> milkMp;   //milkMp[i]={1,2,3},产量是i的牛有{1,2,3}

    int ans = 0;

    for (int i = 0; i <= N - 1; ++i)
    {
        int id = a[i].id;           //当前牛id
        int milkBefore = 0;         //计算当前日志，改变之前产量

        set<int> topSetBefore;      //改变之前最高产量的牛id的集合
        set<int> topSetAfter;       //改变之后最高产量的牛id的集合

        if (!milkMp.empty())
            topSetBefore = milkMp.begin()->second;

        if (cowMp.count(id) == 0)
        {
            cowMp[id] = G + a[i].change;
        }
        else
        {
            milkBefore = cowMp[id];
            cowMp[id] += a[i].change;
        }

        int milkAfter = cowMp[id];          //计算当前日志，改变之后的产量
        milkMp[milkAfter].insert(id);       //插入产量是milkAfter的牛id

        if (milkMp.count(milkBefore))       //删除产量是milkBefore的牛id
        {
            if (milkMp[milkBefore].count(id) == 1)
                milkMp[milkBefore].erase(id);

            if (milkMp[milkBefore].empty())  //产量是milkBefore的牛没有，则删除这项
            {
                milkMp.erase(milkBefore);
            }
        }

        topSetAfter = milkMp.begin()->second;

        if (isEqual(topSetBefore, topSetAfter) == false)    //改变之前和改变之后最高产量的牛id集合比较
        {
            ++ans;
        }
    }
    fout << ans << "\n";

    return 0;
}
