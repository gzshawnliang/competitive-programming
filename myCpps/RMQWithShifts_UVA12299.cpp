#include<bits/stdc++.h>

using namespace std;

ifstream fin("RMQWithShifts_UVA12299.in");
ofstream fout("RMQWithShifts_UVA12299.out");


class fenwickTree
{
    private:
    int lowbit(int x)
    {
        return x & (-x);
    }

    public:
    vector<int> a;
    vector<int> s;

    fenwickTree(vector<int> & in)
    {
        int n = in.size();

        a = in;
        s.assign(n, INT_MAX);

        for (int i = 1; i <= n; ++i)
        {
            update(i, a[i]);
        }
    }

    void update(int x, int d)
    {
        int n = s.size();
        a[x] = d;
        while (x <= n)
        {
            if (s[x] > d)
            {
                s[x] = d;
            }
            else break;
                
            x = x + lowbit(x);
        }
    }

    int query(int l, int r)
    {
        int n = s.size();

        int ans = a[r];
        while (l != r)
        {
            r--;
            while (r - lowbit(r) > l)
            {
                ans = min(ans, s[r]);
                r -= lowbit(r);
            }
            ans = min(ans, a[r]);
        }
        return ans;
    }
};

int main2()
{
    int x = 6;

    fout << (x & (-x)) << '\n';

    return 0;
}

int main()
{
    int n, q; fin >> n >> q;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
    }

    fenwickTree tree(a);

    for (int s = 1; s <= q; ++s)
    {
        string in; fin >> in;

        int size = in.size();
        string temp = "";
        vector<int> num;
        
        for (int i = 0; i <= size - 1; ++i)
        {
            char now = in[i];

            if ('0' <= now && now <= '9')
            {
                temp += now;
            }
            else
            {
                if (temp.size() > 0)
                {
                    num.push_back(stoi(temp));
                    temp = "";
                }
            }
        }

        fout << "s:";
        for (int i = 1; i <= n; ++i)
        {
            fout << ' ' << tree.s[i];
        }
        fout << '\n';

        fout << "a:";
        for (int i = 1; i <= n; ++i)
        {
            fout << ' ' << tree.a[i];
        }
        fout << "\n\n";

        if (in[0] == 'q')
        {
            fout << tree.query(num[0] - 1, num[1] - 1) << '\n';
        }
        else
        {
            int sizeN = num.size();
            for (int i = 0; i <= sizeN - 2; ++i)
            {
                int tempA = tree.a[num[i]], tempB = tree.a[num[i + 1]];
                tree.update(num[i], tempB); tree.update(num[i + 1], tempA);
            }
        }
    }

    return 0;
}
