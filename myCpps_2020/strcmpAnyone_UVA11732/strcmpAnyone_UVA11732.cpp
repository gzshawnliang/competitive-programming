#include <bits/stdc++.h>

using namespace std;

ifstream fin("strcmpAnyone_UVA11732.in");
ofstream fout("strcmpAnyone_UVA11732.out");

using ll = long long;
const ll nc = 4000, cc = 62;
const node _null{-1, -1, -1};

struct node
{
    ll parent;
    ll lSon;
    ll rBro;
};

class trie
{
  private:

    int num = 1;
    vector<int> l, wordCount;
    vector<node> tree;

    ll ctol(char ch)
    {
        if ('0' <= ch && ch <= '9')      return ch - '0' + 1;
        else if ('A' <= ch && ch <= 'Z') return ch - 'A' + 11;
        else                             return ch - 'a' + 37;
    };

  public:

    trie()
    {
        l.assign(nc + 1, -1);
        wordCount.assign(nc * cc + 1, 0);
        tree.assign(nc * cc + 1, _null);
    }

    void insert(string & s)
    {
        int size = s.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            int si_l = ctol(s[i]);

            
        }
    }

};



int main()
{
    while (true)
    {
        ll n; fin >> n;

        ll pos = 1;
        vector<node> a(n, _null);
        for (ll c = 1; c <= n; ++c)
        {
            string s; fin >> s;
            add(pos, s, a);
        }
    }

    return 0;
}
