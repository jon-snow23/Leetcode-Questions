class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<ListNode*> nodes; 
        while (l1) {
            nodes.push_back(l1);
            l1 = l1->next;
        }
        while (l2) {
            nodes.push_back(l2);
            l2 = l2->next;
        }
        sort(nodes.begin(), nodes.end(), [](ListNode* a, ListNode* b) {
            return a->val < b->val;
        });
        ListNode dummy = ListNode(0);
        ListNode* current = &dummy;
        for (ListNode* node : nodes) {
            current->next = new ListNode(node->val);
            current = current->next;
        }
        return dummy.next;
    }
};
