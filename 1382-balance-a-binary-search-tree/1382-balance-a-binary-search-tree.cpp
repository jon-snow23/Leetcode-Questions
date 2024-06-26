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
    void inorder(TreeNode* root, vector<int>&temp){
        if(root==NULL) return;
        inorder(root->left,temp);
        temp.push_back(root->val);
        inorder(root->right,temp);
    }
    
    TreeNode* createBST(vector<int> &temp, int s, int e){
        if(s>e) return NULL;

        int mid = (s+e)/2;
        TreeNode* ut = new TreeNode(temp[mid]);
        ut->left = createBST(temp,s,mid-1);
        ut->right = createBST(temp,mid+1,e);
        return ut;
    }


    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL) return root;
        vector<int> temp;
        inorder(root,temp);
        return createBST(temp,0,temp.size()-1);

    }
};