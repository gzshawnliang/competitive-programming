#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

ifstream fin("article.in");
ofstream fout("article.out");

struct ch
{
    char c;
    int _count;

    bool operator<(const ch &temp) const
    {
        return _count < temp._count;
    }
};

int main()
{
    long long total = 0;
    vector<int> a(95, 0);

    fout << fixed << setprecision(4);

    while (true)
    {
        string in = "";
        getline(fin, in);

        if (fin.eof() == true)
        {
            break;
        }

        int size = in.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            for (char c = ' '; c <= '~'; ++c)
            {
                if (in[i] == c)
                {
                    ++a[c - ' '];
                    break;
                }
            }
        }

        total += size;
    }

    int _max = 0;
    vector<string> out;

    for (int i = 0; i <= 94; ++i)
    {
        char c = ' ' + i;

        string temp = "";
        temp.push_back(c);

        for (int j = 1; j <= a[i]; ++j)
        {
            temp += '|';
        }

        _max = max(_max, a[i]);
        out.push_back(temp);
    }

    for (int i = 0; i <= 94; ++i)
    {
        for (int c = 1; c <= _max - a[i]; ++c)
        {
            out[i].push_back(' ');
        }
    }
    

    for (int j = _max - 1; j >= 0; --j)
    {
        for (int i = 0; i <= 94; ++i)
        {
            fout << out[i][j];
        }
        fout << '\n';
    }

    fout << '\n';
    fout << "total chars: " << total << '\n';

    double _total = (double)total;
    vector<ch> list;

    for (int i = 0; i <= 94; ++i)
    {
        char c = ' ' + i, k = 37;

        double m = (double)a[i];

        fout << c << ' ' << setw(10) << a[i] << setw(15) << m / _total * 100.0 << k << '\n';

        ch temp{c, a[i]};
        list.push_back(temp);
    }


    fout << '\n';
    
    sort(list.begin(), list.end());

    for (int i = 94; i >= 0; --i)
    {
        fout << list[i].c;
    }

    fout << '\n';

    return 0;
}