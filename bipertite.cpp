#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr first
#define sc second

bool dfs(int node, int col, int color[], vector<int>adj[]) {
	color[node] = col;
	for (auto it : adj[node]) {
		if (color[it] == col)return false;
		else if (dfs(it, col, color, adj) == false)return false;

		return true;
	}

}
bool isBipartite(int V, vector<int>adj[]) {
	int vis[V] = { -1};
	for (int i = 0; i < V; i++) {
		if (vis[i] == -1) {
			if (dfs(i, 0, vis, adj) == false)
				return false;
		}
	}
	return true;

}
void addEdge(vector <int> adj[], int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main() {

	// V = 4, E = 4
	vector<int>adj[4];

	addEdge(adj, 0, 2);
	addEdge(adj, 0, 3);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 1);


	bool ans = isBipartite(4, adj);
	if (ans)cout << "1\n";
	else cout << "0\n";

	return 0;
}