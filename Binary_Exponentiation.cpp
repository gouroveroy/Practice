#include <bits/stdc++.h>
using namespace std;

int binaryExpRecursive(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }

    int result = binaryExpRecursive(a, n / 2);

    if (n % 2)
    {
        return result * result * a;
    }
    else
    {
        return result * result;
    }
}

int binaryExpLoop(int a, int n)
{
    int result = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            result *= a;
        }
        a *= a;
        n >>= 1;
    }
    return result;
}

int main(int argc, const char **argv)
{
    int a, n;
    cin >> a >> n;
    cout << binaryExpRecursive(a, n) << endl;
    cout << binaryExpLoop(a, n) << endl;
    return 0;
}
