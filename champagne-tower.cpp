/* 西山居-香槟塔 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int size = query_row + 1;
        vector<vector<double>> dp(size, vector<double>(size, 0.0));
        dp[0][0] = poured;
        for (int i = 0; i < size-1; i++) { // 遍历当前行，会更新下一行
            for (int j = 0; j <= i; j++) { // 每一列的数量=当前行数(i)+1
                if (dp[i][j] > 1) { // 如果当前杯子大于1，说明会溢出
                    dp[i + 1][j] += (dp[i][j] - 1.0) / 2.0;
                    dp[i + 1][j + 1] += (dp[i][j] - 1.0) / 2.0;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};

int main() {
    Solution sol;
    cout << sol.champagneTower(2, 1, 1);
}
