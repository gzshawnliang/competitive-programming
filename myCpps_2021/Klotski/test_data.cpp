#include "MyRandom.h"
#include <bits/stdc++.h> //includes everything, supported in CF, usaco, not POJ

using namespace std;

string getCurrTime()
{
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
    time_t raw_time = std::chrono::system_clock::to_time_t(tp);

    // tm*使用完后不用delete，因为tm*是由localtime创建的，并且每个线程中会有一个
    struct tm * timeinfo = std::localtime(&raw_time);
    std::stringstream ss;
    //ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S");
    ss << std::put_time(timeinfo, "%H%M%S");
    return ss.str();
}

int main()
{
    const int FileCount = 1; //note:文件数量
    ofstream fout;           //note:文件流
    random rdNum;            //note:随机数

    string currTime = getCurrTime();

    int len = to_string(FileCount).length();

    for (int fileId = 1; fileId <= FileCount; ++fileId)
    {
        stringstream ss;
        //ss << "test_" << currTime << "_" << setw(len) << setfill('0') << fileId << ".in";
        ss << "Klotski.in";

        fout.open(ss.str());

        vector<vector<int>> a =
            {
                {-1, -1, -1, -1, -1, -1},
                {-1, 1, 2, 3, 4, -1},
                {-1, 5, 6, 7, 8, -1},
                {-1, 9, 10, 11, 12, -1},
                {-1, 13, 14, 15, 0, -1},
                {-1, -1, -1, -1, -1, -1}};
        vector<int> b = {1, -1};

        pair<int, int> z = {4, 4};
        pair<int, int> zLast = z;

        int swapCount = 0;
        int zCount = 0;
        //int maxZCount=rdNum.GetRand(1000, 2000);
        int maxZCount=5;
        while (true)
        {
            vector<pair<int, int>> swapPairVec;

            for (auto c : b)
            {
                if (a[z.first + c][z.second] > 0)
                    swapPairVec.push_back({z.first + c, z.second});

                if (a[z.first][z.second + c] > 0)
                    swapPairVec.push_back({z.first, z.second + c});
            }

            auto nextPair = swapPairVec[rdNum.GetRand(0, swapPairVec.size() - 1)];
            while (true)
            {
                if (zLast == nextPair)
                {
                    //std::this_thread::sleep_for (std::chrono::seconds(1));
                    nextPair = swapPairVec[rdNum.GetRand(0, swapPairVec.size() - 1)];
                }
                else
                {
                    zLast = z;
                    break;
                }
            }

            std::swap(a[z.first][z.second], a[nextPair.first][nextPair.second]);
            z = nextPair;

            //fout << nextPair.first-1 << " " << nextPair.second-1 << "\n";

            ++swapCount;
            // if(swapCount>=5)
            //     break;
            if (z == make_pair(4, 4))
            {
                ++zCount;
                if (zCount >= maxZCount)
                    break;
            }
        }

        //fout << zCount <<"\n";
        for (int i = 1; i <= 4; ++i)
        {
            for (int j = 1; j <= 4; ++j)
            {
                fout << a[i][j] << " ";
            }
            fout << "\n";
        }

        fout.close();
    }

    return 0;
}
