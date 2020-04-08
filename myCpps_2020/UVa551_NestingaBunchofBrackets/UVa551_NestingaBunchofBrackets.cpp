/*
===========================================================
* @Name:           UVa-551 Nesting a Bunch of Brackets
* @Author:         Shawn
* @create Time:    2020/4/8 22:51:12
* @url:            
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int inf = INT_MAX / 2;

void solve()
{
    vector<int> isB(256, 0);
    isB[1] = 1; isB[2] = 1;
    isB['('] = 1; isB[')'] = 1;
    isB['{'] = 1; isB['}'] = 1;
    isB['['] = 1; isB[']'] = 1;
    isB['<'] = 1; isB['>'] = 1;

    string ins = "";
    while (getline(cin, ins))
    {
            bool flg = true;
            int sizI = ins.size(), ans = sizI, j = 0;
            stack<int> stk;
        for (int i = 0; i <= sizI - 1; ++i)
        {
            int typ = '-';
            if (i <= sizI - 2)
            {
                if      (ins[i] == '(' && ins[i + 1] == '*') typ = 1;
                else if (ins[i] == '*' && ins[i + 1] == ')') typ = 2;
            }
            if (typ == '-') typ = ins[i];

            if (isB[typ] == 0)
            {
                ++j;
                continue;
            }

            if      (typ == 1) stk.push(typ);
            else if (typ == '(') stk.push(typ);
            else if (typ == '[') stk.push(typ);
            else if (typ == '{') stk.push(typ);
            else if (typ == '<') stk.push(typ);
            else
            {
                int nowTop = '-';
                if (stk.empty() == false) nowTop = stk.top();

                if      (typ == 2)
                {
                    if (nowTop != 1)
                    {
                        flg = false;
                        ans = j;
                        break;
                    }
                    else stk.pop();
                }
                else if (typ == ')')
                {
                    if (nowTop != '(')
                    {
                        flg = false;
                        ans = j;
                        break;
                    }
                    else stk.pop();
                }
                else if (typ == ']')
                {
                    if (nowTop != '[')
                    {
                        flg = false;
                        ans = j;
                        break;
                    }
                    else stk.pop();
                }
                else if (typ == '}')
                {
                    if (nowTop != '{')
                    {
                        flg = false;
                        ans = j;
                        break;
                    }
                    else stk.pop();
                }
                else if (typ == '>')
                {
                    if (nowTop != '<')
                    {
                        flg = false;
                        ans = j;
                        break;
                    }
                    else stk.pop();
                }
            }

            if (typ == 1 || typ == 2)
            {
                ++i; --ans;
            }
            ++j;
        }
        
        if (stk.empty() == false || flg == false) cout << "NO " << ans + 1 << '\n';
        else                      cout << "YES\n";    
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("UVa551_NestingaBunchofBrackets.in", "r", stdin);
        freopen("UVa551_NestingaBunchofBrackets.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}