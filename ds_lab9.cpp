#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static void downAdjust(vector<int>& a, int parent, int len) {
	int temp = a[parent];
	int child = parent * 2 + 1;
	while (child < len) {
		if (child + 1 < len && a[child + 1] > a[child]) {
			child++;
		}
		if (temp >= a[child]) {
			break;
		}
		a[parent] = a[child];
		parent = child;
		child = parent * 2 + 1;
	}
	a[parent] = temp;
}

static void buildMaxHeap(vector<int>& a) {
	int n = static_cast<int>(a.size());
	for (int i = n / 2 - 1; i >= 0; --i) {
		downAdjust(a, i, n);
	}
}

static void firstPartition(vector<int>& a) {
	int n = static_cast<int>(a.size());
	if (n == 0) {
		return;
	}

	int pivot = a[0];
	int left = 0;
	int right = n - 1;

	while (left < right) {
		while (left < right && a[right] >= pivot) {
			right--;
		}
		if (left < right) {
			a[left++] = a[right];
		}
		while (left < right && a[left] <= pivot) {
			left++;
		}
		if (left < right) {
			a[right--] = a[left];
		}
	}
	a[left] = pivot;
}

static void firstBubblePass(vector<int>& a) {
	for (int i = static_cast<int>(a.size()) - 1; i > 0; --i) {
		if (a[i - 1] > a[i]) {
			swap(a[i - 1], a[i]);
		}
	}
}

static void printArray(const vector<int>& a) {
	for (int i = 0; i < static_cast<int>(a.size()); ++i) {
		if (i > 0) {
			cout << ' ';
		}
		cout << a[i];
	}
	cout << '\n';
}

int main() {

	int n;
	if (!(cin >> n)) {
		return 0;
	}

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> heapArray = a;
	buildMaxHeap(heapArray);
	printArray(heapArray);

	vector<int> partitionArray = a;
	firstPartition(partitionArray);
	printArray(partitionArray);

	firstBubblePass(partitionArray);
	printArray(partitionArray);

	return 0;
}
