#include <bits/stdc++.h>

using namespace std;

//ifstream fin("1.in");
//ofstream fout("1.out");
const int inf =INT_MAX /2;

int main()
{


    //vector<pair<int,int>> a={{1,5},{3,6},{2,4},{4,6},{4,7},{2,9}};
    vector<pair<int,int>> a={{2,9},{3,6}};
    sort(a.begin(),a.end());
    int l=1;
    int r=6;
    auto pos1=lower_bound(a.begin(),a.end(),make_pair(l,0));
    auto pos2 = upper_bound(pos1, a.end(), make_pair(0, r),
                            [](pair<int, int> a, pair<int, int> b) -> bool
                             { 
                                 return a.second < b.second; 
                             });

    cout << pos2-pos1 << "\n";
    return 0;
}

