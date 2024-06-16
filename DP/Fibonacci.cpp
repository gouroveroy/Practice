#include <bits/stdc++.h>
using namespace std;

class matrix
{
public:
    long long mat[2][2];

    matrix()
    {
    }

    matrix(long long m[2][2])
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                mat[i][j] = m[i][j];
            }
        }
    }

    matrix friend operator*(matrix &a, matrix &b)
    {
        matrix c;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                c.mat[i][j] = 0;
                for (int k = 0; k < 2; k++)
                {
                    c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                }
            }
        }
        return c;
    }
};

matrix multiplication(matrix m, long long n)
{
    long long i[2][2] = {{1, 0}, {0, 1}};
    matrix ans(i);
    while (n)
    {
        if (n & 1)
        {
            ans = ans * m;
        }
        m = m * m;
        n >>= 1;
    }
    return ans;
}

int main()
{
    long long n;
    cin >> n;
    long long base[2][2] = {{1, 1}, {1, 0}};
    cout << multiplication(matrix(base), n).mat[0][1] << endl;
    return 0;
}
