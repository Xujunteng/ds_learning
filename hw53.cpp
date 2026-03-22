#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// 链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

// 将链表从中间分成两半，返回第二半的头指针
ListNode* split(ListNode* head) {
    if (!head || !head->next) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* second = slow->next;
    slow->next = nullptr;  // 断开前后两半
    return second;
}

// 合并两个已排序的链表
ListNode* merge(ListNode* a, ListNode* b) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (a && b) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a ? a : b);
    return dummy.next;
}

// 链表的二路归并排序（递归）
ListNode* mergeSort(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* second = split(head);
    ListNode* left = mergeSort(head);
    ListNode* right = mergeSort(second);
    return merge(left, right);
}

// 释放链表内存
void deleteList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
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

    int x;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while (iss >> x) {
        ListNode* node = new ListNode(x);
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    if (!head) {
        fin.close();
        fout.close();
        return 0;
    }

    // 链表二路归并排序
    head = mergeSort(head);

    // 输出结果
    ListNode* cur = head;
    bool first = true;
    while (cur) {
        if (!first) fout << " ";
        fout << cur->val;
        first = false;
        cur = cur->next;
    }

    deleteList(head);
    fin.close();
    fout.close();
    return 0;
}