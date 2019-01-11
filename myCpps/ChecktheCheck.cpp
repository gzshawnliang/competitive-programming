#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cmath>
#include <algorithm>
using namespace std;

void ChecktheCheck();
vector< vector<char> > Configuration(8,vector<char> (8));
int gametime=0;
bool overflow(int OFx,int OFy);
int BCTCwithPawn(int Kx,int Ky);
int WCTCwithPawn(int Kx,int Ky);
int BCTCwithRookQueen(int Kx,int Ky);
int WCTCwithRookQueen(int Kx,int Ky);
int BCTCwithKnight(int Kx,int Ky);
int WCTCwithKnight(int Kx,int Ky);
int BCTCwithBishopQueen(int Kx,int Ky);
int WCTCwithBishopQueen(int Kx,int Ky);
int CTCwithKing(int Kx,int Ky);

int main()
{
    ChecktheCheck();
    //system("pause");
    return 0;
}

void ChecktheCheck()
{
    ifstream cin("CTC.in");
    ofstream cout("ChecktheCheck.out");
    while(true)
    {
        int BKx=0,BKy=0,WKx=0,WKy=0;
        bool configuration=false;
        for(int i=0;i<8;++i)
        {
            for(int h=0;h<8;++h)
            {
                cin>>Configuration[i][h];
                if(Configuration[i][h]=='k')
                {
                    BKx=i;
                    BKy=h;
                }
                if(Configuration[i][h]=='K')
                {
                    WKx=i;
                    WKy=h;
                }
                if(configuration==false)
                {
                    if(Configuration[i][h]!='.')
                    {
                        configuration=true;
                    }
                }
            }
        }
        ++gametime;
        if(configuration==false)
        {
            break;
        }
        //Check the Check with Pawn
        if(WCTCwithPawn(WKx,WKy)==0)
        {
            cout<<"Game #"<<gametime<<": white king is in check."<<endl;
            continue;
        }
        //Check the Check with Rook and Queen
        if(WCTCwithRookQueen(WKx,WKy)==0)
        {
            cout<<"Game #"<<gametime<<": white king is in check."<<endl;
            continue;
        }
        //Check the Check with Knight
        if(WCTCwithKnight(WKx,WKy)==0)
        {
            cout<<"Game #"<<gametime<<": white king is in check."<<endl;
            continue;
        }
        //Check the Check with Bishop and Queen
        if(WCTCwithBishopQueen(WKx,WKy)==0)
        {
            cout<<"Game #"<<gametime<<": white king is in check."<<endl;
            continue;
        } 
        //Check the Check with King
        if(CTCwithKing(WKx,WKy)==0)
        {
            cout<<"Game #"<<gametime<<": white king is in check."<<endl;
            continue;
        }
        if(BCTCwithBishopQueen(BKx,BKy)==0)
        {
            cout<<"Game #"<<gametime<<": black king is in check."<<endl;
            continue;
        }
        if(BCTCwithRookQueen(BKx,BKy)==0)
        {
            cout<<"Game #"<<gametime<<": black king is in check."<<endl;
            continue;
        }
        if(BCTCwithPawn(BKx,BKy)==0)
        {
            cout<<"Game #"<<gametime<<": black king is in check."<<endl;;
            continue;
        }
        if(BCTCwithKnight(BKx,BKy)==0)
        {
            cout<<"Game #"<<gametime<<": black king is in check."<<endl;
            continue;
        }
        cout<<"Game #"<<gametime<<": no king is in check."<<endl;
    }
}

bool overflow(int OFx,int OFy)
{
    if(OFx<0 || OFx>7 || OFy<0 || OFy>7)
    {
        return false;
    }
    return true;
}

int BCTCwithPawn(int Kx,int Ky)
{
    if(overflow(Kx+1,Ky-1)==true)
    {
        if (Configuration[Kx + 1][Ky - 1] == 'P')
        {
            return 0;
        }
    }
    if(overflow(Kx+1,Ky+1)==true)
    {
        if (Configuration[Kx + 1][Ky + 1] == 'P')
        {
            return 0;
        }
    }
    return 1;
}

int WCTCwithPawn(int Kx,int Ky)
{
    if(overflow(Kx-1,Ky-1)==true)
    {
        if (Configuration[Kx - 1][Ky - 1] == 'p')
        {
            return 0;
        }
    }
    if(overflow(Kx-1,Ky+1)==true)
    {
        if (Configuration[Kx - 1][Ky + 1] == 'p')
        {
            return 0;
        }
    }
    return 1;
}

