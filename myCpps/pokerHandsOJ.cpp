/***********************************************************
 * @名称:		Poker Hands
 * @作者:		Shawn 
 * @创建时间: 2017-12-24 15:54:36 
 * @修改人:   Shawn 
 * @修改时间: 2017-12-24 15:54:36 
 * @备注:		so hard !!!
 * @题目来源： https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1256
***********************************************************/
#include <cstdio>
#include <cstdlib>
#include <set>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct card
{
    int valume;
    char suit;

    bool operator<(const card &i) const
    {
        return valume < i.valume;
    };
};

int turn(char in)
{
    if (in == 'T')
    {
        return 10;
    }
    else if (in == 'J')
    {
        return 11;
    }
    else if (in == 'Q')
    {
        return 12;
    }
    else if (in == 'K')
    {
        return 13;
    }
    else if (in == 'A')
    {
        return 14;
    }
    else
    {
        int temp = in - '0';
        return temp;
    }
}

int findHightestRepeatoin(vector<card> &a)
{
    int size = a.size(), nowSum = 1, maxSum = 0;
    for (int i = 1; i <= size - 1; ++i)
    {
        if (a[i].valume == a[i - 1].valume)
        {
            ++nowSum; 
        }
        else
        {
            if (nowSum > maxSum)
            {
                maxSum = nowSum;
            }

            nowSum = 1;
        }
    }

    if (nowSum > maxSum)
    {
        maxSum = nowSum;
    }

    return maxSum;
}

bool sameSuit(vector<card> &a)
{
    char compare = a[0].suit;
    int size = a.size();
    for (int i = 1; i <= size - 1; ++i)
    {
        if (a[i].suit != compare)
        {
            return false;
        }
    }

    return true;
}

bool MyOrder(vector<card> &a)
{
    int size = a.size();
    for (int i = 1; i <= size - 1; ++i)
    {
        if (a[i].valume - a[i - 1].valume != 1)
        {
            return false;
        }
    }

    return true;
}

int typeDefin(vector<card> &a)
{
    int repeats = findHightestRepeatoin(a);
    bool isSameSuit = sameSuit(a);
    bool inOrder = MyOrder(a);
    if (isSameSuit == true)
    {
        if (inOrder == true)
        {
            return 9;
        }
        else
        {
            return 6;
        }
    }
    else
    {
        if (repeats == 1)
        {
            if (inOrder == true)
            {
                return 5;
            }
            else
            {
                return 1;
            }
        }
        else if (repeats == 2)
        {
            int pairs = 0;
            for (int i = 1; i <= 4; ++i)
            {
                if (a[i].valume == a[i - 1].valume)
                {
                    ++pairs;
                }
            }
            if (pairs == 1)
            {
                return 2;
            }
            else
            {
                return 3;
            }
        }
        else if (repeats == 3)
        {
            set<int> store;
            for (int i = 1; i <= 4; ++i)
            {
                store.insert(a[i].valume); 
            }
            if (store.size() == 3)
            {
                return 4;
            }
            else
            {
                return 7;
            }
        }
        else
        {
            return 8;
        }
    }

    return 1;
}

