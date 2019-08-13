#include <bits/stdc++.h>

using namespace std;

//ifstream fin("LCS.in");
//ofstream fout("LCS.out");

int max_of_three(int a, int b, int c)
{
    return max(a, max(b, c));
}

int LISRecursion(string & word1, string & word2, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return 0;
    }
    else if (word1[i-1] == word2[j-1])
    {
        return LISRecursion(word1, word2, i - 1, j - 1) + 1;
    }
    else
    {

        return max(LISRecursion(word1, word2, i - 1, j),
                   LISRecursion(word1, word2, i, j - 1));
    }
}

int main()
{
    string x = "ABCDEF";
    string y = "DXBCEK";
    cout << setw(4) << "X:" << x << '\n';
    cout << setw(4) << "Y:" << y << '\n';
    cout << setw(4) << "LCS:" << LISRecursion(x, y, x.length(), y.length()) << '\n';

    return 0;
}
