#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct BridgeCard
{
    char suit;
    char number;
    //int value;

    int value() const
    { 
        if (number == 'T')
        {
            return 10;
        }
        else if (number == 'J')
        {
            return 11;
        }
        else if (number == 'Q')
        {
            return 12;
        }
        else if (number == 'K')
        {
            return 13;
        }
        else if (number == 'A')
        {
            return 14;
        }
        else
        {
            return number - '0';
        }        
    };    

    bool operator<(const BridgeCard &i) const
    {
        if (suit == 'S' && i.suit == 'H')
        {
            return true;
        }
        else if (suit == 'H' && i.suit == 'S')
        {
            return false;
        }
        else if (suit < i.suit)
        {
            return true;
        }
        else if (suit > i.suit)
        {
            return false;
        }
        else
        {
            return value() < i.value();
        }
    };
};

void printVector(vector<BridgeCard> &a)
{
    for (auto i = a.begin(); i != a.end(); ++i)
    {
        //cout << " " << i->suit << i->number;
        printf(" %c%c",i->suit,i->number);
    }
    //cout << '\n';
    printf("\n");
}

void solve()
{
    while (true)
    {
        char tempIn=0;
        int loop;
        //cin >> tempIn;
        scanf("%c\n",&tempIn);

        if (tempIn == 'N')
        {
            loop = 1;
        }
        else if (tempIn == 'E')
        {
            loop = 2;
        }
        else if (tempIn == 'S')
        {
            loop = 3;
        }
        else if (tempIn == 'W')
        {
            loop = 4;
        }
        else
        {
            break;
        }

        vector<BridgeCard> p1, p2, p3, p4;

        for (int i =1; i <= 52; ++i)
        {
            char tempSiut;
            char tempNumber;
            if(i==27)
            {
                scanf("\n%c %c",&tempSiut,&tempNumber);
            }
            else if(i==52)
            {
                scanf("%c %c\n",&tempSiut,&tempNumber);
            }
            else
            {
                scanf("%c %c",&tempSiut,&tempNumber);
            }
            

            //cin >> tempSiut >> tempNumber;
            
            BridgeCard temp{tempSiut, tempNumber};
            //setCardValue(temp);

            ++loop;
            if (loop > 4)
            {
                loop = 1;
            }

            if (loop == 1)
            {
                p1.push_back(temp);
            }
            else if (loop == 2)
            {
                p2.push_back(temp);
            }
            else if (loop == 3)
            {
                p3.push_back(temp);
            }
            else
            {
                p4.push_back(temp);
            }
        }
        
        sort(p1.begin(),p1.end());
        sort(p2.begin(),p2.end());
        sort(p3.begin(),p3.end());
        sort(p4.begin(),p4.end());

        //cout << "S:";
        printf("S:");
        printVector(p3);
        //cout << "W:";
        printf("W:");
        printVector(p4);
        printf("N:");
        //cout << "N:";
        printVector(p1);
        //cout << "E:";
        printf("E:");
        printVector(p2);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("bridgeHand.in", "r", stdin);
    freopen("bridgeHand.out", "w", stdout);    
    #endif

    //ios_base::sync_with_stdio(false);
    //std::cin.tie(NULL);
    solve();
    //cout.flush();    

    #ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);    
    #endif
    return 0;

}