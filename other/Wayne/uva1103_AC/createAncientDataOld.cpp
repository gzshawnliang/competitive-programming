#include <bits/stdc++.h>
#include <MyRandom.h>

using namespace std;

//2进制转16进制
string binToHex(string bit_string)
{
    bitset<64> b3(bit_string);
    unsigned long long a = b3.to_ullong();
    
    string result;
    stringstream ss;

    ss << hex << a;
    ss >> result;
    return result;
}

//16进制转2进制
unordered_map<char, string> hexToBinary = {
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'a', "1010"},
    {'b', "1011"},
    {'c', "1100"},
    {'d', "1101"},
    {'e', "1110"},
    {'f', "1111"},
    {'A', "1010"},
    {'B', "1011"},
    {'C', "1100"},
    {'D', "1101"},
    {'E', "1110"},
    {'F', "1111"}
    };

string repeat(const string & s, int n) 
{ 
    if(n<=0)
    {
        return s;
    }
    string s1 = s; 
  
    for (int i=1; i<n;i++) 
        s1 += s; 
  
    return s1; 
}

int main()
{
    // ifstream fin("createAncientData.in");

    int fileCount=5;
    random myRand;
    
    ofstream fout;
    ofstream fout2;
    for (int ifile = 1; ifile <= fileCount; ++ifile)
    {
        fout.open("data_new_2_"+ to_string(ifile)+".out");
        fout2.open("data_new_2_"+ to_string(ifile)+".txt");
        int testCase=20;
        while(testCase--)
        {
            int H=myRand.GetRand(1,200);
            int W=myRand.GetRand(1,12)*4;
            int backgroundCount =myRand.GetRand(1,2)*4;
            
            fout << H << " " << W+backgroundCount << "\n";
            //fout2 << H << " " << W+backgroundCount << "\n";        
            vector<string> vecBin;
            
            bool existHole=false;
            for (int i = 0; i <= H - 1; ++i)
            {
                string binString=repeat("1",W);
                
                int onePieCount=myRand.GetRand(1,3);
                while(onePieCount--)
                {
                    int beginId=myRand.GetRand(0,W);
                    int endId=beginId+myRand.GetRand(0,W);
                    if(endId<=W-1)
                    {
                        for (int j = beginId; j <=endId; ++j)
                        {
                            binString[j]='0';
                        }
                        existHole=true;
                    }
                }
                
                for (int j = 0; j <= backgroundCount - 1; ++j)
                {
                    if(myRand.GetBoolRand()==true)
                    {
                        binString.push_back('0');
                    }
                    else
                    {
                        binString = "0" + binString;
                    }
                }
                vecBin.push_back(binString);
            }

            if(!existHole)
            {
                vector<int> rd=myRand.GetUniqueRand(1,H);
                int icount=myRand.GetRand(0,H-1);
                for (int i = 0; i <= icount - 1; ++i)
                {
                    int beginId=myRand.GetRand(0,W-1);
                    int endId=beginId+myRand.GetRand(0,W);
                    if(endId<=W-1)
                    {
                        for (int j = beginId; j <=endId; ++j)
                        {
                            vecBin[rd[i]][j]='0';
                        }
                    }
                    else
                    {
                        vecBin[rd[i]][beginId]='0';
                    }
                    
                }
            }
            
            vector<string> vecHex(vecBin.size());
            int maxHexSize=0;
            for (int i = 0; i <= vecBin.size() - 1; ++i)
            {
                fout << vecBin[i]<< "\n";
                string hexString = binToHex(vecBin[i]);
                vecHex[i]=hexString;
                maxHexSize = maxHexSize>hexString.size()?maxHexSize:hexString.size();
            }
            //++maxHexSize;
            fout2 << H << " " << maxHexSize  << "\n";        
            for (int i = 0; i <= vecBin.size() - 1; ++i)
            {
                //string hexString = binToHex(vecBin[i]);
                string hexString = vecHex[i];
                if(hexString.size()<maxHexSize)
                {
                    vecHex[i]=repeat("0", maxHexSize-hexString.size())+hexString;    
                }
                fout2 <<vecHex[i] << "\n";
            }
        }
        
        fout << 0 << " " << 0 << "\n";
        fout2 << 0 << " " << 0 << "\n";

        fout.close();
        fout2.close();
    }

    return 0;
}


int main2()
{
    ifstream fin("data_new_2_1.txt");
    ofstream fout("data_new_2_1.bin");
    while(true)
    {
        int H=0;
        int W=0;        
        fin >> H >> W;
        if(H==0 && W==0)
            break;

        fout << H << " " << W*4 << "\n";
        string useless;
        getline(fin,useless);

        for (int i = 0; i <= H - 1; ++i)
        {
            string hexString;
            getline(fin,hexString);
            string binString="";
            for (int j = 0; j <= hexString.size() - 1; ++j)
            {
                binString+=hexToBinary[hexString[j]];
            }
            fout << binString << "\n";
        }
    }
    fout << 0 << " " << 0 << "\n";
    
    return 0;
}

