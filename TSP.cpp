// CPP program to implement traveling salesman
// problem using naive approach.
#include <bits/stdc++.h>
using namespace std;
#define V 6
vector<int> min_tour;

// implementation of traveling Salesman Problem
int travelingSalesmanProblem(int graph[][V], int s)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do
    {

        // store current Path weight(cost)
        int current_path_weight = 0;

        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            current_path_weight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_path_weight += graph[k][s];

        // update minimum
        // min_path = min(min_path, current_path_weight);
        if(current_path_weight < min_path)
        {
            min_path = current_path_weight;
            min_tour = vertex;
        }

    } while (
        next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

// Driver Code
int main()
{
    // matrix representation of graph
    // int graph[][V] = {{0, 8, 4, 7, 5, 4},
    //                   {10, 0, 8, 13, 11, 9},
    //                   {5, 9, 0, 5, 4, 6},
    //                   {7, 3, 8, 0, 15, 3},
    //                   {9, 8, 9, 7, 0, 6},
    //                   {4, 11, 7, 10, 5, 0}};
    int graph[][V] = {{0, 10, 15, 20, 25, 30},
                      {5, 0, 12, 18, 24, 29},
                      {8, 9, 0, 17, 22, 28},
                      {11, 14, 16, 0, 21, 27},
                      {13, 19, 23, 26, 0, 31},
                      {28, 27, 25, 24, 22, 0}};
    int s = 0;
    min_tour.resize(V);
    cout << travelingSalesmanProblem(graph, s) << endl;
    for(auto vertex : min_tour)
    {
        cout << vertex << " ";
    }
    cout << endl;
    return 0;
}
