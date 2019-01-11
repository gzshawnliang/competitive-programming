#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool tect(vector<int> missile, int num, int last)
{
    int size = missile.size();
    for (int i = 0; i <= size - 1; ++i)
    {
        if (missile[i] <= last)
        {
            tect(missile, num - 1, missile[i]);
        }
        else
        {

        }
    }
}

int main()
{
    ifstream fin("missile.in");
    ofstream fout("missile.out");

    int length, num = 1;
    fin >> length;
    vector<int> missile(length);
    for (int i = 0; i <= length - 1; ++i)
    {
        fin >> missile[i];
    }

    while(true)
    {
        if (tect(missile, num, 100000) == true)
        {
            break;
        }
        ++num;
    }

    fout << num << endl;

    return 0;
}