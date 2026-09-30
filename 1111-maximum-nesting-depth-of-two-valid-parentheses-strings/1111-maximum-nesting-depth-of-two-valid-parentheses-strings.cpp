class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> v;
        int depth = 0;

        for(int i = 0; i < seq.size(); i++){
            if(seq[i] == '('){
                depth++;
                v.push_back(depth % 2);
            }
            else{
                v.push_back(depth % 2);
                depth--;
            }
        }
        return v;
    }
};