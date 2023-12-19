#include <bits/stdc++.h>
using namespace std;

class coinchange
{
    vector<int> dp;

public:
    coinchange(int N)
    {
        dp.assign(N, -1);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }

        if (dp[amount] != -1)
        {
            return dp[amount];
        }

        int count = INT_MAX;
        for (int coin : coins)
        {
            if (coin <= amount)
            {
                count = min(count + 0LL, coinChange(coins, amount - coin) + 1LL);
            }
        }
        return dp[amount] = count;
    }
};

int main()
{
    int N;
    cin >> N;
    int amount;
    cin >> amount;
    vector<int> coins(N);

    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }
    coinchange cc(amount + 1);
    int count = cc.coinChange(coins, amount);
    cout << (count == INT_MAX ? -1 : count) << endl;
    return 0;
}
