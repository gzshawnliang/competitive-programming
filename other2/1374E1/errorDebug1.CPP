#include <bits/stdc++.h>

using namespace std;

//ifstream fin("1.in");
//ofstream fout("1.out");

int main()
{
    vector<int> a={1,2,3,4,5,6,7};
    for (int i = 0,len=a.size(); i <= len-1; i++)
    {
        cout << a[i] << ",";
    }
    a[11]=100;
    cout << "\n";
    cout << a[11] << "";
    cout << "\n" <<a.at(10);

    return 0;
}
