#include <bits/stdc++.h>
using namespace std;
const int N = 55;

int T;
vector<string> vec[N];
string a[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    freopen("PatternMatching.in", "r", stdin);
    freopen("PatternMatching.out", "w", stdout);    
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        cout << "Case #" << cs << ": ";
        cin >> n;
        for (int i = 1; i <= n; i++) {
            vec[i].clear();
            string str;
            cin >> str;
            string cur = "";
            for (int j = 0; j < str.length(); j++) {
                if (str[j] == '*') {
                    vec[i].push_back(cur);
                    cur = "";
                    continue;
                }
                cur += str[j];
            }
            vec[i].push_back(cur);
            a[i] = str;
        }
        bool flag = true;
        vector<pair<int, string>> suffix, prefix;
        for (int i = 1; i <= n; i++) {
            suffix.push_back({vec[i][vec[i].size() - 1].length(), vec[i][vec[i].size() - 1]});
            prefix.push_back({vec[i][0].length(), vec[i][0]});
        }
        sort(suffix.begin(), suffix.end());
        sort(prefix.begin(), prefix.end());
        for (int i = 0; i < prefix.size() - 1; i++) {
            string s = prefix[i].second;
            string t = prefix[i + 1].second;
            bool ff = true;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] != t[j]) {
                    ff = false;
                }
            }
            flag &= ff;
        }
        for (int i = 0; i < suffix.size() - 1; i++) {
            string s = suffix[i].second;
            string t = suffix[i + 1].second;
            bool ff = true;
            int offset = t.length() - s.length();
            for (int j = 0; j < s.length(); j++) {
                if (s[j] != t[offset + j]) {
                    ff = false;
                }
            }
            flag &= ff;
        }
        if (flag == false) {
            cout << "*" << endl;
            continue;
        }
        string ans = prefix[prefix.size() - 1].second;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < vec[i].size() - 1; j++) {
                ans += vec[i][j];
            }
        }
        ans += suffix[suffix.size() - 1].second;
        cout << ans << endl;
    }
    return 0;
}

/*

3
5
*CONUTS
*COCONUTS
*OCONUTS
*CONUTS
*S
2
*XZ
*XYZ

3
3
aabc*
aa*
*c
3
aac*
ac*
*
5
aab*cv*ssc*bbc
aabc*aa*ee*d*bc
a*c
aabc*
*bc

*/