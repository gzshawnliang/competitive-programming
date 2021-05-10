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

using ill = long long;

class node
{
    public:
    string s;
    int step;
    node(string S,int Step)
    {
        s=S;
        step=Step;
    }
};

class solution
{


    string doubleOper(string s)
    {
        if(s!="0")
            s.push_back('0');
        return s;
    }
    string notOper(string s)
    {
        for (int i = 0,len=s.length(); i <= len - 1; ++i)
        {
            if(s[i]=='1')
                s[i]='0';
            else 
                s[i]='1';
        }
        while ((*s.begin())=='0' && s.length()>1)
        {
            s.erase(s.begin());
        }
        return s;
    }

  public:
    void solve()
    {
        int T;
        cin>>T;
        for (int cas = 1; cas <= T; ++cas)
        {
            int ans = 0;
            string S,E;
            cin >> S>>E;

            if(S!=E)
            {
                node startNode(S,0);
                set<string> nodeSet;
                queue<node> q;
                q.push(startNode);
                nodeSet.insert(S);
                int cnt=0;
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
                    node node1(notOper(curr.s),curr.step+1);
                    if(node1.s==E)
                    {
                        ans=node1.step;
                        break;
                    }
                    else if(node1.s!=S && nodeSet.count(node1.s)==0)
                    {
                        q.push(node1);    
                        nodeSet.insert(node1.s);                    
                    }
                    
                    node node2(doubleOper(curr.s),curr.step+1);
                    if(node2.s==E)
                    {
                        ans=node2.step;
                        break;
                    }
                    else if(node2.s!=S && nodeSet.count(node2.s)==0)
                    {
                        q.push(node2);
                        nodeSet.insert(node2.s);
                    }
                    ++cnt;
                    if(cnt>1e4)
                    {
                        ans=-1;
                        break;
                    }
                }
            }

            if(ans==-1)
                cout << "Case #" << cas << ": IMPOSSIBLE\n";
            else 
                cout << "Case #" << cas << ": " << ans << "\n";
            
            cout.flush();
        }
       
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("C2.in", "r", stdin);
    freopen("C.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}