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
  public:
    void solve()
    {
        int T;
        cin >> T;
        for(int t=1;t<=T;++t)
        {
            int N,C;
            cin >> N>>C;
            vector<int> maxN(N+1);
            vector<int> A(N+1);
            for (int i = 1; i <= N; ++i)
                A[i] = i;

            maxN[2]=2;
            for(int i=3;i<=N;++i)
                maxN[i]=maxN[i-1] +i;

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
                int i=1;
                int j=N;
                A[i]=2;
                A[j]=1;
                while (true)
                {
                    ++i;
                    --j;
                    if(i==j)
                    {
                        A[i]=A[i-1]+1;
                        //A[j]=A[j+1]+1;
                    }
                    else if(i+1<=j)
                    {
                        A[i]=A[i-1]+2;
                        A[j]=A[j+1]+2;
                    }
                    else
                    {
                        break;
                    }
                }

                for (int i = 1; i <= N; ++i)
                    cout << A[i] << " ";
            }
                        
            
            else if(C>(N-1) && C <2*(N-1))
            {
                int total=C-(N-1);
                int curr=N;
                while (total--)
                {
                    swap(A[curr],A[curr-1]);
                    --curr;
                }

                for (int i = 1; i <= N; ++i)
                    cout << A[i] << " ";
            }
            else if(C==2*(N-1))
            {
                for (int i = N; i >= 1; --i)
                    cout << A[i] << " ";
            }
            else if(C>2*(N-1))
            {
                reverse(A.begin()+1,A.end());

                int total=C-2*(N-1)+1;
                int curr=1;
                while (total--)
                {
                    swap(A[curr],A[curr+1]);
                    ++curr;
                    if(curr==N-1)
                        break;
                }

                for (int i = 1; i <=N; ++i)
                    cout << A[i] << " ";
            }

        }
        return;
        
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