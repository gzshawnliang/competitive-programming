#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, base[N];
vector<int> items[N];

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("dishes.in", "r", stdin);
        //freopen("dishes.out", "w", stdout);
    #endif

    cin >> n;

    int placed = 0, ans = n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        // impossible to add this plate
        if (x < placed)
        {
            ans = i;
            break;
        }
        // plates that go on this stack
        for (int j = x; j > 0 && !base[j]; j--)
        {
            base[j] = x;
        }
        // remove plates with smaller labels
        while (!items[base[x]].empty() && items[base[x]].back() < x)
        {
            placed = items[base[x]].back();
            items[base[x]].pop_back();
        }
        // add this plate to the stack
        items[base[x]].push_back(x);
    }

    cout << ans << endl;
}