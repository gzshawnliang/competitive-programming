#include <bits/stdc++.h>

using namespace std;


using ll = long long;
const ll maxL = 4000 * 1000;

struct node
{
    char ch;
    ll parent;
    ll lSon;
    ll rBro;
    ll res;
};

node tree[maxL + 1];

class trie
{
  private:
    ll num;

  public:
    ll ans;

    void init()
    {
        num = 0;

        tree[0].ch = '-';
        tree[0].parent = -1;
        tree[0].lSon = -1;
        tree[0].rBro = -1;
        tree[0].res = 0;

        ans = 0;
    }

    void insert(string & s)
    {
        int size = s.size(),
            now = 0;
        for (int i = 0; i <= size; ++i)
        {
            int next = -1;
            for (int j = tree[now].lSon; j != -1; j = tree[j].rBro)
            {
                if (tree[j].ch == s[i])
                {
                    ans += (tree[j].res * 2);
                    next = j;
                }
                else
                {
                    ans += tree[j].res;
                }
            }

            if (next == -1)
            {
                ++num;
                next = num;

                tree[next].ch = s[i];
                tree[next].parent = now;
                tree[next].lSon = -1;
                tree[next].rBro = tree[now].lSon;
                tree[next].res = 0;

                tree[now].lSon = next;
            }
            
            now = next;
            ++tree[now].res;
        }
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int _t = 0;
    while (true)
    {
        ll n = 0; cin >> n;
        if (n == 0) break;
        ++_t;

        trie t;
        t.init();

        for (ll c = 1; c <= n; ++c)
        {
            string s; cin >> s;
            t.insert(s);
        }

        cout << "Case " << _t << ": " << t.ans << '\n';
    }

   	cout.flush();
   	return 0;
}

