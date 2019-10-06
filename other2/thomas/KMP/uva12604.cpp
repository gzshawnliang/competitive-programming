/* 題目: UVa 12604 - Caesar Cipher
 * Language: C++
 * Created on: 2016年10月12日
 *   Author: hanting
 */
#include <bits/stdc++.h>
using namespace std;
unsigned Base = 7; // 任一質數 // 不能2
int countStr(char * str, char * pat)
{
    int cnt = 0;
    unsigned baseMax = 1;
    unsigned strHash, patHash;
    strHash = str[0];
    patHash = pat[0];
    for (int i = 1; pat[i]; i++)
    {
        patHash = patHash * Base + pat[i];
        strHash = strHash * Base + str[i];
        baseMax *= Base;
    }
    if (patHash == strHash)
        cnt++;
    for (int i = strlen(pat), j = 0; str[i]; i++, j++)
    {
        strHash = (strHash - baseMax * str[j]) * Base + str[i];
        if (strHash == patHash)
            cnt++;
    }
    return cnt;
}
int fail[50005];
int KMP(char * str, char * pat)
{
    /*build failure function*/
    fail[0] = -1;
    int j;
    for (int i = 1; pat[i]; i++)
    {
        j = fail[i - 1];
        while (j >= 0 && pat[i] != pat[j + 1])
        {
            j = fail[j];
        }
        if (pat[i] == pat[j + 1])
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
    for (int i = 0; str[i]; i++)
    {
        while (j >= 1 && str[i] != pat[j])
        {
            j = fail[j - 1] + 1;
        }
        if (str[i] == pat[j])
        {
            j++;
        }
        if (!pat[j])
        {
            cnt++;
            j = fail[j - 1] + 1;
        }
    }

    return cnt;
}
char Alphabet[65], plainText[50005], encryptedText[500005];
int ans[50005];
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while (testCase--)
    {
        int pos[128]; // pos['a'] = 0; pos['w'] = 1;// 表上'a'在第0個位置，下一個是'w'
        scanf("%s%s%s", Alphabet, plainText, encryptedText);
        for (int i = 0; Alphabet[i]; i++)
        {
            pos[Alphabet[i]] = i;
        }
        int AlphaL = strlen(Alphabet);
        Alphabet[AlphaL] = Alphabet[0];
        Alphabet[AlphaL + 1] = 0;
        int ansi = 0;
        for (int i = 0; i < AlphaL; i++)
        {
            if (countStr(encryptedText, plainText) == 1)
            //if(KMP(encryptedText, plainText) == 1)
            {
                ans[ansi++] = i;
            }
            for (int j = 0; plainText[j]; j++)
            {
                int k = pos[plainText[j]]; // k在table中第幾個
                plainText[j] = Alphabet[k + 1];
            }
        }
        if (ansi == 0)
        {
            puts("no solution");
        }
        else if (ansi == 1)
        {
            printf("unique: %d\n", ans[0]);
        }
        else
        {
            printf("ambiguous: ");
            for (int i = 0; i < ansi - 1; i++)
            {
                printf("%d ", ans[i]);
            }
            printf("%d\n", ans[ansi - 1]);
        }
    }
    return 0;
}