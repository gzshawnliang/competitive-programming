#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

ifstream fin("simpleEquations.in");
ofstream fout("simpleEquations.out");

void solve()
{
    int times = 0;
    fin >> times;
    for (int i = 1; i <= times; ++i)
    {
        int A, B, C;
        bool ok = false;
        fin >> A >> B >> C;
        for (int x = -100; x <= 100 && ok == false; ++x)
        {
            for (int y = x + 1; y <= 100 && ok == false; ++y)
            {
                int z = A - x - y;
                if (x == y || x == z || y == z)
                {
                    continue;
                }
                else if (x * y * z == B && x * x + y * y + z * z == C)
                {
                    fout << x << " " << y << " " << z << '\n';
                    ok = true;
                    break;
                }
            }
        }

        if (ok == false)
        {
            fout << "No solution.\n"; 
        }
    }

}

int main()
{
    solve();

    return 0;
}