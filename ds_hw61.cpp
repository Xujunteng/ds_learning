#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    int low = 0, high = n - 1;
    bool found = false;
    vector<int> seq;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        seq.push_back(a[mid]);
        if (a[mid] == k) {
            found = true;
            break;
        }
        if (a[mid] < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "Not Found" << endl;
    }
    else {
        for (int i = 0; i < (int)seq.size(); ++i) {
            if (i > 0) cout << " ";
            cout << seq[i];
        }
        cout << endl;
    }

    return 0;
}