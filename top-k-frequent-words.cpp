/* 692. 前K个高频单词 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    class Compare {
    public:
        bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) {
            if (p1.second != p2.second) {
                return p1.second > p2.second;
            } else {
                return p1.first < p2.first;
            }

        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        /* 统计字符串出现的个数 */
        unordered_map<string, int> map;
        for (const auto& it : words) {
            map[it]++;
        }
        /* 创建优先级队列 */
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pQueue;
        /* 将小顶堆设为固定大小k */
        for (auto it = map.begin(); it != map.end(); it++) {
            pQueue.push(*it);
            if (pQueue.size() > k) {
                pQueue.pop();
            }
        }
        /* 找到前k个高频元素 */
        vector<string> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = pQueue.top().first;
            pQueue.pop();
        }
        return res;
    }
};

int main() {
    vector<string> words = {"aaaa", "aa", "aaa"};
    Solution sol;
    vector<string> res = sol.topKFrequent(words, 2);
    for (auto it : res) {
        cout << it << ", ";
    }
    cout << endl;
    return 0;
}
