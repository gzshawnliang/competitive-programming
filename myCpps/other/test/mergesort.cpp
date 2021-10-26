#include <iostream>

using namespace std;

int n, inversePairsCount, a[100005], t[100005], i;

void mergesort(int l, int r)
{
    if (l == r)
        return;

    int mid = (l + r) / 2;
    int p = l;
    int i = l;
    int j = mid + 1;
    mergesort(l, mid);
    mergesort(mid + 1, r);

    while (i <= mid && j <= r)
    {
        if (a[j] < a[i])
        {
            inversePairsCount += mid - i + 1;       //计算逆序对的数量，a[j]和前面逗哥数都能组成逆序对
            t[p] = a[j];
            p++;
            j++;
        }
        else
        {

            t[p] = a[i];
            p++;
            i++;
        }
    }

    while (i <= mid)
    {

        t[p] = a[i];
        p++;
        i++;
    }

    while (j <= r)
    {
        t[p] = a[j];
        p++;
        j++;
    }

    for (i = l; i <= r; i++)
        a[i] = t[i];
}

int main()
{

    cin >> n;

    for (i = 1; i <= n; i++)
        cin >> a[i];

    mergesort(1, n);
    cout << inversePairsCount << endl;

    return 0;
}