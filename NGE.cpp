#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    vector<int> NGE(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && v[i] > v[st.top()])
        {
            NGE[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        NGE[st.top()] = -1;
        st.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " " << (NGE[i] == -1 ? -1 : v[NGE[i]]) << endl;
    }
    return 0;
}
