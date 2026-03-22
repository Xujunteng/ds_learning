#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

// 双哈希参数：两个不同的大素数模数
const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll BASE = 131;  // 质数基数，分布更好

// 字符映射：'a'=1, 'b'=2, ..., 'z'=26
ll charVal(char c) {
    return c - 'a' + 1;
}

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    int n = (int)text.size();
    int m = (int)pattern.size();

    if (m > n || m == 0) {
        cout << endl;
        return 0;
    }

    // 预计算 pow1 = BASE^(m-1) % MOD1, pow2 = BASE^(m-1) % MOD2
    ll pow1 = 1, pow2 = 1;
    for (int i = 0; i < m - 1; i++) {
        pow1 = (pow1 * BASE) % MOD1;
        pow2 = (pow2 * BASE) % MOD2;
    }

    // 计算模式串双哈希值
    ll patHash1 = 0, patHash2 = 0;
    for (int i = 0; i < m; i++) {
        ll cv = charVal(pattern[i]);
        patHash1 = (patHash1 * BASE + cv) % MOD1;
        patHash2 = (patHash2 * BASE + cv) % MOD2;
    }

    // 计算第一个窗口双哈希值
    ll winHash1 = 0, winHash2 = 0;
    for (int i = 0; i < m; i++) {
        ll cv = charVal(text[i]);
        winHash1 = (winHash1 * BASE + cv) % MOD1;
        winHash2 = (winHash2 * BASE + cv) % MOD2;
    }

    vector<int> matches;

    for (int i = 0; i <= n - m; i++) {
        if (i > 0) {
            ll oldCV = charVal(text[i - 1]);
            ll newCV = charVal(text[i + m - 1]);
            // 移除旧字符
            winHash1 = (winHash1 - oldCV * pow1 % MOD1 + MOD1) % MOD1;
            winHash2 = (winHash2 - oldCV * pow2 % MOD2 + MOD2) % MOD2;
            // 加入新字符
            winHash1 = (winHash1 * BASE + newCV) % MOD1;
            winHash2 = (winHash2 * BASE + newCV) % MOD2;
        }
        // 双哈希同时匹配才认为命中（碰撞概率 ≈ 1/(MOD1*MOD2) ≈ 10⁻¹⁸，可忽略）
        if (winHash1 == patHash1 && winHash2 == patHash2) {
            matches.push_back(i);
        }
    }

    for (size_t i = 0; i < matches.size(); i++) {
        if (i > 0) cout << " ";
        cout << matches[i];
    }
    cout << endl;

    return 0;
}
