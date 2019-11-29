#include <bits/stdc++.h>

using namespace std;

ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

void dfs(int start, int curr, vector<int> & a, vector<int> & visited, vector<int> & excluded, unordered_set<int> & circle)
{
    if (visited[curr] == 1 || circle.count(curr) == 1)
    {
        for (auto i : excluded)
            visited[i] = 0;

        return;
    }
    else
    {
        visited[curr] = 1;
    }

    excluded.push_back(curr);
    if (start == curr)
    {
        //找到圆圈，excluded里面的内容就是圆圈里面的内容
        for (auto i : excluded)
            circle.insert(i);

        return;
    }
    else
    {
        //不是圆圈，继续找下一个
        int next = a[curr];
        dfs(start, next, a, visited, excluded, circle);
    }
}

int main()
{
    int N;
    fin >> N;

    vector<int> a(N + 1, 0);       //输入的数据，第i头牛移动到a[i]
    vector<int> visited(N + 1, 0); //全局走过的路
    vector<int> excluded;          //排除不需要走的节点
    unordered_set<int> circle;     //圆圈里面的节点

    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        fin >> a[i];
        if (i == a[i]) //自己指向自己的情况
            ++ans;
    }

    for (int i = 1; i <= N; ++i)
    {
        /*
            1.自己指向自己的情况不要再找
            2.圆圈里面的节点不要再找
        */
        if (i != a[i] && circle.count(i) == 0)
        {
            excluded.clear();

            //从i开始找圆圈
            dfs(i, a[i], a, visited, excluded, circle);
        }
    }
    ans += circle.size();
    fout << ans << "\n";
    return 0;
}
