#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

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

struct team
{
    int points;
    int wins;
    int ties;
    int loses;
    int goalsDifferent;
    int goals;
    int goalsAgainsts;
    int gamePlays;
    string name;


    bool operator<(const team & temp) const
    {
        if (points != temp.points)
        {
            return points > temp.points;
        }
        else if (wins != temp.wins)
        {
            return wins > temp.wins;
        }
        else if (goalsDifferent != temp.goalsDifferent)
        {
            return goalsDifferent > temp.goalsDifferent;
        }
        else if (goals != temp.goals)
        {
            return goals > temp.goals;
        }
        else if (gamePlays != temp.gamePlays)
        {
            return gamePlays < temp.gamePlays;
        }
        else
        {
            return compare(name, temp.name);
        }
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int T; cin >> T;
    string useless0;
    getline(cin, useless0);

    for (int t = 1; t <= T; ++t)
    {
        if (t > 1)
        {
            cout << '\n';
        }

        string tournament;
        getline(cin, tournament);
        cout << tournament << '\n';

        int n; cin >> n;
        getline(cin, useless0);

        vector<team> game(n);
        map <string, int> positions;

        for (int i = 0; i <= n - 1; ++i)
        {
            string name;
            getline(cin, name); 

            team temp{0, 0, 0, 0, 0, 0, 0, 0, name};

            game[i] = temp;
            positions[name] = i;
        }

        int m; cin >> m;
        getline(cin, useless0);

        for (int c = 1; c <= m; ++c)
        {
            string match;
            getline(cin, match);

            int size0 = match.size(), i = 0, goal0, goal1;
            string temp = "", team0, team1;

            while (match[i] != '#')
            {
                temp += match[i];
                ++i;
            }
            ++i;
            team0 = temp;
            temp = "";

            while (match[i] != '@')
            {
                temp += match[i];
                ++i;
            }
            ++i;
            goal0 = stoi(temp);
            temp = "";

            while (match[i] != '#')
            {
                temp += match[i];
                ++i;
            }
            ++i;
            goal1 = stoi(temp);
            temp = "";

            while (i <= size0 - 1)
            {
                temp += match[i];
                ++i;
            }
            team1 = temp;
            temp = "";


            int pos0 = positions[team0], pos1 = positions[team1];

            if (goal0 > goal1)
            {
                game[pos0].points += 3;
                ++game[pos0].wins;
                ++game[pos1].loses;
            }
            else if (goal0 < goal1)
            {
                game[pos1].points += 3;
                ++game[pos1].wins;
                ++game[pos0].loses;
            }
            else
            {
                ++game[pos0].points;
                ++game[pos1].points;
                ++game[pos0].ties;
                ++game[pos1].ties;
            }

            ++game[pos0].gamePlays;
            ++game[pos1].gamePlays;

            game[pos0].goals += goal0;
            game[pos1].goals += goal1;
            game[pos0].goalsAgainsts += goal1;
            game[pos1].goalsAgainsts += goal0;

            game[pos0].goalsDifferent += goal0 - goal1;
            game[pos1].goalsDifferent += goal1 - goal0;
        }

        sort(game.begin(), game.end());


        for (int i = 0; i <= n - 1; ++i)
        {
            cout << i + 1 << ") ";

            cout << game[i].name << ' ';

            cout << game[i].points << "p, ";

            cout << game[i].gamePlays << "g (";

            cout << game[i].wins << '-' << game[i].ties << '-' << game[i].loses << "), ";

            cout << game[i].goalsDifferent << "gd (";

            cout << game[i].goals << '-' << game[i].goalsAgainsts << ")\n";
        }
    }

    

   	cout.flush();
   	return 0;
}
