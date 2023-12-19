#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int target;
        int n;
        vector<int> v;
        bool found = false;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        cin >> target;
        sort(v.begin(), v.end());
        int p1 = 0;
        int p2 = n - 1;
        while (p1 < p2)
        {
            if (v[p1] + v[p2] == target)
            {
                found = true;
                break;
            }
            else if (v[p1] + v[p2] < target)
            {
                p1++;
            }
            else if (v[p1] + v[p2] > target)
            {
                p2--;
            }
        }
        if (found)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}