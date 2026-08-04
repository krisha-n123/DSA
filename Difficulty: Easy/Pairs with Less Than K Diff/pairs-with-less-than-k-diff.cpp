class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
         int l=0,r=0;
         int ans=0;
        while(r<arr.size()){
         
            if(arr[r]-arr[l]<k){
                ans+=r-l;
                r++;
            }else{
                l++;
            }
        }
        return ans;
         
    }
};