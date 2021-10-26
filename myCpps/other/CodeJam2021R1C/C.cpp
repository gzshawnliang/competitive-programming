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
        if (s != "0")
            s.push_back('0');
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

    void NOT(vector<int> & group)
    {
        if(group.size()>1)
            group.erase(group.begin());
        else 
            group[0]=1;
    }
    void DOUBLE(vector<int> & group, int times)
    {
        if (times == 0)
            return;

        int len = group.size();
        if (len % 2 == 0)
        {
            group[len - 1] += times;
        }
        else
        {
            group.push_back(times);
        }
    }
    bool isPRE(const vector<int> & a, const vector<int> & b)
    {
        if(a.size() > b.size())
        {
            return false;
        }
        else 
        {
            for (int i = 0,len=a.size(); i <= len - 1; ++i)
            {
                if(a[i]!=b[i])
                    return false;               
            }
        }
        return true;
    }

    bool isEq(const vector<int> & A, const vector<int> & B)
    {
        if (A.size() == B.size())
        {
            for (int i = 0, len = A.size(); i <= len - 1; ++i)
            {
                if (A[i] != B[i])
                    return false;
            }
            return true;
        }
        return false;
    }
    bool isPrefix(const string & a, const string & b)
    {
        if(a.length() > b.length())
            return false;
        else 
            return a==b.substr(0,a.length());
    }
    int check(const string & S, const string & E,bool isPriorNOT)
    {
        int ans = 0;

        if (S != E)
        {
            vector<int> groupS = createGroup(S);
            vector<int> groupE = createGroup(E);
            int lenS = groupS.size();
            bool tag = true;
            auto curr = groupE.begin();

            if (groupS.back() <= groupE.front() && isPriorNOT)
            {
                //可以利用S
                if (lenS % 2 == 1)
                {
                    ++ans; //NOT
                    NOT(groupS);
                }

                ans += (groupE.front() - groupS.back());
                DOUBLE(groupS, (groupE.front() - groupS.back()));
                ++curr;
                tag = false;
            }

            lenS = groupS.size();

            if (lenS % 2 == 0)
            {
                ++ans; //NOT
                NOT(groupS);
                tag = true;
            }

            while (curr != groupE.end())
            {
                //交替DOUBLE，NOT操作。
                if (tag)
                {
                    ans += (*curr);
                    DOUBLE(groupS, *curr);
                    ++curr;
                }
                else
                {
                    ++ans;
                    NOT(groupS);
                }
                tag = !tag;
            }

            if (groupS.size() > groupE.size())
            {
                while (true)
                {
                    ++ans;
                    NOT(groupS);

                    if (groupS.size() == groupE.size())
                        break;
                }

                if (isEq(groupS, groupE) == false)
                    ans = INF;
            }
            else if (groupS.size() == groupE.size())
            {
                if (isEq(groupS, groupE) == false)
                    ans = INF;
            }
            else
            {
                ans = INF;
            }
        }

        return ans;
    }
 
    void test()
    {
        string a="1010";
        string b="101011011";
        clog << isPrefix(a,b)<<"\n";
    }

    int check2(const string & S,const string & subStr, const string & E,int notCnt)
    {
        int doubleCnt = E.length()-subStr.length();

        string trimE=E.substr(subStr.length(),E.length()-subStr.length());
        vector<int> a=createGroup(trimE);
        int aLen=a.size();

        if(notCnt < aLen)        //NOT太少不足够
            return INF;
        else 
            return doubleCnt+notCnt;
    }

    int check0(const string & S, const string & E,int K)
    {
        int doubleCnt = E.length();
        vector<int> a=createGroup(E);
        int aLen=a.size();
        if(S.back()=='1')
            --aLen;

        if(aLen>K)
            return INF;
        else 
            return doubleCnt+K+1;
    }

  public:
    void solve()
    {
        int T;
        cin >> T;
        for (int cas = 1; cas <= T; ++cas)
        {
            int ans =0;
            string S, E;
            cin >> S >> E;
            vector<int> a=createGroup(S);
            vector<int> b=createGroup(E);            
            if (S =="0" && E=="1")
            {
                ans=1;
                // if(E=="1")
                // {
                //     ans=1;
                // }
                // else
                // {
                //      vector<int> b=createGroup(E);
                //      if(b.size()<=2)
                //      {
                //          ans = E.length()+2;
                //      }
                //      else 
                //      {
                //          ans =INF;
                //      }
                // }
                
            }
            else if (S =="0" && b.size()>2)
            {
                ans =INF;
            }
            else if (S != E)
            {
                // set<string> subSet;
                ans=INF;

                vector<int> a1(a);
                int K=a.size();
                string prefix=S;
                bool tag1=false;

                if(S =="0")
                   prefix="1";


                for (int X = 0; X <= K ; ++X)
                {
                    if(isPrefix(prefix,E))
                    {
                        int Y=E.length()-prefix.length();
                        string suffix=E.substr(prefix.length(),E.length()-prefix.length());
                        // while ((*suffix.begin()) == '0' && suffix.length() > 1)
                        // {
                        //     suffix.erase(suffix.begin());
                        // }                        
                        vector<int> suffixGroup=createGroup(suffix);
                        int M=suffixGroup.size();
                        int Z=M;
                        // if (M % 2 == 0)
                        // {
                        //     Z=M+1;                            
                        // }
                        // if(prefix.back()=='1')
                        //     Z=M-1;
                        // else 

                        if(suffix.back()=='0')
                            Z=M-1;

                        if(Z>X)
                        {
                            
                        }
                        else 
                            ans=min(ans,X+Y);
                    }
                    else if(prefix=="0")
                    {
                        int Y=E.length();
                        string suffix=E;
                        vector<int> suffixGroup=createGroup(suffix);
                        int M=suffixGroup.size();
                        int Z=M;

                        if(suffix.back()=='0')
                            Z=M-1;

                        if(Z>X)
                        {
                            
                        }
                        else 
                            ans=min(ans,X+Y);
                    }
                    prefix = exec_not(prefix);

                    if(prefix=="1")
                    {
                        if(tag1==false)
                            tag1=true;
                        else 
                            break;
                    }
                }

                if(S =="0" && ans <INF)
                   ++ans;                
            }

            if (ans == INF)
                cout << "Case #" << cas << ": IMPOSSIBLE\n";
            else
                cout << "Case #" << cas << ": " << ans << "\n";
        }
    }

    void solve2()
    {
        int T;
        cin >> T;
        for (int cas = 1; cas <= T; ++cas)
        {
            string S, E;
            cin >> S >> E;

            int ans =check(S,E,true);
            ans =min(ans,check(S,E,false));

            if (ans == INF)
                cout << "Case #" << cas << ": IMPOSSIBLE\n";
            else
                cout << "Case #" << cas << ": " << ans << "\n";
        }
        return;
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
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