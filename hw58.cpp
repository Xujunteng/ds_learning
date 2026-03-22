#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ifstream fin("in.txt");
    if (!fin.is_open()) {
        return 0;
    }

    int n;
    fin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        fin >> x[i] >> y[i];
    }

    // Sort x and y separately
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    // Median of y
    int median_y = y[n / 2];

    // Compute z[i] = x[i] - i, then find its median
    vector<int> z(n);
    for (int i = 0; i < n; ++i) {
        z[i] = x[i] - i;
    }
    sort(z.begin(), z.end());
    int median_z = z[n / 2];

    // Calculate total moves
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        total += abs(x[i] - (median_z + i));
        total += abs(y[i] - median_y);
    }

    cout << total << endl;

    fin.close();
    return 0;
}