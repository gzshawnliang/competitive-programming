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

  public:
    void solve()
    {
        int T;
        cin >> T;

        int N,Q;
        cin >> N >> Q;        
        int tcc=1;
        while (T--)
        {
            list<int> A;
            queue<int> qu;
            for (int i = 1; i <= N; ++i)
            {
                qu.push(i);
            }

            int l= qu.front();
            qu.pop();

            int m = qu.front();
            qu.pop();

            int r = qu.front();
            qu.pop();

            int result;
            // int time = 0;

            cout << l << " " << m << " " << r << "\n";

            cout.flush();
            cin >> result;

            if (result == l)
            {
                swap(l, m);
            }
            else if (result == r)
            {
                swap(r, m);
            }
            else
            {
            }

            A.push_back(l);
            A.push_back(m);
            A.push_back(r);

            auto i = A.begin();
            auto j = A.begin();
            ++j;

            while (A.size() < N)
            {
                if (A.size() == N)
                    break;

                result = -1;
                int newNo = qu.front();
                qu.pop();
                while (true)
                {
                    int l2 = *i;
                    int r2 = *j;

                    cout << l2 << " " << r2 << " " << newNo << "\n";
                    cout.flush();
                    cin >> result;

                    if (result == l2 && i == A.begin())
                    {
                        A.push_front(newNo);
                        i = A.begin();
                        j = A.begin();
                        ++j;
                        break;
                    }
                    else if (result == l2 && i != A.begin())
                    {
                        --i;
                        --j;
                    }
                    else if (result == newNo)
                    {
                        A.insert(j,newNo);
                        i = A.begin();
                        j = A.begin();
                        ++j;
                        break;
                    }
                    else if (result == r2 && j == (--A.end()))
                    {
                        A.push_back(newNo);
                        i = (--(--A.end()));
                        j = (--A.end());                        
                        break;
                    }
                    else
                    {
                        ++i;
                        ++j;
                    }
                }
            }
            //cout << "Case #" << tcc << ": ";
            for (auto x : A)
            {
                cout << x << " ";
            }
            cout<<"\n";
            cout.flush();
            ++tcc;
            int judgeError;
            cin >> judgeError;

            if(judgeError==1)            
                continue;
            else 
                return;
        }
    }
};

signed main()
{

    solution sln1;
    sln1.solve();
    
    return 0;
}