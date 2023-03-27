/* 美团-解释器 */
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

/* 测试用例 */
/*  LOGNAME=default;SHELL=/bin/bash;HOME=/home/xiaomei;LOGNAME=xiaomei;
    4
    SHELL
    HOME
    LOGNAME
    logname
*/
int main() {
    unordered_map<string, string> map; // 用来存储键值对
    /* 得到输入字符串并解析 */
    string str;
    getline(cin, str);
    stringstream ss(str);
    string token; // 分割字符串临时变量
    while (getline(ss, token, ';')) { // 先对;号进行分割
        size_t pos = token.find("="); // 查询"="的位置
        if (pos != string::npos) { // 如果找到了的话
            string key = token.substr(0, pos);
            string value = token.substr(pos+1);
            map[key] = value;
        }
    }

    /* 查询并保存结果 */
    int queryNum; // 查询次数
    cin >> queryNum;
    vector<string> outStr; // 输出结果容器
    for (int i = 0; i < queryNum; i++) { // 遍历每次查询操作
        string qStr;
        cin >> qStr;
        if (map.find(qStr) != map.end()) { // 如果找到了键的话
            outStr.push_back(map[qStr]);
        } else { // 没找到该键的话，输出EMPTY
            outStr.push_back("EMPTY");
        }
    }

    /* 输出查询结果 */
    for (auto it : outStr) {
        cout << it << endl;
    }

    return 0;
}
