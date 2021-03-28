#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

class solution
{

    void printVec(vector<pair<int, int>> & A)
    {
        for (auto x : A)
        {
            cerr << x.second << " ";
        }
        cerr << "\n";
    }

  public:
    void solve()
    {
        int T;
        cin >> T;
        while (T--)
        {
            int N,Q;
            cin >> N >> Q;

            vector<pair<int, int>> A;
            queue<int> qu;
            for (int i = 1; i <= N; ++i)
            {
                qu.push(i);
            }

            pair<int, int> l = {1000, qu.front()};
            qu.pop();

            pair<int, int> m = {2000, qu.front()};
            qu.pop();

            pair<int, int> r = {3000, qu.front()};
            qu.pop();

            int result;
            // int time = 0;

            cout << l.second << " " << m.second << " " << r.second << "\n";

            cout.flush();
            cin >> result;

            if (result == l.second)
            {
                swap(l.second, m.second);
            }
            else if (result == r.second)
            {
                swap(r.second, m.second);
            }
            else
            {
            }

            A.push_back(l);
            A.push_back(m);
            A.push_back(r);
            int i = 0, j = 1;

            while (A.size() < N)
            {
                if (A.size() == N)
                    break;

                result = -1;
                int newNo = qu.front();
                qu.pop();
                while (true)
                {
                    pair<int, int> l2 = A[i];
                    pair<int, int> r2 = A[j];

                    cout << l2.second << " " << r2.second << " " << newNo << "\n";
                    cout.flush();
                    cin >> result;

                    if (result == l2.second && i == 0)
                    {
                        A.push_back({l2.first - 50, newNo});
                        i = 0;
                        j = 1;
                        sort(A.begin(), A.end());
                        break;
                    }
                    else if (result == l2.second && i > 0)
                    {
                        --i;
                        j = i + 1;
                    }
                    else if (result == newNo)
                    {
                        A.push_back({(l2.first + r2.first) / 2, newNo});
                        i = 0;
                        j = 1;
                        sort(A.begin(), A.end());
                        break;
                    }
                    else if (result == r2.second && j == A.size() - 1)
                    {
                        i = A.size() - 1;
                        j = i + 1;
                        A.push_back({r2.first + 50, newNo});
                        sort(A.begin(), A.end());
                        break;
                    }
                    else
                    {
                        ++i;
                        j = i + 1;
                    }
                }

                //printVec(A);
            }

            for (auto x : A)
            {
                cout << x.second << " ";
            }
        }
    }
};

signed main()
{

    // #ifdef LOCAL_DEBUG
    //     freopen("C3.in", "r", stdin);
    //     freopen("C3.out", "w", stdout);
    //     auto startTime = chrono::high_resolution_clock::now();
    // #endif

    solution sln1;
    sln1.solve();
    cout.flush();

    // #ifdef LOCAL_DEBUG
    //     cerr << "Execution time: "
    //          << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
    //          << " ms\n";
    // #endif

    return 0;
}