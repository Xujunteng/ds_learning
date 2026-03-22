#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;

int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int bfs() {
	if (g[0][0] == 1 || g[n - 1][m - 1] == 1) return -1;
	vector<vector<int>> dist(n, vector<int>(m, -1));
	queue<pair<int, int>> q;
	dist[0][0] = 1;
	q.push({0, 0});

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if (x == n - 1 && y == m - 1) return dist[x][y];
		for (int k = 0; k < 4; ++k) {
			int nx = x + dirs[k][0];
			int ny = y + dirs[k][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (g[nx][ny] == 1 || dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({nx, ny});
		}
	}
	return -1;
}

int main() {

	if (!(cin >> n >> m)) return 0;
	if (n <= 0 || m <= 0) {
		cout << -1;
		return 0;
	}

	g.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> g[i][j];
		}
	}

	int ans = bfs();
	cout << ans;
	return 0;
}
