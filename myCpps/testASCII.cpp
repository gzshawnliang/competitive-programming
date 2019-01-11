#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

int main()
{
    char a = 8;

    cout << "hello there";

    Sleep(1000);

    for (int i = 1; i <= 5; ++i)
    {
        cout << a;
    }

    Sleep(1000);

    cout << "Shawn is here" << '\n';;

    Sleep(5000);

    return 0;
}