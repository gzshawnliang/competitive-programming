/*
===========================================================
 * @名称:		Dance Mooves
 * @作者:		Thomas 
 * @创建时间: 2021-02-14 21:01:49 
 * @修改人:   Shawn 
 * @修改时间: 2021-02-14 21:01:49 
 * @备注:	USACO 2021 January Contest, Gold Problem 3. Dance Mooves	
 * @题目来源： http://www.usaco.org/index.php?page=viewproblem2&cpid=1091&lang=en
===========================================================
*/

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
    vector<int> ans;                    //编号i的牛答案
    vector<int> vist;                   //编号i牛是否访问过,dfs使用
    vector<int> currPosCow;             //currPosCow[i]=j,编号i位置现在是编号j牛
    vector<int> currCowPos;             //currCowPos[i]=j,编号i牛现在是位置j
    vector<unordered_set<int>> vistPos; //编号i牛到过的地方

    vector<int> to;   //to[i]=j,编号i牛下个回合到编号j牛
    vector<int> from; //from[i]=j,编号i的牛来自(上回合)编号j牛

    vector<map<int, int>> cowStep; //cowStep[i]={k1,j1},{k2,j2} 编号i的牛在第k1步到达位置j1,k2步到达j2

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
        cowStep = vector<map<int, int>>(n + 1);

        //初始位置
        for (int i = 1; i <= n; ++i)
        {
            to[i] = i;
            from[i] = i;
            currPosCow[i] = i;
            currCowPos[i] = i;
            vistPos[i].insert(i);
            ans[i] = 1;
            cowStep[i].insert({0,i});
        }

        //模拟交换k次,一个回合，如果m<k则m次
        for (int i = 1; i <= min(k, m); ++i)
        {
            int a, b;
            cin >> a >> b;

            cowStep[currPosCow[a]].insert({i,b});
            cowStep[currPosCow[b]].insert({i,a});

            vistPos[currPosCow[a]].insert(b);
            vistPos[currPosCow[b]].insert(a);

            swap(currPosCow[a], currPosCow[b]);
            currCowPos[currPosCow[a]] = a;
            currCowPos[currPosCow[b]] = b;
        }

        if (m <= k)         //m<=k输出答案，最多1个回合,直接输出答案
        {
            for (int i = 1; i <= n; ++i)
                cout << vistPos[i].size() << "\n";
            return;
        }

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
                continue; //i已经在环中

            int size = cycle.size();
            //cerr << "cycle  size:" << size <<",";

            int roundCount = roundCnt; //牛交换的回合数==环中走的步数
            int R = remCnt;            //完成交换回合数之后，还需要交换remCnt次
            if (roundCount >= size)
            {
                //回合数大于环的长度
                roundCount = size;
                R = 0;
            }

            /*
             ******************************************************  
             * 模拟在环中走totalStep步，每个节点次走totalStep步
             ******************************************************  
            */

            int totalStep = roundCount - 1; //已经走了一步

            int posCnt = 0;
            vector<int> posPassCnt(n + 1); //posPassCnt[i]=j.编号i的位置访问了j次

            auto addCow = [&](int cowId, int len) {
                for (auto c : cowStep[cowId])
                {
                    if (c.first > len)
                        return;

                    if (posPassCnt[c.second] == 0) //增加位置c访问数量  posPassCnt.count(c)==0 ||
                        ++posCnt;

                    ++posPassCnt[c.second];
                }
            };

            auto removeCow = [&](int cowId, int len) {
                for (auto c : cowStep[cowId])
                {
                    if (c.first > len)
                        return;

                    if (posPassCnt[c.second] == 0)
                        continue;

                    if (posPassCnt[c.second] == 1)
                        --posCnt;
                    //posPassCnt.erase(c);

                    --posPassCnt[c.second]; //减少位置c访问数量
                }
            };

            int pBegin = 0; //双指针头部位置
            int pEnd = 0;   //双指针尾部位置

            //创建并滑动双指针
            for (int cyclePos = 0; cyclePos <= size - 1; ++cyclePos)
            {
                pBegin = cycle[cyclePos];

                if (cyclePos == 0) //在环中第0个节点创建双指针
                {
                    posCnt = vistPos[pBegin].size();
                    for (auto kk : vistPos[pBegin])
                        posPassCnt[kk] = 1;

                    pEnd = pBegin;
                    for (int step = 1; step <= totalStep; ++step) //创建长度是totalStep的双指针
                    {
                        int next = to[pEnd];
                        addCow(next, k);
                        pEnd = next;
                    }
                }
                else //滑动双指针
                {
                    removeCow(from[pBegin], k); //删除头指针
                    addCow(to[pEnd], k);        //加入尾指针
                    pEnd = to[pEnd];
                }

                //往前走R步，模拟交换剩余次数
                if (R > 0)
                    addCow(to[pEnd], R);

                ans[pBegin] = posCnt;      //记录当前答案

                //撤销前走R步，需要模拟下个节点
                if (R > 0)
                    removeCow(to[pEnd], R);
            }
        }

        for (int i = 1; i <= n; ++i)
            cout << ans[i] << "\n";
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