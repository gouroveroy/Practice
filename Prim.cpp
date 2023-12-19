//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    vector<int> parent, key;
    vector<bool> mstSet;

    int minkey(int V)
    {
        int min = INT_MAX, min_index;
        for (int i = 0; i < V; i++)
        {
            if (mstSet[i] == false && key[i] < min)
            {
                min = key[i];
                min_index = i;
            }
        }
        return min_index;
    }

public:
    Solution()
    {
        parent.resize(1010);
        key.resize(1010);
        mstSet.resize(1010);
    }
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            key[i] = INT_MAX;
            mstSet[i] = false;
        }

        key[0] = 0;
        int totalWeight = 0;

        for (int i = 0; i < V - 1; i++)
        {
            int u = minkey(V);
            mstSet[u] = true;

            for (auto &edge : adj[u])
            {
                int v = edge[0];
                int weight = edge[1];

                if (mstSet[v] == false && weight < key[v])
                {
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }
        for (int i = 1; i < V; i++)
        {
            totalWeight += key[i];
        }
        return totalWeight;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
