class Solution {
public:
    int sum(TreeNode* root, int& count){
        if(!root){
            return 0;
        }
        count++;
        return root->val+sum(root->left, count)+sum(root->right , count);

    }
    void avgval(TreeNode* root, int& cnt){
        if(!root) return;
        int count=0;
        int avg=(sum(root, count))/count;
        if(root->val==avg) cnt++;
        avgval(root->left, cnt);
        avgval(root->right, cnt);


    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        avgval(root, ans);
        return ans;
    }
};