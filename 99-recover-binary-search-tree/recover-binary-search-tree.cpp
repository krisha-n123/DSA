/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<int>& arr, int& idx) {
        if (!root)
            return;

        solve(root->left, arr, idx);
        root->val = arr[idx++];
        solve(root->right, arr, idx);
    }
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    void recoverTree(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        sort(arr.begin(), arr.end());
        int idx=0;
        solve(root, arr, idx);
        
    }
};