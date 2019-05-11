#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;

    if (n < 10)
    {
        cout << 9 << '\n';
        return 0;
    }

    while (n >= 10)
    {
        ++n;
        ans++;

        while (n % 10 == 0)
        {
            n = n / 10;
        }
        if (n < 10)
        {
            ans += 9;
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}
