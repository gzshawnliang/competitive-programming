#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <windows.h>
#include "ConsoleColor.h"

using namespace std;

ifstream fin("theSameGame.in");

const int N = 1000;

//#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

void cls()
{
    // Get the Win32 handle representing standard output.
    // This generally only has to be done once, so we make it static.
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD topLeft = { 0, 0 };

    // cout uses a buffer to batch writes to the underlying console.
    // We need to flush that to the console because we're circumventing
    // cout entirely; after we clear the console, we don't want
    // stale buffered text to randomly be written out.
    cout.flush();

    // Figure out the current width and height of the console window
    if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
        // TODO: Handle failure!
        abort();
    }
    DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

    DWORD written;

    // Flood-fill the console with spaces to clear it
    FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

    // Reset the attributes of every character to the default.
    // This clears all background colour formatting, if any.
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

    // Move the cursor back to the top left for the next sequence of writes
    SetConsoleCursorPosition(hOut, topLeft);
}

struct showStage
{
    vector<string> text;
    vector<string> choice;
};

void print(string s)
{
    int size = s.size();
    for (int i = 0; i <= size - 1; ++i)
    {
        if (s[i] == '|')
        {
            ++i;
            if (s[i] == 'B')
            {
                cout << blue;
            }
            else if (s[i] == 'R')
            {
                cout << red;
            }
            else if (s[i] == 'G')
            {
                cout << green;
            }
            else if (s[i] == 'Y')
            {
                cout << yellow;
            }
            else if (s[i] == 'W')
            {
                cout << white;
            }
        }
        else
        {
            cout << s[i];
        }

        if (GetAsyncKeyState(VK_SPACE))
        {
            Sleep(5);
        }
        else
        {
            Sleep(100);
        }
    }
    cout << '\n';
}

void create(showStage a)
{
    int size0 = a.text.size(), size1 = a.choice.size();

    for (int i = 0; i <= size0 - 1; ++i)
    {
        print(a.text[i]);
    }

    if (size1 == 0)
    {
        return;
    }

    print("\n|YYour choices are :\n");

    for (int i = 0; i <= size1 - 1; ++i)
    {
        cout << yellow << "choice NO." << i << " : ";
        print(a.choice[i]);
    }

    cout << white << '\n';
}

void _generate(vector<vector<int>> & game, vector<showStage> & show)
{
    // stage0
    game[0] = {1, 2};

    show[0].text.push_back("|WThis is a game with no check point LOL .");
    show[0].text.push_back("|WIf you die, don\'t rage too much .");
    show[0].text.push_back("|WAre you ready ?");

    show[0].choice.push_back("|WYeah, boiiiiii !");
    show[0].choice.push_back("|WNo, i am afraid !");

    // stage1
    game[1] = {3, 4, 5};

    show[1].text.push_back("|WOK, you are now in a world of |RZOMBIES|W !!!");
    show[1].text.push_back("|WYou wake up and find out there is a |RZOMBIE right besides you|W !!!");
    show[1].text.push_back("|WOf couse you are terrified .");
    show[1].text.push_back("|WNow what should you do ?");

    show[1].choice.push_back("|RKILL HIM(or maybe it) !!!");
    show[1].choice.push_back("|WRun a way as fast as you can .");
    show[1].choice.push_back("|WCry for |Ghelp .");

    // stage2
    game[2] = {1};

    show[2].text.push_back("|WNANI ?!! You aren\'t ready ??");
    show[2].text.push_back("|WNo problem bro I\'ll give you enough time");
    show[2].text.push_back("|WI\'ll just sit here LOL !");

    show[2].choice.push_back("|ROK I am ready now !");

    // stage3
    game[3] = {};

    show[3].text.push_back("|WYou beat it with your fist and ...");
    show[3].text.push_back("|WIt trunes around and shallowes you .");
    show[3].text.push_back("|WIt is never a good idea ...");

    // stage4
    game[4] = {6, 6, 7};

    show[4].text.push_back("|WThat is always a good choice !");
    show[4].text.push_back("|WWhile you are running, |Gyou run in to a person|W .");
    show[4].text.push_back("|WYou look up and ... |Bluckily, he is a human|W .");
    show[4].text.push_back("|WBut he looks a bit angry .");

    show[4].choice.push_back("|WSay sorry to him .");
    show[4].choice.push_back("|WTry to convince him to join you and fight together |Gblabalbla|W .");
    show[4].choice.push_back("|WPush him back and use him to |Rhold the zombie for a while|W .");

    show[3].text.push_back("|WYou beat it with your fist and ...");
    show[3].text.push_back("|WIt trunes around and shallowes you .");
    show[3].text.push_back("|WIt is never a good idea ...");

    // stage5
    game[5] = {};

    show[5].text.push_back("|WYour voice atracks |Rmore zombies |W...");
    show[5].text.push_back("|WThey surround you ...");

    game[6] = {};

    show[6].text.push_back("|WAlthough you said that, he doesn\'t want to acknowledge you .");
    show[6].text.push_back("|WBut, unexpectedly, he |Rpushes you twoward the zombie|W .");
    show[6].text.push_back("|WYou don\'t expect that and you fell .");
    show[6].text.push_back("|RHe smiles ...");
    show[6].text.push_back("|RYou feel cold .");

    game[7] = {8, 9};

    show[7].text.push_back("|WHe fells ...");
    show[7].text.push_back("|WHe shouts to you, and |Rcries for help|W .");
    show[7].text.push_back("|WYou look at him with no ... mercy");
    show[7].text.push_back("|WThen you run to the centre of the city .");
    show[7].text.push_back("|WYou hear the sound of the flesh, being tear apart .");
    show[7].text.push_back("|WYou run as fast as you can .");
    show[7].text.push_back("|WThe zombie doesn\'t folow .");

    show[7].choice.push_back("|WTry to look for |Gfood|W .");
    show[7].choice.push_back("|WTry to look for |Gshelter|W .");
}

int main()
{
    // game
    vector<vector<int>> game(N);
    vector<showStage> show(N);

    _generate(game, show);

    print("|YInput your last stage ...|W");
    int stage = 0;
    cin >> stage;
    while (true)
    {
        cout << white << "\n----------";
        cout << "stage " << stage;
        cout << "----------\n\n";

        create(show[stage]);

        int n = show[stage].choice.size();

        if (n == 0)
        {
            print("|RYOU DIED !");
            break;
        }

        int c = 0;
        while (true)
        {
            cin >> c;

            if (c >= 0 && c <= n - 1)
            {
                break;
            }
            else
            {
                print("|RThere is no such choice !!!");
                cout << white;
            }
        }

        stage = game[stage][c];
    }

    cout << white << '\n';
    cout << "The Program has completed running\n";
    cout << "Press ENTER key to continue...\n";
    cin.clear();
    cin.get();

    return 0;
}