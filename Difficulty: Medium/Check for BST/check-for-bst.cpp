/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<int> & ans){
        if(root==NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    bool isBST(Node* root) {
        // code here
        vector<int> ans;
        inorder(root,ans);
        for(int i=0;i<ans.size();i++){
            if(i> 0 && !(ans[i-1]<ans[i])){
                return false;
            }
        }
        return true;
    }
};