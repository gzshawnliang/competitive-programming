#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct custom_type {
    int val;
    int pos;

    bool operator < (const custom_type &B) const {
        return val > B.val; // min heap
    }
};
int main()
{
    int K, L1[800], L2[800];
    while (scanf("%d", &K) != EOF) {
        for (int i = 0; i < K; ++i) scanf("%d", &L1[i]);
        sort(L1, L1 + K);

        for (int k = 1; k < K; ++k) {
            for (int i = 0; i < K; ++i) scanf("%d", &L2[i]);
            sort(L2, L2 + K);
            
            priority_queue<custom_type> PQ;
            for (int i = 0; i < K; ++i) 
                PQ.push({L1[i] + L2[0], 0});
            
            for (int i = 0; i < K; ++i) {
                custom_type tmp = PQ.top();
                PQ.pop();
                L1[i] = tmp.val;
                if (tmp.pos+1 < K)
                    PQ.push({tmp.val - L2[tmp.pos] + L2[tmp.pos+1], tmp.pos + 1});
            }
        }
        for (int i = 0; i < K - 1; ++i)
            printf("%d ", L1[i]);
        printf("%d\n", L1[K-1]);
    }
}