int BCTCwithRookQueen(int Kx,int Ky)
{
    bool BCTCwRQ = false,BCTCwRQ2 = false;
    //Check with black king (x)
    for (int i = 0; i < 8; ++i)
    {
        if (Configuration[Kx][i] == 'R' || Configuration[Kx][i] == 'Q')
        {
            BCTCwRQ = true;
            if(i<Ky-1)
            {
                int temp=i+1;
                while(temp<Ky)
                {
                    if(Configuration[Kx][temp]!='.')
                    {
                        BCTCwRQ = false;
                        break;
                    }
                    ++temp;
                }
            }
            else if(i>Ky+1)
            {
                int temp=i-1;
                while(temp>Ky)
                {
                    if(Configuration[Kx][temp]!='.')
                    {
                        BCTCwRQ = false;
                        break;
                    }
                    --temp;
                }
            }
            else
            {
                return 0;
            }
            if (BCTCwRQ == true)
            {
                return 0;
            }
        }
    }
    //Check with black king (y)
    for (int i = 0; i < 8; ++i)
    {
        if (Configuration[i][Ky] == 'R' || Configuration[i][Ky] == 'Q')
        {
            BCTCwRQ2 = true;
            if(i<Kx-1)
            {
                int temp=i+1;
                while(temp<Kx)
                {
                    if(Configuration[temp][Ky]!='.')
                    {
                        BCTCwRQ2 = false;
                        break;
                    }
                    ++temp;
                }
            }
            else if(i>Kx+1)
            {
                int temp=i-1;
                while(temp>Kx)
                {
                    if(Configuration[temp][Ky]!='.')
                    {
                        BCTCwRQ2 = false;
                        break;
                    }
                    --temp;
                }
            }
            else
            {
                return 0;
            }
            if (BCTCwRQ2 == true)
            {
                return 0;
            }
        }
    }
    return 1;
}

int WCTCwithRookQueen(int Kx,int Ky)
{
    bool WCTCwRQ = false,WCTCwRQ2 = false;
    //Check with White king (x)
    for (int i = 0; i < 8; ++i)
    {
        if (Configuration[Kx][i] == 'r' || Configuration[Kx][i] == 'q')
        {
            WCTCwRQ = true;
            if(i<Ky-1)
            {
                int temp=i+1;
                while(temp<Ky)
                {
                    if(Configuration[Kx][temp]!='.')
                    {
                        WCTCwRQ = false;
                        break;
                    }
                    ++temp;
                }
            }
            else if(i>Ky+1)
            {
                int temp=i-1;
                while(temp>Ky)
                {
                    if(Configuration[Kx][temp]!='.')
                    {
                        WCTCwRQ = false;
                        break;
                    }
                    --temp;
                }
            }
            else
            {
                return 0;
            }
            if(WCTCwRQ == true)
            {
                return 0;
            }
        }
    }
    if (WCTCwRQ == true)
    {
        return 0;
    }
    //Check with White king (y)
    for (int i = 0; i < 8; ++i)
    {
        if (Configuration[i][Ky] == 'r' || Configuration[i][Ky] == 'q')
        {
            WCTCwRQ2 = true;
            if(i<Kx-1)
            {
                int temp=i+1;
                while(temp<Kx)
                {
                    if(Configuration[temp][Ky]!='.')
                    {
                        WCTCwRQ2 = false;
                        break;
                    }
                    ++temp;
                }
            }
            else if(i>Kx+1)
            {
                int temp=i-1;
                while(temp>Kx)
                {
                    if(Configuration[temp][Ky]!='.')
                    {
                        WCTCwRQ2 = false;
                        break;
                    }
                    --temp;
                }
            }
            else
            {
                return 0;
            }
            if (WCTCwRQ2 == true)
            {
                return 0;
            }
        }
    }
    return 1;
}

int BCTCwithKnight(int Kx,int Ky)
{
    vector<int> Knx;
    Knx.push_back(2);
    Knx.push_back(1);
    Knx.push_back(-1);
    Knx.push_back(-2);
    Knx.push_back(-2);
    Knx.push_back(-1);
    Knx.push_back(1);
    Knx.push_back(2);
    vector<int> Kny;
    Kny.push_back(1);
    Kny.push_back(2);
    Kny.push_back(2);
    Kny.push_back(1);
    Kny.push_back(-1);
    Kny.push_back(-2);
    Kny.push_back(-2);
    Kny.push_back(-1);
    for(int i=0;i<8;++i)
    {
        if (overflow(Kx + Knx[i], Ky + Kny[i]) == true)
        {
            if (Configuration[Kx + Knx[i]][Ky + Kny[i]] == 'N')
            {
                return 0;
            }
        }
        else
        {
            continue;
        }
    }
    return 1;
}

