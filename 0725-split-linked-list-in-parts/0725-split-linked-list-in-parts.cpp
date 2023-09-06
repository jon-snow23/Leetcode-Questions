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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k);
        ListNode* dummy=head;
       int n=0;
        while(dummy){
            n++;
            dummy=dummy->next;
        }
        if(n<=k){
            int i=0;
            while(head){
                ans[i]=head; head=head->next;
                ans[i]->next=NULL;
                i++;
            }  
        }
        else{
            int j=n%k , s=n/k , i=0;
            while(head){
                if(j>0){
                   int s=(n/k)+1; ans[i]=head;
                    while(--s){
                        head=head->next;
                    }
                    ListNode*cur=head; head=head->next;
                    cur->next=NULL;
                    j-- , i++;
                }
                else{
                    int s=(n/k);  ans[i]=head;
                    while(--s){
                        head=head->next;
                    }
                    ListNode*cur=head;
                    head=head->next;
                    cur->next=NULL;
                    i++;
                }
            }
        }
        return ans;
    }
}; 