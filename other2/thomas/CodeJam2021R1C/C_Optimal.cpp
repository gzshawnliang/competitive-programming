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
    string exec_double(string s)
    {
        return exec_double(s,1);
    }
    string exec_double(string s,int times)
    {
        if (s != "0")
        {
            for (int i = 1; i <= times; ++i)
            {
                s.push_back('0');                
            }
        }

        return s;
    }    
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

    //官方解决方案（比较难理解）
    //https://codingcompetitions.withgoogle.com/codejam/round/00000000004362d7/00000000007c1139#analysis
    void solve_official(const string & S, const string & E)
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

    //模拟解决方案1（比较难理解）
    void solve1(const string & S, const string & E)
    {
        int ans = 0;

        vector<int> a = createGroup(S);
        vector<int> b = createGroup(E);
        if (S == E)
        {
            ans = 0;
        }
        else if (E == "0")
        {
            ans = a.size();
        }
        else if (S == "0" && E == "1")
        {
            ans = 1;
        }
        else if (S == "0" && b.size() > 2)
        {
            ans = INF;
        }
        else 
        {
            ans = INF;

            int K = a.size();
            string prefix = S;

            for (int X = 0; X <= K+1; ++X)
            {
                //进行X次NOT操作之后，是否可以构造E
                if (isPrefix(prefix, E))    //只有是E的前缀才可能构建
                {
                    //int Y = E.length() - prefix.length();   //需要Y次double
                    string suffix = E.substr(prefix.length(), E.length() - prefix.length());   //E移除前缀之后的后缀

                    vector<int> suffixGroup = createGroup(suffix);      //后缀产生的组
                    int M = suffixGroup.size();                         //M=组的长度。至少M次NOT操作才能产生后缀
                    int cnt=0;

                    //模拟
                    string e1 = S;
                    int begin=0;
                    if(prefix.back()=='1' && suffix.front()=='1')
                    {
                        if(S.back()=='1')
                        {
                            ++cnt;
                            e1=exec_not(S);
                        }
                        else
                        {
                            int times=suffixGroup[0];
                            cnt+=times;
                            e1=exec_double(S,times);
                            ++begin;
                        }
                    }
                    if(prefix.back()=='1' && suffix.front()=='0')
                    {
                        if(S.back()=='0')
                        {
                            ++cnt;
                            e1=exec_not(S);                            
                        }
                        else 
                        {
                            int times=suffixGroup[0];
                            cnt+=times;
                            e1=exec_double(S,times);
                            ++begin;                        
                        }
                    }                    
                    else if(prefix.back()=='0' && suffix.front()=='1')
                    {
                        if(S.back()=='0')
                        {
                            ++cnt;
                            e1=exec_not(S);
                        }
                        else 
                        {                        
                            int times=suffixGroup[0];
                            cnt+=times;
                            e1=exec_double(S,times);
                            ++begin;
                        }
                    } 
                    else if(prefix.back()=='0' && suffix.front()=='0')
                    {
                        if(S.back()=='1')
                        {
                            ++cnt;
                            e1=exec_not(S);
                        }
                    }                         


                    for (int i = begin; i <= M - 1; ++i)
                    {
                        if(i>0)
                        {
                            ++cnt;
                            e1=exec_not(e1);                              
                        }

                        e1=exec_double(e1,suffixGroup[i]);
                        cnt +=suffixGroup[i];
                    }
                    while (e1.length()>E.length())
                    {
                        ++cnt;
                        e1=exec_not(e1);    
                    }
                    

                    if(e1==E)
                        ans=min(ans,cnt);
                }
                else if (prefix=="0")    
                {
                    //int Y = E.length();   //需要Y次double
                    string suffix = E;   //E移除前缀之后的后缀

                    vector<int> suffixGroup = createGroup(suffix);      //后缀产生的组
                    int M = suffixGroup.size();                         //M=组的长度。至少M次NOT操作才能产生后缀
                    int cnt=0;

                    //模拟
                    string e1 = S;

                    if(S.back()=='0' )
                    {
                        ++cnt;
                        e1=exec_not(S);
                    }                         

                    for (int i = 0; i <= M - 1; ++i)
                    {
                        if(i>0)
                        {
                            ++cnt;
                            e1=exec_not(e1);                              
                        }

                        e1=exec_double(e1,suffixGroup[i]);
                        cnt +=suffixGroup[i];
                    }
                    while (e1.length()>E.length())
                    {
                        ++cnt;
                        e1=exec_not(e1);    
                    }                    

                    if(e1==E)
                        ans=min(ans,cnt);

                }                
                prefix = exec_not(prefix);
            }
        }

        if (ans == INF)
            cout << "IMPOSSIBLE";
        else
            cout << ans << "";
    }

    //模拟解决方案2（比较容易理解）
    void solve2(const string & S, const string & E)
    {
        int ans = 0;

        vector<int> a = createGroup(S);
        vector<int> b = createGroup(E);
        if (S == E)         //两个字符串相同不需要操作
        {
            ans = 0;
        }
        else if (E == "0")  //特殊情况1
        {
            ans = a.size();
        }
        else if (S == "0" && E == "1")  //特殊情况2
        {
            ans = 1;
        }
        else if (S == "0" && b.size() > 2)  //特殊情况3
        {
            ans = INF;
        }
        else 
        {
            ans = INF;

            int K = a.size();
            string prefix = S;

            for (int X = 0; X <= K+1; ++X)
            {
                //根据后缀计算生成E需要的步骤，
                //isNOT=true表示，开始先进行NOT操作,
                //isNOT=false表示，开始先进行DOUBLE操作
                auto getCnt=[&](bool isNOT,const string & suffix)
                {
                    vector<int> suffixGroup = createGroup(suffix);      //后缀产生的组
                    int cnt=0;

                    //模拟
                    string e1 = S;
                    int begin=0;
                    if(isNOT)
                    {
                        ++cnt;
                        e1=exec_not(S);
                    }
                    else
                    {
                        if(suffixGroup.size()>0)
                        {
                            int times=suffixGroup[0];
                            cnt+=times;
                            e1=exec_double(S,times);
                            ++begin;
                        }
                    }

                    int M = suffixGroup.size();                         //M=组的长度。至少M次NOT操作才能产生后缀
                    for (int i = begin; i <= M - 1; ++i)
                    {
                        if(i>0)
                        {
                            ++cnt;
                            e1=exec_not(e1);                              
                        }

                        e1=exec_double(e1,suffixGroup[i]);
                        cnt +=suffixGroup[i];
                    }
                    while (e1.length()>E.length())
                    {
                        ++cnt;
                        e1=exec_not(e1);    
                    }
                    
                    if(e1==E)
                        return cnt;
                    else 
                        return INF;
                };


                //进行X次NOT操作之后，是否可以构造E
                if (isPrefix(prefix, E))    //只有是E的前缀才可能构建
                {
                    string suffix = E.substr(prefix.length(), E.length() - prefix.length());   //E移除前缀之后的后缀

                    ans = min(ans,getCnt(true,suffix));
                    ans = min(ans,getCnt(false,suffix));
                }
                else if (prefix=="0")    
                {
                    string suffix = E;      //E移除前缀之后的后缀
                    ans = min(ans,getCnt(true,suffix));
                    ans = min(ans,getCnt(false,suffix));
                }                
                prefix = exec_not(prefix);
            }
        }

        if (ans == INF)
            cout << "IMPOSSIBLE";
        else
            cout << ans << "";
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
            solve2(S,E);
            cout << "\n";
            // cout << "->";
            // solve_official(S,E);
        }
    }
};



signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("c_test.in", "r", stdin);
    freopen("C_Optimal.in", "r", stdin);
    freopen("C_Optimal.out", "w", stdout);
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