#include <bits/stdc++.h>
using namespace std;

int binary_gcd(int a, int b)
{
    if (!a || !b)
    {
        return a | b;
    }
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do
    {
        b >>= __builtin_ctz(b);
        if (a > b)
        {
            swap(a, b);
        }
        b -= a;
    } while (b);
    return a << shift;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int extendedGcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extendedGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        if (line.empty())
        {
            continue;
        }
        istringstream iss(line);
        int a, b;
        if (iss >> a >> b)
        {
            int x, y;
            int d = extendedGcd(a, b, x, y);
            cout << x << " " << y << " " << d << endl;
        }
        else
        {
            cerr << "Invalid input" << endl;
        }
    }
    // int a, b;
    // cin >> a >> b;
    // int x, y;
    // cout << binary_gcd(a, b) << endl;
    // cout << gcd(a, b) << endl;
    // cout << lcm(a, b) << endl;
    // cout << extendedGcd(a, b, x, y) << endl;
    // int d = extendedGcd(a, b, x, y);
    // cout << x << " " << y << " " << d << endl;
    return 0;
}
