#include <bits/stdc++.h>

using namespace std;

ifstream fin("shawnTrie.in");
ofstream fout("shawnTrie.out");

const int nc = 10000, cc = 128;

class trie
{
  private:

    int num = 1;
    vector<int> count;
    vector<vector<int>> a, g;

    vector<string> PfindPrefix(int _i, const string & s, string now)
    {
        if (_i == 0)
        {
            int size = s.size(), last = 0;
            vector<string> ans;
            for (int i = 0; i <= size - 1; ++i)
            {
                if (a[last][s[i]] == -1)
                {
                    return ans;
                }

                last = a[last][s[i]];
            }

            string temp = s;
            return PfindPrefix(last, s, temp);
        }
        else
        {
            int size = g[_i].size();

            vector<string> ans;
            if (count[_i] > 0)
            {
                for (int c = 1; c <= count[_i]; ++c)
                {
                    ans.push_back(now);
                }
            }

            for (int i = 0; i <= size - 1; ++i)
            {
                char ch = g[_i][i];

                vector<string> temp = PfindPrefix(a[_i][ch], s, now + ch);
                
                int sizeTemp = temp.size();
                for (int i = 0; i <= sizeTemp - 1; ++i)
                {
                    ans.push_back(temp[i]);
                }
            }

            return ans;
        }
    }
    
  public:

    trie()
    {
        count.assign(nc, 0);
        a.assign(nc, vector<int>(cc, -1));
        g.assign(nc, vector<int>());
    }

    void insert(const string & s)
    {
        int size = s.size(), last = 0;
        for (int i = 0; i <= size - 1; ++i)
        {
            if (a[last][s[i]] == -1)
            {
                a[last][s[i]] = num;
                g[last].push_back(s[i]);

                ++num;
            }

            last = a[last][s[i]];

            if (i == size - 1)
            {
                ++count[last];
            }
        }
    }

    bool find(const string & s)
    {
        int size = s.size(), last = 0;
        for (int i = 0; i <= size - 1; ++i)
        {
            if (a[last][s[i]] == -1)
            {
                return 0;
            }

            last = a[last][s[i]];
        }

        return 1;
    }

    vector<string> findPrefix(const string & s)
    {
        return PfindPrefix(0, s, "");
    }
};

int main()
{
    //例子
    // vector<string> a = {"abcd", "abd", "ab", "cdd", "efg", "hij", "hi", "cdd"};
    // trie trie1;
    // for (auto s : a)
    // {
    //     trie1.insert(s);
    // }

    // cout << trie1.exists("ab") << '\n';
    // cout << trie1.existsPrefix("ab") << '\n';

    vector<string> as = {"abcd", "abd", "ab", "cdd", "efg", "hij", "hi", "cdd"};

    trie t;
    for (auto s : as)
    {
        t.insert(s);
    }

    vector<string> ans =  t.findPrefix("hi");
    for (auto s : ans)
    {
        fout << s << '\n';
    }


    return 0;
}
