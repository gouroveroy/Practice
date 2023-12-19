#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    int n;
    cin >> n;
    stack<int> maxs;
    while (n--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int x;
            cin >> x;
            s.push(x);
            if (maxs.empty())
            {
                maxs.push(x);
            }
            else
            {
                maxs.push(max(maxs.top(), x));
            }
        }
        else if (q == 2)
        {
            s.pop();
            maxs.pop();
        }
        else
        {
            if(maxs.empty())
            {
                cout << "There is no element in the stack" << endl;
                continue;
            }
            cout << maxs.top() << endl;
        }
    }
    return 0;
}