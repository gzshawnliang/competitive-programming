#include <bits/stdc++.h>

using namespace std;

ifstream fin("herding.in");
ofstream fout("herding.out");

using namespace std;

int solve_min(const vector<int> & A)
{
    int N=A.size();

    if (A[N - 2] - A[0] == N - 2 && A[N - 1] - A[N - 2] > 2)
        return 2;
    if (A[N - 1] - A[1] == N - 2 && A[1] - A[0] > 2)
        return 2;
    int i, j = 0, best = 0;
    for (i = 0; i <= N-1; ++i)
    {
        while (j < N - 1 && A[j + 1] - A[i] <= N - 1)
            ++j;
        best = max(best, j - i + 1);
    }
    return N - best;
}

int main(void)
{
    int N;
    fin >> N;
    vector<int> A(N);
    for (int i = 0; i <= N - 1; ++i)
        fin >> A[i];
    sort(A.begin(), A.end());

    int answer_min = solve_min(A);
    int answer_max = max(A[N - 2] - A[0], A[N - 1] - A[1]) - (N - 2);
    fout << answer_min << "\n"
         << answer_max << "\n";
    return 0;
}