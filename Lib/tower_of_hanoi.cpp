#include <bits/stdc++.h>
using namespace std;

int step=0;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    
    if (n == 1)
    {
        ++step;
        cout <<"\n" << step << ". Move disk 1 from rod "<<from_rod <<" to rod " <<to_rod;
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);

    ++step;
    cout <<"\n" << step << ". Move disk " << n << " from rod " << from_rod <<" to rod " << to_rod;
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n=3;
    cout<<"\n Enter Number of Disks ";
    //cin>>n;

    towerOfHanoi(n, 'A', 'C', 'B');
    cout<<"\n";
    return 0;
}