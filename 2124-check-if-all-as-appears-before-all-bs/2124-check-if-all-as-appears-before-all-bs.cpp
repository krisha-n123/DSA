class Solution {
public:
    bool checkString(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]=='b' && i+1<s.size() && s[i+1]=='a'){
                return false;
            }
        }
        return true;
    }
};