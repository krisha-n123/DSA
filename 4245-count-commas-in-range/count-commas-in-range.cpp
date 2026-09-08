class Solution {
public:
    int countCommas(int n) {
        if(n<=999){
            return 0;
        }else {
            return abs(n-1000+1);
        }
    }
};