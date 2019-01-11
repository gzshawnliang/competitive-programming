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

struct card
{
    char suit;
    int valume;
    bool operator<(const card &i) const
    {
        if (suit == 'S' && i.suit == 'H')
        {
            return true;
        }
        else if (suit == 'H' && i.suit == 'S')
        {
            return false;
        }
        else if (suit < i.suit)
        {
            return true;
        }
        else if (suit > i.suit)
        {
            return false;
        }
        else
        {
            return valume < i.valume;
        }
    };
};

char turn2(int in)
{
    if (in == 10)
    {
        return 'T';
    }
    else if (in == 11)
    {
        return 'J';
    }
    else if (in == 12)
    {
        return 'Q';
    }
    else if (in == 13)
    {
        return 'K';
    }
    else if (in == 14)
    {
        return 'A';
    }
    else
    {
        char temp = '0' + in;
        return temp;
    }
}

void print(set<card> &a)
{
    for (auto i = a.begin(); i != a.end(); ++i)
    {
        cout << " " << i->suit << turn2(i->valume);
    }
    cout << '\n';
}

int turn1(char in)
{
    if (in == 'T')
    {
        return 10;
    }
    else if (in == 'J')
    {
        return 11;
    }
    else if (in == 'Q')
    {
        return 12;
    }
    else if (in == 'K')
    {
        return 13;
    }
    else if (in == 'A')
    {
        return 14;
    }
    else
    {
        int temp = in - '0';
        return temp;
    }
}

void solve()
{
    while (true)
    {
        char tempIn;
        int loop;
        cin >> tempIn;

        if (tempIn == 'N')
        {
            loop = 1;
        }
        else if (tempIn == 'E')
        {
            loop = 2;
        }
        else if (tempIn == 'S')
        {
            loop = 3;
        }
        else if (tempIn == 'W')
        {
            loop = 4;
        }
        else
        {
            break;
        }

        set<card> p1, p2, p3, p4;

        for (int i = 1; i <= 52; ++i)
        {
            char tempSiut;
            char tempValume;
            cin >> tempSiut >> tempValume;
            card temp{tempSiut, turn1(tempValume)};
            ++loop;
            if (loop > 4)
            {
                loop = 1;
            }

            if (loop == 1)
            {
                p1.insert(temp);
            }
            else if (loop == 2)
            {
                p2.insert(temp);
            }
            else if (loop == 3)
            {
                p3.insert(temp);
            }
            else
            {
                p4.insert(temp);
            }
        }

        cout << "S:";
        print(p3);
        cout << "W:";
        print(p4);
        cout << "N:";
        print(p1);
        cout << "E:";
        print(p2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    cout.flush();       
    return 0;

}