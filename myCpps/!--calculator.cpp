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

int main()
{
    map<string, int> variables;
    while (true)
    {
        string in;
        getline(cin, in);

        if (in == "shutdown" || in == "sd")
        {
            return 0;
        }
        else if (in == "variables" || in == "v")
        {
            for (auto it = variables.begin(); it != variables.end(); ++it)
            {
                if (it == variables.begin())
                {
                    cout << "[@] " << it->first << " = " << it->second << '\n';
                }
                else
                {
                    cout << "    " << it->first << " = " << it->second << '\n';
                }
            }
        }
        else if (in == "")
        {
            continue;
        }
        else
        {
            int size0 = in.size();
            vector<string> store;
            string temp = "";

            for (int i = 0; i <= size0 - 1; ++i)
            {
                if (in[i] == ' ' || in[i] == ';')
                {
                    store.push_back(temp);
                    temp = "";
                }
                else
                {
                    temp += in[i];
                }
            }
            if (temp != "")
            {
                store.push_back(temp);
            }

            if (store[0] == "out" || store[0] == "o")
            {
                if (variables.find(store[1]) == variables.end())
                {
                    cout << "[@] There is no variable called " << '\'' << store[1] << "\' .\n";
                }
                else
                {
                    cout << "[@] " << variables[store[1]] << '\n';
                }
            }
            else if (store[0] == "create" || store[0] == "cr")
            {
                if (store.size() == 2)
                {
                    if (variables.find(store[1]) == variables.end())
                    {
                        variables[store[1]] = 0;
                        cout << "[@] Variable " << '\'' << store[1] << "\' (0) has been created .\n";
                    }
                    else
                    {
                        cout << "[@] There is already a variable called " << '\'' << store[1] << "\' (" << variables[store[1]] << ") .\n";
                    }
                }
                else
                {
                    if (variables.find(store[1]) == variables.end())
                    {
                        variables[store[1]] = stoi(store[3]);
                        cout << "[@] Variable " << '\'' << store[1] << "\' (" << store[3] << ") has been created .\n";
                    }
                    else
                    {
                        cout << "[@] There is already a variable called " << '\'' << store[1] << "\' (" << variables[store[1]] << ") .\n";
                    }
                }
            }
            else if (store[0] == "change" || store[0] == "ch")
            {
                if (variables.find(store[1]) == variables.end())
                {
                    cout << "[@] There is no variable called " << '\'' << store[1] << "\' .\n";
                }
                else
                {
                    if (store.size() == 4)
                    {
                        if (store[3][0] >= '0' && store[3][0] <= '9')
                        {
                            variables[store[1]] = stoi(store[3]);
                            cout << "[@] Changed variable " << '\'' << store[1] << "\' to " << store[3] << " .\n";
                        }
                        else 
                        {
                            if (variables.find(store[3]) == variables.end())
                            {
                                cout << "[@] There is no variable called " << '\'' << store[3] << "\' .\n";
                                continue;
                            }
                            variables[store[1]] = variables[store[3]];
                            cout << "[@] Set variable " << '\'' << store[1] << "\' as same as " << store[3] << '(' << variables[store[3]] << ") .\n";
                        }
                    }
                    else
                    {
                        int a, b, ans;
                        if (store[3][0] >= '0' && store[3][0] <= '9')
                        {
                            a = stoi(store[3]);
                        }
                        else
                        {
                            if (variables.find(store[3]) == variables.end())
                            {
                                cout << "[@] There is no variable called " << '\'' << store[3] << "\' .\n";
                                continue;
                            }
                            a = variables[store[3]];
                        }

                        if (store[5][0] >= '0' && store[5][0] <= '9')
                        {
                            b = stoi(store[5]);
                        }
                        else
                        {
                            if (variables.find(store[5]) == variables.end())
                            {
                                cout << "[@] There is no variable called " << '\'' << store[5] << "\' .\n";
                                continue;
                            }
                            b = variables[store[5]];
                        }

                        if (store[4] == "+")
                        {
                            ans = a + b;
                        }
                        else if (store[4] == "-")
                        {
                            ans = a - b;
                        }
                        else if (store[4] == "*")
                        {
                            ans = a * b;
                        }
                        else if (store[4] == "/")
                        {
                            ans = a / b;
                        }
                        else
                        {
                            ans = a % b;
                        }

                        variables[store[1]] = ans;
                        cout << "[@] Changed variable " << '\'' << store[1] << "\' to " << ans << " .\n";
                    }
                }
            }
            else 
            {
                cout << "Cannot understand the input .\n";
            }
        }
    }
}