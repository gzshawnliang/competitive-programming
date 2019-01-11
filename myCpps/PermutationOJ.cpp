#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int total;
    cin >> total;
    while (total--)
    {
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        bool ok = false;
        do
        {
            cout << str << '\n';
        } while (next_permutation(str.begin(), str.end()) && ok == false);
        cout << '\n';
    }

    cout.flush();

    return 0;
}