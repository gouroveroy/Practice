#include <bits/stdc++.h>
using namespace std;

class Happiness
{
    vector<vector<int>> dp;

public:
    Happiness(int N)
    {
        dp.assign(N + 1, vector<int>(3, -1));
    }
    int happiness(vector<vector<int>> &v, int N, int activity)
    {
        if (N < 0)
        {
            return 0;
        }

        if (dp[N][activity] != -1)
        {
            return dp[N][activity];
        }

        int maxHappiness = INT_MIN;
        if (activity != 0)
        {
            maxHappiness = max(maxHappiness, v[N][0] + happiness(v, N - 1, 0));
        }

        if (activity != 1)
        {
            maxHappiness = max(maxHappiness, v[N][1] + happiness(v, N - 1, 1));
        }

        if (activity != 2)
        {
            maxHappiness = max(maxHappiness, v[N][2] + happiness(v, N - 1, 2));
        }
        return dp[N][activity] = maxHappiness;
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
    Happiness hp(N);
    cout << max(hp.happiness(v, N - 1, 0), max(hp.happiness(v, N - 1, 1), hp.happiness(v, N - 1, 2))) << endl;
    return 0;
}
