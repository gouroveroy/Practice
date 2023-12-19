#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<pair<int, pair<int, int>>> graph;
    vector<vector<int>> shortestPath;
    int vertices, source, destination, stopages;

    void buildMatrix()
    {
        for (int i = 0; i < vertices; i++)
        {
            shortestPath[i][i] = 0;
        }

        for (auto &edge : graph)
        {
            int u = edge.second.first;
            int v = edge.second.second;
            int w = edge.first;
            shortestPath[u][v] = w;
            // shortestPath[v][u] = w;
        }
    }

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        this->vertices = n;
        this->source = src;
        this->destination = dst;
        this->stopages = k;
        for (auto &flight : flights)
        {
            graph.push_back({flight[2], {flight[0], flight[1]}});
        }
        shortestPath.assign(vertices + 1, vector<int>(vertices + 1, INT_MAX));
        buildMatrix();
        floydWarshall();
        return shortestPath[source][destination];
    }

    void floydWarshall()
    {
        for (int k = 0; k < vertices; k++)
        {
            for (int i = 0; i < vertices; i++)
            {
                for (int j = 0; j < vertices; j++)
                {
                    if (shortestPath[i][k] != INT_MAX && shortestPath[k][j] != INT_MAX)
                    {
                        shortestPath[i][j] = min(shortestPath[i][j], shortestPath[i][k] + shortestPath[k][j]);
                    }
                }
            }
        }
    }
};

int main()
{
    int n = 4;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    Solution sl;
    cout << sl.findCheapestPrice(n, flights, 0, 3, 1) << endl;
    return 0;
}
