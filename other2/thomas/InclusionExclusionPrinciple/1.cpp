#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

const int N = 5;    // 元素數量


 
void print(int comb)
{
    cout << '{';
    for (int i=0; i<N; ++i)
        if (comb & (1 << i))
            cout << 1;
        else
            cout << 0;
    cout << '}' << '\n';
}

void inclusion_exclusion_principle(int N)
{
    for (ull comb = 0; comb < (1ULL<<N); ++comb)
    {
        int c = 0;  // size of set
        for (int i=0; i<N; ++i)
            if (comb & (1 << i))
                c++;
 
        if (c & 1) cout << "-\n";
        else cout << "+\n";
    }
}

int main()
{
    print(5);

    //inclusion_exclusion_principle(5);  

    // for (int i=0; i<(1<<N); ++i)
    //     inclusion_exclusion_principle(i);    

    //cout << (1ULL<<32) << "\n";
    
    return 0;
}
