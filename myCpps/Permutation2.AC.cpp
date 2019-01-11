/**
 * Tittle:	10063 - Knuth's Permutation
 * Author:	Cheng-Shih, Wong
 * Date:	2015/03/14
 * File:	10063 - Knuths Permuation.cpp - solve it
 */

// include files
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>


using namespace std;

// definitions
#define FOR(i, a, b) for (int i = (a), _n = (b); i <= _n; ++i)
#define clr(x, v) memset(x, v, sizeof(x))

// declarations
string str;

// functions
void dfs(const string &s, const int l)
{
    if (l == str.size())
        cout << s << endl;
    else
    {
        FOR(i, 0, s.size())
        dfs(s.substr(0, i) + str[l] + s.substr(i), l + 1);
    }
}

// main function
int main()
{
    freopen("Permutation2.in", "r", stdin);
    freopen("Permutation3.out", "w", stdout);

    bool nl = false;
    // input
    while (cin >> str)
    {

        // solve & output
        if (nl)
            putchar('\n');
        else
            nl = true;

        dfs("", 0);
    }

	//F11
	fclose(stdin);
	fclose(stdout);

    return 0;
}