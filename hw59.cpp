#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Stick {
    int l, w;
};

int main() {
    ifstream fin("in.txt");
    if (!fin.is_open()) {
        return 0;
    }

    int n;
    fin >> n;

    vector<Stick> sticks(n);
    for (int i = 0; i < n; ++i) {
        fin >> sticks[i].l >> sticks[i].w;
    }

    // Sort by length ascending, then by weight ascending
    sort(sticks.begin(), sticks.end(), [](const Stick& a, const Stick& b) {
        if (a.l != b.l) return a.l < b.l;
        return a.w < b.w;
    });

    vector<bool> used(n, false);
    int chains = 0;

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ++chains;
            int last_w = sticks[i].w;
            used[i] = true;
            for (int j = i + 1; j < n; ++j) {
                if (!used[j] && sticks[j].w >= last_w) {
                    used[j] = true;
                    last_w = sticks[j].w;
                }
            }
        }
    }

    cout << chains << endl;

    fin.close();
    return 0;
}