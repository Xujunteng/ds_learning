#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("in.txt");
    if (!fin.is_open()) {
        return 0;
    }

    int n, m;
    fin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
    }

    // 降序排序
    sort(arr.begin(), arr.end(), greater<int>());

    // 输出前 m 大的数
    for (int i = 0; i < m; ++i) {
        if (i > 0) cout << " ";
        cout << arr[i];
    }
    cout << endl;

    fin.close();
    return 0;
}
