#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
    double w;
    char ch;
    Node* left;
    Node* right;
    int id;

    Node(double weight, char c, int order)
        : w(weight), ch(c), left(nullptr), right(nullptr), id(order) {}

    Node(double weight, Node* l, Node* r, int order)
        : w(weight), ch('\0'), left(l), right(r), id(order) {}
};

struct Cmp {
    bool operator()(const Node* a, const Node* b) const {
        const double kEps = 1e-12;
        if (fabs(a->w - b->w) > kEps) {
            return a->w > b->w;
        }
        return a->id > b->id;
    }
};

static Node* buildHuffman(const vector<Node*>& leaves) {
    priority_queue<Node*, vector<Node*>, Cmp> pq;
    for (Node* leaf : leaves) {
        pq.push(leaf);
    }

    int nextId = static_cast<int>(leaves.size());
    while (pq.size() > 1) {
        Node* x = pq.top();
        pq.pop();
        Node* y = pq.top();
        pq.pop();

        Node* parent = new Node(x->w + y->w, x, y, nextId++);
        pq.push(parent);
    }

    return pq.empty() ? nullptr : pq.top();
}

static string sanitizeBits(const string& line) {
    string bits;
    bits.reserve(line.size());
    for (char c : line) {
        if (c == '0' || c == '1') {
            bits.push_back(c);
        }
    }
    return bits;
}

static string decodeLine(const string& bits, Node* root) {
    if (!root) {
        return "";
    }

    if (!root->left && !root->right) {
        return string(bits.size(), root->ch);
    }

    string out;
    out.reserve(bits.size());
    Node* cur = root;

    for (char b : bits) {
        cur = (b == '0') ? cur->left : cur->right;
        if (!cur->left && !cur->right) {
            out.push_back(cur->ch);
            cur = root;
        }
    }

    return out;
}

int main() {
    int n = 0;
    if (!(cin >> n)) {
        return 0;
    }

    vector<Node*> leaves;
    leaves.reserve(n);

    for (int i = 0; i < n; ++i) {
        char ch = '\0';
        char colon = '\0';
        double freq = 0.0;
        cin >> ch >> colon >> freq;
        leaves.push_back(new Node(freq, ch, i));
    }

    Node* root = buildHuffman(leaves);

    ifstream fin("in.txt");
    ofstream fout("out.txt");

    string line;
    bool firstLine = true;
    while (getline(fin, line)) {
        string bits = sanitizeBits(line);
        string decoded = decodeLine(bits, root);
        if (!firstLine) {
            fout << '\n';
        }
        firstLine = false;
        fout << decoded;
    }

    return 0;
}