int WCTCwithKnight(int Kx,int Ky)
{
    vector<int> Knx;
    Knx.push_back(2);
    Knx.push_back(1);
    Knx.push_back(-1);
    Knx.push_back(-2);
    Knx.push_back(-2);
    Knx.push_back(-1);
    Knx.push_back(1);
    Knx.push_back(2);
    vector<int> Kny;
    Kny.push_back(1);
    Kny.push_back(2);
    Kny.push_back(2);
    Kny.push_back(1);
    Kny.push_back(-1);
    Kny.push_back(-2);
    Kny.push_back(-2);
    Kny.push_back(-1);
    for(int i=0;i<8;++i)
    {
        if (overflow(Kx + Knx[i], Ky + Kny[i]) == true)
        {
            if (Configuration[Kx + Knx[i]][Ky + Kny[i]] == 'n')
            {
                return 0;
            }
        }
        else
        {
            continue;
        }
    }
    return 1;
}

int BCTCwithBishopQueen(int Kx,int Ky)
{
    int tKx=Kx,tKy=Ky;
    //左斜上列
    while(true)
    {
        if(overflow(tKx-1,tKy-1)==true)
        {
            --tKx;
            --tKy;
            if(Configuration[tKx][tKy]=='B' || Configuration[tKx][tKy]=='Q')
            {
                bool CwBQ=true;
                int hh=Kx-(tKx+1),hhh=1,ttKx=tKx,ttKy=tKy;
                while(hhh<=hh)
                {
                    ++ttKx;
                    ++ttKy;
                    if(Configuration[ttKx][ttKy]!='.' && Configuration[ttKx][ttKy]!='k')
                    {
                        CwBQ=false;
                        break;
                    }
                    ++hhh;
                }
                if(CwBQ==true)
                {
                    return 0;
                }
            }
        }
        else
        {
            break;
        }
    }
    tKx=Kx;
    tKy=Ky;
    //右斜上列
    while(true)
    {
        if(overflow(tKx-1,tKy+1)==true)
        {
            --tKx;
            ++tKy;
            if(Configuration[tKx][tKy]=='B' || Configuration[tKx][tKy]=='Q')
            {
                bool CwBQ=true;
                int hh=Kx-(tKx+1),hhh=1,ttKx=tKx,ttKy=tKy;
                while(hhh<=hh)
                {
                    ++ttKx;
                    --ttKy;
                    if(Configuration[ttKx][ttKy]!='.' && Configuration[ttKx][ttKy]!='k')
                    {
                        CwBQ=false;
                        break;
                    }
                    ++hhh;
                }
                if(CwBQ==true)
                {
                    return 0;
                }
            }
        }
        else
        {
            break;
        }
    }
    tKx=Kx;
    tKy=Ky;
    //左斜下列
    while(true)
    {
        if(overflow(tKx+1,tKy-1)==true)
        {
            ++tKx;
            --tKy;
            if(Configuration[tKx][tKy]=='B' || Configuration[tKx][tKy]=='Q')
            {
                bool CwBQ=true;
                int hh=tKx-1-Kx,hhh=1,ttKx=tKx,ttKy=tKy;
                while(hhh<=hh)
                {
                    --ttKx;
                    ++ttKy;
                    if(Configuration[ttKx][ttKy]!='.' && Configuration[ttKx][ttKy]!='k')
                    {
                        CwBQ=false;
                        break;
                    }
                    ++hhh;
                }
                if(CwBQ==true)
                {
                    return 0;
                }
            }
        }
        else
        {
            break;
        }
    }
    tKx=Kx;
    tKy=Ky;
    //右斜下列
    while(true)
    {
        if(overflow(tKx+1,tKy+1)==true)
        {
            ++tKx;
            ++tKy;
            if(Configuration[tKx][tKy]=='B' || Configuration[tKx][tKy]=='Q')
            {
                bool CwBQ=true;
                int hh=tKx-1-Kx,hhh=1,ttKx=tKx,ttKy=tKy;
                while(hhh<=hh)
                {
                    --ttKx;
                    --ttKy;
                    if(Configuration[ttKx][ttKy]!='.' && Configuration[ttKx][ttKy]!='k')
                    {
                        CwBQ=false;
                        break;
                    }
                    ++hhh;
                }
                if(CwBQ==true)
                {
                    return 0;
                }
            }
        }
        else
        {
            break;
        }
    }
    return 1;
}

