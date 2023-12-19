#include <iostream>
#include <cmath>

using namespace std;

int sroot(int n)
{
    return sqrt(n);
}

long sroot(long n)
{
    return sqrt(n);
}

double sroot(double n)
{
    return sqrt(n);
}

int main()
{
    cout << "Square root of 10 is " << sroot(10) << endl;
    cout << "Square root of 10L is " << sroot(10L) << endl;
    cout << "Square root of 10.00 is " << sroot(10.00) << endl;
    return 0;
}