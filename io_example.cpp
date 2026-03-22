#include<bits/stdc++.h>
using namespace std;

//cin cout在课内机考的大多数情况下效率足够
//特殊情况可以关闭同步ios::sync_with_stdio(false); cin.tie(nullptr);（此时不能混用cin/cout和scanf/printf）
signed main()
{
    //已知输入个数
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    for(int num : arr) {
        cout << num << " ";
    }
    cout<<"\n";


    //未知输入个数。本地控制台测试时候，ctrl+z结束
    int x;//or char x;string x
    while(cin>>x)
    {
        cout << x << "\n";
        //处理逻辑
    }

    //需要输入整行（cin>>str碰到空格就结束了）
    //注意和cin混用情况
    cin.get();//消耗掉换行符
    string line;
    getline(cin,line);
    cout << line << "\n";

    //getline+stringstream 按行处理，每行按空格分割
    while (getline(cin, line)) {
        stringstream ss(line);
        int num;
        vector<int> row;
        
        //处理当前行的所有数字
        while (ss >> num) {
            row.push_back(num);
        }
        for (int n : row) {
            cout << n << " ";
        }
        cout << "\n";
    }
    //逗号分隔
    while (getline(cin, line)) {
        if(line.empty()) break;
        stringstream ss(line);
        string token;
        vector<int> nums;
        while (getline(ss, token, ',')) {
            nums.push_back(stoi(token));
        }
        for (int num : nums) {
            cout << num << " ";
        }
        cout << "\n";
    }


    //文件输入(使用ifstream，和cin用法类似)
    ifstream ifs("input.txt");
    //例如int num;ifs >> num;

    //输出
    //一般没什么问题，cout即可，文件输出使用ofstream
    //例如 ofstream ofs("output.txt"); ofs << "output";
    //大部分题目会忽略输出中多余的空格和换行，如果不允许多余的换行，循环时加上条件判断即可
    //小数输出控制精度：printf("%.2f", num); 或者 cout << fixed << setprecision(2) << num;
    return 0;
}

