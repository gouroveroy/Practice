#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> dp;

public:
    Solution(int N = 37)
    {
        dp.assign(N + 1, -1);
    }

    int tribonacci(int n)
    {
        if (dp[n] != -1)
        {
            return dp[n];
        }
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 1;
        }
        return dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s(n);
    cout << s.tribonacci(n) << endl;
    return 0;
}
