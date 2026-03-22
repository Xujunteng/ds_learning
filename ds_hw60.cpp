#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> R(n);
    for (int i = 0; i < n; ++i) {
        cin >> R[i];
    }

    int left = 0, right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (R[mid] == mid) {
            found = true;
            break;
        }
        else if (R[mid] < mid) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << (found ? "Yes" : "No") << endl;

    return 0;
}