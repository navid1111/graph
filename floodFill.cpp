#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int newColor, int iniColor) {
	if (row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] != iniColor || ans[row][col] == newColor) {
		return;
	}

	ans[row][col] = newColor;

	static int dr[] = { -1, 0, 1, 0};
	static int dc[] = {0, 1, 0, -1};

	for (int i = 0; i < 4; i++) {
		int newRow = row + dr[i];
		int newCol = col + dc[i];
		dfs(newRow, newCol, image, ans, newColor, iniColor);
	}
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	int iniColor = image[sr][sc];
	if (iniColor == newColor) {
		return image;
	}

	int n = image.size();
	int m = image[0].size();
	vector<vector<int>> ans = image;
	dfs(sr, sc, image, ans, newColor, iniColor);

	return ans;
}

int main() {
	vector<vector<int>> image{
		{1, 1, 1},
		{1, 1, 0},
		{1, 0, 1}
	};

	vector<vector<int>> ans = floodFill(image, 1, 1, 2);

	for (auto i : ans) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "\n";
	}

	return 0;
}
