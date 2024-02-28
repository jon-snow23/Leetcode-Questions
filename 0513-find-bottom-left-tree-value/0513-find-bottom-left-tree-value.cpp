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
public:
    vector<int>v;
    int findBottomLeftValue(TreeNode* root) {
        if (root==NULL) return 0 ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int count = q.size();
            for(int i =0;i<count;i++) {
                TreeNode* curr = q.front(); q.pop() ;
                if (i==0) {
                    v.push_back(curr->val);
                }
                if (curr->left!=NULL) q.push(curr->left);
                if (curr->right!=NULL) q.push(curr->right);
            }
        }
        int n = v.size();
        return v[n-1];
    }
};