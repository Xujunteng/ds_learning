#include <cctype>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct ParseResult {
    bool valid = false;
    vector<char> postfix;
};

struct EvalResult {
    bool ok = false;
    bool divZero = false;
    int value = 0;
};

bool IsOperand(char c) {
    return isdigit(static_cast<unsigned char>(c)) || isalpha(static_cast<unsigned char>(c));
}

int Priority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return -1;
}

ParseResult ToPostfix(const string& expr) {
    ParseResult res;
    stack<char> ops;
    bool expectOperand = true;

    for (char ch : expr) {
        if (isspace(static_cast<unsigned char>(ch))) {
            continue;
        }

        if (IsOperand(ch)) {
            if (!expectOperand) {
                return res;
            }
            res.postfix.push_back(ch);
            expectOperand = false;
        } else if (ch == '(') {
            if (!expectOperand) {
                return res;
            }
            ops.push(ch);
        } else if (ch == ')') {
            if (expectOperand) {
                return res;
            }
            bool matched = false;
            while (!ops.empty()) {
                char top = ops.top();
                ops.pop();
                if (top == '(') {
                    matched = true;
                    break;
                }
                res.postfix.push_back(top);
            }
            if (!matched) {
                return res;
            }
            expectOperand = false;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (expectOperand) {
                return res;
            }
            while (!ops.empty() && ops.top() != '(' && Priority(ops.top()) >= Priority(ch)) {
                res.postfix.push_back(ops.top());
                ops.pop();
            }
            ops.push(ch);
            expectOperand = true;
        } else {
            return res;
        }
    }

    if (expectOperand) {
        return res;
    }

    while (!ops.empty()) {
        if (ops.top() == '(' || ops.top() == ')') {
            return res;
        }
        res.postfix.push_back(ops.top());
        ops.pop();
    }

    res.valid = !res.postfix.empty();
    return res;
}

EvalResult EvalPostfix(const vector<char>& postfix) {
    EvalResult ret;
    stack<int> st;

    for (char token : postfix) {
        if (isdigit(static_cast<unsigned char>(token))) {
            st.push(token - '0');
        } else if (isalpha(static_cast<unsigned char>(token))) {
           
            st.push(static_cast<int>(token));
        } else {
            if (st.size() < 2) {
                return ret;
            }
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            if (token == '+') {
                st.push(a + b);
            } else if (token == '-') {
                st.push(a - b);
            } else if (token == '*') {
                st.push(a * b);
            } else if (token == '/') {
                if (b == 0) {
                    ret.divZero = true;
                    return ret;
                }
                st.push(a / b);
            } else {
                return ret;
            }
        }
    }

    if (st.size() != 1) {
        return ret;
    }

    ret.ok = true;
    ret.value = st.top();
    return ret;
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    if (!fin.is_open() || !fout.is_open()) {
        return 0;
    }

    int n = 0;
    fin >> n;
    string expr1, expr2;
    getline(fin, expr1);

    for (int i = 0; i < n; ++i) {
        if (!getline(fin, expr1)) {
            expr1.clear();
        }
        if (!getline(fin, expr2)) {
            expr2.clear();
        }

        ParseResult p1 = ToPostfix(expr1);
        ParseResult p2 = ToPostfix(expr2);

        vector<string> parts;
        if (!p1.valid) {
            parts.push_back("表达式1无效！");
        }
        if (!p2.valid) {
            parts.push_back("表达式2无效！");
        }
        if (!parts.empty()) {
            fout << "测试用例" << (i + 1) << "：";
            for (size_t k = 0; k < parts.size(); ++k) {
                fout << parts[k];
            }
            if (i + 1 < n) {
                fout << '\n';
            }
            continue;
        }

        EvalResult v1 = EvalPostfix(p1.postfix);
        EvalResult v2 = EvalPostfix(p2.postfix);

        parts.clear();
        if (v1.divZero) {
            parts.push_back("表达式1除0出错！");
        }
        if (v2.divZero) {
            parts.push_back("表达式2除0出错！");
        }
        if (!parts.empty()) {
            fout << "测试用例" << (i + 1) << "：";
            for (size_t k = 0; k < parts.size(); ++k) {
                fout << parts[k];
            }
            if (i + 1 < n) {
                fout << '\n';
            }
            continue;
        }

        string answer;
        if (!v1.ok) {
            answer = "表达式1无效！";
        } else if (!v2.ok) {
            answer = "表达式2无效！";
        } else if (v1.value == v2.value) {
            answer = "TRUE";
        } else {
            answer = "FALSE";
        }

        fout << "测试用例" << (i + 1) << "：" << answer;
        if (i + 1 < n) {
            fout << '\n';
        }
    }

    return 0;
}