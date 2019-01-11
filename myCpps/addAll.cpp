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
    ifstream fin("addAll.in");
    ofstream fout("addAll.out");

    while (true)
    {
        int total, ans = 0;
        fin >> total;
        priority_queue<int, vector<int>, greater<int>> a;

        if (total == 0)
        {
            break;
        }

        for (int i = 1; i <= total; ++i)
        {
            int temp;
            fin >> temp;
            a.push(temp);
        }

        while (!(a.empty()))
        {
            int sum = a.top();
            //cout << sum << " + ";
            a.pop();
            if (a.empty() == true)
            {
                break;
            }
            sum += a.top();
            //cout << a.top() << " = ";
            a.pop();
            a.push(sum);
            ans += sum;
            //cout << sum << '\n';
        }

        fout << ans << endl;
    }

    return 0;
}