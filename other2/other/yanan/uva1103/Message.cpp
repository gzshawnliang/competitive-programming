#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <vector>
//#include <windows.h>

using namespace std;

int Amount=0;

string convert(string X)
{
    string NewX="";
    for(int i=0;i<X.size();++i)
    {
        if(X[i]=='0')
        {
            NewX+="0000";
        }
        else if(X[i]=='1')
        {
            NewX+="0001";
        }
        else if(X[i]=='2')
        {
            NewX+="0010";
        }
        else if(X[i]=='3')
        {
            NewX+="0011";
        }
        else if(X[i]=='4')
        {
            NewX+="0100";
        }
        else if(X[i]=='5')
        {
            NewX+="0101";
        }
        else if(X[i]=='6')
        {
            NewX+="0110";
        }
        else if(X[i]=='7')
        {
            NewX+="0111";
        }
        else if(X[i]=='8')
        {
            NewX+="1000";
        }
        else if(X[i]=='9')
        {
            NewX+="1001";
        }
        else if(X[i]=='a')
        {
            NewX+="1010";
        }
        else if(X[i]=='b')
        {
            NewX+="1011";
        }
        else if(X[i]=='c')
        {
            NewX+="1100";
        }
        else if(X[i]=='d')
        {
            NewX+="1101";
        }
        else if(X[i]=='e')
        {
            NewX+="1110";
        }
        else if(X[i]=='f')
        {
            NewX+="1111";
        }
    }
    return NewX;
}

bool Out(int x,int y,int SizeX,int SizeY)
{
    if(x<0 || y<0 || x>=SizeX || y>=SizeY)
    {
        return false;
    }
    return true;
}

void background(vector<string> & I,int x,int y,int level)
{
    if(level>=10000)
    {
        return;
    }
    if(Out(x+1,y,I.size(),I[0].size())==true)
    {
        if(I[x+1][y]=='0')
        {
            I[x+1][y]='o';
            background(I,x+1,y,level+1); 
        }
    }
    if(Out(x-1,y,I.size(),I[0].size())==true)
    {
        if(I[x-1][y]=='0')
        {
            I[x-1][y]='o';
            background(I,x-1,y,level+1);
        }
    }
    if(Out(x,y-1,I.size(),I[0].size())==true)
    {
        if(I[x][y-1]=='0')
        {
            I[x][y-1]='o';
            background(I,x,y-1,level+1);
        }
    }
    if(Out(x,y+1,I.size(),I[0].size())==true)
    {
        if(I[x][y+1]=='0')
        {
            I[x][y+1]='o';
            background(I,x,y+1,level+1);
        }
    }
    return;
}   

bool Inside(vector<string> & I,int x,int y,int level,bool & complete)
{
    if(level>=10000)
    {
        complete=true;
        return true;
    }
    if(complete==true)
    {
        return true; 
    }
    if(Out(x+1,y,I.size(),I[0].size())==true)
    {
        if(I[x+1][y]=='0')
        {
            I[x+1][y]='Q';
            Inside(I,x+1,y,level+1,complete);
        }
    }
    if(Out(x-1,y,I.size(),I[0].size())==true)
    {
        if(I[x-1][y]=='0')
        {
            I[x-1][y]='Q';
            Inside(I,x-1,y,level+1,complete);
        }
    }
    if(Out(x,y-1,I.size(),I[0].size())==true)
    {
        if(I[x][y-1]=='0')
        {
            I[x][y-1]='Q';
            Inside(I,x,y-1,level+1,complete);
        }
    }
    if(Out(x,y+1,I.size(),I[0].size())==true)
    {
        if(I[x][y+1]=='0')
        {
            I[x][y+1]='Q';
            Inside(I,x,y+1,level+1,complete);
        }
    }
    if(complete==true)
    {
        return true; 
    }
    return false;
}

