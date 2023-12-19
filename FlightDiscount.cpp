#include <bits/stdc++.h>
using namespace std;

vector<long long> dist;
vector<int> parent;

void solve(vector<vector<pair<int, int>>> &graph, int n)
{
    dist.assign(n + 1, INT_MAX);
    parent.assign(n + 1, -1);
    dist[1] = 0;
    int max_price = INT_MIN;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto &edge : graph[u])
        {
            int v = edge.first;
            int v_w = edge.second;
            if (dist[v] > dist[u] + v_w)
            {
                dist[v] = dist[u] + v_w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
    for (int i = n; i > 0;)
    {
        int u = parent[i];
        if (u != -1)
        {
            for (auto &edge : graph[u])
            {
                if (edge.first == i)
                {
                    max_price = max(max_price, edge.second);
                    break;
                }
            }
        }
        i = u;
    }
    cout << dist[n] - max_price + max_price / 2 << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    solve(graph, n);
    return 0;
}
