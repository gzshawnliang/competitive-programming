#include <bits/stdc++.h>

using namespace std;

ifstream fin("cellphoneTyping_UVA12526.in");
ofstream fout("cellphoneTyping_UVA12526.out");

const int nc = 1000000, cc = 26;

class trie
{
  private:

    int num = 1;
    vector<int> wordCount;
    vector<vector<int>> a, g;

    int ctoi(char ch)
    {
        return ch - 'a';
    }
    
  public:

    trie()
    {
        wordCount.assign(nc, 0);
        a.assign(nc, vector<int>(cc, -1));
        g.assign(nc, vector<int>());
    }

    void insert(const string & s)
    {
        int size = s.size(), last = 0;
        for (int i = 0; i <= size - 1; ++i)
        {
            if (a[last][ctoi(s[i])] == -1)
            {
                a[last][ctoi(s[i])] = num;
                g[last].push_back(ctoi(s[i]));

                ++num;
            }

            last = a[last][ctoi(s[i])];

            if (i == size - 1)
            {
                ++wordCount[last];
            }
        }
    }

    int count(const string & s)
    {
        int size = s.size(), last = 0, res = 0;
        for (int i = 0; i <= size - 1; ++i)
        {
            if (i == 0 || g[last].size() > 1 || wordCount[last] > 0)
            {
                ++res;
            }

            last = a[last][ctoi(s[i])];
        }

        return res;
    }
};

int main()
{
    fout << fixed << setprecision(2);

    while (true)
    {
        int n = 0; fin >> n;
        if (n == 0) break;

        vector<string> dictionary(n);
        trie t;
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> dictionary[i];
            t.insert(dictionary[i]);
        }

        int ans = 0;
        for (int i = 0; i <= n - 1; ++i)
        {
            ans += t.count(dictionary[i]);
        }

        double ans_d = (double)ans / (double)n;
        fout << (int)(ans_d * 100 + 0.5) / 100.0 << '\n';
    }

    return 0;
}
