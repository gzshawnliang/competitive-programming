#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define fastIo  ios_base::sync_with_stdio(false);std::cin.tie(NULL); std::cout.tie(NULL);

using namespace std;
using ill = long long;
const double eps = 1e-10;

class solution
{

  public:

    void solve()
    {
        cout << fixed << setprecision(10);
        int n;
        cin >> n;
        assert(n > 0);

        vector<int> x(n);
        vector<int> v(n);
        for (int i = 0; i <= n - 1; ++i)
            cin >> x[i];

        for (int i = 0; i <= n - 1; ++i)
            cin >> v[i];

        //所有人到达y坐标时候的时间
        auto f = [&](double y) {
            double t = 0;
            for (int i = 0; i <= n - 1; ++i)
                t = max(t, abs(x[i] * 1.0 - y) / (v[i] * 1.0));

            return t;
        };

        //三分到达y的时间
        double right = 1e9 + 1;
        double left = 0;
        while (right - left > eps)
        {
            double midL = left * 1.0 + (right - left) / 3.0;
            double midR = right * 1.0 - (right - left) / 3.0;

            //如果是求最大值的话这里判>=即可
            //如果是求最小值的话这里判<=即可
            if (f(midL) <= f(midR))
                right = midR;
            else
                left = midL;
        }

        cout << f(left) << "\n";

        return;
    }
};

signed main()
{
    fastIo

#ifdef LOCAL_DEBUG
    freopen("2.in", "r", stdin);
    //freopen("2.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();

    cout.flush();

#ifdef LOCAL_DEBUG
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}