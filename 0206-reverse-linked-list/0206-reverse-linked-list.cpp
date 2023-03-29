/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==NULL or head->next==NULL) return head;
        auto re_head = reverseList(head->next);
        auto rest_tail = head->next;
        rest_tail->next = head;
        head->next = NULL;
        return re_head;
    }
};