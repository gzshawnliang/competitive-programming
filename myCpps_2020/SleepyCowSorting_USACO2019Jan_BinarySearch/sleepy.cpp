#include <bits/stdc++.h>

using namespace std;

ifstream fin("sleepy.in");
ofstream fout("sleepy.out");

int main()
{
    int n; fin >> n;

    vector<int> a(n);
    for (int i = 0; i <= n - 1; ++i)
    {
        fin >> a[i];
    }

    int incCount = 1;
    vector<int> backA = {a.back()};
    for (int i = n - 2; i >= 0 && a[i] < a[i + 1]; --i)
    {
        backA.push_back(a[i]);
        ++incCount;
    }
    reverse(backA.begin(), backA.end());

    fout << n - incCount << '\n';
    for (int i = 0; i <= n - 1 - incCount; ++i)
    {
        int now = a[i];

        auto pos = lower_bound(backA.begin(), backA.end(), now);
        
        if (i > 0) fout << ' ';
        fout << (pos - backA.begin()) + n - incCount - i - 1;

        backA.insert(pos, now);
    }
    fout << '\n';

    return 0;
}
