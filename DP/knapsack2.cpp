#include <bits/stdc++.h>
using namespace std;

class Knapsack
{
    vector<vector<int>> dp;
    vector<int> value;
    vector<int> weight;

public:
    Knapsack(int N, int W, vector<int> &value, vector<int> &weight)
    {
        dp.assign(N + 1, vector<int>(W + 1, -1));
        this->value = value;
        this->weight = weight;
    }

    int knapsack(int n, int v)
    {
        if (v <= 0)
        {
            return 0;
        }

        if (n == 0)
        {
            return 1e4;
        }

        if (dp[n][v] != -1)
        {
            return dp[n][v];
        }

        int ans = knapsack(n - 1, v);

        if (v - value[n] >= 0)
        {
            ans = min(ans, knapsack(n - 1, v - value[n]) + weight[n]);
        }

        return dp[n][v] = ans;
    }
};

int main()
{
    long long N, W;
    cin >> N >> W;
    vector<int> value(N + 1), weight(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> value[i] >> weight[i];
    }
    Knapsack ks(N, W, value, weight);
cout << ks.knapsack(N - 1, 1001) << endl;
    return 0;
}
