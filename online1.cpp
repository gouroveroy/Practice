#include <bits/stdc++.h>
using namespace std;

vector<int> dist;
vector<int> parent;

void solve(vector<vector<pair<int, int>>> &graph, int n, int source)
{
    dist.assign(n + 1, INT_MAX);
    parent.assign(n + 1, -1);
    dist[source] = 0;
    int max_price = INT_MIN;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
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
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    int f;
    cin >> f;
    int destination;
    int time = INT_MAX;
    vector<int> dist1, dist2, fdist1, fdist2;
    int t1, t2;
    for (int i = 0; i < n; i++)
    {
        if(i == f) continue;
        solve(graph, n, f);
        dist1 = parent;
        t1 = dist[i];
        solve(graph, n, i);
        dist2 = parent;
        t2 = dist[f];
        if(t1 + t2 < time)
        {
            fdist1 = dist1;
            fdist2 = dist2;
            time = t1 + t2;
            destination = i;
        }
    }
    cout << "Minimum total time: " << time << endl;
    int i = destination;
    stack<int> s1;
    while(i != -1)
    {
        s1.push(i);
        i = parent[i];
    }
    while(!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    fclose(stdin);
    return 0;
}
