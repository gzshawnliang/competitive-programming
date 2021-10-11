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
    const int N = 4;
    vector<vector<int>> a;
    vector<vector<int>> b;
    const vector<pair<int, int>> dxy = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    vector<pair<int, int>> bfs(pair<int, int> p0, pair<int, int> p1)
    {
        auto peq=[&](pair<int, int> pa, pair<int, int> pb)
        {
            return pa.first == pb.first && pa.second == pb.second;
        };

        vector<pair<int, int>> ans;
        if (peq(p1, p0)) return ans;

        vector<vector<pair<int, int>>> las(N, vector<pair<int, int>>(N, {-1, -1}));

        bool flg = true;
        queue<pair<int, int>> q; q.push(p0); las[p0.first][p0.second] = p0;
        while (!q.empty() && flg)
        {
            pair<int, int> topP = q.front(); q.pop();

            for (int p = 0; p <= 3; ++p)
            {
                pair<int, int> nowP = {topP.first + dxy[p].first, topP.second + dxy[p].second};

                if (nowP.first >= 0 && nowP.first <= 3 && nowP.second >= 0 && nowP.second <= 3)
                {
                    if (peq(las[nowP.first][nowP.second], {-1, -1}) && b[nowP.first][nowP.second] == 0)
                    {
                        q.push(nowP);
                        las[nowP.first][nowP.second] = topP;

                        if (peq(nowP, p1))
                        {
                            flg = false;
                            break;
                        }
                    }
                }
            }
        }

        pair<int, int> nowP = p1;
        while (true)
        {
            ans.push_back(nowP);
            nowP = las[nowP.first][nowP.second];
            if (peq(nowP, las[nowP.first][nowP.second]))
            {
                //ans.push_back(nowP);
                break;
            }
        }

        return ans;
    }

  public:
    void solve()
    {
        a = vector<vector<int>>(N, vector<int>(N, 0));
        b = vector<vector<int>>(N, vector<int>(N, 0));

        vector<pair<int, int>> pos(N * N);
        for (int y = 0; y <= N - 1; ++y)
        {
            for (int x = 0; x <= N - 1; ++x)
            {
                cin >> a[y][x];
                pos[a[y][x]] = {y, x};
            }
        }

        vector<pair<int, int>> ans;
        vector<pair<int, int>> endPos(N * N);
        for (int num = 1; num <= N * N - 1; ++num) endPos[num] = {(num - 1) / N, (num - 1) % N};

        auto touch=[&](pair<int, int> p1)
        {
            ans.push_back(p1);
            int tmpP1 = a[p1.first][p1.second];
            pair<int, int> pEmp = pos[0];

            pos[0] = p1;
            a[p1.first][p1.second] = 0;
            pos[tmpP1] = pEmp;
            a[pEmp.first][pEmp.second] = tmpP1;
        };

        auto moveEmpTo=[&](pair<int, int> p1)
        {
            vector<pair<int, int>> er = bfs(pos[0], p1);
            int sizT = er.size();
            for (int i = sizT - 1; i >= 0; --i) touch(er[i]);
        };

        auto move=[&](int num)
        {
            while (pos[num] != endPos[num])
            {
                vector<pair<int, int>> iniR = bfs(pos[num], endPos[num]);
                pair<int, int> nextEmpPos = iniR.back();

                b[pos[num].first][pos[num].second] = 1;
                moveEmpTo(nextEmpPos);
                b[pos[num].first][pos[num].second] = 0;

                touch(pos[num]);
            }
            b[pos[num].first][pos[num].second] = 1;
        };

        auto moveTmp=[&](int num, pair<int, int> endPosP1)
        {
            while (pos[num] != endPosP1)
            {
                vector<pair<int, int>> iniR = bfs(pos[num], endPosP1);
                pair<int, int> nextEmpPos = iniR.back();

                b[pos[num].first][pos[num].second] = 1;
                moveEmpTo(nextEmpPos);
                b[pos[num].first][pos[num].second] = 0;

                touch(pos[num]);
            }
        };

        auto peq=[&](pair<int, int> pa, pair<int, int> pb)
        {
            return pa.first == pb.first && pa.second == pb.second;
        };

        for (int num = 1; num <= 3; ++num) move(num);
        moveEmpTo({1, 0});
        for (int x = 0; x <= 2; ++x)
        {
            b[0][x] = 0;
            touch({0, x});
        }
        b[1][0] = 1; b[0][0] = 1; b[0][1] = 1;
        move(4);

        moveEmpTo({1, 2});
        touch({0, 2}); touch({0, 1}); touch({0, 0}); touch({1, 0});

        b[1][0] = 0; b[0][0] = 0; b[0][1] = 0;
        for (int x = 0; x <= 3; ++x) b[0][x] = 1;

        //------------------------------------------------------------------------

        for (int num = 5; num <= 7; ++num) move(num);
        moveEmpTo({2, 0});
        for (int x = 0; x <= 2; ++x)
        {
            b[1][x] = 0;
            touch({1, x});
        }
        b[2][0] = 1; b[1][0] = 1; b[1][1] = 1;

        if (peq(pos[8], {3, 0}) || (peq(pos[8], {3, 1}) && peq(pos[0], {3, 0})))
        {
            b[2][0] = 0;
            moveTmp(8, {1, 2}); b[pos[8].first][pos[8].second] = 1;
            moveTmp(5, {2, 0}); b[pos[5].first][pos[5].second] = 1;
            moveEmpTo({1, 3});

            for (int num = 8; num >= 5; --num) touch(pos[num]);
            b[1][2] = 1; b[1][3] = 1; b[2][0] = 0;
        }
        else
        {
            move(8);
            moveEmpTo({2, 2});
            touch({1, 2}); touch({1, 1}); touch({1, 0}); touch({2, 0});

            b[2][0] = 0; b[1][0] = 0; b[1][1] = 0;
            for (int x = 0; x <= 3; ++x) b[1][x] = 1;
        }

        moveEmpTo({3, 3});

        move(9);
        if (peq(pos[10], {3, 0}) || (peq(pos[10], {3, 1}) && peq(pos[0], {3, 0})))
        {
            b[2][0] = 0;
            moveTmp(10, {2, 2}); b[pos[10].first][pos[10].second] = 1;
            moveTmp(9, {2, 0}); b[pos[9].first][pos[9].second] = 1;
            moveEmpTo({2, 1});
            touch(pos[10]); b[2][2] = 0; b[2][1] = 1;
        }
        else
        {
            move(10);
        }
        
        moveEmpTo({3, 0});
        b[2][0] = 0; b[2][1] = 0;
        touch({2, 0}); touch({2, 1});
        b[3][0] = 1; b[2][0] = 1;
        moveTmp(11, {2, 1});
        b[2][1] = 1;

        moveEmpTo({3, 1});

        b[3][0] = 0; b[2][0] = 0; b[2][1] = 0;
        touch(pos[9]); touch(pos[10]); touch(pos[11]);
        b[3][1] = 1; b[3][0] = 1; b[2][0] = 1;

        if (peq(pos[12], {2, 2}))
        {
            touch(pos[11]); touch(pos[10]); touch(pos[9]);
        }
        else
        {
            moveTmp(12, {2, 3});


            moveEmpTo({2, 1});
            touch(pos[11]); touch(pos[10]); touch(pos[9]);
            touch({3, 2}); touch({2, 2}); touch(pos[12]);
        }

        b[3][1] = 0; b[3][0] = 0; b[2][0] = 0;
        b[3][0] = 1; for (int x = 0; x <= 2; ++x) b[2][x] = 1;

        moveEmpTo({3, 1});
        for (int num = 9; num <= 12; ++num) touch(pos[num]);

        vector<pair<int, int>> loopPos = {{3, 2}, {3, 3}, {2, 3}, {2, 2}};
        for (int li = 0; true; li = (li + 1) % 4)
        {
            if (peq(pos[13], {3, 2}) && peq(pos[14], {3, 3}) && peq(pos[15], {2, 3})) break;
            touch(loopPos[li]);
        }

        for (int c = 1; c <= 2; ++c)
        {
            for (int num = 12; num >= 9; --num) touch(pos[num]);
            for (int num = 13; num <= 15; ++num) touch(pos[num]);
        }

        for (auto p:ans) cout << p.first << ' ' << p.second << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    //freopen("Klotski.in", "r", stdin);
    //freopen("Klotski.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}