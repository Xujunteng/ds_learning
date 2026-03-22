#include <iostream>
#include <vector>
using namespace std;

// 在递增序列中找 k 的第一次出现位置（左边界），找不到返回 -1
int findLeft(const vector<int>& arr, int k) {
    int lo = 0, hi = arr.size() - 1;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] >= k) {
            if (arr[mid] == k) ans = mid;  // 命中时记录
            hi = mid - 1;                   // 继续往左找
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

// 在递增序列中找 k 的最后一次出现位置（右边界），找不到返回 -1
int findRight(const vector<int>& arr, int k) {
    int lo = 0, hi = arr.size() - 1;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] <= k) {
            if (arr[mid] == k) ans = mid;  // 命中时记录
            lo = mid + 1;                   // 继续往右找
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int k;
    cin >> k;
    
    int left = findLeft(arr, k);
    if (left == -1) {
        cout << 0 << endl;
    } else {
        int right = findRight(arr, k);
        cout << (right - left + 1) << endl;
    }
    
    return 0;
}
