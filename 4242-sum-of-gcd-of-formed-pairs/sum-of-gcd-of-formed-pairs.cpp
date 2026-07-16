class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi=INT_MIN;
        vector<int>prefixGcd(0);
        
        for(int val:nums){
            maxi=max(maxi,val);
            prefixGcd.push_back(gcd(val,maxi));
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long  sum=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            sum+=gcd(prefixGcd[i],prefixGcd[j]);
            i++;j--;
        }
        return sum;
        
        
    }
};