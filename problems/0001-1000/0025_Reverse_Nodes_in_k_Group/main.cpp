#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;

        while (cur) {
            n++;
            cur = cur->next;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* p0 = dummy;

        while (n >= k) {
            ListNode* pre = nullptr;
            ListNode* cur = p0->next;
            ListNode* temp = p0->next;

            for (int i = 0; i < k; i++) {
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
                n--;
            }

            p0->next->next = cur;
            p0->next = pre;
            p0 = temp;
        }

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};

ListNode* buildList(vector<int> nums) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;

    for (int i = 1; i < nums.size(); i++) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* cur = head;

    while (cur) {
        cout << cur->val;

        if (cur->next) cout << " -> ";

        cur = cur->next;
    }

    cout << endl;
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4, 5};
    int k1 = 2;

    ListNode* head1 = buildList(nums1);

    cout << "Original list 1: ";
    printList(head1);

    ListNode* result1 = sol.reverseKGroup(head1, k1);

    cout << "After reverseKGroup k = " << k1 << ": ";
    printList(result1);
    // Expected: 2 -> 1 -> 4 -> 3 -> 5

    freeList(result1);

    cout << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 3;

    ListNode* head2 = buildList(nums2);

    cout << "Original list 2: ";
    printList(head2);

    ListNode* result2 = sol.reverseKGroup(head2, k2);

    cout << "After reverseKGroup k = " << k2 << ": ";
    printList(result2);
    // Expected: 3 -> 2 -> 1 -> 4 -> 5

    freeList(result2);

    return 0;
}