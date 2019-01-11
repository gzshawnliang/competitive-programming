#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("division.in");
ofstream fout("division.out");

int main()
{
    int count = 0;
    while(true)
    {
        ++count;
        
        int in;
        bool find = false;
        fin >> in;

        if (in == 0)
        {
            return 0;
        }

        if (count != 1)
        {
            fout << '\n';
        }
        
        for (int a = 0; a <= 4; ++a)
        {
            for (int b = 0; b <= 9; ++b)
            {
                if (b == a)
                {
                    continue;
                }
                for (int c = 0; c <= 9; ++c)
                {
                    if (c == a || c == b)
                    {
                        continue;
                    }
                    for (int d = 0; d <= 9; ++d)
                    {
                        if (d == a || d == b || d == c)
                        {
                            continue;
                        }
                        for (int e = 0; e <= 9; ++e)
                        {
                            if (e == a || e == b || e == c || e == d)
                            {
                                continue;
                            }
                            string n = "0123456789";
                            string first = "";
                            first.push_back(n[a]);
                            first.push_back(n[b]);
                            first.push_back(n[c]);
                            first.push_back(n[d]);
                            first.push_back(n[e]);
                            string second = to_string(stoi(first) * in);
                            bool ok = true;
                            vector<int> dp(10,false);
                            if (second.size() != 5)
                            {
                                ok = false;
                            }
                            for (int i = 0; i <= 4 && ok == true; ++i)
                            {
                                int now = second[i] - '0';
                                if (now != a && now != b && now != c && now != d && now != e && dp[now] == false)
                                {
                                    dp[now] = true;
                                }
                                else
                                {
                                    ok = false;
                                    break;
                                }
                            }
                            if (ok == true)
                            {
                                find = true;
                                //fout << a << " " << b << " " << c << " " << d << " " << e << " --> ";
                                fout << second << " / " << first << " = " << in << '\n';
                            }
                        }
                    }
                }
            }
        }

        if (find == false)
        {
            fout << "There are no solutions for " << in <<".\n";
        }
    }
}