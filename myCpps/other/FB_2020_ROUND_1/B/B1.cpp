#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;
const ill INF =LLONG_MAX;

class solution
{
  public:
    void solve(int caseId)
    {
        int N,M,K,S;
        cin >> N >>M>>K>>S;
        vector<int> P(N+1);
        vector<int> Q(M+1);

        vector<int> Ql(M+1,INF);
        vector<int> Qr(M+1,INF);

        for (int i = 1; i <= K; ++i)
        {
            cin >>P[i];
        }
        int Ap,Bp,Cp,Dp;
        cin >> Ap>>Bp>>Cp>>Dp;
        for (int i = K+1; i <= N; ++i)
        {
            P[i]=((Ap*P[i-2] + Bp*P[i-1]+Cp) % Dp) +1;
        }

        for (int i = 1; i <= K; ++i)
        {
            cin >>Q[i];
        }
        int Aq,Bq,Cq,Dq;
        cin >> Aq>>Bq>>Cq>>Dq;
       
        for (int i = K+1; i <= M; ++i)
        {
            Q[i]=((Aq*Q[i-2] + Bq*Q[i-1]+Cq) % Dq) +1;
        }

        sort(P.begin()+1,P.end());
        sort(Q.begin()+1,Q.end());

        for (int i = 1; i <= N ; ++i)
        {
            cout<< P[i] << " ";
        }
        cout<< "\n";
        for (int i = 1; i <= M ; ++i)
        {
            cout<< Q[i] << " ";
        }

        cout<< "\n";
        cout<< "\n";

        return;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("B1.in", "r", stdin);
    //freopen("B.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif
    int t;
    cin >> t;
    for (int i = 1; i <= t ; ++i)
    {
        solution sln1;
        sln1.solve(i);
    }
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms\n";
#endif

    return 0;
}