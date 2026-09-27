class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == ')') {
                vector<char> v;
                while (st.top() != '(') {
                    v.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for (int i = 0; i < v.size(); i++) {
                    st.push(v[i]);
                }
            } else {
                st.push(ch);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};