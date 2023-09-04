/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto fast = head , slow = head;
        while(fast and fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow==fast) return true;
        }
        return false;
    }
};