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
  public:
    void solve(int caseId)
    {
        int N,K,W;
        cin >> N >> K >> W;
        
        vector<int> L(N+1),H(N+1);
        for (int i = 1; i <= K ; ++i)
            cin >> L[i];
        
        int Al,Bl,Cl,Dl;
        int Ah,Bh,Ch,Dh;
        cin >> Al >> Bl >> Cl >> Dl;

        for (int i = 1; i <= K ; ++i)
            cin >> H[i];

        cin >> Ah >> Bh >> Ch >> Dh;

        for (int i = K+1; i <= N ; ++i)
        {
            L[i] = (Al*L[i-2] + Bl*L[i-2]+Cl) % Dl +1;
            H[i] = (Ah*H[i-2] + Bh*H[i-2]+Ch) % Dh +1;
        }

        for (int i = 1; i <= N ; ++i)
            cout << "(" << L[i] << ",0) ";
        cout << "\n";
        for (int i = 1; i <= N ; ++i)
            cout  << "(" <<  L[i] +W << "," << H[i] << ") ";

        cout << "\n";
        cout << "\n";

    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("A1.in", "r", stdin);
    //freopen("A1.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    int t;
    cin>>t;
    solution sln1;
    for (int i = 1; i <= t ; ++i)
    {
        sln1.solve(t);
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