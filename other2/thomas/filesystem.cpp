#include <bits/stdc++.h>
#include <experimental/filesystem>

#include <windows.h>

namespace fs = std::experimental::filesystem;

using namespace std;

void v()
{
    fs::path p = fs::current_path();
 
    std::cout << "The current path " << p << " decomposes into:\n"
              << "root name " << p.root_name() << '\n'
              << "root directory " << p.root_directory() << '\n'
              << "relative path " << p.relative_path() << '\n';

    for(auto & p2: fs::recursive_directory_iterator(p))
    {
        std::cout << p2.path() << " | " << p2.path().filename() << '\n';              
    }
}

/**
 * 查找文件是否存在，如果不存在ans是空字符串，存在ans是全路径+文件名 (Win API)
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
    v();
    return 0;
}