#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	if (!(cin >> n)) return 0;
	if (n <= 0) return 0;

	vector<vector<int>> a(n, vector<int>(n, 0));
	int top = 0, bottom = n - 1, left = 0, right = n - 1;
	int cur = 1;
	while (left <= right && top <= bottom) {
		// left -> right
		for (int j = left; j <= right; ++j) a[top][j] = cur++;
		++top;
		// top -> bottom
		for (int i = top; i <= bottom; ++i) a[i][right] = cur++;
		--right;
		if (top <= bottom) {
			for (int j = right; j >= left; --j) a[bottom][j] = cur++;
			--bottom;
		}
		if (left <= right) {
			for (int i = bottom; i >= top; --i) a[i][left] = cur++;
			++left;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << setw(3) << a[i][j];
		}
		cout << '\n';
	}

	return 0;
}

