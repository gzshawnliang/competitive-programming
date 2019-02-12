#include <bits/stdc++.h>

using namespace std;


const int maxP = 300;

bool dp[150][1001][15];

bool compare(int x, int y)
{
    stringstream ss1;
    stringstream ss2;
    ss1 << x;
    ss2 << y;
    return ss1.str() < ss2.str();
}

bool solve(int i, int s, int c, int x, int t, vector<int> & path, vector<int> & primes)
{
    int sizeP = primes.size();

    if (i == primes.size())
    {
        return false;
    }
    else if (c == t)
    {
        if (s == x)
        {
            return true;
        }
        return false;
    }
    else if (s >= x)
    {
        return false;
    }
    else if (dp[i][s][c] == false)
    {
        return false;
    }

    path[c] = primes[i];
    if (solve(i + 1, s + primes[i], c + 1, x, t, path, primes) == true)
    {
        return true;
    }
    else if (solve(i + 1, s, c, x, t, path, primes) == true)
    {
        return true;
    }

    dp[i][s][c] = false;
    return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    vector<bool> isPrime(maxP + 1, true);
    isPrime[0] = false, isPrime[1] = false;
    vector<int> primes;

    for (int i = 2; i <= maxP; ++i)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j <= maxP; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    primes.push_back(2);
    for (int x = 3; x <= 300; ++x)
    {
        if (isPrime[x] == true)
        {
            for (int c = 1; c <= 2; ++c)
            {
                primes.push_back(x);
            }
        }
    }

    sort(primes.begin(), primes.end(), compare);

    int _case = 0, sizeP = primes.size();

    while (true)
    {
        int x = 0, t = 0;
        cin >> x >> t;
        if (x + t == 0)
            break;
        ++_case;

        cout << "CASE " << _case << ":\n";

        vector<int> path(t);

        memset(dp, true, sizeof(dp));

        bool ans = solve(0, 0, 0, x, t, path, primes);

        if (ans == false)
        {
            cout << "No Solution.\n";
        }
        else
        {
            for (int i = 0; i <= t - 1; ++i)
            {
                if (i > 0)
                    cout << '+';
                cout << path[i];
            }
            cout << '\n';
        }
    }

   	cout.flush();
   	return 0;
}

