#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int main()
{
    ifstream fin("meetings.in");
    ofstream fout("meetings.out");
    int l,n,htotalw=0;
    fin >> n >> l;
    //vector<cow> c;
    vector<pi> ctr;
    vector<pi> ctl;
    vector<pi> dis;
    for (int i = 0; i < n;++i)
    {
        int tw, td, tp;
        fin >> tw >> tp >> td;
        dis.push_back(pi(tp, tw));
        if(td==1)
        {
            ctr.push_back(pi(tp, tw));
        }
        else
        {
            ctl.push_back(pi(tp, tw));
        }
        htotalw += tw;
    }
    htotalw /= 2;
    sort(dis.begin(), dis.end());
    sort(ctr.begin(), ctr.end());
    reverse(ctr.begin(), ctr.end());
    sort(ctl.begin(), ctl.end());
    vector<pi> tol, tor;
    //calculating time
    int lw = 0, rw = 0;
    int j = 0;
    for (int i = 0; i < ctl.size(); ++i)
    {
        tol.push_back(pi(ctl[i].first, dis[j].second));
        ++j;
    }
    j = dis.size() - 1;
    for (int i = 0; i < ctr.size(); ++i)
    {
        tor.push_back(pi(l - ctr[i].first, dis[j].second));
        --j;
    }
    int i = 0, anst=0;
    j = 0;
    bool rcon = true, lcon = true;
    while (true)
    {
        if(rcon==true&&lcon==true)
        {
            if (tor[i].first < tol[j].first)
            {
                rw += tor[i].second;
                if (rw+lw >= htotalw)
                {
                    anst = tor[i].first;
                    break;
                }
                ++i;
                if (i >= tor.size())
                {
                    rcon = false;
                }
            }
            else if (tor[i].first > tol[j].first)
            {
                lw += tol[j].second;
                if (rw + lw >= htotalw)
                {
                    anst = tol[j].first;
                    break;
                }
                ++j;
                if (j >= tol.size())
                {
                    lcon = false;
                }
            }
            else
            {
                rw += tor[i].second;
                if (rw + lw >= htotalw)
                {
                    anst = tor[i].first;
                    break;
                }
                ++i;
                if (i >= tor.size())
                {
                    rcon = false;
                }
                lw += tol[j].second;
                if (rw + lw >= htotalw)
                {
                    anst = tol[j].first;
                    break;
                }
                ++j;
                if (j >= tol.size())
                {
                    lcon = false;
                }
            }
        }
        else if(rcon==true)
        {
            rw += tor[i].second;
            if (rw >= htotalw)
            {
                anst = tor[i].first;
                break;
            }
            ++i;
            if (i >= tor.size())
            {
                rcon = false;
            }
        }
        else if(lcon==true)
        {
            lw += tol[j].second;
            if (lw >= htotalw)
            {
                anst = tol[j].first;
                break;
            }
            ++j;
            if (j >= tol.size())
            {
                lcon = false;
            }
        }
        else 
        {
            break;
        }
    }
    //int t = Time(ctr, ctl, dis, htotalw);
    int ans = 0;
    for (int i = 0; i < ctr.size();++i)
    {
        for (int h = 0; h < ctl.size();++h)
        {
            if(ctr[i].first+2*anst>=ctl[h].first && ctr[i].first<ctl[h].first)
            {
                ++ans;
            }
        }
    }
    fout << ans<<'\n';
    return 0;
}

// struct cow
// {
//     int w;
//     int d;
//     int p;
// };

// int Time(vector<pi> & ctr, vector<pi> & ctl, vector<pi> & dis, int midw)
// {
//     int t;
//     int leftw=0, rightw=0;
//     int rightn=0, leftn=0;
//     bool r=true, l=true;
//     if(1>ctl.size())
//     {
//         l = false;
//     }
//     if(1>ctr.size())
//     {
//         r = false;
//     }
//     for (int i = 0; i < dis.size();++i)
//     {
//         if(dis[i].second==1)
//         {
//             if(l==true)
//             {
//                 leftw += ctl[leftn].second;
//                 if(leftw>=midw)
//                 {
//                     ///////////////////////
//                     break;
//                 }
//                 ++leftn;
//                 if (leftn >= ctl.size())
//                 {
//                     l = false;
//                 }
//             }
//             else
//             {
//                 leftw+=ctr[rightn].second;
//                 if (leftw >= midw)
//                 {
//                     ///////////////////////////
//                     break;
//                 }
//                 ++rightn;
//             }
//         }
//         else
//         {
//             if (r == true)
//             {
//                 rightw += ctr[rightn].second;
//                 if (rightw >= midw)
//                 {
//                     //////////////////////////////
//                     break;
//                 }
//                 ++rightn;
//                 if(rightn>=ctr.size())
//                 {
//                     r = false;
//                 }
//             }
//             else
//             {
//                 rightw += ctl[leftn].second;
//                 if (rightw >= midw)
//                 {
//                     //////////////////////////////////
//                     break;
//                 }
//                 ++leftn;
//             }
//         }
//     }
//     return t;
// }