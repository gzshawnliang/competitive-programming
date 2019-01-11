
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<string>
using namespace std;
const int maxn = 20;
char vis[maxn][maxn],str[maxn];
int book[maxn][maxn],used[maxn][maxn];
int n,m;
int k[4][2]={0,1,0,-1,1,0,-1,0};
string ans;
struct node{
	int x,y;
};
int find(int x,int y)
{
	if(x < 0||x >n-1||y<0||y>m-1)
		return 0;
	return 1;
}
int Judge(int x,int y)//查找能够到达的所有数字 
{
	int i,j,count,nx,ny;
	struct node nowq,nextq;
	queue<node>q;
	for(i = 0; i < n; i ++)
		for(j = 0; j < m; j ++)
			used[i][j] = book[i][j]; 
	count = 0;
	nowq.x = x;
	nowq.y = y;
	q.push(nowq);
	while(!q.empty())
	{
		nowq = q.front();
		q.pop();
		for(i = 0; i < 4; i ++)
		{
			nx = nowq.x + k[i][0];
			ny = nowq.y + k[i][1];
			if(find(nx,ny)&&!used[nx][ny]&&vis[nx][ny]!='#')
			{   
                count++;
				str[count] = vis[nx][ny];
				used[nx][ny] = 1;
				nextq.x = nx;
				nextq.y = ny;
				q.push(nextq);
			}
		}
	}
	str[count] = '\0';
	return count;
}
void dfs(int x,int y,string s)
{
	int nx,ny,i,j,length;
	length = Judge(x,y);
	if(s.length() > ans.length()||(s.length() == ans.length()&&s > ans))
		ans = s;//当前数字长度大于最优值or长度相等字典序更大时，更新最优值 
	if(length + s.length() < ans.length())
		return ;//如果当前长度+能够到达数字的长度小于最优长度，则剪枝 
	else if(length+s.length() == ans.length())//如果相等，则比较字典序 
	{
		sort(str,str+length);//将能够到达的值按升序排列 
		string ss = s;
		for(i = length-1; i >= 0; i --)
			ss += str[i];
		if(ss < ans)//如果字典序小于最优值，则剪枝 
			return;
	}
	for(i = 0; i < 4; i ++)
	{
		nx = x + k[i][0];
		ny = y + k[i][1];
		if(find(nx,ny)&&!book[nx][ny]&&vis[nx][ny]!='#')
		{
			book[nx][ny] = 1;
			dfs(nx,ny,s+vis[nx][ny]);
			book[nx][ny] = 0;
		}
	}

	return;
}
void Count()
{
	int i,j;
	string s;
	ans.clear();
	for(i = 0; i < n; i ++)
		for(j = 0; j < m; j ++)
			if(vis[i][j]!='#')
			{
				memset(book,0,sizeof(book));
				book[i][j] = 1;
				s.clear();
				dfs(i,j,s +vis[i][j]);
			}
	return;
}
int main()
{
    freopen("biggestNumber.in", "r", stdin);      
    freopen("biggestNumber.out", "w", stdout);   
	int i;
	while(scanf("%d%d",&n,&m),n!=0||m!=0)
	{
		for(i = 0; i < n; i ++)
			scanf("%s",vis[i]);
		Count();
		cout<<ans<<endl;
	}
	return 0;
}


// 7 4
// #738
// 4739
// 5124
// 2224
// 625#
// 3661
// 5479
// 0 0

// 98377451226354791662524423


// 3 4
// #73#
// #4##
// #12#
// 0 0