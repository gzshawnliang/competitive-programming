#include <bits/stdc++.h>

using namespace std;

//ifstream fin("DigitPrime.in");
//ofstream fout("DigitPrime.out");

int main()
{
    ios_base::sync_with_stdio(false);std::cin.tie(nullptr); std::cout.tie(nullptr);
#ifdef LOCAL_DEBUG
    freopen("DigitPrime.in", "r", stdin);
    freopen("DigitPrime.out", "w", stdout);
#endif
    
    int n;cin>>n;
    vector<int> IsPrime(1500000,1);
    IsPrime[0]=0;
    IsPrime[1]=0;
    for(int i=2;i<3880;++i)
    {
        int temp=i;
        int product=i;
        while(true)
        {
            if(temp*product>1500000) break;
            IsPrime[temp*product]=0;
            ++product;
        }
    }
    // for(int i=0;i<1000001;++i)
    // {
    //     if(IsPrime[i]) cout<<i<<'\n';
    // }
    vector<int> IsDigitPrime(1000001,0);
    for(int i=2;i<=1000000;++i)
    {
        if(IsPrime[i])
        {
            string temp=to_string(i);
            int tempSum=0;
            for(int j=0;j<temp.size();++j)
            {
                tempSum+=temp[j]-48;
            }
            if(IsPrime[tempSum])
            {
                IsDigitPrime[i]=IsDigitPrime[i-1]+1;
            }
            else{
                IsDigitPrime[i]=IsDigitPrime[i-1];
            }
        }
        else{
            IsDigitPrime[i]=IsDigitPrime[i-1];
        }
    }
    for(int t=0;t<n;++t)
    {
        int a,b;cin>>a>>b;
        int ans=IsDigitPrime[b]-IsDigitPrime[a]+1;
        if(IsDigitPrime[a]==IsDigitPrime[a-1]) ans--;
        cout<<ans<<'\n';
    }
    return 0;
}
