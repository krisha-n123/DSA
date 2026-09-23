class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        }
        totalsum-=x;
        int currsum=0;
        int wid=-1;
        int l=0;

        for(int r=0;r<nums.size();r++){
            currsum+=nums[r];

            while(l<=r && currsum>totalsum){
                currsum-=nums[l];
                l+=1;

            }

            if(currsum==totalsum){
                wid=max(wid, r-l+1);

            }
            
        }



        return wid==-1?-1:nums.size()-wid;        
    }

};