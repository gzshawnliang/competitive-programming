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
#include <set>
#include <map>

using namespace std;


struct event
{
    double d;
    string name;
    double v;
};

void skipFin(int c)
{
    for (int i = 1; i <= c; ++i)
    {
        string s; cin >> s;
    }
}

bool check(double f, double n, vector<event> & e)
{
    int size = e.size();
    double leak = 0.0, nowF = f;
    for (int i = 1; i <= size - 1; ++i)
    {
        if ((e[i].d - e[i - 1].d) * (n / 100.0 + leak) > nowF)
        {
            return false;
        }
        else
        {
            nowF -= (e[i].d - e[i - 1].d) * (n / 100.0 + leak);

            if (e[i].name == "Goal")
            {
                return true;
            }
            else if (e[i].name == "Leak")
            {
                ++leak;
            }
            else if (e[i].name == "Gas")
            {
                nowF = f;
            }
            else if (e[i].name == "Mechanic")
            {
                leak = 0;
            }
            else if (e[i].name == "Fuel")
            {
                n = e[i].v;
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    cout << fixed << setprecision(3);
    while (true)
    {
        skipFin(3);
        double n; cin >> n;

        if (n == 0)
        {
            break;
        }

        vector<event> e;
        event ubeless1{0, "start"};
        e.push_back(ubeless1);

        while (true)
        {
            event temp; cin >> temp.d >> temp.name;
            if (temp.name == "Gas" || temp.name == "Fuel")
            {
                skipFin(1);
                if (temp.name == "Fuel")
                {
                    cin >> temp.v;
                }
            }

            e.push_back(temp);

            if (temp.name == "Goal")
            {
                break;
            }
        }

        double l = 0.0, r = 10000000.0001;
        while (r - l > 0.0001)
        {
            double f = (l + r) / 2.0;

            if (check(f, n, e) == true)
            {
                r = f;
            }
            else
            {
                l = f;
            }
        }

        cout << l << '\n';
    }

   	cout.flush();
   	return 0;
}

