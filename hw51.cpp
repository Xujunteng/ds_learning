#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 哈希表类：除留余数法 + 拉链法
class HashTable2 {
private:
    int size;  // 哈希表长度
    vector<list<int>> table;  // 每个槽一个链表，只存 key（value 不参与 ASL 计算）

    int hash(int key) const {
        return key % size;
    }

public:
    HashTable2(int sz = 13) : size(sz), table(sz) {}

    // 插入 key
    void insert(int key) {
        int idx = hash(key);
        table[idx].push_back(key);
    }

    // 计算成功查找的平均查找长度（向下取整）
    int ASL1() {
        int totalComparisons = 0;
        int count = 0;

        for (int i = 0; i < size; i++) {
            int pos = 1;  // 1-based 位置
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {
                totalComparisons += pos;  // 第 pos 个元素需要 pos 次比较
                pos++;
                count++;
            }
        }

        if (count == 0) return 0;
        return totalComparisons / count;  // 整数除法自动向下取整
    }
};

int main() {
    int n;
    cin >> n;

    HashTable2 ht(13);  // 哈希表长度取素数 13

    for (int i = 0; i < n; i++) {
        int key, value;
        cin >> key >> value;
        ht.insert(key);  // value 不参与 ASL 计算，仅插入 key
    }

    cout << ht.ASL1() << endl;
    return 0;
}
