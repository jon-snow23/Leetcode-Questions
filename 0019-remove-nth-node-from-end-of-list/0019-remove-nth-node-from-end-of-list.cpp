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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       auto first = head;
        for(int i =1 ; i<= n ;i++) {
            first = first->next;
        }
        auto second = head;
        if (!first) return head->next;
        while(first->next) second=second->next, first = first->next;
        second->next=second->next->next;
        return head;
    }
};