void solve()
{
    while (!(cin.eof()))
    {
        vector<card> black(5);
        vector<card> white(5);
        
        for (int i = 0; i <= 4; ++i)
        {
            char temp;
            cin >> temp >> black[i].suit;
            black[i].valume = turn(temp);
        }

        for (int i = 0; i <= 4; ++i)
        {
            char temp;
            cin >> temp >> white[i].suit;
            white[i].valume = turn(temp);
        }

        if(cin.eof())
        {
            break;
        }

        sort(black.begin(), black.end());
        sort(white.begin(), white.end());

        int Btype = typeDefin(black);
        int Wtype = typeDefin(white);     

        if (Btype > Wtype)
        {
            cout << "Black wins.\n";
        }
        else if (Btype < Wtype)
        {
            cout << "White wins.\n";
        }
        else
        {
            if (Btype == 4 || Btype == 8 || Btype == 7)
            {
                int Bv;
                for (int i = 1; i <= 4; ++i)
                {
                    if (black[i].valume == black[i - 2].valume)
                    {
                        Bv = black[i].valume;
                        break;
                    }
                }

                int Wv;
                for (int i = 2; i <= 4; ++i)
                {
                    if (white[i].valume == white[i - 2].valume)
                    {
                        Wv = white[i].valume;
                        break;
                    }
                }

                if (Bv > Wv)
                {
                    cout << "Black wins.\n";
                }
                else if (Bv < Wv)
                {
                    cout << "White wins.\n";
                }
                else
                {
                    cout << "Tie.\n";
                }
            }
            else if (Btype == 2)
            {
                int Bv, BvPos;
                for (int i = 1; i <= 4; ++i)
                {
                    if (black[i].valume == black[i - 1].valume)
                    {
                        Bv = black[i].valume;
                        BvPos = i;
                        break;
                    }
                }

                int Wv, WvPos;
                for (int i = 1; i <= 4; ++i)
                {
                    if (white[i].valume == white[i - 1].valume)
                    {
                        Wv = white[i].valume;
                        WvPos = i;
                        break;
                    }
                }

                if (Bv > Wv)
                {
                    cout << "Black wins.\n";
                }
                else if (Bv < Wv)
                {
                    cout << "White wins.\n";
                }
                else
                {
                    black.erase(black.begin() + BvPos - 1);
                    black.erase(black.begin() + BvPos - 1);

                    white.erase(white.begin() + WvPos - 1);
                    white.erase(white.begin() + WvPos - 1);

                    bool lal = true;
                    for (int i = 2; i >= 0; --i)
                    {
                        if (black[i].valume > white[i].valume)
                        {
                            lal = false;
                            cout << "Black wins.\n";
                            break;
                        }
                        else if (black[i].valume < white[i].valume)
                        {
                            lal = false;
                            cout << "White wins.\n";
                            break;
                        }
                    }
                    if (lal == true)
                    {
                        cout << "Tie.\n";
                    }
                }
            }
            else if (Btype == 3)
            {
                vector<int> Bv;
                int Bnvpos;
                for (int i = 1; i <= 4; ++i)
                {
                    if (black[i].valume == black[i - 1].valume)
                    {
                        Bv.push_back(black[i].valume);
                    }
                    else
                    {
                        Bnvpos = i;
                    }
                }

                vector<int> Wv;
                int Wnvpos;
                for (int i = 1; i <= 4; ++i)
                {
                    if (white[i].valume == white[i - 1].valume)
                    {
                        Wv.push_back(white[i].valume);
                    }
                    else
                    {
                        Wnvpos = i;
                    }
                }

                if (Bv[0] > Wv[0])
                {
                    cout << "Black wins.\n";
                }
                else if (Bv[0] < Wv[0])
                {
                    cout << "White wins.\n";
                }
                else
                {
                    if (Bv[1] > Wv[1])
                    {
                        cout << "Black wins.\n";
                    }
                    else if (Bv[1] < Wv[1])
                    {
                        cout << "White wins.\n";
                    }
                    else
                    {
                        if (black[Bnvpos].valume > white[Wnvpos].valume)
                        {
                            cout << "Black wins.\n";
                        }
                        else if (black[Bnvpos].valume < white[Wnvpos].valume)
                        {
                            cout << "White wins.\n";
                        }
                        else
                        {
                            cout << "Tie.\n";
                        }
                    }
                }
            }
            else
            {
                bool lal = true;
                for (int i = 4; i >= 0; --i)
                {
                    if (black[i].valume > white[i].valume)
                    {
                        lal = false;
                        cout << "Black wins.\n";
                        break;
                    }
                    else if (black[i].valume < white[i].valume)
                    {
                        lal = false;
                        cout << "White wins.\n";
                        break;
                    }
                }
                if (lal == true)
                {
                    cout << "Tie.\n";
                }
            }
        }
    }
}

int main()
{
    solve();

    return 0;
}
