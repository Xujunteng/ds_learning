#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<vector<int>> vis;
int ans = -1;
bool found_path = false;

int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; // 上, 右, 下, 左

void dfs(int x, int y, int len) {
	if (found_path) return;
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (g[x][y] == 1 || vis[x][y]) return;
	if (x == n-1 && y == m-1) {
		ans = len;
		found_path = true;
		return;
	}
	vis[x][y] = 1;
	for (int k = 0; k < 4; ++k) {
		int nx = x + dirs[k][0];
		int ny = y + dirs[k][1];
		dfs(nx, ny, len + 1);
		if (found_path) return;
	}
	vis[x][y] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	if (!(cin >> n >> m)) return 0;
	g.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> g[i][j];
		}
	}

	if (n <= 0 || m <= 0) {
		cout << -1;
		return 0;
	}

	if (g[0][0] == 1 || g[n-1][m-1] == 1) {
		cout << -1;
		return 0;
	}

	vis.assign(n, vector<int>(m, 0));
	dfs(0, 0, 1); // 起点算一个节点

	if (found_path) cout << ans;
	else cout << -1;

	return 0;
}

