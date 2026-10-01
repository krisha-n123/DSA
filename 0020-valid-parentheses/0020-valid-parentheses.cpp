class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);count++;
            }else{
                if(st.empty()) {
                    return false;
                }
                if(st.top()=='(' && s[i]!=')') return false;
                if(st.top()=='{' && s[i]!='}') return false;
                if(st.top()=='[' && s[i]!=']') return false;
                st.pop();
                count--;
                
            }

            

        }
        return count==0;
        
    }
};