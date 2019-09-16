#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("uva-429-WordTransformation.in", "r", stdin);
    freopen("uva-429-WordTransformation.out", "w", stdout);
    int N;
    cin >> N;
    while (N--)
    {
        vector<string> dict;
        map<string, int> map;

        string s;
        int idx = 0;
        while (true)
        {
            cin >> s;
            if (s != "*")
            {
                dict.push_back(s);
                map[s] = idx;
                ++idx;
            }
            else
            {
                break;
            }
        }

        vector<vector<int>> adj_list(dict.size());

        for (int i = 0; i <= dict.size() - 1; ++i)
        {
            for (int j = i + 1; j <= dict.size() - 1; ++j)
            {
                if (i != j)
                {
                    int dis = 0;
                    string s1 = dict[i];
                    string s2 = dict[j];
                    if (s1.size() == s2.size())
                    {
                        for (int i1 = 0; i1 <= s1.size() - 1; ++i1)
                        {
                            if (s1[i1] != s2[i1])
                            {
                                ++dis;
                                if (dis >= 2)
                                {
                                    break;
                                }
                            }
                        }
                        if (dis == 1)
                        {
                            adj_list[i].push_back(j);
                            adj_list[j].push_back(i);
                        }
                    }
                }
            }
        }
        string uselessline = "";
        getline(cin, uselessline);
        while (true)
        {
            string line = "";
            getline(cin, line);
            if (line == "")
            {
                break;
            }
            else
            {
                int startIdx = -1;
                int endIdx = -1;
                string startStr = "";
                string endStr = "";
                bool isStart = true;
                for (int i = 0; i <= line.size() - 1; ++i)
                {
                    if (line[i] != ' ')
                    {
                        if (isStart)
                            startStr.push_back(line[i]);
                        else
                            endStr.push_back(line[i]);
                    }
                    else
                    {
                        isStart = false;
                        continue;
                    }
                }

                if (startStr == endStr)
                {
                    cout << startStr << " " << endStr << " " << 0 << "\n";
                }
                else
                {
                    startIdx = map[startStr];
                    endIdx = map[endStr];

                    //BFS
                    queue<int> Q;
                    Q.push(startIdx);
                    vector<int> step(dict.size(), 0);
                    step[startIdx] = 0;

                    while (!Q.empty() && step[endIdx] == 0)
                    {
                        int now = Q.front();
                        Q.pop();

                        for (int k = 0; k <= adj_list[now].size() - 1; ++k)
                        {
                            int i = adj_list[now][k];
                            if (step[i] == 0)
                            {
                                step[i] = step[now] + 1;
                                if (i == endIdx)
                                    break;
                                Q.push(i);
                            }
                        }
                    }
                    cout << startStr << " " << endStr << " " << step[endIdx] << "\n";
                }
            }
        }
        cout << "\n";
    }

    return 0;
}