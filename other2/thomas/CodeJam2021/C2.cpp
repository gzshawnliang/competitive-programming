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
    int T,N,C;
    vector<int> A;
    vector<int> B;
    void GetB(int total,int k,int left,int right)
    {
        if(total==C)
        {
            for (int i = 1; i <= N; ++i)
                cout << B[i] << " ";
        }
        else if(total==N-1)
        {
            for (int i = 1; i <= N; ++i)
                cout << A[i] << " ";            
        }
        else
        {
            int t1=B[k];
            vector<int> t;
            for (int i = left;i <= right; ++i)
            {
                t.push_back(B[i]);
            }
            
            int tt=k;
            for(auto i:t)
            {
                B[tt]=i;
                ++tt;
            }
            B[right]=t1;

            int t2=total-1;
            int l,r;
            int k2=k;
            if(left==right)
            {
                ++k2;
                l=left+1;
                r = B.size()-1;
            }
            else 
            {
                l=left;
                r=right-1;
            }

            GetB(t2,k2,l,r);

        }

    }

  public:
    void solve()
    {
        cin >> T;
        for(int t=1;t<=T;++t)
        {
            cin >> N>>C;
            vector<int> maxN(N+1);
            A=vector<int>(N+1);
            B=vector<int>(N+1);
            for (int i = 1; i <= N; ++i)
                A[i] = i;

            int i=1;
            int j=N;
            B[i]=2;
            B[j]=1;
            while (true)
            {
                ++i;
                --j;
                if(i==j)
                {
                    B[i]=B[i-1]+1;
                }
                else if(i+1<=j)
                {
                    B[i]=B[i-1]+2;
                    B[j]=B[j+1]+2;
                }
                else
                {
                    break;
                }
            }

            maxN[2]=2;
            for(int i=3;i<=N;++i)
                maxN[i]=maxN[i-1] +i;

            cout << "Case #"<< t <<": ";
            if(C>maxN[N] || C<(N-1))
            {
                cout <<"IMPOSSIBLE\n";
                continue;
            }
            else if(C==N-1)
            {
                for (int i = 1; i <= N; ++i)
                    cout << A[i] << " ";
            }
            else if(C==maxN[N])
            {
                for (int i = 1; i <= N; ++i)
                    cout << B[i] << " ";
            }
            else
            {
                int total=maxN[N];
                GetB(total,1,2,N);
            }
            cout << "\n";
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("C1.in", "r", stdin);
    freopen("C1.out", "w", stdout);
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