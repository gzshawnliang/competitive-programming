#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>


using namespace std;

int main()
{
    while (!(cin.eof()))
    {
        string temp = "";
        getline(cin, temp);
        if (temp == "")
        {
            break;
        }

        list<char> out;
        auto it = out.end();
        int size = temp.size();
        for (int i = 0; i <= size - 1; ++i)
        {
            if (temp[i] == '[')
            {
                it = out.begin();
            }
            else if (temp[i] == ']')
            {
                it = out.end();
            }
            else
            {
                out.insert(it, temp[i]);
            }
        }

        for (auto i = out.begin(); i != out.end(); ++i)
        {
            cout << *i;
        }
        cout << '\n';
    }

    return 0;
}