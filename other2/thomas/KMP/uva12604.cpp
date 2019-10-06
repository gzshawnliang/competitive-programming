#include <bits/stdc++.h>
using namespace std;

const unsigned Base = 37; // 任一质数 ,不能2,质数7可能会相撞

int countStrHash(const string & encryptedText, const string & plainText)
{
    int cnt = 0;
    unsigned baseMax = 1;
    unsigned encryptedTextHashCode, plainTextHashCode;
    encryptedTextHashCode = encryptedText[0];
    plainTextHashCode = plainText[0];
    for (int i = 1; plainText[i]; ++i)
    {
        plainTextHashCode = plainTextHashCode * Base + plainText[i];
        encryptedTextHashCode = encryptedTextHashCode * Base + encryptedText[i];
        baseMax *= Base;
    }
    if (plainTextHashCode == encryptedTextHashCode)
        ++cnt;

    for (int i = plainText.length(), j = 0; encryptedText[i]; ++i, ++j)
    {
        encryptedTextHashCode = (encryptedTextHashCode - baseMax * encryptedText[j]) * Base + encryptedText[i];
        if (encryptedTextHashCode == plainTextHashCode)
            ++cnt;
    }
    return cnt;
}

int countStrKMP(const string & encryptedText, const string & plainText)
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

int main()
{
    freopen("uva12604.in", "r", stdin);

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        string alphabet;
        string plainText;
        string encryptedText;

        vector<int> pos(128); // pos['a'] = 0; pos['w'] = 1;// 表上'a'在第0個位置，下一個是'w'

        vector<int> ans(50005);

        cin >> alphabet >> plainText >> encryptedText;
        for (int i = 0; alphabet[i]; i++)
        {
            pos[alphabet[i]] = i;
        }
        int alphaLen = alphabet.length();
        alphabet[alphaLen] = alphabet[0];
        alphabet[alphaLen + 1] = 0;
        int ansi = 0;
        for (int i = 0; i < alphaLen; i++)
        {
            if (countStrHash(encryptedText, plainText) == 1)
            //if(countStrKMP(encryptedText, plainText) == 1)
            {
                ans[ansi] = i;
                ++ansi;
            }
            for (int j = 0; plainText[j]; j++)
            {
                int k = pos[plainText[j]]; // k在table中第幾個
                plainText[j] = alphabet[k + 1];
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