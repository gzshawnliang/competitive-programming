#include <bits/stdc++.h>

using namespace std;

//ifstream fin("CF_631D_Messenger.in");
//ofstream fout("CF_631D_Messenger.out");

using ull = unsigned long long;
const ull base = 277;           //质数

struct ch
{
    int num;
    char c;
    ull hash;
};


int main()
{
    ios_base::sync_with_stdio(false);       
    std::cin.tie(NULL);


    // stringstream ss;
    // ss << "12345-abc";
    // string temp1, temp2;
    // getline(ss, temp1, '-');        //以'-'为分隔符，将数字提取出来
    // getline(ss, temp2, '-');        //以'-'为分隔符，将字母提取出来


    #ifndef ONLINE_JUDGE
        freopen("CF_631D_Messenger.in", "r", stdin);
        freopen("CF_631D_Messenger.out", "w", stdout);
    #endif    

    int n,m;
    cin>>n>>m;
    vector<ch> T;
    vector<ch> S;
    for (int i = 0; i <= n - 1; ++i)
    {
        string temp1;
        cin >> temp1;

        stringstream ss;
        ss << temp1;
        
        string temp2;
        string letter;
        getline(ss, temp2, '-');        //以'-'为分隔符，将数字提取出来
        getline(ss, letter, '-');        //以'-'为分隔符，将字母提取出来

        ch curr{stoi(temp2),letter[0],0};

        if(!T.empty())
        {
            if(T.back().c==letter[0])
            {
                T.back().num +=stoi(temp2);
                continue;
            }

        }
        T.push_back(curr);
        //cerr << num << "-" <<letter<< "\n";
    }
    int size1=T.size();
    vector<ull> hastT(size1,0);
    for (int i = 0; i <= n - 1; ++i)
    {
        hastT[i] = T[i].c * base + T[i].num;
    }


    // cerr << "\n";
    for (int i = 0; i <= m - 1; ++i)
    {
        string temp1;
        cin >> temp1;

        stringstream ss;
        ss << temp1;
        
        string temp2;
        string letter;
        getline(ss, temp2, '-');        //以'-'为分隔符，将数字提取出来
        getline(ss, letter, '-');        //以'-'为分隔符，将字母提取出来

        ch curr{stoi(temp2),letter[0],0};

        if(!S.empty())
        {
            if(S.back().c==letter[0])
            {
                S.back().num +=stoi(temp2);
                continue;
            }

        }
        S.push_back(curr);

    }    

    int size2=S.size();
    vector<ull> hastS(size2,0);
    for (int i = 0; i <= n - 1; ++i)
    {
        hastS[i] = S[i].c * base + S[i].num;
    }

    // stringstream ss;
    // ss << "12345-abc";
    // string temp1, temp2;
    // getline(ss, temp1, '-');        //以'-'为分隔符，将数字提取出来
    // getline(ss, temp2, '-');        //以'-'为分隔符，将字母提取出来


    cout.flush();
    return 0;
}
