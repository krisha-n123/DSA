class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        vector<vector<int>> ans;
        int level=0;
        for(int i=0 ; i<arr.size();i++){
            int size=pow(2,level);
            vector<int> temp;
            while(size-- && i<arr.size()){
                temp.push_back(arr[i]);
                i++;
            }
            i--;
            sort(temp.begin(),temp.end());
            level++;
            ans.push_back(temp);
        }
        return ans;
    }
};
