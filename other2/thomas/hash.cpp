#include <bits/stdc++.h>

using namespace std;

//ifstream fin("hash.in");
//ofstream fout("hash.out");

int hashCode(int x) {return x % 5;}

int hashCode2(const string & x, int prime)
{
    int hashValue = 0;
    for (auto i : x)
        hashValue += i;
    return hashValue % prime;
}

unsigned long long hashCode3(const string  & x)
{
    int len=x.length();
    unsigned long long ans=0,p=1;
    for(int i=0;i<=len-1;++i)
    {
        ans=ans*p+x[i];
        p*=13331;
    }
    return ans;
}

int main()
{
    // cout << hashCode(13) << '\n';
    // cout << hashCode(7) << '\n';
    // cout << hashCode(14) << '\n';
    // cout << hashCode(11) << '\n';

    // cout << "----------------" << "\n";
    // cout << hashCode2("abc",11) << '\n';
    // cout << hashCode2("abe",11) << '\n';
    // cout << hashCode2("abg",11) << '\n';
    // cout << hashCode2("gbc",11) << '\n';
    // cout << "----------------" << "\n";
    
    // std::hash<string> h;
    // cout << h("abe") % 99923<<'\n';
    // cout << h("abc")  % 99923<<'\n';
    
    // cout << h("Meet the new boss...") %99923 <<'\n';
    // cout << "----------------" << "\n";

    // std::hash<int> h2;
    // cout << h2(100) %991 <<'\n';
    // cout << h2(99) <<'\n';
    
    // cout << h2(832487234) <<'\n';

    cout << "----------------" << "\n";
    cout << hashCode3("a") << '\n';
    cout << hashCode3("b") << '\n';
    cout << hashCode3("ab") << '\n';
    cout << "----------------" << "\n";    

    return 0;
}
