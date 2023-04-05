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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string current_path;
        dfs(root, current_path, paths);
        return paths;
    }
    
    void dfs(TreeNode* node, string current_path, vector<string>& paths) {
        if (!node) {
            return;
        }
        
        // Append the current node's value to the current path.
        current_path += to_string(node->val);
        
        // If the current node is a leaf, add the current path to the result vector.
        if (!node->left && !node->right) {
            paths.push_back(current_path);
            return;
        }
        
        // If the current node has a left child, recursively traverse the left subtree.
        if (node->left) {
            dfs(node->left, current_path + "->", paths);
        }
        
        // If the current node has a right child, recursively traverse the right subtree.
        if (node->right) {
            dfs(node->right, current_path + "->", paths);
        }
    }
};