#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    cout << (a * b) % m << endl;
    cout << a % m * b % m << endl;
}