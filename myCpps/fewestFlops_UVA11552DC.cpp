#include <bits/stdc++.h>

using namespace std;

ofstream fout("fewestFlops_UVA11552.in");

int getRand(int a, int b)
{
    int c = b - a + 1;
    return rand() % c + a;
}

int main()
{
    //string alphabets = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphabets = "abcdefghijklmnopqrstuvwxyz";
    int ac = alphabets.size();

    int tcc = 1000, maxN = 10;
    fout << tcc << '\n';

    for (int t = 1; t <= tcc; ++t)
    {
        int k = getRand(2, 5);

        string ans = "";
        int n = getRand(1, maxN / k) * k;
        for (int c = 1; c <= n; ++c)
        {
            ans.push_back(alphabets[getRand(0, ac - 1)]);
        }

        fout << k << ' ' << ans << '\n';
    }

    return 0;
}
