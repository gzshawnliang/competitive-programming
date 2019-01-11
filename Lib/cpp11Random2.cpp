#include "MyRandom.h"

int main()
{
    random random22;

    int TestCase=11;
    while(TestCase--)
    {
        cout<< random22.GetRand(100,99999) <<"\n";
    }

    cout<< "---------------\n";

    TestCase=11;
    random rand3(1,100);
    while(TestCase--)
    {
        cout<< rand3.GetRand() <<"\n";
    }
    cout<< "---------------\n";
    vector<int> v = random22.GetUniqueRand(1,100);
    for (int i = 0; i <= v.size()-1; ++i)
    {
        cout<< v[i] <<"\n";
    }

    return 0;
}
