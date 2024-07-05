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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result = {-1, -1};
        int dis = INT_MAX;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int ind = 1;
        int prevInd = 0;
        int f = 0;

        while (curr->next != nullptr) {
            if ((curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val)) {
                if (prevInd == 0) {
                    prevInd = ind;
                    f = ind;
                } else {
                    dis =
                        min(dis, ind - prevInd);
                    prevInd = ind;
                }
            }
            ind++;
            prev = curr;
            curr = curr->next;
        }
        if (dis != INT_MAX) {
            int maxidis = prevInd - f;
            result = {dis, maxidis};
        }

        return result;
    }
};