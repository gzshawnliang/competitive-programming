#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <vector>
//#include <windows.h>

using namespace std;

bool compare(string a, string b)
{
    int size = min(a.size(), b.size());

    for (int i = 0; i <= size - 1; ++i)
    {
        if (a[i] != b[i])
        {
            if (((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) && (b[i] >= 'a' && b[i] <= 'z') || (b[i] >= 'A' && b[i] <= 'Z'))
            {
                int tempA = a[i], tempB = b[i];

                if (tempA >= 'A' && tempA <= 'Z')
                {
                    tempA = tempA - 'A' + 'a';
                }
                if (tempB >= 'A' && tempB <= 'Z')
                {
                    tempB = tempB - 'A' + 'a';
                }

                if (tempA != tempB)
                {
                    return tempA < tempB;
                }
                else if ((a[i] >= 'a' && a[i] <= 'z') && (b[i] >= 'A' && b[i] <= 'Z'))
                {
                    return true;
                }
                else if ((a[i] >= 'A' && a[i] <= 'Z') && (b[i] >= 'a' && b[i] <= 'z'))
                {
                    return false;
                }
            }
            else
            {
                return a[i] < b[i];
            }
        }
        else if (i == size - 1)
        {
            return a.size() < b.size();
        }
    }
}

struct TeamData
{
    int point;
    int gametimes;
    int win, tie, lose;
    int GoalsS, GoalsA;
    string TeamN;
    bool operator<(const TeamData & NewData) const
    {
        if (point > NewData.point)
        {
            return true;
        }
        else if (point < NewData.point)
        {
            return false;
        }
        else if (win > NewData.win)
        {
            return true;
        }
        else if (win < NewData.win)
        {
            return false;
        }
        else if (GoalsS - GoalsA > NewData.GoalsS - NewData.GoalsA)
        {

            return true;
        }
        else if (GoalsS - GoalsA < NewData.GoalsS - NewData.GoalsA)
        {
            return false;
        }
        else if (GoalsS > NewData.GoalsS)
        {

            return true;
        }
        else if (GoalsS < NewData.GoalsS)
        {
            return false;
        }
        else if (gametimes < NewData.gametimes)
        {

            return true;
        }
        else if (gametimes > NewData.gametimes)
        {
            return false;
        }
        else
        {
            return compare(TeamN, NewData.TeamN);
        }
    }
};

int main()
{
    //ifstream cin("Football2.in");
    //ofstream cout("Football.out");
    int n;
    cin >> n;
    string useless1;
    getline(cin, useless1);
    for (int i = 0; i < n; ++i)
    {
        if (i != 0)
        {
            cout << endl;
        }
        string temp = "";
        getline(cin, temp);
        cout << temp << endl;
        int T, GT;
        cin >> T;
        string useless2;
        getline(cin, useless2);
        vector<string> TN(T, "");
        vector<TeamData> TS(T);
        for (int h = 0; h < T; ++h)
        {
            string TeamName;
            getline(cin, TeamName);
            TN[h] = TeamName;
        }
        cin >> GT;
        string useless3;
        getline(cin, useless3);
        for (int h = 0; h < GT; ++h)
        {
            string GS;
            getline(cin, GS);
            string temp1, temp2;
            int TNumber1, TNumber2;
            bool complete = false;
            vector<int> score;
            for (int x = 0; x < GS.size(); ++x)
            {
                if (complete == false)
                {
                    if (GS[x] != '#')
                    {
                        temp1 += GS[x];
                    }
                    else
                    {
                        complete = true;
                    }
                }
                else
                {
                    if (GS[x] == '#')
                    {
                        for (int y = x + 1; y < GS.size(); ++y)
                        {
                            temp2 += GS[y];
                        }
                        break;
                    }
                    if (GS[x] >= 48 && GS[x] <= 57)
                    {
                        score.push_back(GS[x] - 48);
                    }
                }
            }
            for (int x = 0; x < TN.size(); ++x)
            {
                if (temp1 == TN[x])
                {
                    TNumber1 = x;
                }
                if (temp2 == TN[x])
                {
                    TNumber2 = x;
                }
            }
            TS[TNumber1].gametimes += 1;
            TS[TNumber2].gametimes += 1;
            if (score[0] > score[1])
            {
                TS[TNumber1].point += 3;
                TS[TNumber1].win += 1;
                TS[TNumber2].lose += 1;
            }
            else if (score[0] == score[1])
            {
                TS[TNumber1].point += 1;
                TS[TNumber2].point += 1;
                TS[TNumber1].tie += 1;
                TS[TNumber2].tie += 1;
            }
            else
            {
                TS[TNumber2].point += 3;
                TS[TNumber2].win += 1;
                TS[TNumber1].lose += 1;
            }
            TS[TNumber1].GoalsS += score[0];
            TS[TNumber1].GoalsA += score[1];
            TS[TNumber2].GoalsS += score[1];
            TS[TNumber2].GoalsA += score[0];
        }
        for (int h = 0; h < TN.size(); ++h)
        {
            TS[h].TeamN = TN[h];
        }
        sort(TS.begin(), TS.end());
        for (int h = 0; h < TN.size(); ++h)
        {
            cout << h + 1 << ") ";
            cout << TS[h].TeamN << " " << TS[h].point << "p"
                 << ", " << TS[h].gametimes << "g (";
            cout << TS[h].win << "-" << TS[h].tie << "-" << TS[h].lose << "), " << TS[h].GoalsS - TS[h].GoalsA << "gd (";
            cout << TS[h].GoalsS << "-" << TS[h].GoalsA << ")" << endl;
        }
    }
    //system("pause");
    return 0;
}