#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static const int INF = 1000000000;

static int shortestInPrefix(const vector<vector<int>>& base, int activeCount, int x, int y) {
	if (x >= activeCount || y >= activeCount) {
		return -1;
	}

	vector<vector<int>> dist = base;
	for (int k = 0; k < activeCount; ++k) {
		for (int i = 0; i < activeCount; ++i) {
			if (dist[i][k] >= INF) {
				continue;
			}
			for (int j = 0; j < activeCount; ++j) {
				if (dist[k][j] >= INF) {
					continue;
				}
				int through = dist[i][k] + dist[k][j];
				if (through < dist[i][j]) {
					dist[i][j] = through;
				}
			}
		}
	}

	if (dist[x][y] >= INF) {
		return -1;
	}
	return dist[x][y];
}

int main() {

	int n, m;
	if (!(cin >> n >> m)) {
		return 0;
	}

	vector<int> rebuildTime(n);
	for (int i = 0; i < n; ++i) {
		cin >> rebuildTime[i];
	}

	vector<vector<int>> base(n, vector<int>(n, INF));
	for (int i = 0; i < n; ++i) {
		base[i][i] = 0;
	}

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		if (w < base[u][v]) {
			base[u][v] = w;
			base[v][u] = w;
		}
	}

	int q;
	cin >> q;

	int activeCount = 0;
	for (int caseId = 0; caseId < q; ++caseId) {
		int x, y, t;
		cin >> x >> y >> t;

		while (activeCount < n && rebuildTime[activeCount] <= t) {
			activeCount++;
		}

		cout << shortestInPrefix(base, activeCount, x, y) << '\n';
	}

	return 0;
}
