#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr)

using namespace std;

using ill = long long;

class solution
{
    vector<int> ans;                        //编号i的牛占据的不同的位置数量(答案)
    vector<int> vist;                       //编号i牛是否访问过,dfs使用
    vector<int> currPosCow;                 //currPosCow[i]=j,编号i位置现在是编号j牛
    vector<int> currCowPos;                 //currCowPos[i]=j,编号i牛现在是位置j
    vector<unordered_set<int>> vistPos;     //编号i牛到过的地方

    vector<int> to;                         //to[i]=j,编号i牛下个回合到编号j牛
    vector<int> from;                       //from[i]=j,编号i的牛来自(上回合)编号j牛

    vector<vector<pair<int, int>>> cowStep; //cowStep[i]={j1,k1},{j2,k2} 编号i的牛在第k1步到达位置j1,k2步到达j2

    void dfs(int i, vector<int> & cycle)
    {
        if (vist[i] == 1)
            return;

        vist[i] = 1;
        cycle.push_back(i);
        dfs(to[i], cycle);
    }

  public:
    void solve()
    {
        ill n, k, m;
        cin >> n >> k >> m;
        
        to = vector<int>(n + 1);
        from = vector<int>(n + 1);
        vist = vector<int>(n + 1);
        ans = vector<int>(n + 1);
        currPosCow = vector<int>(n + 1);
        currCowPos = vector<int>(n + 1);
        vistPos = vector<unordered_set<int>>(n + 1);
        cowStep = vector<vector<pair<int, int>>>(n + 1);

        auto swapPos = [&](int a, int b) {
            vistPos[currPosCow[a]].insert(b);
            vistPos[currPosCow[b]].insert(a);
            swap(currPosCow[a], currPosCow[b]);
            currCowPos[currPosCow[a]] = a;
            currCowPos[currPosCow[b]] = b;
        };

        //初始位置
        for (int i = 1; i <= n; ++i)
        {
            to[i] = i;
            from[i] = i;
            currPosCow[i] = i;
            currCowPos[i] = i;
            vistPos[i].insert(i);
            ans[i] = 1;
            // visitedAll[i][i]=1;

            cowStep[i].push_back({i, 0});
        }

        //模拟交换k次,一个回合，如果m<k则m次
        for (int i = 1; i <= min(k, m); ++i)
        {
            int a, b;
            cin >> a >> b;

            cowStep[currPosCow[a]].push_back({b, i});
            cowStep[currPosCow[b]].push_back({a, i});

            swapPos(a, b);
        }

        if (m <= k) //m<=k输出答案，不够一个回合
        {
            for (int i = 1; i <= n; ++i)
                cout << vistPos[i].size() << "\n";
        }
        else
        {
            //建图
            for (int i = 1; i <= n; ++i)
            {
                to[currPosCow[i]] = i;
                from[i] = currPosCow[i];
            }

            ill roundCnt = m / k;          //牛交换的回合数==环中走的步数
            ill remCnt = m - roundCnt * k; //完成交换回合数之后，还需要交换remCnt次
            if (m == (ill)1e18)
                remCnt = 0;

            //在图中找环
            for (int i = 1; i <= n; ++i)
            {
                //auto startTime = chrono::high_resolution_clock::now();
                vector<int> cycle; //环的集合
                if (vist[i] == 0)
                    dfs(i, cycle);
                else
                    continue;

                int size = cycle.size();
                int roundCount = roundCnt; //牛交换的回合数==环中走的步数
                int R = remCnt;            //完成交换回合数之后，还需要交换remCnt次
                if (roundCount >= size)
                {
                    //回合数大于环的长度
                    roundCount = size;
                    R = 0;
                }

                //模拟在环中走roundCnt步，每个节点次走roundCnt步
                int totalStep = roundCount - 1; //已经走了一步

                int posCnt = 0;
                vector<int> posPassCount(n + 1); //posPassCount[i]=j.编号i的位置访问了j次

                auto addCow = [&](int cowId, int len) {
                    for (auto c : cowStep[cowId])
                    {
                        if (c.second > len)
                            return;

                        if (posPassCount[c.first] == 0) //增加位置c访问数量  posPassCount.count(c)==0 ||
                            ++posCnt;

                        ++posPassCount[c.first];
                    }
                };

                auto removeCow = [&](int cowId, int len) {
                    for (auto c : cowStep[cowId])
                    {
                        if (c.second > len)
                            return;

                        if (posPassCount[c.first] == 0)
                            continue;

                        if (posPassCount[c.first] == 1)
                            --posCnt;
                        //posPassCount.erase(c);

                        --posPassCount[c.first]; //减少位置c访问数量
                    }
                };

                int last = 0;

                //循环圈
                for (int cyclePos = 0; cyclePos <= size - 1; ++cyclePos)
                {

                    int curr = cycle[cyclePos];

                    if (cyclePos == 0)
                    {
                        posCnt = vistPos[curr].size();
                        for (auto kk : vistPos[curr])
                            posPassCount[kk] = 1;

                        int step = 1;
                        int j = curr;
                        while (step <= totalStep)
                        {
                            int next = to[j];
                            addCow(next, k);
                            j = next;
                            ++step;
                        }
                        last = j;
                    }
                    else
                    {
                        removeCow(from[curr], k);
                        addCow(to[last], k);
                        last = to[last];
                    }

                    //往前走R步，模拟交换剩余次数
                    if (remCnt > 0)
                        addCow(to[last], R);

                    ans[curr] = posCnt;

                    if (R > 0)
                        removeCow(to[last], R);
                }
            }

            //输出答案
            for (int i = 1; i <= n; ++i)
                cout << ans[i] << "\n";
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("DanceMooves.in", "r", stdin);
    freopen("DanceMooves.out", "w", stdout);
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

    return 0;
}