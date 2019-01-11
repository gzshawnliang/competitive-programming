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

ifstream fin("packets.in");
ofstream fout("packets.out");

int main()
{
    while (true)
    {
        vector<int> packets(7, 0);
        fin >> packets[1] >> packets[2] >> packets[3] >> packets[4] >> packets[5] >> packets[6];

        if (packets[1] + packets[2] + packets[3] + packets[4] + packets[5] + packets[6] == 0)
        {
            break;
        }

        int total = 0;

        // size 6 x 6
        total += packets[6];
        packets[6] = 0;

        // size 5 x 5
        for (int i = 1; i <= packets[5]; ++i)
        {
            if (packets[1] >= 11)
            {
                packets[1] -= 11;
            }
            else
            {
                packets[1] = 0;
            }
            ++total;
        }
        packets[5] = 0;

        // size 4 x 4
        int left0 = -1;
        for (int i = 1; i <= packets[4]; ++i)
        {
            if (packets[2] >= 5)
            {
                packets[2] -= 5;
            }
            else
            {
                if (left0 == -1)
                {
                    left0 = (5 - packets[2]) * 4;
                    packets[2] = 0;
                }

                if (packets[1] >= left0)
                {
                    packets[1] -= left0;
                }
                else
                {
                    packets[1] = 0;
                }
            }
            ++total;
        }
        packets[4] = 0;

        // size 3 x 3
        total += packets[3] / 4;
        packets[3] %= 4;

        if (packets[3] <= 0)
        {
            // Do nothing
        }
        else
        {
            ++total;
            if (packets[3] == 3)
            {
                if (packets[2] >= 1)
                {
                    --packets[2];

                    if (packets[1] >= 5)
                    {
                        packets[1] -= 5;
                    }
                    else
                    {
                        packets[1] = 0;
                    }
                }
                else
                {
                    packets[2] = 0;

                    if (packets[1] >= 9)
                    {
                        packets[1] -= 9;
                    }
                    else
                    {
                        packets[1] = 0;
                    }
                }
            }
            else if (packets[3] == 2)
            {
                if (packets[2] >= 3)
                {
                    packets[2] -= 3;

                    if (packets[1] >= 6)
                    {
                        packets[1] -= 6;
                    }
                    else
                    {
                        packets[1] = 0;
                    }
                }
                else
                {
                    int left1 = 18 - packets[2] * 4;
                    packets[2] = 0;

                    if (packets[1] >= left1)
                    {
                        packets[1] -= left1;
                    }
                    else
                    {
                        packets[1] = 0;
                    }
                }
            }
            else if (packets[3] == 1)
            {
                if (packets[2] >= 5)
                {
                    packets[2] -= 5;

                    if (packets[1] >= 7)
                    {
                        packets[1] -= 7;
                    }
                    else
                    {
                        packets[1] = 0;
                    }
                }
                else
                {
                    int left1 = 27 - packets[2] * 4;
                    packets[2] = 0;

                    if (packets[1] >= left1)
                    {
                        packets[1] -= left1;
                    }
                    else
                    {
                        packets[1] = 0;
                    }
                }
            }
        }

        // size 2 x 2
        total += packets[2] / 9;
        packets[2] %= 9;

        if (packets[2] > 0)
        {
            ++total;
            if (packets[1] > 36 - packets[2] * 4)
            {
                packets[1] -= 36 - packets[2] * 4;
            }
            else
            {
                packets[1] = 0;
            }
        }
        
        // size 1 x 1
        total += packets[1] / 36;
        packets[1] %= 36;

        if (packets[1] > 0)
        {
            ++total;
        }

        fout << total << '\n';
    }

    return 0;
}