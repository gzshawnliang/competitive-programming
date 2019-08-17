#include <bits/stdc++.h>

using namespace std;

//ifstream fin("hash.in");
//ofstream fout("hash.out");

int myhash(int x) {return x % 5;}

int myhash2(string x, int prime)
{
    int hashValue = 0;
    for (auto i : x)
        hashValue += i;
    return hashValue % prime;
}

int main()
{
    cout << myhash(13) << '\n';
    cout << myhash(7) << '\n';
    cout << myhash(14) << '\n';
    cout << myhash(11) << '\n';

    cout << "----------------" << "\n";
    cout << myhash2("abc",11) << '\n';
    cout << myhash2("abe",11) << '\n';
    cout << myhash2("abg",11) << '\n';
    cout << myhash2("gbc",11) << '\n';
    cout << "----------------" << "\n";
    
    std::hash<string> h;
    cout << h("abe") <<'\n';
    cout << h("abc") <<'\n';
    
    cout << h("Meet the new boss...") <<'\n';
    

    return 0;
}
