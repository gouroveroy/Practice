#include <bits/stdc++.h>
using namespace std;

int lis(int i, int *nums, int *dp)
{
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if (nums[j] < nums[i])
        {
            ans = max(ans, lis(j, nums, dp) + 1);
        }
    }
    return dp[i] = ans;
}

int lengthOfLIS(int *nums, int numsSize)
{
    int dp[numsSize];
    memset(dp, -1, sizeof(dp));
    int ans = 1;
    for (int i = 0; i < numsSize; i++)
    {
        ans = max(ans, lis(i, nums, dp));
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << lengthOfLIS(nums, n) << endl;
    return 0;
}
