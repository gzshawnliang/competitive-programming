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

    void solve()
    {
        tuple<int,int,int>  a(1,2,3);
        a={2,3,4};

        cout << "size:" << tuple_size<decltype(a)>::value << '\n';
        
        cout << "index 0:" << std::get<0>(a) <<'\n';
        cout << "index 1:" << get<1>(a) <<'\n';
        cout << "index 2:" << get<2>(a) <<'\n';

        int first;
        int second;
        tie(first, second, std::ignore) = a;


        //Structured Bindings
        auto [x,y,z]=a;
        cout << "x :" << x <<'\n';
        cout << "y :" << y <<'\n';
        cout << "z :" << z <<'\n'; 

    

        vector<tuple<int,int,int>> t;
        t.push_back({10,11,12});
        t.push_back({7,8,9});
        t.push_back({4,5,6});
        t.push_back({1,2,3});
        t.push_back({10,11,12});

        sort(t.begin(),t.end());


        set<tuple<int,int,int>> s;
        s.insert({10,11,12});
        s.insert({7,8,9});
        s.insert({4,5,6});
        s.insert({1,2,3});
        s.insert({10,11,12});

        map<tuple<int,int,int>,int> m;
        m[{1,2,3}]=4;
        m[{1,2,3}]=5;
        m[{3,2,3}]=6;
        m[{1,3,3}]=4;

        //Structured binding
        for(auto[x,y]:m)
        {
            auto [a,b,c]=x;
            cout << a << " " << b << " " << c << " " << y << '\n';
        }

       
        int i=10;
        --i;

        for (int __s = 0; __s == 0; ++__s);

        
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}
