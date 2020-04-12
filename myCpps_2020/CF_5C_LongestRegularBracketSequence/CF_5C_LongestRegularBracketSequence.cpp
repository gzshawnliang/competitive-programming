#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
    string ins; cin >> ins;

        int siz = ins.size();
        vector<int> match(siz, -1);
    for (int i = 0; i <= siz - 1; ++i)
    {       
            stack<int> stk;
        for (int j = i; j <= siz - 1; ++j)
        {
            if (ins[j] == '(') stk.push(j);
            else if (ins[j] == ')')
            {
                if (stk.empty() == true)
                {
                    i = j;
                    break;
                }

                match[j] = stk.top();
                match[stk.top()] = j;

                stk.pop();
            }

            if (j == siz - 1)
            {
                i = j;
                break;
            }
        }
    }

    int nowL = 0, maxL = 0, maxLC = 1;
    for (int i = 0; i <= siz; ++i)
    {
        if (match[i] == -1 || i == siz)
        {
            if      (nowL > maxL)  {maxL = nowL; maxLC = 1;}
            else if (nowL == maxL) {++maxLC;}
            
            nowL = 0;
        }
        else
        {
            ++nowL;
        }
    }

    if (maxL == 0) maxLC = 1;
    cout << maxL << ' ' << maxLC << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_5C_LongestRegularBracketSequence.in", "r", stdin);
        freopen("CF_5C_LongestRegularBracketSequence.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}