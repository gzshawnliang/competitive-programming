#include <bits/stdc++.h>

using namespace std;

//ifstream fin("1.in");
//ofstream fout("1.out");

class a
{
    public:
    int b;
    int c;

};

class b:a{

    public:
    int d;
};

int main()
{
    
    a testa;
    testa.b=123;
    testa.c=456;

    b testb=(b)testa;
    
    testb.b=345;
    
    return 0;
}
