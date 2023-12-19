#include <bits/stdc++.h>
using namespace std;

class Hapiness
{
    vector<vector<int>> dp;

public:
    Hapiness(int N)
    {
        dp.assign(N + 1, vector<int>(3, -1));
    }
    int hapiness(vector<vector<int>> &v, int N, int activity)
    {
        if (N < 0)
        {
            return 0;
        }

        if (dp[N][activity] != -1)
        {
            return dp[N][activity];
        }

        int maxhap = INT_MIN;
        if (activity != 0)
        {
            maxhap = max(maxhap, v[N][0] + hapiness(v, N - 1, 0));
        }

        if (activity != 1)
        {
            maxhap = max(maxhap, v[N][1] + hapiness(v, N - 1, 1));
        }

        if (activity != 2)
        {
            maxhap = max(maxhap, v[N][2] + hapiness(v, N - 1, 2));
        }
        return dp[N][activity] = maxhap;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(3));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> v[i][j];
        }
    }
    Hapiness hp(N);
    cout << max(hp.hapiness(v, N - 1, 0), max(hp.hapiness(v, N - 1, 1), hp.hapiness(v, N - 1, 2))) << endl;
    return 0;
}
