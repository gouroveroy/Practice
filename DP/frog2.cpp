#include <bits/stdc++.h>
using namespace std;

class DP
{
    int k;
    vector<int> dp;
    vector<int> v;

public:
    DP(int N, int k, vector<int> &v)
    {
        this->v = v;
        this->k = k;
        dp.assign(N, -1);
    }

    int Cost(int n)
    {
        if (n == 0)
        {
            return 0;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }

        int cost = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            if (n >= i)
            {
                cost = min(cost, Cost(n - i) + abs(v[n] - v[n - i]));
            }
        }
        return dp[n] = cost;
    }
};

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    DP dp(N, K, v);
    cout << dp.Cost(N - 1) << endl;
    return 0;
}
