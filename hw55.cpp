#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// 希尔排序（递增排序）
void shellSort(vector<int>& arr) {
    int n = (int)arr.size();

    // 增量序列: n/2, n/4, n/8, ..., 1
    for (int gap = n / 2; gap >= 1; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int key = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > key) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
    }
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    if (!fin.is_open() || !fout.is_open()) {
        return 0;
    }

    // 读取一行中的所有整数
    string line;
    getline(fin, line);
    istringstream iss(line);

    vector<int> arr;
    int x;
    while (iss >> x) {
        arr.push_back(x);
    }

    int n = (int)arr.size();
    if (n == 0) {
        fin.close();
        fout.close();
        return 0;
    }

    // 希尔排序
    shellSort(arr);

    // 输出结果
    for (int i = 0; i < n; ++i) {
        if (i > 0) fout << " ";
        fout << arr[i];
    }

    fin.close();
    fout.close();
    return 0;
}
