#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr first
#define sc second

void DFS(int node, vector<int>& dfs_order, vector<int> adj[], int vis[]) {
    vis[node] = 1; // Mark the node as visited
    dfs_order.push_back(node);
    for (auto it : adj[node]) {
        if (vis[it] == 0) {
            DFS(it, dfs_order, adj, vis);
        }
    }
}

vector<int> dfs(int V, vector<int> adj[]) {
    int vis[V] = {0};
    int start = 0;
    vector<int> dfs_order;
    DFS(start, dfs_order, adj, vis);
    return dfs_order;
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int>& ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    vector<int> adj[6];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    vector<int> ans = dfs(6, adj);
    printAns(ans);

    return 0;
}
