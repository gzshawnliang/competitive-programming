#include <bits/stdc++.h>

using namespace std;

vector<string> a(4);
vector<string> b(4);
set<string> ans;
vector<string> reach;
vector<string> reach2;
string t1, t2, t3, t4;
bool Yes = false;

bool out(int x,int y)
{
    if(x<0 || y<0 || x>3 || y>3)
    {
        return true;
    }
    return false;
}

bool cal2(int x,int y,string & t,int num)
{
    if(num>=4)
    {
        Yes = true;
        return true;
    }
    if (!out(x - 1, y))
    {
        if (reach2[x - 1][y] != '0' && b[x-1][y]==t[num])
        {
            char Temp = reach2[x - 1][y];
            reach2[x - 1][y] = '0';
            cal2(x - 1, y, t, num+1);
            if(Yes)
            {
                return true;
            }
            reach2[x - 1][y] = Temp;
        }
    }
    if (!out(x + 1, y))
    {
        if (reach2[x + 1][y] != '0' && b[x + 1][y] == t[num])
        {
            char Temp = reach2[x + 1][y];
            reach2[x + 1][y] = '0';
            cal2(x + 1, y, t, num+1);
            if (Yes)
            {
                return true;
            }
            reach2[x + 1][y] = Temp;
        }
    }
    if (!out(x, y - 1))
    {
        if (reach2[x][y - 1] != '0' && b[x][y-1] == t[num])
        {
            char Temp = reach2[x][y - 1];
            reach2[x][y - 1] = '0';
            cal2(x, y - 1, t, num+1);
            if (Yes)
            {
                return true;
            }
            reach2[x][y - 1] = Temp;
        }
    }
    if (!out(x, y + 1))
    {
        if (reach2[x][y + 1] != '0' && b[x][y+1] == t[num])
        {
            char Temp = reach2[x][y + 1];
            reach2[x][y + 1] = '0';
            cal2(x, y + 1, t, num+1);
            if (Yes)
            {
                return true;
            }
            reach2[x][y + 1] = Temp;
        }
    }
    if (!out(x - 1, y - 1))
    {
        if (reach2[x - 1][y - 1] != '0' && b[x - 1][y-1] == t[num])
        {
            char Temp = reach2[x - 1][y - 1];
            reach2[x - 1][y - 1] = '0';
            cal2(x - 1, y - 1, t, num+1);
            if (Yes)
            {
                return true;
            }
            reach2[x - 1][y - 1] = Temp;
        }
    }
    if (!out(x - 1, y + 1))
    {
        if (reach2[x - 1][y + 1] != '0' && b[x - 1][y+1] == t[num])
        {
            char Temp = reach2[x - 1][y + 1];
            reach2[x - 1][y + 1] = '0';
            cal2(x - 1, y + 1, t, num+1);
            if (Yes)
            {
                return true;
            }
            reach2[x - 1][y + 1] = Temp;
        }
    }
    if (!out(x + 1, y - 1))
    {
        if (reach2[x + 1][y - 1] != '0' && b[x + 1][y-1] == t[num])
        {
            char Temp = reach2[x + 1][y - 1];
            reach2[x + 1][y - 1] = '0';
            cal2(x + 1, y - 1, t, num+1);
            if (Yes)
            {
                return true;
            }
            reach2[x + 1][y - 1] = Temp;
        }
    }
    if (!out(x + 1, y + 1))
    {
        if (reach2[x + 1][y + 1] != '0' && b[x + 1][y+1] == t[num])
        {
            char Temp = reach2[x + 1][y + 1];
            reach2[x + 1][y + 1] = '0';
            cal2(x + 1, y + 1, t, num+1);
            if (Yes)
            {
                return true;
            }
            reach2[x + 1][y + 1] = Temp;
        }
    }
    if (Yes)
    {
        return true;
    }
    return false;
}

