#include <bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define WEIGHT 1

class Graph
{
    vector<int> graph;
    vector<int> color;
    vector<int> parent;
    vector<int> distance;
    vector<int> path;
    bool destinationFound;

public:
    // Constructor
    Graph(int vertices)
    {
        graph.resize(vertices);
        color.assign(vertices, WHITE);
        parent.assign(vertices, -1);
        distance.assign(vertices, INT_MAX);
        path.resize(vertices);
        destinationFound = false;
    }

    Graph(vector<vector<int>> &inputGraph)
    {
        graph = inputGraph;
        int vertices = 0;
        for (vector<int> v : graph)
        {
            vertices += v.size();
        }
        color.assign(vertices, WHITE);
        parent.assign(vertices, -1);
        distance.assign(vertices, INT_MAX);
        destinationFound = false;
    }

    void setDistanceAndPath(int source)
    {
        distance[source] = 0;
        path.clear();
    }

    void DFS(int source, int destination)
    {
        color[source] = GRAY;
        path.push_back(source);
        if (source == destination)
        {
            destinationFound = true;
            return;
        }
        for (int child : graph[source])
        {
            if (color[child] == WHITE)
            {
                parent[child] = source;
                color[child] = GRAY;
                distance[child] = distance[source] + WEIGHT;
                DFS(child, destination);
            }
            else
            {
                continue;
            }
        }
        color[source] = BLACK;
    }

    void DFSprint()
    {
        if (destinationFound)
        {
            cout << path.size() - 1 << endl;
            for (int vertex : path)
            {
                cout << vertex << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
};

int main()
{
    int vertices;
    cin >> vertices;
    vector<int> parent(vertices);
    for (int i = 0; i < vertices; i++)
    {
        cin >> parent[i];
    }
    Graph Graph(parent);

    return 0;
}
