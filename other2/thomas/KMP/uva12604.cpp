#include <bits/stdc++.h>
using namespace std;

const unsigned Base = 7; // 任一質數 // 不能2

int countStr(const string & encryptedText, const string & plainText)
{
    int cnt = 0;
    unsigned baseMax = 1;
    unsigned strHash, patHash;
    strHash = encryptedText[0];
    patHash = plainText[0];
    for (int i = 1; plainText[i]; i++)
    {
        patHash = patHash * Base + plainText[i];
        strHash = strHash * Base + encryptedText[i];
        baseMax *= Base;
    }
    if (patHash == strHash)
        ++cnt;
        
    for (int i = plainText.length(), j = 0; encryptedText[i]; ++i, ++j)
    {
        strHash = (strHash - baseMax * encryptedText[j]) * Base + encryptedText[i];
        if (strHash == patHash)
            ++cnt;
    }
    return cnt;
}

int KMP(const string & encryptedText, const string & plainText)
{
    /*build failure function*/
    vector<int> fail(50005);
    fail[0] = -1;
    int j;
    for (int i = 1; plainText[i]; ++i)
    {
        j = fail[i - 1];
        while (j >= 0 && plainText[i] != plainText[j + 1])
        {
            j = fail[j];
        }
        if (plainText[i] == plainText[j + 1])
        {
            fail[i] = j + 1;
        }
        else
        {
            fail[i] = -1;
        }
    }
    /*KMP*/
    int cnt = 0;
    j = 0;
    for (int i = 0; encryptedText[i]; ++i)
    {
        while (j >= 1 && encryptedText[i] != plainText[j])
        {
            j = fail[j - 1] + 1;
        }
        if (encryptedText[i] == plainText[j])
        {
            ++j;
        }
        if (!plainText[j])
        {
            ++cnt;
            j = fail[j - 1] + 1;
        }
    }

    return cnt;
}
//char Alphabet[65], plainText[50005], encryptedText[500005];
int ans[50005];
int main()
{
    freopen("uva12604.in", "r", stdin);

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        string Alphabet;
        string plainText;
        string encryptedText;

        vector<int> pos(128); // pos['a'] = 0; pos['w'] = 1;// 表上'a'在第0個位置，下一個是'w'
        //scanf("%s%s%s", Alphabet, plainText, encryptedText);
        cin >> Alphabet >> plainText >> encryptedText;
        for (int i = 0; Alphabet[i]; i++)
        {
            pos[Alphabet[i]] = i;
        }
        int AlphaL = Alphabet.length();
        Alphabet[AlphaL] = Alphabet[0];
        Alphabet[AlphaL + 1] = 0;
        int ansi = 0;
        for (int i = 0; i < AlphaL; i++)
        {
            if (countStr(encryptedText, plainText) == 1)
            //if(KMP(encryptedText, plainText) == 1)
            {
                ans[ansi] = i;
                ++ansi;
            }
            for (int j = 0; plainText[j]; j++)
            {
                int k = pos[plainText[j]]; // k在table中第幾個
                plainText[j] = Alphabet[k + 1];
            }
        }
        if (ansi == 0)
        {
            cout << "no solution\n";
        }
        else if (ansi == 1)
        {
            cout << "unique: " << ans[0] << "\n";
        }
        else
        {
            cout << "ambiguous: ";
            for (int i = 0; i < ansi - 1; i++)
            {
                cout << ans[i] << " ";
            }
            cout << ans[ansi - 1] << "\n";
        }
    }
    return 0;
}