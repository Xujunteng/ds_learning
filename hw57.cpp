 #include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

// 统计有序数组 arr 中差值 ≤ D 的数对个数
ll countPairs(const vector<int>& arr, int D) {
    int n = (int)arr.size();
    ll cnt = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j + 1 < n && arr[j + 1] - arr[i] <= D) {
            ++j;
        }
        cnt += (j - i);
    }
    return cnt;
}

int main() {
    ifstream fin("in.txt");
    if (!fin.is_open()) {
        return 0;
    }

    int n;
    fin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
    }

    // 排序
    sort(arr.begin(), arr.end());

    // 总差值个数 m = C(n,2)，目标位置 k
    ll m = (ll)n * (n - 1) / 2;
    ll k = (m + 1) / 2;   // 无论 m 奇偶，目标位置均为第 k 小

    // 二分答案
    int left = 0, right = arr[n - 1] - arr[0];
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (countPairs(arr, mid) >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;

    fin.close();
    return 0;
}
