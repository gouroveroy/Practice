#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    stack<int> s1;
    stack<int> s2;
    stack<int> s3;

    int a;
    for (int i = 0; i < n1; i++)
    {
        cin >> a;
        v1.push_back(a);
    }
    v1.push_back(0);
    for (int i = n1 - 1; i >= 0; i--)
    {
        v1[i] += v1[i + 1];
        s1.push(v1[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        cin >> a;
        v2.push_back(a);
    }
    v2.push_back(0);
    for (int i = n2 - 1; i >= 0; i--)
    {
        v2[i] += v2[i + 1];
        s2.push(v2[i]);
    }

    for (int i = 0; i < n3; i++)
    {
        cin >> a;
        v3.push_back(a);
    }
    v3.push_back(0);
    for (int i = n3 - 1; i >= 0; i--)
    {
        v3[i] += v3[i + 1];
        s3.push(v3[i]);
    }
    bool flag = true;
    while (!s1.empty() && !s2.empty() && !s3.empty())
    {
        if (s1.top() == s2.top() && s2.top() == s3.top() && s3.top() == s1.top())
        {
            cout << s1.top() << endl;
            flag = false;
            break;
        }

        else
        {
            int maxi = max(s1.top(), max(s2.top(), s3.top()));
            if (maxi == s1.top())
            {
                s1.pop();
            }
            if (maxi == s2.top())
            {
                s2.pop();
            }
            if (maxi == s3.top())
            {
                s3.pop();
            }
        }
    }
    if(flag)
    {
        cout << 0 << endl;
    }
    return 0;
}

/*
5 3 4
3 2 1 1 1
4 3 2
1 1 4 1
*/