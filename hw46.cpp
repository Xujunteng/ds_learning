#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> R(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }
    
    int lo = 0, hi = n - 1;
    bool found = false;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (R[mid] == mid) {
            found = true;
            break;
        } else if (R[mid] < mid) {
            // 下标增长快于值，左边不可能，往右找
            lo = mid + 1;
        } else {
            // 值增长快于下标，右边不可能，往左找
            hi = mid - 1;
        }
    }
    
    cout << (found ? "Yes" : "No") << endl;
    return 0;
}
