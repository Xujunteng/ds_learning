#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> R(n);
    for (int i = 0; i < n; ++i) {
        cin >> R[i];
    }

    int l = 0, r = n - 1;
    int cmpCount = 0;

    while (l < r) {
        int mid = (l + r) / 2;
        cmpCount++;
        // check(mid): R[mid] <= k
        if (R[mid] <= k) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    // l points to first element > k (or n if all <= k)
    bool found = false;
    if (l > 0 && R[l - 1] == k) {
        found = true;
    }
    // Also check R[l] itself in edge cases
    if (l < n && R[l] == k) {
        found = true;
    }

    if (!found) {
        cout << -1 << endl;
    }
    else {
        cout << cmpCount << endl;
    }

    return 0;
}