int WCTCwithBishopQueen(int Kx,int Ky)
{
    int tKx=Kx,tKy=Ky;
    //左斜上列
    while(true)
    {
        if(overflow(tKx-1,tKy-1)==true)
        {
            --tKx;
            --tKy;
            if(Configuration[tKx][tKy]=='b' || Configuration[tKx][tKy]=='q')
            {
                bool CwBQ=true;
                int hh=Kx-(tKx+1),hhh=1,ttKx=tKx,ttKy=tKy;
                while(hhh<=hh)
                {
                    ++ttKx;
                    ++ttKy;
                    if(Configuration[ttKx][ttKy]!='.' && Configuration[ttKx][ttKy]!='K')
                    {
                        CwBQ=false;
                        break;
                    }
                    ++hhh;
                }
                if(CwBQ==true)
                {
                    return 0;
                }
            }
        }
        else
        {
            break;
        }
    }
    tKx=Kx;
    tKy=Ky;
    //右斜上列
    while(true)
    {
        if(overflow(tKx-1,tKy+1)==true)
        {
            --tKx;
            ++tKy;
            if(Configuration[tKx][tKy]=='b' || Configuration[tKx][tKy]=='q')
            {
                bool CwBQ=true;
                int hh=Kx-(tKx+1),hhh=1,ttKx=tKx,ttKy=tKy;
                while(hhh<=hh)
                {
                    ++ttKx;
                    --ttKy;
                    if(Configuration[ttKx][ttKy]!='.' && Configuration[ttKx][ttKy]!='K')
                    {
                        CwBQ=false;
                        break;
                    }
                    ++hhh;
                }
                if(CwBQ==true)
                {
                    return 0;
                }
            }
        }
        else
        {
            break;
        }
    }
    tKx=Kx;
    tKy=Ky;
    //左斜下列
    while(true)
    {
        if(overflow(tKx+1,tKy-1)==true)
        {
            ++tKx;
            --tKy;
            if(Configuration[tKx][tKy]=='b' || Configuration[tKx][tKy]=='q')
            {
                bool CwBQ=true;
                int hh=tKx-1-Kx,hhh=1,ttKx=tKx,ttKy=tKy;
                while(hhh<=hh)
                {
                    --ttKx;
                    ++ttKy;
                    if(Configuration[ttKx][ttKy]!='.' && Configuration[ttKx][ttKy]!='K')
                    {
                        CwBQ=false;
                        break;
                    }
                    ++hhh;
                }
                if(CwBQ==true)
                {
                    return 0;
                }
            }
        }
        else
        {
            break;
        }
    }
    tKx=Kx;
    tKy=Ky;
    //右斜下列
    while(true)
    {
        if(overflow(tKx+1,tKy+1)==true)
        {
            ++tKx;
            ++tKy;
            if(Configuration[tKx][tKy]=='b' || Configuration[tKx][tKy]=='q')
            {
                bool CwBQ=true;
                int hh=tKx-1-Kx,hhh=1,ttKx=tKx,ttKy=tKy;
                while(hhh<=hh)
                {
                    --ttKx;
                    --ttKy;
                    if(Configuration[ttKx][ttKy]!='.' && Configuration[ttKx][ttKy]!='K')
                    {
                        CwBQ=false;
                        break;
                    }
                    ++hhh;
                }
                if(CwBQ==true)
                {
                    return 0;
                }
            }
        }
        else
        {
            break;
        }
    }
    return 1;
}

int CTCwithKing(int Kx,int Ky)
{
    vector<int> Knx;
    Knx.push_back(-1);
    Knx.push_back(-1);
    Knx.push_back(-1);
    Knx.push_back(0);
    Knx.push_back(0);
    Knx.push_back(1);
    Knx.push_back(1);
    Knx.push_back(1);
    vector<int> Kny;
    Kny.push_back(-1);
    Kny.push_back(0);
    Kny.push_back(1);
    Kny.push_back(-1);
    Kny.push_back(1);
    Kny.push_back(-1);
    Kny.push_back(0);
    Kny.push_back(1);
    for(int i=0;i<8;++i)
    {
        if (overflow(Kx + Knx[i], Ky + Kny[i]) == true)
        {
            if (Configuration[Kx + Knx[i]][Ky + Kny[i]] == 'k')
            {
                return 0;
            }
        }
        else
        {
            continue;
        }
    }
    return 1;
}