#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <vector>
//#include <windows.h>

using namespace std;

vector<int> answer;
void caculate(vector<int> & T,int sum,int & MaxSum,int limit,int pos)
{
    for(int i=pos;i<T.size();++i)
    {
        if(sum+T[i]<=limit && T[i]!=0)
        {
            vector<int> temp=T;
            int Tsum=sum;
            temp[i]=0;
            Tsum+=T[i];
            caculate(temp,Tsum,MaxSum,limit,i+1);
        }
        else
        {
            continue;
        }
    }
    if (sum > MaxSum)
    {
        MaxSum = sum;
        answer=T;
        return;
    }
}

int main()
{
    ifstream cin("CD.in");
    ofstream cout("CD.out");
    while(true)
    {
        int tape=0;
        cin>>tape;
        if(tape==0)
        {
            break;
        }
        int NT,total=0;
        cin>>NT;
        vector<int> tracks(NT);
        answer.clear();
        for(int i=1;i<=NT;++i)
        {
            int temp;
            cin>>temp;
            tracks[i-1]=temp;
            total+=temp;
        }
        if(total<=NT)
        {
            for(int i=0;i<tracks.size();++i)
            {
                cout<<tracks[i]<<" ";
            }
            cout<<"sum:"<<total<<'\n';
            continue;
        }
        else
        {
            total=0;
        }
        caculate(tracks,0,total,tape,0);
        for(int i=0;i<answer.size();++i)
        {
            if(answer[i]==0)
            {
                cout<<tracks[i]<<" ";
            }
        }
        cout<<"sum:"<<total<<'\n';
    }
    //system("pause");
    return 0;
}