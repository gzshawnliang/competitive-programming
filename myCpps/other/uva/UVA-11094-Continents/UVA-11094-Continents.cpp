#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
 
using namespace std;

class sln
{ 
    private:
    
    
    int dxy[4][2] = {0,1,1,0,-1,0,0,-1};

    public:
    char maps[22][22];
    int dfs(int x, int y, int m, int n, char c)
    {
        if (x < 0 || x >= m) return 0;
        if (maps[x][y] != c) return 0;
        maps[x][y] = 0;
        int sum = 1;
        for (int i = 0; i < 4; ++ i)
            sum += dfs(x+dxy[i][0], (y+n+dxy[i][1])%n, m, n, c);
        return sum;
    }
};

int main()
{
	int m,n,x,y;
    
    while (cin >> m >> n) {
        sln sln1;
		for (int i = 0; i < m; ++ i)
			cin >> sln1.maps[i];
		cin >> x >> y;
		char ch =sln1.maps[x][y];
		int  Max = 0;
		sln1.dfs(x, y, m, n, ch);
		for (int i = 0; i < m; ++ i)
		for (int j = 0; j < n; ++ j)
			if (sln1.maps[i][j] == ch)
				Max = max(Max, sln1.dfs(i, j, m, n, ch));
		cout << Max << endl;
	}

    return 0;
}
