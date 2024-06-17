#include <bits/stdc++.h>
using namespace std;

vector<int> weight, value;
vector<vector<int>> dp;

long long knapsack(int n, int value_left)
{
    if (value_left == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return 1e10;
    }
    if (dp[n][value_left] != -1)
    {
        return dp[n][value_left];
    }
    long long ans = knapsack(n - 1, value_left);
    if (value_left >= value[n])
    {
        ans = min(ans, knapsack(n - 1, value_left - value[n]) + weight[n]);
    }
    return dp[n][value_left] = ans;
}

int main()
{
    dp.assign(101, vector<int>(100001, -1));
    value.resize(101);
    weight.resize(101);
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    int max_value = 1e5;
    for (int i = max_value; i >= 0; i--)
    {
        if (knapsack(n, i) <= w)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
