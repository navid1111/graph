#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr first
#define sc second
vector<int> Bfs(int v, vector<int>adj[]) {
    int vis[v] = {0};
    queue<int>q;
    q.push(0);
    vis[0] = 1;
    vector<int>bsf;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bsf.push_back(node);
        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                vis[it] = 1;
                q.push(it);
            }
        }


    }
    return bsf;


}

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}


int main()
{
    vector <int> adj[6];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);
    vector <int> ans = Bfs(5, adj);
    printAns(ans);






    return 0;
}