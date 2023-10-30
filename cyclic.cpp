#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool dfs(int node, int parent, vector<int> adj[], int vis[]) {
    vis[node] = 1; // Mark the node as visited

    for (auto it : adj[node]) {
        if (vis[it] == 0) {
            if (dfs(it, node, adj, vis)) return true; // If a cycle is found in the subtree, return true.
        } else if (it != parent) {
            return true; // If the adjacent node is already visited and not the parent, a cycle is found.
        }
    }
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    int vis[V] = {0};
    for (int i = 0; i < V; i++) {
        if (vis[i] == 0 && dfs(i, -1, adj, vis)) return true; // Start DFS from unvisited nodes.
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    vector<int> adj[5];
    int V = 5;

    // Adding edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    if (isCyclic(V, adj)) cout << "YES";
    else cout << "NO";

    return 0;
}
