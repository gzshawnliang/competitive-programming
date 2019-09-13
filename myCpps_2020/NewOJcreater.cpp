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

using namespace std;

//***************************************
const string CPPfile = "wheresWaldorf_UVA10010"; //*
//***************************************

ifstream fin;
ofstream fout;



bool _isAlpha(char a)
{
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
}

/**
 * 查找文件是否存在，如果不存在ans是空字符串，存在ans是全路径+文件名
 * @param  {char*} dir         : 文件目录
 * @param  {string} c_FileName : 需要查找的文件名称
 * @param  {string} ans        : 返回文件名称，不存在ans是空字符串，存在ans是全路径+文件名
 */
void findFile(const char * dir,const string & c_FileName,string & ans)
{
    
    HANDLE hFind;
    WIN32_FIND_DATA findData;
    char dirNew[100];
    
    // 向目录加通配符，用于搜索第一个文件 
    strcpy(dirNew, dir);
    strcat(dirNew, "\\*.*");
    
    hFind = FindFirstFile(dirNew, &findData);    
    do
    {
        // 是否是文件夹，并且名称不为"."或".." 
        if ((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0
        && strcmp(findData.cFileName, ".") != 0
        && strcmp(findData.cFileName, "..") != 0
        )
        {
            // 将dirNew设置为搜索到的目录，并进行下一轮搜索 
            strcpy(dirNew, dir);
            strcat(dirNew, "\\");
            strcat(dirNew, findData.cFileName);
            findFile(dirNew,c_FileName,ans);
        }
        else if(strcmp(findData.cFileName, ".") !=0 && strcmp(findData.cFileName, "..") != 0)
        {
            // LARGE_INTEGER size;
            // size.LowPart = findData.nFileSizeLow;
            // size.HighPart = findData.nFileSizeHigh;
            //cout << dir << "\\"<< findData.cFileName << "\t" << size.QuadPart << " bytes\n";
            string fileName = string(findData.cFileName);
            if(fileName == c_FileName)
            {
                ans=string(dir) + "\\" + fileName;
                break;
            }
                //return string(dir) + "\\" + fileName;
        }
    } while (FindNextFile(hFind, &findData));
    
    FindClose(hFind);
}
/**
 * 获取当前路径
 * @return {string}  : 
 */
string CurrPath() 
{
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}

int main()
{
    string noFoundErrMsg ="error : file "+ CPPfile + ".cpp" + " no found!";
    string cpp=CPPfile + ".cpp";
    string Path =CurrPath();
    string cppfileFullName="";
    findFile(Path.c_str(),cpp,cppfileFullName);
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

    cout << OjCpp << '\n';
    
    return 0;
}