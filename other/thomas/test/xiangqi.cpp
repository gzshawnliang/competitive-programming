/*
* 20171108
*/

#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

int color[11][10];

void A(int a,int b,int c,int d)
{
    int x = rand()%a+b;
    int y = rand()%c+d;
    if(color[x][y]==0)
    {
        color[x][y] = 1;
        printf("%d %d\n",x,y);
    }else A(a,b,c,d);
}

int main()
{
    freopen("input.txt","w",stdout);
    int n = 1000;
    srand(time(NULL));
    while(n--)
    {
        memset(color,0,sizeof(color));
        printf("7 ");
        A(3,1,3,4);
        printf("G ");
        A(3,8,3,4);
        printf("R ");
        A(10,1,9,1);
        printf("R ");
        A(10,1,9,1);
        printf("H ");
        A(10,1,9,1);
        printf("H ");
        A(10,1,9,1);
        printf("C ");
        A(10,1,9,1);
        printf("C ");
        A(10,1,9,1);
        printf("\n");
    }
    printf("0 0 0\n");
    return 0;
}