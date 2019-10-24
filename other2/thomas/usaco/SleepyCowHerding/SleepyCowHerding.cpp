#include <bits/stdc++.h>

using namespace std;

ifstream fin("SleepyCowHerding.in");
ofstream fout("SleepyCowHerding.out");

using namespace std;

int getMin(const vector<int> & A)
{
    int N = A.size() - 1;

    if (A[N - 1] - A[1] == N - 2 && A[N] - A[N - 1] > 2)
        return 2;
    if (A[N] - A[2] == N - 2 && A[2] - A[1] > 2)
        return 2;
    int r = 1, ans = N;
    for (int l = 1; l <= N; ++l)
    {
        while (r < N && A[r + 1] - A[l] <= N - 1)
            ++r;
        ans = min(ans, N - (r - l + 1));
    }
    return ans;
}

int main(void)
{
    int N;
    fin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i)
        fin >> A[i];
    sort(A.begin() + 1, A.end());

    int answer_min = getMin(A);
    int answer_max = max(A[N - 1] - A[1], A[N] - A[2]) - (N - 1) + 1;
    fout << answer_min << "\n"
         << answer_max << "\n";
    return 0;
}