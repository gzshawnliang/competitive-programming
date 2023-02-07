#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    a=100;
    int num=-100;
    printf("ok\n");
    
    char snum[5];
    itoa(abs(num), snum, 10);

    // Print our string
    printf("%s\n", snum);    

    return 0;
}