#include <algorithm>  
#include <iostream>  
#include <cstdlib>  
#include <cstring>  
#include <cstdio>  
  
using namespace std;  
  
char data[11];  
char save[3628800][11];  
int  used[11];  
  
typedef struct noded  
{  
    char   data;  
    noded* next;  
}dnode;  
dnode  D[11];  
dnode* Head;  
  
int  Count;  
void dfs( int d, int n )  
{  
    if ( d == n ) {  
        dnode* p = Head;  
        for ( int i = 0 ; i < n ; ++ i ) {  
            save[Count][i] = p->data;  
            p = p->next;  
        }  
        save[Count ++][n] = 0;  
        return;  
    }  
    dnode *p = Head,*q = p;  
    for ( int i = 0 ; i <= d ; ++ i ) {  
        //²åµã   
        D[d].data = data[d];  
        D[d].next = p;  
        if ( !i ) Head = &D[d];  
        else q->next = &D[d];  
        //µÝ¹é   
        dfs( d+1, n );  
        //»ØËÝ   
        if ( !i ) Head = p;  
        else q->next = p;  
          
        q = p;  
        if ( i < d ) p = p->next;  
    }  
}  
  
int main()  
{  
    freopen("Permutation2.in", "r", stdin);
    freopen("Permutation3.out", "w", stdout);

    int count = 0;   
    while ( scanf("%s",data) != EOF ) {  
        if ( count ++ ) printf("\n");  
          
        Count = 1;  
        memset( save, 0, sizeof(save) );  
        dfs( 0, strlen(data) );  
          
        for ( int i = 1 ; i < Count ; ++ i )  
            printf("%s\n",save[i]);  
    }  

	//F11
	fclose(stdin);
	fclose(stdout);    
    return 0;  
}  