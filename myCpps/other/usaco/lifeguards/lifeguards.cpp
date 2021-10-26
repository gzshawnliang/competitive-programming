#include <bits/stdc++.h>
using namespace std;

ifstream fin("lifeguards.in");
ofstream fout("lifeguards.out");

struct lifeguard
{
    int l;
    int r;
};

int main()
{
    int N;
    fin >> N;
    vector<lifeguard> a(N + 1);

    for (int i = 0; i <= N - 1; ++i)
    {
        fin >> a[i].l >> a[i].r;
    }

    //按照左端点排序
    sort(a.begin(), a.end() - 1, [](lifeguard a, lifeguard b) {
        return a.l < b.l;
    });

    int total = 0;

    //不断的合并线段
    lifeguard merged = a.front(); //第一个线段
    for (int i = 1; i <= N - 1; ++i)
    {
        if (merged.r >= a[i].l)
        {
            merged.r = max(a[i].r, merged.r); //最左边不变，合并最右边
        }
        else
        {
            total += (merged.r - merged.l); //不能合并，累加计算线段长度
            merged = a[i];                  //开始新的线段
        }
    }
    total += (merged.r - merged.l); //加上最后一根线段长度

    int preMaxRight = 0;   //上一个线段的最右边
    int minTime = INT_MAX; //有效时间最小值

    //最后多加一条线防止溢出
    a[N].l = a[N - 1].r;

    //重新初始化并建立一个边界
    for (int i = 0; i <= N - 1; ++i)
    {
        lifeguard curr = a[i];
        lifeguard next = a[i + 1];

        if (curr.r <= preMaxRight)
        {
            minTime = 0; //完全被覆盖的情况，最小值是0,已经最小不用找了
        }
        else
        {
            int l = max(curr.l, preMaxRight); //取最右边
            int r = min(next.l, curr.r);      //取最左边

            minTime = min(minTime, r - l); //记录最小一段

            preMaxRight = max(curr.r, preMaxRight); //更新线段最右边，下次使用
        }

        if (minTime == 0) //完全被覆盖的情况，最小值是0，已经最小不用找了
            break;
    }

    fout << total - minTime << "\n";
    return 0;
}
