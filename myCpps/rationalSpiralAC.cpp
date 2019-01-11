#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <fstream>
#include <queue>
#include <set>

using namespace std;

ifstream fin("rationalSpiral.in");
ofstream fout("rationalSpiral.out");

struct number
{
    int id;
    int a;
    int b;
    
    bool operator<(const number & newtest1) const
    {
        //C++ ÑÏ¸ñÈõÐò
        return std::tie(this->a, this->b) < std::tie(newtest1.a, newtest1.b);
    };
};


bool mySortFunc (number &i,number &j)
{
    return i.id<j.id; 
}

int gcd(int a, int b)
{
    while(b != 0)
    {
        int r = b;
        b = a % b;
        a = r;
    }
    return a;
}

int main()
{
    set<number> a;

    int y = 0, x = 0, count0 = 1, direction = 0;
    bool count1 = 0;
    while (a.size() <= 510000)
    {
        for (int i = 1; i <= count0; ++i)
        {
            if (direction == 0)
            {
                ++y;
            }
            else if (direction == 1)
            {
                ++x;
            }
            else if (direction == 2)
            {
                --y;
            }
            else
            {
                --x;
            }

            if (a.size() == 8)
            {
                cout << "";
            }
            
            int tempY = y, tempX = x;
            if (tempX == 0)
            {
                continue;
            }

            int divide = gcd(tempY, tempX);
            tempY /= divide;
            tempX /= divide;

            if (tempX < 0)
            {
                tempY *= - 1;
                tempX *= -1;
            }

            int size = a.size();
            number temp{size, tempY, tempX};
            a.insert(temp);
        }

        if (count1 == false)
        {
            count1 = true;
        }
        else
        {
            ++count0;
            count1 = false;
        }

        ++direction;
        direction %= 4;
    }

    vector<number> store;
    for (set<number>::iterator it=a.begin(); it!=a.end(); ++it)
    {
        store.push_back(*it);
    }
    
    sort(store.begin(),store.end(),mySortFunc);

    while (true)
    {
        int in = -1;
        fin >> in;

        if (in == -1)
        {
            break;
        }

        fout << store[in].a << " / " << store[in].b << '\n';
    }
   
    return 0;
}