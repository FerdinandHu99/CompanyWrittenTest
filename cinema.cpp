/* 酷家乐-电影院 */
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;

string addZeroPrefix(int num) {
    string res = to_string(num);
    if (num < 10) {
        res = "0"+res;
        return res;
    } else {
        return res;
    }
}

string getTimeStr(tm& tm) {
    tm.tm_year += 1900;
    tm.tm_mon += 1;
    string res = to_string(tm.tm_year)+"-"+addZeroPrefix(tm.tm_mon)+"-"+addZeroPrefix(tm.tm_mday)+" "+
                 addZeroPrefix(tm.tm_hour)+":"+addZeroPrefix(tm.tm_min)+":"+addZeroPrefix(tm.tm_sec);
    return res;
}
int main() {
    vector<vector<string>> cinema;
    vector<string> history;
    cout << "Welcome to Cinema! " << endl;
    while (true) {
        string cmd;
        getline(cin, cmd);
        stringstream cmdStream(cmd);
        string word;
        vector<string> cmdVec;
        while (getline(cmdStream, word, ' ')) {
            cmdVec.push_back(word);
        }
        auto now = std::chrono::system_clock::now();
        time_t now_t = std::chrono::system_clock::to_time_t(now);
        tm local_tm = *std::localtime(&now_t);
        string timeStr = getTimeStr(local_tm);
        if (cmdVec[0] == "init") {
            int row = atoi(cmdVec[1].c_str());
            int col = atoi(cmdVec[2].c_str());
            cinema.resize(row);
            for (int i = 0; i < row; i++) {
                cinema[i] = vector<string>(col, "O");
            }
        } else if (cmdVec[0] == "sell") {
            int row = atoi(cmdVec[1].c_str());
            int col = atoi(cmdVec[2].c_str());
            cinema[row-1][col-1] = "X";
            string optStr = " row " + to_string(row) + " column " + to_string(col);
            string hisStr = timeStr + optStr;
            history.push_back(hisStr);
        } else if (cmdVec[0] == "print") {
            for (int i = 0; i < cinema.size(); i++) {
                for (int j = 0; j < cinema[i].size(); j++) {
                    cout << cinema[i][j];
                }
                cout << endl;
            }
        } else if (cmdVec[0] == "listorder") {
            for (auto his : history) {
                cout << his << endl;
            }
        } else if (cmdVec[0] == "refund") {
            int row = atoi(cmdVec[1].c_str());
            int col = atoi(cmdVec[2].c_str());
            cinema[row-1][col-1] = "O";
            string optStr = " row " + to_string(row) + " column " + to_string(col) + " refund";
            string hisStr = timeStr + optStr;
            history.push_back(hisStr);
        }
    }
    return 0;
}

