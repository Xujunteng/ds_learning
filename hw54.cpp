#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// 快速排序，使用最左端作为枢轴
void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[left];
    int i = left;
    int j = right + 1;
    while (true) {
        while (arr[++i] < pivot) {}
        while (arr[--j] > pivot) {}
        if (i < j)
            swap(arr[i], arr[j]);
        else
            break;
    }
    swap(arr[left], arr[j]);

    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    if (!fin.is_open() || !fout.is_open()) {
        return 0;
    }

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

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        if (i > 0) fout << " ";
        fout << arr[i];
    }

    fin.close();
    fout.close();
    return 0;
}