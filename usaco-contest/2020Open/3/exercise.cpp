#include <bits/stdc++.h>

using namespace std;

ifstream fin("exercise.in");
ofstream fout("exercise.out");

int main()
{
    int N,M;
    fin >> N >> M;
    int ans=0;
    for (int i = 1; i <= N+1 ; ++i)
        ans+=i;
        
    fout << ans % M << "\n";
    return 0;
}
