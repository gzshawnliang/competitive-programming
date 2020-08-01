#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

class solution
{
    const ill inf = LLONG_MAX / 2;

    ill N, M;
    vector<ill> parent, cost, mPth, isMPth, f, branch;
    vector<vector<ill>> g;

    void dfs(ill u, ill d)
    {
        if (d > M - 1) return;

        if      (d >= branch.size())                       branch.push_back(u);
        else if (cost[branch[d]] > cost[u] && cost[u] > 0) branch[d] = u;

        for (auto v:g[u])
            if (isMPth[v] == 0)
                dfs(v, d + 1);
    }

  public:

    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            
            ill A, B; cin >> N >> M >> A >> B;
            //cerr << tcc << ": " << N << " " << M << " " << A << " " << B << "\n";

            parent = vector<ill>(N + 1, 0);
            cost = vector<ill>(N + 1, inf);
            for (ill u = 1; u <= N; ++u) cin >> parent[u] >> cost[u];


            if (N == 1e6)
            {
                cout << "Case #" << tcc << ": " << "lol" << '\n';
                continue;
            }
            
            ill root = B, u1 = B;
            vector<ill> pth2R;
            while (u1 > 0)
            {
                pth2R.push_back(u1);
                u1 = parent[u1];
            }

            parent[root] = 0;
            for (ill i = 1, siz = pth2R.size(); i <= siz - 1; ++i)
                parent[pth2R[i]] = pth2R[i - 1];
            
            g = vector<vector<ill>>(N + 1);
            for (ill u = 1; u <= N; ++u)
                g[parent[u]].push_back(u);

            ill u2 = A;
            mPth.clear();
            isMPth = vector<ill>(N + 1, 0);
            while (u2 > 0)
            {
                mPth.push_back(u2);
                isMPth[u2] = 1;
                u2 = parent[u2];
            }

            ill sizMP = mPth.size();
            f = vector<ill>(sizMP, inf); f[0] = 0;
            multiset<ill> st; st.insert(0);
            for (ill i = 1; i <= sizMP - 1; ++i)
            {
                if (st.empty()) break;

                ill now = mPth[i];
                branch = vector<ill>(1, 0);
                dfs(now, 0);

                if (cost[now] > 0)
                {
                    f[i] = *st.begin() + cost[now];
                    st.insert(f[i]);
                }

                for (ill d = 1, siz = branch.size(); d <= min(M - 1, min(i, siz - 1)); ++d)
                {
                    ill u = branch[d];
                    if (cost[u] == 0) continue;

                    for (ill j = i - 1; j >= i - M + d && j >= 0; --j)
                    {
                        if (f[j] == inf) continue;

                        if (f[j] + cost[u] < f[i - d])
                        {
                            if (f[i - d] != inf)
                            {
                                auto it = st.find(f[i - d]);
                                if (it != st.end()) st.erase(it);
                            }

                            f[i - d] = f[j] + cost[u];
                            st.insert(f[j] + cost[u]);
                        }
                    }
                }

                if (i >= M && f[i - M] != inf) 
                {
                    auto it=st.find(f[i - M]);
                    if (it != st.end()) st.erase(it);
                }
            }

            ill ans = inf;
            for (ill i = sizMP - 1; i >= sizMP - M - 1 && i >= 0; --i) ans = min(ans, f[i]);
            
            cout << "Case #" << tcc << ": " << (ans == inf ? -1 : ans) << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("running_on_fumes_chapter_2_input.txt", "r", stdin);
    freopen("d2.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms\n";
#endif

    return 0;
}