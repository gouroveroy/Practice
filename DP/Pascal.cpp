#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // array
    // vector<vector<int>> generate(int numRows)
    // {
    //     vector<vector<int>> triangle;
    //     triangle.push_back({1});
    //     for (int i = 1; i < numRows; i++)
    //     {
    //         vector<int> row = {1, 1};
    //         for (int j = 1; j < i; j++)
    //         {
    //             row.insert(row.begin() + j, triangle[i - 1][j - 1] + triangle[i - 1][j]);
    //         }
    //         triangle.push_back(row);
    //     }
    //     return triangle;
    // }

    // dynamic programming (bottom up approach)
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            triangle[i].resize(i + 1);
            triangle[i][0] = triangle[i][i] = 1;
            for (int j = 1; j < i; ++j)
            {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        return triangle;
    }

    void printTriangle(vector<vector<int>> &triangle)
    {
        cout << "[" << "[1]";
        for (int i = 1; i < triangle.size(); i++)
        {
            cout << ",[" << triangle[i][0];
            for (int j = 1; j < triangle[i].size(); j++)
            {
                cout << "," << triangle[i][j];
            }
            cout << "]";
        }
        cout << "]" << endl;
    }
};

int main()
{
    int numRows;
    cin >> numRows;
    Solution s;
    vector<vector<int>> triangle = s.generate(numRows);
    s.printTriangle(triangle);
    return 0;
}
