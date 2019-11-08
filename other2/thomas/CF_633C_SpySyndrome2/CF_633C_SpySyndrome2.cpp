#include <bits/stdc++.h>

using namespace std;
using ull=unsigned long long;

const ull R1 = 3;                       //质数
const ull PRIME = 100000000743856857ull; 

ull hashCode(const string & s)
{
    int len = s.length();
    ull hashValue = 0;
    for (int i = 0; i <= len - 1; ++i)
        hashValue = (R1 * hashValue + (s[i] - 'a' + 1)) % PRIME;

    return hashValue;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("CF_633C_SpySyndrome2.in", "r", stdin);
        //freopen("CF_182D_CommonDivisors.out", "w", stdout);
    #endif

    int n;
    cin >>n;

    string t;
    cin >> t;
    reverse(t.begin(),t.end());
    
    int m;
    cin>>m;
    unordered_map<ull,string> wordHashMap;


    vector<string> ans;
    for (int i = 0; i <= m - 1; ++i)
    {
        string w;
        cin >> w;
        string w2=w;
        transform(w2.begin(), w2.end(), w2.begin(), ::tolower);
        wordHashMap[hashCode(w2)]=w;
        
    }

    int i = 0;
    while (i <= n - 1)
    {
        ull hashValue = 0;
        bool found=false;
        for (int j = i; j <= n - 1; ++j)
        {
            hashValue = (R1 * hashValue + (t[j] - 'a' + 1)) % PRIME;        
            if(j!=i && wordHashMap.count(hashValue)==1)
            {
                ans.push_back(wordHashMap[hashValue]);
                i=j+1;
                found=true;
                break;
            }
        }
        if(!found)
            ++i;
    }
    
    reverse(ans.begin(),ans.end());
    i=0;
    for(auto a:ans)
    {
        if(i==0)
            cout << a;
        else 
            cout << " " << a;            
        ++i;
    }
        

    return 0;
}
