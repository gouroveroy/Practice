#include <iostream>
using namespace std;

void function(int n)
{
    int count = 0;
    for (int i = n / 2; i <= n; i++)
    {
        for (int j = 1; j + n / 2 <= n; j = j++)
        {
            for (int k = 1; k <= n; k *= 2)
            {
                count++;
            }
        }
    }
}

int main(int argc, char **argv)
{
}
