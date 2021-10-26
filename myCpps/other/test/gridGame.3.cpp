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

int main()
{
    freopen("gridGame.3.in", "r", stdin);
    freopen("gridGame.3.out", "w", stdout);    
	int t;
	cin>>t;
	while (t--)
	{
		int ans=-INT_MAX;
        int size;
		cin>>size;
        vector< vector<int> > girdData(size, vector<int>(size));
        vector<int> seq;
        vector<int> rowSeqAlice;
        for (int i = 0; i <= size - 1; ++i)
        {
            seq.push_back(i);
            rowSeqAlice.push_back(i);
            for (int j = 0; j <= size - 1; ++j)
            {
                cin >>girdData[i][j];
            }
        }
		int minSum=INT_MAX;

        vector<int> colSeqBob;

        //找出能使Alice获得最小candy的列排列
		do
		{
			int sum=0;
			for (int i=0;i<=size-1;++i)
			{
				sum+=girdData[i][seq[i]];
			}
			if(sum<minSum)
            {
				minSum=sum;
                colSeqBob=seq;
			}
		} while (next_permutation(seq.begin(),seq.end()));

		do
		{
			int sum=0;
			for (int i=0;i<=size-1;++i)
			{
                int row=rowSeqAlice[i];
                int col=colSeqBob[row];

                //对于Alice选择的每一种行排列,Bob选择能使Alice获利最小的那一列
				sum+=girdData[row][col];
			}

			if(sum>ans)
            {
                ans=sum;
            }
		} while (next_permutation(rowSeqAlice.begin(),rowSeqAlice.end()));
		cout<< ans << '\n';
	}
	return 0;
}