#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

using namespace std;

using ill = long long;

const int INF = INT_MAX / 2;

class solution_set1
{
    class node
    {
      public:
        string s;
        int step;
        node(string S, int Step)
        {
            s = S;
            step = Step;
        }
    };

    string doubleOper(string s)
    {
        if (s != "0")
            s.push_back('0');
        return s;
    }
    string notOper(string s)
    {
        for (int i = 0, len = s.length(); i <= len - 1; ++i)
        {
            if (s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }
        while ((*s.begin()) == '0' && s.length() > 1)
        {
            s.erase(s.begin());
        }
        return s;
    }

  public:
    void solve()
    {
        int T;
        cin >> T;
        for (int cas = 1; cas <= T; ++cas)
        {
            int ans = 0;
            string S, E;
            cin >> S >> E;

            if (S != E)
            {
                node startNode(S, 0);
                set<string> nodeSet;
                queue<node> q;
                q.push(startNode);
                nodeSet.insert(S);
                int cnt = 0;
                while (!q.empty())
                {
                    node curr = q.front();
                    q.pop();

                    // if(curr.step>10)
                    // {
                    //     ans=-1;
                    //     break;
                    // }

                    //cout << curr.step << "->" <<curr.s << endl;
                    node node1(notOper(curr.s), curr.step + 1);
                    if (node1.s == E)
                    {
                        ans = node1.step;
                        break;
                    }
                    else if (node1.s != S && nodeSet.count(node1.s) == 0)
                    {
                        q.push(node1);
                        nodeSet.insert(node1.s);
                    }

                    node node2(doubleOper(curr.s), curr.step + 1);
                    if (node2.s == E)
                    {
                        ans = node2.step;
                        break;
                    }
                    else if (node2.s != S && nodeSet.count(node2.s) == 0)
                    {
                        q.push(node2);
                        nodeSet.insert(node2.s);
                    }
                    ++cnt;
                    if (cnt > 1e4)
                    {
                        ans = -1;
                        break;
                    }
                }
            }

            if (ans == -1)
                cout << "Case #" << cas << ": IMPOSSIBLE\n";
            else
                cout << "Case #" << cas << ": " << ans << "\n";
        }
    }
};

class solution_set2
{
    // string exec_double(string s)
    // {
    //     if (s != "0")
    //         s.push_back('0');
    //     return s;
    // }
    string exec_not(string s)
    {
        for (int i = 0, len = s.length(); i <= len - 1; ++i)
        {
            if (s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }
        while ((*s.begin()) == '0' && s.length() > 1)
        {
            s.erase(s.begin());
        }
        return s;
    }

    vector<int> createGroup(const string & s)
    {
        vector<int> group;
        int len = s.length();
        if (len == 1)
        {
            group.push_back(1);
        }
        else
        {
            int curr = 1;
            for (int i = 0; i <= len - 2; ++i)
            {
                if (s[i] != s[i + 1])
                {
                    group.push_back(curr);
                    curr = 1;
                }
                else
                {
                    ++curr;
                }
                if (i == len - 2)
                {
                    group.push_back(curr);
                }
            }
        }
        return group;
    }

    bool isPrefix(const string & a, const string & b)
    {
        if (a.length() > b.length())
            return false;
        else
            return a == b.substr(0, a.length());
    }

    void solve(const string & S, const string & E)
    {
        int ans = 0;

        vector<int> a = createGroup(S);
        vector<int> b = createGroup(E);

        if (S == "0" && E == "1")
        {
            ans = 1;
        }
        else if (S == "0" && b.size() > 2)
        {
            ans = INF;
        }
        else if (S != E)
        {
            ans = INF;

            int K = a.size();
            string prefix = S;
            bool tag1 = false;

            if (S == "0")
                prefix = "1";

            for (int X = 0; X <= K; ++X)
            {
                //进行X次NOT操作之后，是否可以构造E

                if (isPrefix(prefix, E))    //只有是E的前缀才可能构建
                {
                    int Y = E.length() - prefix.length();   //需要Y次double
                    string suffix = E.substr(prefix.length(), E.length() - prefix.length());   //E移除前缀之后的后缀

                    vector<int> suffixGroup = createGroup(suffix);      //后缀产生的组
                    int M = suffixGroup.size();                         //M=组的长度。至少M次NOT操作才能产生后缀
                    int Z = M;

                    if (suffix.back() == '0')  //后缀有0减少一次
                        --Z;                    

                    if (Z <= X)             //只有X>=Z才可能构建成功
                        ans = min(ans, X + Y);
                }
                else if (prefix == "0")     //特殊情况0
                {
                    int Y = E.length();
                    string suffix = E;
                    vector<int> suffixGroup = createGroup(suffix);
                    int M = suffixGroup.size();
                    int Z = M;

                    if (suffix.back() == '0')   //后缀有0减少一次
                        --Z;

                    if (Z <= X)
                        ans = min(ans, X + Y);
                }
                prefix = exec_not(prefix);

                if (prefix == "1")
                {
                    if (tag1 == false)
                        tag1 = true;
                    else
                        break;
                }
            }

            if (S == "0" && ans < INF)
                ++ans;
        }

        if (ans == INF)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << "\n";
    }

  public:
    void solve()
    {
        int T;
        cin >> T;
        for (int cas = 1; cas <= T; ++cas)
        {
            string S, E;
            cin >> S >> E;
            cout << "Case #" << cas << ": ";
            solve(S,E);
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("c_test.in", "r", stdin);
    // freopen("C_Optimal.in", "r", stdin);
    // freopen("C_Optimal.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution_set2 sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}