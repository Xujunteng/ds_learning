#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	if (!(cin >> s)) {
		return 0;
	}

	int n = static_cast<int>(s.size());
	if (n == 0) {
		cout << s << "有0个好串：";
		return 0;
	}

	vector<int> firstBadFrom(n, n - 1);
	vector<int> prevBadBefore(max(1, n - 1), -1);

	if (n >= 2) {
		vector<bool> pairOK(n - 1, false);
		for (int i = 0; i < n - 1; ++i) {
			int d = (s[i + 1] - '0') - (s[i] - '0');
			pairOK[i] = (d == 0 || d == 1);
		}

		firstBadFrom[n - 1] = n - 1;
		for (int i = n - 2; i >= 0; --i) {
			if (!pairOK[i]) {
				firstBadFrom[i] = i;
			} else {
				firstBadFrom[i] = firstBadFrom[i + 1];
			}
		}

		prevBadBefore[0] = pairOK[0] ? -1 : 0;
		for (int i = 1; i < n - 1; ++i) {
			prevBadBefore[i] = pairOK[i] ? prevBadBefore[i - 1] : i;
		}
	}

	vector<string> goods;
	goods.reserve(static_cast<size_t>(n) * (n + 1) / 2);

	for (int l = 0; l < n; ++l) {
		for (int r = l; r < n; ++r) {
			bool isGood = false;

			if (l == r) {
				isGood = true;
			} else {
				int lower = l + 1;
				int upper = r;

				
				lower = max(lower, prevBadBefore[r - 1] + 1);
				upper = min(upper, firstBadFrom[l] + 1);

				if (lower <= upper) {
					isGood = true;
				}
			}

			if (isGood) {
				goods.push_back(s.substr(l, r - l + 1));
			}
		}
	}

	cout << s << "有" << goods.size() << "个好串：";
	for (size_t i = 0; i < goods.size(); ++i) {
		if (i > 0) {
			cout << ' ';
		}
		cout << goods[i];
	}

	return 0;
}
