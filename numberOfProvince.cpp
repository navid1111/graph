#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void Bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
	vis[row][col] = 1;
	queue<pair<int, int>> q;
	q.push({row, col});
	int n = grid.size(); // number of rows
	int m = grid[0].size(); // number of columns

	while (!q.empty()) {
		int nrow = q.front().first;
		int ncol = q.front().second;
		q.pop();
		int dx[] = { -1, 1, 0, 0};
		int dy[] = {0, 0, -1, 1};
		for (int k = 0; k < 4; k++) {
			int new_row = nrow + dx[k];
			int new_col = ncol + dy[k];
			if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] == '1' && vis[new_row][new_col] == 0) {
				vis[new_row][new_col] = 1;
				q.push({new_row, new_col});
			}
		}
	}
}

int numberOfIslands(vector<vector<char>> &grid) {
	int n = grid.size(); // number of rows
	int m = grid[0].size(); // number of columns
	vector<vector<int>> vis(n, vector<int>(m, 0));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '1' && vis[i][j] == 0) {
				cnt++;
				Bfs(i, j, vis, grid);
			}
		}
	}
	return cnt;
}

int main() {
	vector<vector<char>> grid = {
		{'0', '1', '1', '1', '0', '0', '0'},
		{'0', '0', '1', '1', '0', '1', '0'}
	};

	cout << numberOfIslands(grid) << endl;

	return 0;
}
