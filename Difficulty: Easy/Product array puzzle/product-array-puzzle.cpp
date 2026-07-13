class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        vector<int> ans(arr.size(),1);
        int pre=1;
        for(int i=0;i<arr.size();i++){
            ans[i]=pre;
            pre*=arr[i];
        }
        int post=1;
        for(int i=arr.size()-1;i>=0;i--){
            ans[i]*=post;
            post*=arr[i];
        }
        return ans;
    }
};
