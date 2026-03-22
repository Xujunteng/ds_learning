#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Count number of pairs (i,j) with i < j and arr[j] - arr[i] <= M
long long countPairs(const vector<int>& arr, int M) {
    long long cnt = 0;
    int n = (int)arr.size();
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n && arr[j] - arr[i] <= M) {
            ++j;
        }
        cnt += (j - i - 1);
    }
    return cnt;
}

int main() {
    ifstream fin("in.txt");

    int n;
    fin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long m = (long long)n * (n - 1) / 2;
    long long target;
    if (m % 2 == 0) {
        target = m / 2;
    } else {
        target = (m + 1) / 2;
    }

    int lo = 0, hi = arr[n - 1] - arr[0];
    int ans = hi;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (countPairs(arr, mid) >= target) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;

    fin.close();
    return 0;
}