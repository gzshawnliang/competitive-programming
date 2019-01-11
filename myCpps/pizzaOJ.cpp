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

vector<string> store;

void solve(char now, string top)
{
    if (now == 'Q')
    {
        store.push_back(top);
        return;
    }
    else
    {
        char temp = now + 1;
        solve(temp, top + now);
        solve(temp, top);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);    
    solve('A', "");

    while (true)
    {
        int size0 = 0;
        bool ok = false;
        vector<string> people;
        while (ok == false)
        {
            string temp = "<";
            cin >> temp;
            if (temp == "<")
            {
                return 0;
            }
            else if (temp == ".")
            {
                break;
            }

            ++size0;
            temp.pop_back();
            people.push_back(temp);
        }

        string ans = "<";
        for (int i = 0; i <= 65535; ++i)
        {
            string top = store[i];
            int size0 = people.size();
            bool allSatisfied = true;
            for (int i = 0; i <= size0 - 1; ++i)
            {
                int size1 = people[i].size();
                bool satisfied = false;
                for (int j = 0; j <= size1 - 1; j += 2)
                {
                    bool find0 = top.find(people[i][j + 1]) != string::npos;
                    if (people[i][j] == '+')
                    {
                        if (find0 == true)
                        {
                            satisfied = true;
                            break;
                        }
                    }
                    else
                    {
                        if (find0 == false)
                        {
                            satisfied = true;
                            break;
                        }
                    }
                }

                if (satisfied == false)
                {
                    allSatisfied = false;
                    break;
                }
            }

            if (allSatisfied == true)
            {
                ans = top;
                break;
            }
        }

        if (ans == "<")
        {
            cout << "No pizza can satisfy these requests.\n";
        }
        else
        {
            cout << "Toppings: " << ans << '\n';
        }
    }
    cout.flush();
    return 0;
}