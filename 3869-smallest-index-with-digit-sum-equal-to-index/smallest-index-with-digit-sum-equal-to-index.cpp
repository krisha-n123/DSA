class Solution {
public:
    int digitsum(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int mini=-1;
        for(int i=0;i<nums.size();i++){
            if(i==digitsum(nums[i])){
                return i;
            }
        }
        return -1;
    }
};