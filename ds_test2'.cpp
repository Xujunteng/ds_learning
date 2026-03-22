#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 读取要输出的杨辉三角行数
    int n;
    cin >> n;

    // 行数不合法时直接结束
    if (n <= 0) return 0;

    // 队列中始终保存“当前这一行”的数据
    // 生成下一行时，再把新数据放回队列里
    queue<int> q;

    // 第一行只有一个 1，先放进去
    q.push(1);

    for (int row = 1; row <= n; ++row) {
        // 当前这一行一共有多少个元素
        // 必须先记住长度，因为下面会不断 pop，队列大小会变化
        int size = q.size();

        // pre 用来保存“前一个数”，这样才能和当前数相加生成下一行
        int pre = 0;  // 记录前一个元素

        for (int i = 0; i < size; ++i) {
            // 取出当前行的一个元素
            int cur = q.front();
            q.pop();

            // 先输出当前行的数据，保证输出顺序和杨辉三角一致
            cout << cur;
            if (i < size - 1) cout << " ";

            // 生成下一行：
            // 1. 当前行第一个数后面一定还是 1
            // 2. 其他位置由“前一个数 + 当前数”得到
            if (i == 0) {
                q.push(cur);
            } else {
                q.push(pre + cur);
            }

            // 更新前一个数，为下一轮相加做准备
            pre = cur;
        }

        // 当前行处理完后，补上下一行的最后一个 1
        // 这样队列里就完整保存了“下一行”的数据
        q.push(1);

        // 换行输出下一行
        cout << endl;
    }

    return 0;
}