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

    int q(int l,int r,int m)
    {
        int res;
        cout << l << " " << r << " " << m << "\n";
        cout.flush();
        cin >> res;
        return res;
    }

  public:
    void solve()
    {
        int T;
        cin >> T;

        int N,Q;
        cin >> N >> Q;        
        while (T--)
        {
            vector<int> A;
            queue<int> qu;
            for (int i = 1; i <= N; ++i)
                qu.push(i);


            int l= qu.front();
            qu.pop();

            int m = qu.front();
            qu.pop();

            int r = qu.front();
            qu.pop();

            int result = q(l, r, m);

            if (result == l)
            {
                swap(l, m);
            }
            else if (result == r)
            {
                swap(r, m);
            }

            A.push_back(l);
            A.push_back(m);
            A.push_back(r);

            int i = 0;
            int j = 1;
            m = 0;

            while (A.size() < N)
            {
                if (A.size() == N)
                    break;

                result = -1;
                int newNo = qu.front();
                qu.pop();

                while (true)
                {
                    int left = A[i];
                    int mid = A[m];
                    int right = A[j];
                    
                    if(j - i == 1)
                        result = q(left, right, newNo);
                    else 
                        result = q(left, mid, newNo);

                    if (result == -1)
                    {
                        //judge error,may be queried too many times.
                        return;
                    }
                    else if (j - i > 1)
                    {
                        if(result == newNo)     //左端
                        {
                            j=m;
                            m=(i+j)/2;
                            // if(j-i==1)
                            // {
                            //     A.insert(A.begin()+j,newNo);
                            //     break;
                            // }                            
                        }
                        else if(result == mid)    //右端
                        {
                            i=m;
                            m=(i+j)/2;
                        }
                        continue;
                    }
                    else if (result == newNo)
                    {
                        A.insert(A.begin()+j,newNo);
                        i = 0;
                        j =1;
                        m = 0;
                        break;
                    }                    
                    else if (result == left && i == 0)
                    {
                        
                        //A.push_front(newNo);
                        A.insert(A.begin(),newNo);
                        i = 0;
                        j =1;
                        m = 0;
                        break;
                    }
                    else if (result == left && i > 0)
                    {
                        --j;
                        i = 0;
                        m=(i+j)/2;
                        continue;
                        //改为二分查找
                    }
                    else if (result == right && j == A.size()-1)
                    {
                        A.push_back(newNo);
                        j = A.size()-1;                        
                        i = j-1;
                        m=i; 
                        break;
                    }
                    else if (result == right && j < A.size()-1)
                    {
                        ++i;
                        j=A.size()-1;
                        m=(i+j)/2;
                        continue;
                    }
                }
            }
            //cout << "Case #" << tcc << ": ";
            for (auto x : A)
                cout << x << " ";

            cout<<"\n";
            cout.flush();
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