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
    
    void helpher(TreeNode* root ,vector<int>&res) {
        if(root==NULL) {
            res.push_back(INT_MIN);
            return;
        }
        res.push_back(root->val); 
        helpher(root->left, res); 
        helpher(root->right, res);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> v1,v2;
        helpher(p, v1); 
        helpher(q , v2);
        
        return v1 == v2;
    }
};

