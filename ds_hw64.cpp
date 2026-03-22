#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    int k;
    fin >> k;

    vector<int> arr;
    int val;
    while (fin >> val) {
        arr.push_back(val);
    }

    int n = (int)arr.size();
    int low = 0, high = n - 1;
    bool found = false;
    vector<int> seq;

    while (low <= high) {
        int mid = (low + high) / 2;
        seq.push_back(arr[mid]);
        if (arr[mid] == k) {
            found = true;
            break;
        }
        else if (arr[mid] < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    fout << (found ? "True" : "False") << endl;
    for (int i = 0; i < (int)seq.size(); ++i) {
        if (i > 0) fout << " ";
        fout << seq[i];
    }
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}
