class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd =0 ;
        int sumEven =0;

        int i=1;
        for(int k=1;k<=n;k++){
            sumOdd+=i;
            i+=2;
        }
         i=2;
        for(int k=1;k<=n;k++){
            sumEven+=i;
            i+=2;
        }
        
        while(sumOdd!=sumEven){
            if(sumOdd>sumEven){
                sumOdd-=sumEven;
            }else if(sumOdd < sumEven){
                sumEven-=sumOdd;
            }
        }
        return sumOdd;
    }
};