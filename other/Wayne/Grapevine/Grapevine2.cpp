#include <cstdio>
using namespace std;

int N,M,Q,L,U;
int H[501][501];

int BS_1 (int i)            // 二分搜尋找出每列的符合>=L的最小值
{
    int left = 0, right = M-1, mid;
    while (left != right){
        mid = (left+right)/2;
        if (H[i][mid] >= L) right = mid;
        else left = mid+1;
    }
    return left;
}
int BS_2 (int l_y,int l_x)  // 二分搜尋找出右下斜角符合<=U的最大值
{
    int r_x = l_x+(N-1-l_y);      // r_x代表右下角的列index(橫), r_y為行index(直)
        if (r_x >= M) r_x = M-1;  // 避免越界
    int r_y = l_y+(r_x-l_x);
    int mid_x,mid_y;

    while (l_x != r_x){
        mid_x = (l_x+r_x+1)/2;
        mid_y = (l_y+r_y+1)/2;
        if (H[mid_y][mid_x] <= U){
            l_x = mid_x;
            l_y = mid_y;
        }
        else {
            r_x = mid_x-1;
            r_y = mid_y-1;
        }
    }
    return l_x;
}

int main()
{
 //   freopen ("input.txt","rt",stdin);
    freopen("Grapevine.in", "r", stdin);      
    freopen("Grapevine.out", "w", stdout);    
    while (scanf("%d%d",&N,&M))
    {
        if (!N && !M) break;
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                scanf("%d",&H[i][j]);
        scanf("%d",&Q);
        while (Q--)
        {
            scanf("%d%d",&L,&U);
            int Max_len=0;
            for (int i=0; i<N; i++){                            //每次找一列
                int left = BS_1(i);                             //找出該正方形的左上角
                    if (H[i][left] < L) continue;               //解答檢查
                int right = BS_2(i,left);                       //找出該正方形的右下角
                    if (H[i+(right-left)][right] > U) continue; //解答檢查
                int length = right-left+1;
                if (length > Max_len) Max_len = length;
            }
            printf ("%d\n",Max_len);
        }
        printf("-\n");
    }
}