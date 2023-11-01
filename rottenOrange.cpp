#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr first
#define sc second
class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		int tm;
		int r = 0;
		vector<vector<int>> vis(n, vector<int>(m, 0));
		queue<pair<pair<int, int>, int>>q;
		int rotten = 0, good = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 2)
					q.push({{i, j}, 0});
				else if (grid[i][j] == 1)good++;
				else if (grid[i][j] == 2)r++;
			}
		}
		while (!q.empty()) {
			int a = q.front().first.first;
			int b = q.front().first.second;
			tm = q.front().second;
			q.pop();
			int dx[] = { -1, 0, 1, 0};
			int dy[] = {0, 1, 0, -1};
			for (int i = 0; i < 4; i++) {
				int row = a + dx[i];
				int col = b + dy[i];
				if (row >= 0 && row < n && col >= 0 && col < m && vis[row][col] == 0 && grid[row][col] == 1) {
					q.push({{row, col}, tm + 1});
					vis[row][col] = 2;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 2)
					q.push({{i, j}, 0});
				else if (vis[i][j] == 2)rotten++;
			}
		}
		if (r == 0 && good == 0) return 0;
		if (rotten != good)return -1;



		return tm;




	}
};

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);



	return 0;
}