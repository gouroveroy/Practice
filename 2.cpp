#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 100;
    int k = 0;
    for (int i = 1; i <= n; i*=2)
    {
        for (int j = 1; j <= n; j++)
        {
            k++;
        }
    }
    return 0;
}