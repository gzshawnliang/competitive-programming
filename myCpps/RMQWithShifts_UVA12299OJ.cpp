#include<bits/stdc++.h>

using namespace std;


class fenwickTree
{
    private:
    
    vector<int> a;
    vector<int> s;

    int lowbit(int x)
    {
        return x & (-x);
    }

    public:

    fenwickTree(vector<int> & in)
    {
        int n = in.size();

        a = in;
        s.assign(n + 1, INT_MAX);

        for (int i = 0; i <= n - 1; ++i)
        {
            update(i, a[i]);
        }
    }

    void update(int k, int temp)
    {
        ++k;

        int n = s.size();

        a[k - 1] = temp;

        for (int i = k; i <= n - 1; i += lowbit(i))
        {
            s[i] = min(s[i], temp);
        }
    }

    int query(int l, int r)
    {
        ++l; ++r;

        int ans = a[r - 1];

        while (l != r)
        {
            for (--r; r >= l + lowbit(r); r -= lowbit(r))
            {
                ans = min(ans, s[r]);
            }

            ans = min(ans, a[r - 1]);
        }

        return ans;
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n, q; cin >> n >> q;
    vector<int> a(n);

    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
    }

    fenwickTree tree(a);

    for (int c = 1; c <= q; ++c)
    {
        string in; cin >> in;

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

        if (in[0] == 'q')
        {
            cout << tree.query(num[0] - 1, num[1] - 1) << '\n';
        }
        else
        {
            int sizeN = num.size();
            for (int i = 0; i <= sizeN - 2; ++i)
            {
                int tempA = a[num[i] - 1], tempB = a[num[i + 1] - 1];
                tree.update(num[i] - 1, tempB); tree.update(num[i + 1] - 1, tempA);
            }
        }
    }

   	cout.flush();
   	return 0;
}

