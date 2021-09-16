#include <bits/stdc++.h>
#include <MyRandom.h>

using namespace std;

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

string hexToBin(string hex_string)
{
    string result;
    stringstream ss;

    for (int i = 0; i <= hex_string.size() - 1; ++i)
    {
         switch(hex_string[i])
         {
             case '0': ss<<"0000"; break;
             case '1': ss<<"0001"; break;
             case '2': ss<<"0010"; break;
             case '3': ss<<"0011"; break;
             case '4': ss<<"0100"; break;
             case '5': ss<<"0101"; break;
             case '6': ss<<"0110"; break;
             case '7': ss<<"0111"; break;
             case '8': ss<<"1000"; break;
             case '9': ss<<"1001"; break;
             case 'A': ss<<"1010"; break;
             case 'B': ss<<"1011"; break;
             case 'C': ss<<"1100"; break;
             case 'D': ss<<"1101"; break;
             case 'E': ss<<"1110"; break;
             case 'F': ss<<"1111"; break;
             case 'a': ss<<"1010"; break;
             case 'b': ss<<"1011"; break;
             case 'c': ss<<"1100"; break;
             case 'd': ss<<"1101"; break;
             case 'e': ss<<"1110"; break;
             case 'f': ss<<"1111"; break;
             default:  ss<<"nInvalid hexadecimal digit "<<hex_string[i];
         }        
    }

    ss >> result;
    return result;
}


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

    int fileCount=30;
    random myRand;
    
    ofstream fout;
    ofstream fout2;
    for (int ifile = 1; ifile <= fileCount; ++ifile)
    {
        fout.open("data_new_4_"+ to_string(ifile)+".bin");
        fout2.open("data_new_4_"+ to_string(ifile)+".in");
        int testCase=10;
        while(testCase--)
        {
            int H=myRand.GetRand(1,200);
            int W=myRand.GetRand(1,20)*4;
            
            fout << H << " " << W << "\n";
            vector<string> vecBin;
            
            for (int i = 0; i <= H - 1; ++i)
            {
                string binString=repeat("1",W);
                int left = myRand.GetRand(1,W/2);
                int right = myRand.GetRand(1,W/2);

                while(left+right>W)
                {
                    left = myRand.GetRand(1,W/2);
                    right = myRand.GetRand(1,W/2);                    
                }
                
                string oneString=repeat("1",W-left-right);



                int left1 = myRand.GetRand(0,(oneString.size()-1));
                int right1 = left1 + myRand.GetRand(1,(oneString.size()-1));
                while(right1>oneString.size()-1)
                {
                    left1 = myRand.GetRand(0,(oneString.size()-1));
                    right1 = left1 + myRand.GetRand(0,(oneString.size()-1));                  
                }

                for (int k = left1; k <= right1; ++k)
                {
                    oneString[k]='0';
                }  

                if(right1-left1>=5)
                {
                    int left2 = left1 + myRand.GetRand(1,(right1-left1)/2);
                    int right2 = left2 + myRand.GetRand(1,(right1-left1)/4);

                    for (int k = left2; k <= right2; ++k)
                    {
                        oneString[k]='1';
                    }          
                }
               
                binString=repeat("0",left) + oneString +repeat("0",right);;
                
                if(binString.size()>W)
                {
                    binString = binString.substr(1,W);
                }

                vecBin.push_back(binString);
                fout<< binString << "\n";
            }


            vector<string> vecHex(vecBin.size());
            int maxHexSize=0;
            for (int i = 0; i <= vecBin.size() - 1; ++i)
            {
                //fout << vecBin[i]<< "\n";
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


int main3()
{
    ifstream fin("data_new_4_1.in");
    ofstream fout("data_new_4_1.bin2");
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


int main4()
{
    ifstream fin("data_new_4_1.bin");
    ofstream fout("data_new_4_1.hex");
    while(true)
    {
        int H=0;
        int W=0;        
        fin >> H >> W;
        if(H==0 && W==0)
            break;

        fout << H << " " << W/4 << "\n";
        string useless;
        getline(fin,useless);

        for (int i = 0; i <= H - 1; ++i)
        {
            string binString;
            getline(fin,binString);
            string hexString=binToHex(binString);
            fout << hexString << "\n";
        }
    }
    fout << 0 << " " << 0 << "\n";
    
    return 0;
}
