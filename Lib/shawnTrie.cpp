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

class trieS
{
  private:

    // int num = 1;
    // vector<int> count;
    // vector<vector<int>> a, g;

  public:

    int num = 1;
    vector<int> count;
    vector<vector<int>> a, g;

    trieS()
    {
        count.assign(nc, 0);
        a.assign(nc, vector<int>(cc, -1));
        g.assign(nc, vector<int>());
    }
    
    void build(const string & s)
    {
        int size = s.size();
        vector<int> lastNum;
        for (int i = 0; i <= size - 1; ++i)
        {
            if (i == 0)
            {
                a[0][s[i]] = num;
                g[0].push_back(s[i]);
                lastNum.push_back(num);
                ++num;
            }
            else
            {
                vector<int> lastNumTemp = lastNum; lastNum.clear();
                int sizeL = lastNumTemp.size();
                for (int j = 0; j <= sizeL - 1; ++j)
                {
                    int last = lastNumTemp[j];

                    if (a[last][s[i]] == -1)
                    {
                        a[last][s[i]] = num;
                        g[last].push_back(s[i]);
                        lastNum.push_back(num);
                        ++num;
                    }
                }

                if (a[0][s[i]] == -1)
                {
                    a[0][s[i]] = num;
                    g[0].push_back(s[i]);
                    lastNum.push_back(num);
                    ++num;
                }

                if (a[a[0][s[i - 1]]][s[i]] == -1)
                {
                    a[a[0][s[i - 1]]][s[i]] = num;
                    g[a[0][s[i - 1]]].push_back(s[i]);
                    lastNum.push_back(num);
                    ++num;
                }
            }
        }
    };

    bool find(const string & s)
    {
        int size = s.size(), last = 0;
        for (int i = 0; i <= size - 1; ++i)
        {
            if (a[last][s[i]] == -1)
            {
                return 0;
            }
            else
            {
                last = a[last][s[i]];
            }
        }
        return 1;
    }
};

int main()
{
    // vector<string> as = {"abcd", "abd", "ab", "cdd", "efg", "hij", "hi", "cdd"};

    // trie t;
    // for (auto s : as)
    // {
    //     t.insert(s);
    // }

    // vector<string> ans =  t.findPrefix("hi");
    // for (auto s : ans)
    // {
    //     fout << s << '\n';
    // }

    string s = "abcdefcc";
    trieS t; t.build(s);
    fout << t.find("fcc") << '\n';
    fout << t.find("cdef") << '\n';

    return 0;
}