void hieroglyphs(vector<string> & I,int x,int y)
{
    bool initiate=false;
    if(Out(x+1,y,I.size(),I[0].size())==true)
    {
        if(I[x+1][y]=='1')
        {
            I[x+1][y]='l';
            hieroglyphs(I,x+1,y);
        }
        if(I[x+1][y]=='0')
        {
            I[x+1][y]='Q';
            bool temp=Inside(I,x+1,y,0,initiate);
            if(temp==false)
            {
                ++Amount;
            }
        }
    }
    if(Out(x-1,y,I.size(),I[0].size())==true)
    {
        if(I[x-1][y]=='1')
        {
            I[x-1][y]='l';
            hieroglyphs(I,x-1,y);
        }
        if(I[x-1][y]=='0')
        {
            I[x-1][y]='Q';
            bool temp=Inside(I,x-1,y,0,initiate);
            if(temp==false)
            {
                ++Amount;
            }
        }
    }
    if(Out(x,y-1,I.size(),I[0].size())==true)
    {
        if(I[x][y-1]=='1')
        {
            I[x][y-1]='l';
            hieroglyphs(I,x,y-1);
        }
        if(I[x][y-1]=='0')
        {
            I[x][y-1]='Q';
            bool temp=Inside(I,x,y-1,0,initiate);
            if(temp==false)
            {
                ++Amount;
            }
        }
    }
    if(Out(x,y+1,I.size(),I[0].size())==true)
    {
        if(I[x][y+1]=='1')
        {
            I[x][y+1]='l';
            hieroglyphs(I,x,y+1);
        }
        if(I[x][y+1]=='0')
        {
            I[x][y+1]='Q';
            bool temp=Inside(I,x,y+1,0,initiate);
            if(temp==false)
            {
                ++Amount;
            }
        }
    }
    return;
}

int main()
{
    ifstream cin("Message.in");
    ofstream cout("Message.out");
    int n=1;
    while(true)
    {
        int H,W;
        cin>>H>>W;
        if(H==0 && W==0)
        {
            break;
        }
        vector<string> image(H+2);
        string useless;
        getline(cin,useless);
        for(int i=0;i<W*4+2;++i)
        {
            image[0]+='0';
        }
        for(int i=1;i<H+1;++i)
        {
            image[i]+='0';
            string temp;
            getline(cin,temp);
            temp=convert(temp);
            image[i]+=temp;
            image[i]+='0';
        }
        for(int i=0;i<W*4+2;++i)
        {
            image[H+1]+='0';
        }
        image[0][0]='o';
        for(int i=0;i<H+2;++i)
        {
            if(i==0 || i==H+1)
            {
                for(int h=0;h<image[0].size();++h)
                {
                    background(image,i,h,0);
                }
            }
            else
            {
                background(image,i,0,0);
                background(image,i,image[0].size()-1,0);
            }
        }
        // for(int i=1;i<H+1;++i)
        // {
        //     cout<<image[i]<<endl;
        // }
        vector<char> answer;
        for(int i=1;i<H+1;++i)
        {
            for(int h=1;h<W*4+1;++h)
            {
                if(image[i][h]=='1')
                {
                    image[i][h]='l';
                    Amount=0;
                    hieroglyphs(image,i,h);
                    if(Amount==0)
                    {
                        answer.push_back('W');
                    }
                    else if(Amount==1)
                    {
                        answer.push_back('A');
                    }
                    else if(Amount==2)
                    {
                        answer.push_back('K');
                    }
                    else if(Amount==3)
                    {
                        answer.push_back('J');
                    }
                    else if(Amount==4)
                    {
                        answer.push_back('S');
                    }
                    else if(Amount==5)
                    {
                        answer.push_back('D');
                    }
                }
            }
        }
        sort(answer.begin(),answer.end());
        cout<<"Case "<<n<<": ";
        for(int i=0;i<answer.size();++i)
        {
            cout<<answer[i];
        }
        cout<<endl;
        ++n;
    }
    //system("pause");
    return 0;
}