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

//c++2017和gcc8或以上使用filesystem,低于此版本使用实验性功能。
#if __GNUC__>=8 && __cplusplus >= 201703L
    #include <filesystem>
    namespace fs = std::filesystem;
#else
    #include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;
#endif
//#include <windows.h>
//namespace fs = std::experimental::filesystem;

using namespace std;

//***************************************
const string CPPfile = "wattoAndMechanism_CF514C"; //*
//***************************************

ifstream fin;
ofstream fout;



bool _isAlpha(char a)
{
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
}

/**
 * 查找文件是否存在，如果不存在返回空字符串，存在返回是全路径+文件名 (filesystem)
 * @param  {string} c_FileName : 需要查找的文件名称
 * @return {string}            : 返回文件名称，不存在是空字符串，存在是全路径+文件名
 */
string findFile(const string & c_FileName)
{
    fs::path p = fs::current_path();    //获取当前路径

    //获取递归子目录
    for(auto & p2: fs::recursive_directory_iterator(p))
    {
        //std::cout << p2.path() << " | " << p2.path().filename() << '\n';

        if(p2.path().filename()==c_FileName)
        {
           return p2.path().string();
        }
    }
    return "";

}

int main()
{
    string noFoundErrMsg ="error : file "+ CPPfile + ".cpp" + " no found!";
    string cppFileNameWithExt=CPPfile + ".cpp";

    string cppfileFullName=findFile(cppFileNameWithExt);

    if(cppfileFullName=="")
    {
        cout << noFoundErrMsg << '\n';
        return 0;
    }

    fin.open(cppfileFullName);
    if(fin.good()==false)
    {
        cout << noFoundErrMsg << '\n';
        return 0;
    }
    string OjCpp=cppfileFullName.substr(0,cppfileFullName.length()-4) + "OJ.cpp";
    fout.open(OjCpp);


    bool findMain = false;
    bool fastDone = false;
    while (true)
    {
        string in = "I am Shawn.";
        getline(fin, in);
        int size = in.size();

        if (findMain == true && fastDone == false)
        {
            fout << in << '\n';
            fout << "\tios_base::sync_with_stdio(false);\n\tstd::cin.tie(NULL);\n";
            fastDone = true;
            continue;
        }

        if (in == "I am Shawn.")
        {
            break;
        }
        else if (in == "")
        {
            fout << '\n';
            continue;
        }
        else if (in == "int main()")
        {
            findMain = true;
            fout << "int main()\n";
            continue;
        }
        else if (size >= 9)
        {
            int i = 0, SPACEcount = 0, TABcount = 0;
            while (in[i] == ' ' || in[i] == '\t')
            {
                ++i;
                if (in[i] == ' ')
                {
                    ++SPACEcount;
                }
                else
                {
                    ++TABcount;
                }
            }

            string front = "";
            for (int j = i; j <= size - 1; ++j)
            {
                front.push_back(in[j]);
            }

            if (front == "return 0;")
            {
                for (int c = 1; c <= SPACEcount; ++c)
                {
                    fout << ' ';
                }
                for (int c = 1; c <= TABcount; ++c)
                {
                    fout << '\t';
                }

                fout << "cout.flush();\n";

                for (int c = 1; c <= SPACEcount; ++c)
                {
                    fout << ' ';
                }
                for (int c = 1; c <= TABcount; ++c)
                {
                    fout << '\t';
                }

                fout << "return 0;\n";
                continue;
            }
        }

        if (size >= 8)
        {
            string front = "";

            int i = 0;
            while (in[i] == ' ' || in[i] == '\t')
            {
                ++i;
            }

            front.push_back(in[i]);
            front.push_back(in[i + 1]);
            front.push_back(in[i + 2]);
            front.push_back(in[i + 3]);
            front.push_back(in[i + 4]);
            front.push_back(in[i + 5]);
            front.push_back(in[i + 6]);
            front.push_back(in[i + 7]);

            if (front == "ifstream" || front == "ofstream")
            {
                continue;
            }
        }
        if (size >= 2)
        {
            int i = 0;
            while (in[i] == ' ' || in[i] == '\t')
            {
                ++i;
            }

            if (i <= size - 2)
            {
                if (in[i] == '/' && in[i + 1] == '/')
                {
                    continue;
                }
            }
        }
        if (size > 2)

        for (int i = 0; i <= size - 5; ++i)
        {
            string temp;
            temp.push_back(in[i]);
            temp.push_back(in[i + 1]);
            temp.push_back(in[i + 2]);
            if ((temp == "fin" && _isAlpha(in[i + 3]) == false) || (temp == "fou" && in[i + 3] == 't' && _isAlpha(in[i + 4]) == false))
            {
                in[i] = 'c';
            }
        }

        fout << in << '\n';
    }

    cout << "Create OJ file: " << OjCpp << " succeed!" << '\n';
    
    return 0;
}