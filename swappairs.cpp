#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        /* 1 2 3 4 */
        if (!head || !head->next || !head->next->next) return head; // 当只有一个或两个结点时，直接返回
        ListNode* dummy = new ListNode(0); // 新建一个虚拟头结点
        dummy->next = head;
        ListNode* pre = dummy, *cur = head;
        while (cur && cur->next && cur->next->next) { // 至少有三个结点才交换
            ListNode* first = cur, *second = first->next, *third = second->next;
            pre->next = third;
            /* 找到最末结点，可能是第三个结点，也可能是第四个结点 */
            ListNode* tail = cur->next->next;
            if (tail->next) tail = tail->next;
            second->next = tail->next; // 保存尾结点的下一个结点
            tail->next = first; // 将尾结点拉到前面
            cur = second->next; // 更新cur结点，为第二个结点的下一个结点
            pre = second; // 更新pre结点，为第二个结点
        }
        /* 得到最新的头结点 */
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main() {
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);
    ListNode* five = new ListNode(5);
    ListNode* six = new ListNode(6);
    ListNode* seven = new ListNode(7);
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    Solution sol;
    ListNode* head = sol.swapPairs(one);

    cout << "Debug" << endl;

    return 0;
}
