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

using ull = unsigned long long;

class solution
{
    vector<ull> a;

    void genData()
    {
        for (int i = 1; i <= 998; ++i)
        {
            int j = i;
            ++j;
            string s = to_string(i) + to_string(j);
            while (s.length() <= 7)
            {

                a.push_back(stoll(s));
                ++j;
                s += to_string(j);
            }
        }

        sort(a.begin(), a.end());
        
        // clog << "total:" << a.size() << "\n";
        // for (int i = 0, len = a.size(); i <= len - 1; ++i)
        // {
        //     clog << a[i] << "\n";
        // }

        return;
    }

    ull f(ull x,int n)
    {
        string s=to_string(x);
        
        while (1)
        {
            ++x;
            string s1 =s + to_string(x);
            if((int)s1.length() <= n)
                s=s1;
            else 
                break;
        }
        return stoll(s);
    }

    ull fn(ull x,int n)
    {
        if(n<=1)
            return 0;

        string s=to_string(x);
        
        for (int i = 1; i <= n-1; ++i)
        {
           s += to_string(x+i);
        }

        return stoll(s);
    }

  public:
    void test()
    {
        clog << fn(998,5) << "\n";
    }
    void solve_Set2()
    {
        //clog << f(9,19) << "\n";

        int T;
        cin >> T;
        for (int t = 1; t <= T; ++t)
        {
            //clog << t << endl;
            ull ans = 0;
            ull Y;
            cin >> Y;
            
            string s=to_string(Y);
            int lenY=s.length();
            set<ull> ret;
            if(lenY %2==0)
                ret.insert(f(1,lenY+1));
            else if(lenY<=18)
            {
                int zCount=lenY/2;
                ull minY2=1;
                for (int i = 1; i <= zCount; ++i)
                {
                    minY2 *=10;
                }
                ret.insert(f(minY2,lenY+1));
            }

            for (int i = 1; i <=lenY/2 ; ++i)
            {
                // if(lenY % i !=0)
                //     continue;

                ull min_Y=  stoll(s.substr(0,i));
                ull ret1=f(min_Y,lenY);
                // if(to_string(ret1).length() <lenY)
                //     continue;

                if(ret1>Y)
                    ret.insert(ret1);

                int min_Y2=min_Y;    
                while (to_string(min_Y2).length()==to_string(min_Y).length())
                {
                     ++min_Y2;
                    ull ret2=f(min_Y2,lenY);
                    // if(to_string(ret2).length() <lenY)
                    //     continue;

                    if(ret2>Y)
                    {
                        ret.insert(ret2);  
                        break;
                    }
                }
             
            }

            if(ret.size()>0)
                ans=*ret.begin();
            
            
            cout << "Case #" << t << ": " << ans << "\n";
        }

    }
    void solve_Set1()
    {
        genData();

        int t;
        cin >> t;
        for (int i = 1; i <= t; ++i)
        {
            int Y;
            cin >> Y;
            auto ret = lower_bound(a.begin(), a.end(), Y);
            while ((*ret) == (ull)Y)
                ++ret;

            cout << "Case #" << i << ": " << *ret << "\n";
        }
        return;
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("B3_AC_Set1.in", "r", stdin);
    freopen("B3_AC_Set1.out", "w", stdout);
    //auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve_Set1();
    cout.flush();

#ifdef LOCAL_DEBUG
    // cerr << "Execution time: "
    //      << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
    //      << " ms\n";
#endif

    return 0;
}