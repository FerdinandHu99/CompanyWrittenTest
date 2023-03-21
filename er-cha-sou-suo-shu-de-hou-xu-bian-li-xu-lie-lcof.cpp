/* 剑指 Offer 33. 二叉搜索树的后序遍历序列 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool recursion(vector<int>& postorder, int beginIdx, int endIdx) {
        if (beginIdx >= endIdx) return true; // 子树节点数量<=1，默认为二叉搜索树
        int p = beginIdx; // p用来寻找左右子树分界节点
        while (postorder[p] < postorder[endIdx]) p++;
        int splitIndex = p; // 找到分界节点索引
        while (postorder[p] > postorder[endIdx]) p++;
        if (p != endIdx) return false; // 保证右子树的所有节点大于根节点

        bool leftIsTrue = recursion(postorder, beginIdx, splitIndex-1); // 判断左子树是否为二叉搜索树
        bool rightIsTrue = recursion(postorder, splitIndex, endIdx-1); // 判断右子树是否为二叉搜索树

        return leftIsTrue && rightIsTrue;
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recursion(postorder, 0, postorder.size()-1);
    }
};

int main() {
    Solution sol;
    vector<int> postorder = {1, 3, 2, 6, 5};
    cout << "res: " << sol.verifyPostorder(postorder);

    return 0;
}
