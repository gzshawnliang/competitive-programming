#include<bits/stdc++.h>
using namespace std;
vector<int> con[100001];//邻接矩阵判断相邻关系
vector<int> son[100001];//son[1]代表1的儿子们分别有多少子树；
int n,sub[100001],cnt,c[100001];//sub数组表示子树的数量，cnt代表单个的数量（见judge函数），c数组见judge函数
void dfs(int so,int fa)//dfs求son[][]
{
	sub[so]=1;
	for(int i=0;i<con[so].size();i++)
		if(con[so][i]!=fa)
		{
			dfs(con[so][i],so);
			sub[so]+=sub[con[so][i]];
			son[so].push_back(sub[con[so][i]]);
		}
	if(sub[so]!=n)
		son[so].push_back(n-sub[so]);
}
bool judge(int k)
{
	if((n-1)%k!=0)//特判，如果不能整除，说明不能均分
		return 0;
	for(int i=1;i<=k;i++)//清0
		c[i]=0;
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		for(int l=0;l<son[i].size();l++)
		{
			int m=son[i][l]%k;
			if(m==0)
				continue;
			if(c[k-m])//如果可以配对，就配
			{
				c[k-m]--;
				cnt--;
			}
			else//如果不能配对，就留
			{
				c[m]++;
				cnt++;
			}
		}
		if(cnt)//如果有落单的说明不行
			return 0;
	}
	return 1;
}
int main()//主程序
{
    #ifdef LOCAL_DEBUG
        freopen("deleg.in", "r", stdin);
        //freopen("deleg.out", "w", stdout);
    #endif    
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		con[a].push_back(b);
		con[b].push_back(a);
	}
	dfs(1,0);
	for(int i=1;i<n;i++)
		cout<<judge(i);
	return 0;
}