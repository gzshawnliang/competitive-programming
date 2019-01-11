#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

ifstream fin("randomTest.in");
ofstream fout("randomTest.out");

int _rand(int a, int b)
{
    return (rand() * (b / 32767 + 1)) % (b - a + 1) + a;
}

int main()
{
    srand(time(NULL));

    for (int i = 0; i <= 1000 - 1; ++i)
    {
        if (i % 50 == 0 && i > 0) fout << '\n';

        char t = _rand(' ', '~');
        fout << t;
    }
    fout << '\n';

    return 0;
}