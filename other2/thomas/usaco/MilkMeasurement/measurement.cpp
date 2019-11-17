#include <bits/stdc++.h>

using namespace std;

ifstream fin("measurement.in");
ofstream fout("measurement.out");

struct measurement
{
    int day;
    int id;
    int change;
};

bool isEqual(set<int> & topSetBefore,set<int> & topSetAfter)
{
    if(topSetBefore.size() != topSetAfter.size())
    {
        return false;
    }
    else
    {
        auto it1=topSetBefore.begin();
        auto it2=topSetAfter.begin();
        while (it1!=topSetBefore.end())
        {
            if((*it1) !=(*it2))
                return false;

            ++it1;
            ++it2;
        }
    }
    return true;
}

int main()
{
    int N,G;
    fin >> N>>G;
    vector<measurement> a(N);
    for (int i = 0; i <= N - 1; ++i)
    {
        fin >> a[i].day >> a[i].id >>a[i].change;        
    }

    sort(a.begin(), a.end(), [](const measurement & x, const measurement & y) 
    {
        return x.day < y.day;
    });

    map<int,int> cowMp;
    map<int,set<int>,greater<int>> topMp;

    int ans=0;

    for (int i = 0; i <= N - 1; ++i)
    {
        int id =a[i].id;
        int beforeMilk=0;

        set<int> topSetBefore;
        set<int> topSetAfter;

        if(!topMp.empty())
            topSetBefore= topMp.begin()->second; 

        if(cowMp.count(id)==0)
        {
            cowMp[id] = G + a[i].change;
        }
        else
        {
            beforeMilk =cowMp[id];
            cowMp[id] +=a[i].change;
        }

        int currMilk=cowMp[id];
        topMp[currMilk].insert(id);

        if(topMp.count(beforeMilk))
        {
            if(topMp[beforeMilk].count(id)==1)
                topMp[beforeMilk].erase(id);

            if(topMp[beforeMilk].empty())
            {
                topMp.erase(beforeMilk);
            }       
        }

        topSetAfter = topMp.begin()->second; 

        if(isEqual(topSetBefore,topSetAfter)==false)
        {
            ++ans;
        }
        
    }    
    fout << ans << "\n";    

    return 0;
}
