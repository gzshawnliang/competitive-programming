/**
   *Author : Kalyan Chirla
   *Date :- 03-07-2018
 */
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("randomTreeGenerator.in", "r", stdin);
    freopen("randomTreeGenerator.out", "w", stdout);
#endif

    int is1index = 1;
    long long int n = 30; //Number of nodes in the tree.

    long long int src[n];    // source array.
    long long int dst[n];    //destination array.
    long long int arr[n][n]; //adjacency matrix.
    for (long long int i = 0; i < n; i++)
    {
        dst[i] = i;
    }

    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    long long int top = 0;
    src[0] = dst[0];
    top++;

    long long int i = 0;
    while (top != (n))
    {
        srand(time(NULL));
        long long int temp = rand() % (i + 1); // random integer generator between 0 and i.
        arr[src[temp]][dst[top]] = 1;
        arr[dst[top]][src[temp]] = 1;
        src[i + 1] = dst[top];
        top++;
        i++;
    }

    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < n; j++)
        {
            if (j > 0) cout << ' ';
            cout << arr[i][j];
        }
        cout << '\n';
    }
    cout << '\n';

    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                cout << i + is1index << ' ' << j + is1index << '\n';
            }
        }
    }

    return 0;
}