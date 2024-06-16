#include <bits/stdc++.h>
using namespace std;

class KnapSack
{
    vector<vector<long long>> dp;

public:
    KnapSack(long long N, long long W)
    {
        dp.assign(N + 1, vector<long long>(W + 1, -1));
    }
    long long knapsack(vector<pair<long long, long long>> &v, long long N, long long W)
    {
        if (N == -1 || W == 0)
        {
            return 0;
        }
        if(dp[N][W] != -1)
        {
            return dp[N][W];
        }
        long long value = INT_MIN;
        if (W < v[N].first)
        {
            value = knapsack(v, N - 1, W);
        }

        else if (W >= v[N].first)
        {
            value = max(knapsack(v, N - 1, W), knapsack(v, N - 1, W - v[N].first) + v[N].second);
        }
        return dp[N][W] = value;
    }
};

int main()
{
    long long N, W;
    cin >> N >> W;
    vector<pair<long long, long long>> v(N);
    for (long long i = 0; i < N; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    KnapSack ks(N, W);
    cout << ks.knapsack(v, N - 1, W) << endl;
    return 0;
}
