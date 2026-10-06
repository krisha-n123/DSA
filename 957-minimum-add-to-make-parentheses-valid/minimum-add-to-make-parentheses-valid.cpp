class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }else{
                if(!st.empty()){
                    st.pop();
                }else{
                    ans+=s[i];
                }
            }
        }
        return st.size()+ans.length();
    }
};