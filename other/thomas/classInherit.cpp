#include <bits/stdc++.h>

using namespace std;

//ifstream fin("1.in");
//ofstream fout("1.out");

class _a
{
    public:
    int a1;
    int a2;

    protected:
    int pp1;

};

class _k
{
    public:
    int k1;
    int k2;

};

class _b:_a,_k
{

    public:
    int b1;

    void ok()
    {
        
    }
};

int main()
{
    _a testa;
    testa.a2=123;
    testa.a2=456;

    _b testb;

    testb.b1=345;
    
    return 0;
}
