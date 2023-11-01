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
private:
    unordered_map<int, int> mp;
    void helper(TreeNode* node) {
        if(!node) {
            return;
        }
        mp[node->val]++;
        helper(node->left);
        helper(node->right);
    } 
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        helper(root);
        int mx=0;
        for(auto a : mp) {
            mx=max(mx, a.second);
        }
        for(auto a : mp) {
            if(a.second==mx) {
                ans.push_back(a.first);
            }
        }
        return ans;
    }
};