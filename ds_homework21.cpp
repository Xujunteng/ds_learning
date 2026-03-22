#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>
using namespace std;

class Solution {
private:
    int count_result;
    
    // 检查在第row行第col列放置皇后是否合法
    bool isSafe(vector<int>& cols, int row, int col) {
        for (int i = 0; i < row; i++) {
            // 检查第col列是否已有皇后
            if (cols[i] == col) {
                return false;
            }
            // 检查对角线是否有皇后
            // 左上、右上、左下、右下四个对角线方向
            if (abs(cols[i] - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }
    
    // 回溯函数
    void backtrack(vector<int>& cols, int row, int n) {
        // 如果已经放置了n个皇后，找到一个解决方案
        if (row == n) {
            count_result++;
            return;
        }
        
        // 尝试在第row行的每一列放置皇后
        for (int col = 0; col < n; col++) {
            if (isSafe(cols, row, col)) {
                // 放置皇后
                cols[row] = col;
                // 继续递归放置下一行
                backtrack(cols, row + 1, n);
                // 回溯（实际上不需要撤销，因为下一次迭代会覆盖）
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        count_result = 0;
        vector<int> cols(n, -1);  // cols[i]表示第i行皇后所在的列
        backtrack(cols, 0, n);
        return count_result;
    }
};

int main() {
    Solution solution;
    int n;
    
    // 从in.txt文件中读取测试数据
    ifstream infile("in.txt");
    if (!infile) {
        cerr << "无法打开 in.txt 文件" << endl;
        return 1;
    }
    
    infile >> n;
    infile.close();
    
    // 计算并输出结果
    int result = solution.totalNQueens(n);
    cout << result << endl;
    
    return 0;
}
