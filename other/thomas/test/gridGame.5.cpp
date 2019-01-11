#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <cmath>
#include <string>
#include <vector>
using namespace std;  

long long total = 0;  
long long skipCount = 0; 
  
void cinData(vector< vector<int> > & girdData)
{
    int size=  girdData.size();

    for (int i = 0; i <= size - 1; ++i)
    {
        for (int j = 0; j <= size - 1; ++j)
        {
            cin >>girdData[i][j];
        }
    }
}  
  
void calculate(vector< vector<int> > & girdData,vector< vector<bool> > & visitedData,int & ansFinally,int rowCurr,int sumCurr)
{
    ++total;

    int n=girdData.size();  

    //�����б������
    if(rowCurr >=n)
	{  
        if(sumCurr<ansFinally) 
		{
			ansFinally=sumCurr;  
		}
		
        return;  
    }  

    for(int col=0;col<=n-1;++col)
	{  
        if(visitedData[rowCurr][col]==false)
		{  
            for(int i=rowCurr;i<=n-1;++i)
			{
				visitedData[i][col]=true;  
			} 
			
            int newSum = sumCurr + girdData[rowCurr][col];

            //������һ��
            calculate(girdData,visitedData, ansFinally,rowCurr+1,newSum);

            for(int i=rowCurr;i<=n-1;++i) 
			{
                visitedData[i][col]=false;  
			}
        }  
        else
        {
            ++skipCount;
        }
    }  
}  
  
void solve()
{
    int t;
    cin>>t;  
    while(t--)
	{
        int n;
        cin >>n;

        //��������
        vector< vector<int> > girdData(n, vector<int>(n));

        //���ʹ������ݣ�falseû���ʣ�true�ѷ���
        vector< vector<bool> > visitedData(n, vector<bool>(n,false));    

        int ans=20000000;

        //��������        
        cinData(girdData);  

        //��ʼ���㣬�ӵ�0�п�ʼ����
        calculate(girdData,visitedData,ans,0,0);  

        cout<<ans<< "   loops : " << total << "   skip : " << skipCount <<'\n';          

    } 
}

int main()
{  
    freopen("gridGame.3.in", "r", stdin);
    freopen("gridGame.3.out", "w", stdout);	
    solve();
    return 0;  
}  