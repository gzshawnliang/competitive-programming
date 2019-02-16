#include <bits/stdc++.h>
#include <MyRandom.h>

using namespace std;

string binToHex(string bit_string)
{
    //string bit_string = "00000000000001110000000000";
    bitset<64> b3(bit_string);
    //cout << b3.to_string() << '\n';
    unsigned long long a = b3.to_ullong();
    
    string result;
    stringstream ss;

    ss << hex << a;
    ss >> result;
    return result;
}

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

// Function which return string by concatenating it. 
string repeat(const string & s, int n) 
{ 
    // Copying given string to temparory string. 
    string s1 = s; 
  
    for (int i=1; i<n;i++) 
        s1 += s; // Concatinating strings 
  
    return s1; 
}

int main()
{
    // ifstream fin("createAncientData.in");
    ofstream fout("createAncientData.out");
    ofstream fout2("createAncientData.out4");

    random myRand;

    int testCase=75;

    while(testCase--)
    {
        int H=myRand.GetRand(1,100);
        int W=myRand.GetRand(5,40);
        int backgroundCount =myRand.GetRand(1,10);
        
        fout << H << " " << W+backgroundCount << "\n";
        fout2 << H << " " << W+backgroundCount << "\n";        
        vector<string> vec1;
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
            vec1.push_back(binString);
        }

        if(!existHole)
        {
            vector<int> rd=myRand.GetUniqueRand(1,H);
            int icount=myRand.GetRand(0,H-1);
            for (int i = 0; i <= icount - 1; ++i)
            {
                int beginId=myRand.GetRand(1,W);
                int endId=beginId+myRand.GetRand(0,W);
                if(endId<=W-1)
                {
                    for (int j = beginId; j <=endId; ++j)
                    {
                        vec1[rd[i]][j]='0';
                    }
                }
                else
                {
                    vec1[rd[i]][beginId]='0';
                }
                
            }
        }
        
        for(auto a :  vec1)
        {
            fout << a << "\n";
            fout2 <<binToHex(a) << "\n";
        }

        // for (int i = 0; i <= H - 1; ++i)
        // {
        //     string binString="";
        //     int maxContinuous=min(10,W);
        //     int n=myRand.GetRand(1,maxContinuous);
        //     int currSize=0;
        //     while(currSize<=W)
        //     {
        //         int currN=myRand.GetRand(1,n);
        //         if(myRand.GetBoolRand()==true)
        //         {
        //             binString+=repeat("0",currN);
        //         }
        //         else 
        //         {
        //             binString+=repeat("1",currN);
        //         }
        //         currSize+=currN;
        //     }

        //     if(binString.size()>W)
        //     {
        //         binString=binString.substr(1,W);
        //     }

        //     fout << binString << "\n";
        //     fout2 <<binToHex(binString) << "\n";
        // }
    }
    
    fout << 0 << " " << 0 << "\n";
    fout2 << 0 << " " << 0 << "\n";

    // string source="00000000000001110000000000";
    // string result = binToHex(source);
    // cout << source << " -> " << result << "\n";


    // source="65b2";
    // result = hexToBin(source);
    // cout << source << " -> " << result << "\n";

    return 0;
}
