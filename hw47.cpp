#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

// 哈希表类：除留余数法 + 拉链法（链地址法）
class HashTab {
private:
    int size;  // 哈希表长度（槽数）
    vector<list<pair<int, int>>> table;  // 每个槽是一个链表，存 (key, value)

    // 除留余数法：哈希函数
    int hash(int key) const {
        return key % size;
    }

public:
    HashTab(int sz = 13) : size(sz), table(sz) {}

    // 插入 (key, value)
    void insert(int key, int value) {
        int idx = hash(key);
        // 检查是否已存在，存在则更新值
        for (auto& p : table[idx]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[idx].push_back({key, value});
    }

    // 查找 key，返回指针（用于删除），找不到返回 nullptr
    pair<int, int>* search(int key) {
        int idx = hash(key);
        for (auto& p : table[idx]) {
            if (p.first == key) {
                return &p;
            }
        }
        return nullptr;
    }

    // 删除关键字为 k 的元素
    bool remove(int k) {
        int idx = hash(k);
        for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
            if (it->first == k) {
                table[idx].erase(it);
                return true;
            }
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;

    HashTab ht(13);  // 默认取模 13

    while (n--) {
        string op;
        cin >> op;
        if (op == "insert") {
            int key, value;
            cin >> key >> value;
            ht.insert(key, value);
        } else if (op == "remove") {
            int key;
            cin >> key;
            if (ht.remove(key)) {
                cout << "Delete successfully" << endl;
            } else {
                cout << "Key not found" << endl;
            }
        }
    }

    return 0;
}
