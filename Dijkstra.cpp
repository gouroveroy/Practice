#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &graph, int N)
{
    vector<int> dist;
    vector<int> prec;
    dist.assign(N + 1, INT_MAX);
    prec.assign(N + 1, -1);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto &edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                prec[v] = u;
            }
        }
    }
    cout << min(dist[7], min(dist[8], min(dist[9], dist[10]))) << endl;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N + 1);
    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        // graph[v].push_back({u, w});
    }
    dijkstra(graph, N);
    return 0;
}

// Time Complexity: O((V+E)logV)
// Space Complexity: O(V+E) + O(V) + O(V) = O(V+E)

/*
11 13
0 1 2
1 2 5
1 3 4
2 4 1
2 5 4
3 5 4
3 6 7
4 7 8
4 8 6
5 8 6
5 9 9
6 9 9
6 10 6
*/
