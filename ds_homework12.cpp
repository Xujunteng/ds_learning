#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> dp(N + 1, 0);
    dp[0] = 1;
    for (int n = 1; n <= N; ++n) {
        for (int left = 0; left <= n - 1; ++left) {
            int right = n - 1 - left;
            dp[n] = (dp[n] + dp[left] * dp[right]) % 100000007;
        }
    }
    cout << dp[N] << '\n';
    return 0;
}