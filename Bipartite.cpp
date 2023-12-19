//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int WHITE = 0;
    int GRAY = 1;
    int BLACK = 2;
    vector<int> color;
    vector<int> partitions;

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        color.clear();
        color.assign(V, WHITE);
        partitions.clear();
        partitions.assign(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == WHITE)
            {
                queue<int> q;
                q.push(i);
                color[i] = GRAY;
                partitions[i] = 1;
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    for (int &v : adj[u])
                    {
                        if (partitions[v] == partitions[u])
                        {
                            return false;
                        }
                        else if (color[v] == WHITE)
                        {
                            color[v] = GRAY;
                            partitions[v] = 3 - partitions[u];
                            q.push(v);
                        }
                    }
                    color[u] = BLACK;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
