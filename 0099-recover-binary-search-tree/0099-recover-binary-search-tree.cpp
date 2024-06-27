/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode *l1, *l1_next, *l2, *pre;
public:
    void s(TreeNode* root){
        if(!root) return;
        s(root->left);
        if(root->val < pre->val){
            if(!l1){
                l1 = pre;
                l1_next = root; 
            }
            else{
                l2 = root;
            }
        }
        pre = root;
        s(root->right);
    }
    void recoverTree(TreeNode* root) {
        l1 = l2 = l1_next = NULL;
        pre = new TreeNode(-pow(2,31));
        s(root);
        if(l1 && l2) swap(l1->val, l2->val);
        else swap(l1->val, l1_next->val);
    }
};