
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

typedef pair<long long, long long> p;

ifstream fin("rental.in");
ofstream fout("rental.out");

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("rental.in", "r", stdin);
    //     freopen("rental.out", "w", stdout);
    // #endif
    long long n, m, r;
    fin >> n >> m >> r;
    vector<long long> milk;
    for (long long i = 0; i < n; ++i)
    {
        long long temp;
        fin >> temp;
        milk.push_back(temp);
    }
    vector<p> sell;
    for (long long i = 0; i < m; ++i)
    {
        long long temp, t2;
        fin >> temp >> t2;
        sell.push_back({t2, temp});
    }
    vector<long long> rent;
    for (long long i = 0; i < r; ++i)
    {
        long long temp;
        fin >> temp;
        rent.push_back(temp);
    }
    sort(milk.begin(), milk.end(), greater<long long>());
    sort(sell.begin(), sell.end(), greater<p>());
    sort(rent.begin(), rent.end(), greater<long long>());
    long long CS = 0, CR = 0, CRC = n - 1, i = 0, cows = n, lefts = sell[CS].second, TP = 0;
    bool RentService = true;
    bool SellService = true;
    while (cows > 0)
    {
        long long temp = 0, CP = 0;
        temp = milk[i] - lefts;
        bool rentout = false,outlimit=false;
        if (SellService == false && RentService == false)
        {
            break;
        }
        else
        {
            if (temp > 0)
            {
                if (SellService == true)
                {
                    CP += lefts * (sell[CS].first);
                    long long tcs = CS;
                    while (true)
                    {
                        ++CS;
                        if (CS >= m)
                        {
                            SellService = false;
                            outlimit=true;
                            break;
                        }
                        lefts = sell[CS].second;
                        if (lefts < temp)
                        {
                            CP += lefts * (sell[CS].first);
                            temp -= lefts;
                        }
                        else
                        {
                            CP += temp * (sell[CS].first);
                            lefts = lefts - temp;
                            if (lefts == 0)
                            {
                                ++CS;
                                if (CS >= m)
                                {
                                    SellService = false;
                                    break;
                                }
                                lefts = sell[CS].second;
                            }
                            break;
                        }
                    }
                    if (RentService == true)
                    {
                        if (CP < rent[CR])
                        {
                            CP = rent[CR];
                            ++CR;
                            rentout = true;
                            if (CR >= r)
                            {
                                RentService = false;
                            }
                            CS = tcs;
                            SellService = true;
                            if(outlimit==false)
                            {
                                lefts = sell[tcs].second;
                            }
                        }
                    }
                }
                else
                {
                    CP = rent[CR];
                    ++CR;
                    rentout = true;
                    if (CR >= r)
                    {
                        RentService = false;
                    }
                }
                if (rentout == false)
                {
                    ++i;
                }
                --cows;
            }
            else if (temp < 0)
            {
                temp = milk[i];
                if (SellService == true)
                {
                    CP = temp * sell[CS].first;
                    lefts -= temp;
                    if (RentService == true)
                    {
                        if (CP < rent[CR])
                        {
                            lefts += temp;
                            CP = rent[CR];
                            ++CR;
                            rentout = true;
                            if (CR >= r)
                            {
                                RentService = false;
                            }
                        }
                    }
                }
                else
                {
                    CP = rent[CR];
                    ++CR;
                    rentout = true;
                    if (CR >= r)
                    {
                        RentService = false;
                    }
                }
                if (rentout == false)
                {
                    ++i;
                }
                --cows;
            }
            else
            {
                temp = lefts;
                if (SellService == true)
                {
                    CP = temp * sell[CS].first;
                    if (RentService == true)
                    {
                        if (CP < rent[CR])
                        {
                            CP = rent[CR];
                            ++CR;
                            ++i;
                            if (CR >= r)
                            {
                                RentService = false;
                            }
                        }
                        else
                        {
                            ++CS;
                            if (CS >= m)
                            {
                                SellService = false;
                            }
                            else
                            {
                                lefts = sell[CS].second;
                            }
                        }
                    }
                }
                else
                {
                    CP = rent[CR];
                    ++CR;
                    ++i;
                    if (CR >= r)
                    {
                        RentService = false;
                    }
                }
                if (rentout == false)
                {
                    ++i;
                }
                --cows;
            }
        }
        TP += CP;
    }
    fout << TP << '\n';
    return 0;
}