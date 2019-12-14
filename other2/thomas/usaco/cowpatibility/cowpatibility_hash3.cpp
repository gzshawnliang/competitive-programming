#include <bits/stdc++.h>

using namespace std;

ifstream fin("cowpatibility.in");
ofstream fout("cowpatibility.out");

int main()
{
    int N;
    fin >>N;
    vector<unordered_set<int>> a(N+1);
    unordered_map<int,set<int>> b;

    for (int i = 1; i <= N; ++i)
    {
        int c=5;
        while (c--)
        {
            int temp;
            fin >> temp;
            a[i].insert(temp);
            b[temp].insert(i);
        }
    }
    set<pair<int,int>> c;
    for (auto it = b.begin(); it !=b.end(); ++it)
    {
        for (auto it2 = it->second.begin(); it2 !=it->second.end(); ++it2)
        {
            auto it3=it2;
            ++it3;
            for (; it3 !=it->second.end(); ++it3)
            {
                c.insert(make_pair(*it2,*it3));
            }
                
                       
        }
    }
    fout << N*(N-1)/2 - c.size() << "\n";
    return 0;
}
