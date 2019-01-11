#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define ll long long

ifstream fin("playfairCipher_UVA11697.in");
ofstream fout("playfairCipher_UVA11697.out");

int main()
{
    int T; fin >> T;
    string useless = "";
    getline(fin, useless);
    for (int t = 1; t <= T; ++t)
    {
        string key = "", text = "";
        getline(fin, key);
        getline(fin, text);
        int size0 = key.size(), size1 = text.size();

        for (int i = 0; i <= size0 - 1; ++i)
        {
            if (key[i] >= 'a' && key[i] <='z')
            {
                key[i] = key[i] - 'a' + 'A';
            }
            else
            {
                key.erase(key.begin() + i);
                --size0;
                --i;
            }
        }

        for (int i = 0; i <= size1 - 1; ++i)
        {
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                text[i] = text[i] - 'a' + 'A';
            }
            else
            {
                text.erase(text.begin() + i);
                --size1;
                --i;
            }
        }

        vector<int> place(26, -1);
        vector<vector<char>> table(5, vector<char>(5, '-'));
        int pos = 0;
        for (int i = 0; i <= size0 - 1; ++i)
        {
            if (place[key[i] - 'A'] == -1)
            {
                table[pos / 5][pos % 5] = key[i];
                place[key[i] - 'A'] = pos;

                ++pos;
            }
        }

        for (char c = 'A'; c <= 'Z'; ++c)
        {
            if (c != 'Q' && place[c - 'A'] == -1)
            {
                table[pos / 5][pos % 5] = c;
                place[c - 'A'] = pos;

                ++pos;
            }
        }

        // for (int y = 0; y <= 4; ++y)
        // {
        //     for (int x = 0; x <= 4; ++x)
        //     {
        //         if (x > 0)
        //         {
        //             fout << ' ';
        //         }
        //         fout << table[y][x];
        //     }
        //     fout << '\n';
        // }
        // fout << '\n';

        int i = 0;
        while (i <= size1 - 1)
        {
            char a = '-', b = '-';
            if (i == size1 - 1)
            {
                a = text[i];
                b = 'X';
            }
            else if (text[i] == text[i + 1])
            {
                a = text[i];
                b = 'X';
                --i;
            }
            else
            {
                a = text[i];
                b = text[i + 1];
            }

            int pos1 = place[a - 'A'], pos2 = place[b - 'A'], newPos1 = 0, newPos2 = 0;
            if (pos1 / 5 == pos2 / 5)
            {
                newPos1 = pos1 + 1, newPos2 = pos2 + 1;
                if (pos1 / 5 != newPos1 / 5)
                {
                    newPos1 -= 5;
                }
                if (pos2 / 5 != newPos2 / 5)
                {
                    newPos2 -= 5;
                }
            }
            else if (pos1 % 5 == pos2 % 5)
            {
                newPos1 = pos1 + 5, newPos2 = pos2 + 5;
                if (newPos1 > 24)
                {
                    newPos1 -= 25;
                }
                if (newPos2 > 24)
                {
                    newPos2 -= 25;
                }
            }
            else
            {
                int move = pos1 % 5 - pos2 % 5;
                newPos1 = pos1 - move;
                newPos2 = pos2 + move;
            }

            fout << table[newPos1 / 5][newPos1 % 5] << table[newPos2 / 5][newPos2 % 5];

            i += 2;
        }
        fout << '\n';
    }

    return 0;
}