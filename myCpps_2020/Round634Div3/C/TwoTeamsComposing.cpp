#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
    int ttc; cin >> ttc;
    for (int ctc = 1; ctc <= ttc; ++ctc)
    {
            int n; cin >> n;
            map<int, int> cntS;
            set<int> typS;
        for (int i = 0; i <= n - 1; ++i)
        {
            int tmp; cin >> tmp;

            ++cntS[tmp];
            typS.insert(tmp);
        }

        int ans1 = typS.size(), ans2 = 0;
        for (auto ite = typS.begin(); ite != typS.end(); ++ite)
        {
            ans2 = max(ans2, cntS[*ite]);
        }

        cout << max(min(ans1, ans2 - 1), min(ans1 - 1, ans2)) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("TwoTeamsComposing.in", "r", stdin);
        freopen("TwoTeamsComposing.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}