class Solution {
public:
    bool checkDivisibility(int n) {
        int digitsum=0;
        int digitproduct=1;
        int temp=n;
        while(temp>0){
            int rem=temp%10;
            digitsum+=rem;
            digitproduct*=rem;
            temp/=10;
        }

        return n%(digitsum+digitproduct)==0;
    }
};