void cal(int x,int y,string & t){
    if(t.length()==4)
    {
        // if(t=="OGOP")
        // {
        //     cout << 'a';
        // }
        int tn=0;
        for (int i = 0; i < 4;++i)
        {
            if (t[i] == 'A' || t[i] == 'E' || t[i] == 'I' || t[i] == 'O' || t[i] == 'U' || t[i] == 'Y')
                ++tn;
        }
        if (tn==2 && ans.count(t) == 0)
        {
            Yes = false;
            for (int i = 0; i < 4; ++i)
            {
                for (int h = 0; h < 4; ++h)
                {
                    if (b[i][h] == t[0])
                    {
                        reach2 = b;
                        reach2[i][h] = '0';
                        if (cal2(i, h, t, 1))
                        {
                            ans.insert(t);
                            break;
                        }
                    }
                }
                if (Yes)
                {
                    break;
                }
            }
        }
        return;
    }
    if(!out(x-1,y))
    {
        if(reach[x-1][y]!='0')
        {
            char Temp = reach[x - 1][y];
            reach[x - 1][y] = '0';
            string temp = t;
            temp.push_back(a[x - 1][y]);
            cal(x - 1, y, temp);
            reach[x - 1][y] = Temp;
        }
    }
    if(!out(x+1,y))
    {
        if (reach[x + 1][y] != '0')
        {
            char Temp = reach[x + 1][y];
            reach[x + 1][y] = '0';
            string temp = t;
            temp.push_back(a[x + 1][y]);
            cal(x + 1, y, temp);
            reach[x + 1][y] = Temp;
        }
    }
    if (!out(x, y-1))
    {
        if(reach[x ][y-1] != '0')
        {
            char Temp = reach[x][y-1];
            reach[x ][y-1] = '0';
            string temp = t;
            temp.push_back(a[x][y-1]);
            cal(x, y-1, temp);
            reach[x ][y-1] = Temp;
        }
    }
    if (!out(x, y+1))
    {
        if (reach[x][y + 1] != '0')
        {
            char Temp = reach[x][y + 1];
            reach[x][y + 1] = '0';
            string temp = t;
            temp.push_back(a[x][y + 1]);
            cal(x, y+1, temp);
            reach[x][y + 1] = Temp;
        }
    }
    if (!out(x - 1, y-1))
    {
        if (reach[x-1][y - 1] != '0')
        {
            char Temp = reach[x-1][y - 1];
            reach[x-1][y - 1] = '0';
            string temp = t;
            temp.push_back(a[x-1][y - 1]);
            cal(x - 1, y-1, temp);
            reach[x-1][y - 1] = Temp;
        }
    }
    if (!out(x - 1, y + 1))
    {
        if (reach[x - 1][y + 1] != '0')
        {
            char Temp = reach[x - 1][y + 1];
            reach[x - 1][y + 1] = '0';
            string temp = t;
            temp.push_back(a[x - 1][y + 1]);
            cal(x - 1, y+1, temp);
            reach[x - 1][y + 1] = Temp;
        }
    }
    if (!out(x+1, y - 1))
    {
        if (reach[x + 1][y - 1] != '0')
        {
            char Temp = reach[x + 1][y - 1];
            reach[x + 1][y - 1] = '0';
            string temp = t;
            temp.push_back(a[x + 1][y - 1]);
            cal(x + 1, y-1, temp);
            reach[x + 1][y - 1] = Temp;
        }
    }
    if (!out(x+1, y + 1))
    {
        if (reach[x + 1][y + 1] != '0')
        {
            char Temp = reach[x + 1][y + 1];
            reach[x + 1][y + 1] = '0';
            string temp = t;
            temp.push_back(a[x + 1][y + 1]);
            cal(x + 1, y+1, temp);
            reach[x + 1][y + 1] = Temp;
        }
    }
}

int main()
{
    // ifstream cin("Boggle.in");
    // ofstream cout("Boggle.out");
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("Boggle.in", "r", stdin);
        freopen("Boggle.out", "w", stdout);
    #endif

    string empty;
    bool first=true;
    while(true)
    {
        getline(cin, t1);
        if(t1=="#")
        {
            break;
        }
        if(first)
        {
            first = false;
        }
        else
        {
            cout << '\n';
        }
        getline(cin, t2);
        getline(cin, t3);
        getline(cin, t4);
        getline(cin, empty);
        string IN;
        vector<string> ta(4), tb(4);
        for (int i = 0; i < 4;++i)
        {
            if(i==0)
            {
                IN = t1;
            }
            else if(i==1)
            {
                IN = t2;
            }
            else if(i==2)
            {
                IN = t3;
            }
            else 
            {
                IN = t4;
            }
            for (int h = 0; h < 8;h+=2)
            {
                ta[i].push_back(IN[h]);
            }
            for (int h = 11; h < 18;h+=2)
            {
                tb[i].push_back(IN[h]);
            }
        }
        a = ta;
        b = tb;
        ans.clear();
        for (int i = 0; i < 4;++i)
        {
            for (int h = 0; h < 4;++h)
            {
                reach = a;
                string temp = "";
                temp += reach[i][h];
                reach[i][h] = '0';
                cal(i, h, temp);
            }
        }
        if(ans.empty())
        {
            cout << "There are no common words for this pair of boggle boards." << '\n';
        }
        else
        {
            for (auto it = ans.begin(); it != ans.end(); ++it)
                cout << *it << '\n';
        }
    }
    //system("pause");
    cout.flush();
    return 0;
}