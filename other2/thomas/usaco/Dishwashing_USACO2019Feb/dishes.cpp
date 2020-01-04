#include <bits/stdc++.h>

using namespace std;

using ll = long long;


class solution
{
    public:
    int N;
    vector<int> a;
    vector<stack<int>> counter;
    vector<int> buttom;

    void solve()
    {
        cin >> N;
        a.assign(N + 1, 0);
        buttom.assign(N + 1, 0);
        counter.assign(N+1,stack<int>());

        for (int i = 1; i <= N ; ++i)
        {
            cin >> a[i];
        }
        
        //移动到counter
        buttom[1] = a[1];
        counter[1].push(a[1]);
        int ans=0;
        int lastPop=0;
        
        for (int i = 2; i <= N ; ++i)
        {
            int j = 1;
            //查找小于buttom[j]的，没有则新建一个
            while (a[i] > buttom[j])
            {
                if(buttom[j]>0)
                {
                    ++j;
                }
                else if(buttom[j]==0)
                {
                    buttom[j]=a[i];
                    break;
                }
            }

            if(counter[j].empty())
            {
                counter[j].push(a[i]);
            }
            else if(a[i] < counter[j].top() && a[i] > lastPop)
            {
                counter[j].push(a[i]);
            }
            else if(a[i] > lastPop)
            {
                lastPop= counter[j].top();
                if (j > 1)
                {
                    for (int k = 1; k <= j-1; ++k)
                    {
                        while(!counter[k].empty())
                        {
                            counter[k].pop();
                            ++ans;
                        }
                        buttom[k]=0;
                    }
                }

                //j=1;
                counter[j].pop();
                counter[j].push(a[i]);
                ++ans;
            }
            
        }

        for (int i = 1; i <= N; ++i)
        {
            while(!counter[i].empty())
            {
                counter[i].pop();
                ++ans;
            }
        }

        cout << ans ;
        //assert(1==2);
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("dishes.in", "r", stdin);
        freopen("dishes.out", "w", stdout);
    #endif    
    solution sol1;
    sol1.solve();


    cout.flush();
    return 0;
}