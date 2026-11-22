class Solution {
public:
    bool checkString(string s) {
        int bStartorNot=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                bStartorNot=1;
            }
            if(bStartorNot && s[i]=='a'){
                return false;
            }
        }
        return true;
    }
};