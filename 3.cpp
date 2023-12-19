#include <iostream>
using namespace std;
int labs(int n)
{
    return (n > 0) ? n : -n;
}

long labs(long n)
{
    return (n > 0) ? n : -n;
}

double labs(double n)
{
    return (n > 0) ? n : -n;
}

int main()
{
    cout << "Absolute of -10 is " << labs(-10) << endl;
    cout << "Absolute of -10L is " << labs(-10L) << endl;
    cout << "Absolute of -10.01 is " << labs(-10.01) << endl;
}