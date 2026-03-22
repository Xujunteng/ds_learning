#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("in.txt");
    int n;
    fin >> n;

    vector<int> A(n), B(n), C(n), D(n);
    for (int i = 0; i < n; ++i) {
        fin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    // Compute all sums of A + B
    vector<int> sumAB;
    sumAB.reserve((long long)n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sumAB.push_back(A[i] + B[j]);
        }
    }

    // Compute all sums of C + D
    vector<int> sumCD;
    sumCD.reserve((long long)n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sumCD.push_back(C[i] + D[j]);
        }
    }

    // Sort sumAB for binary search
    sort(sumAB.begin(), sumAB.end());

    long long result = 0;
    for (int i = 0; i < (int)sumCD.size(); ++i) {
        int target = -sumCD[i];
        // Count occurrences of target in sumAB using binary search
        auto lo = lower_bound(sumAB.begin(), sumAB.end(), target);
        auto hi = upper_bound(sumAB.begin(), sumAB.end(), target);
        result += (hi - lo);
    }

    cout << result << endl;

    fin.close();
    return 0;
}