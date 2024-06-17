#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int lcs(string &s, string &t, int sn, int tn)
{
    int l1 = lcs(s, t, sn - 1, tn);
    int l2 = lcs(s, t, sn, tn - 1);
    int l3 = lcs(s, t, sn - 1, tn - 1) + (s[sn] == t[tn]);
    return max(l1, max(l2, l3));
}

int main()
{
    dp.assign(3001, vector<int>(3001, -1));
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t, s.length(), t.length());
    return 0;
}
