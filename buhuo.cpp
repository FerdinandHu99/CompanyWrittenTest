/* 美团-捕获 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Player {
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }
public:
    int catchEnemyNum(const int& A, const int& B, vector<pair<int, int>>& enemyLoc) {
        sort(enemyLoc.begin(), enemyLoc.end(), cmp);
        vector<int> dp(enemyLoc.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); i++) {
            int numEnemy = 0;
            for (int j = 0; j <= i; j++) {
                if ((enemyLoc[i].first - enemyLoc[j].first) <= A && (enemyLoc[i].second - enemyLoc[j].second) <= B) {
                    numEnemy++;
                }
            }
            dp[i] = max(dp[i-1], numEnemy);
        }
        return dp[enemyLoc.size()-1];
    }
};



int main() {
    int N, A, B;
    vector<pair<int, int>> enemyLoc;
    cin >> N >> A >> B;
    enemyLoc.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        enemyLoc[i].first = x;
        enemyLoc[i].second = y;
    }
    Player player;
    cout << player.catchEnemyNum(A, B, enemyLoc);

    return 0;
}
