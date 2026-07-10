class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        int n = path.size();
        int i = 0;
        while (i < n) {
            while (i < n && path[i] == '/') {
                ++i;
            }
            if (i >= n) break;
            int start = i;
            while (i < n && path[i] != '/') {
                ++i;
            }
            string token = path.substr(start, i - start);
            if (token == ".") {
                continue;
            } else if (token == "..") {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(token);
            }
        }
        string result;
        for (const auto& dir : stack) {
            result += "/" + dir;
        }
        return result.empty() ? "/" : result;

    }
};