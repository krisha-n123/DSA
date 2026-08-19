class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<pair<int, int>, int> mp;
        set<int> rows;


        int u, v;

        for ( int i = 0; i < reservedSeats.size(); i++ ){
            u = reservedSeats[i][0];
            v = reservedSeats[i][1];

            mp[{u,v}]++;

            rows.insert(u);
        }

        int cnt = ( n - rows.size()) * 2;

        for ( int i : rows ){

            if ( (mp[{i,2}] ==0 ) && (mp[{i,3}] ==0 ) && (mp[{i,4}] ==0 ) && (mp[{i,5}] ==0 ) ){
                cnt++;
                mp[{i,2}]++;
                mp[{i,3}]++;
                mp[{i,4}]++;
                mp[{i,5}]++;
            }
            if ( (mp[{i,4}] ==0 ) && (mp[{i,5}] ==0 ) && (mp[{i,6}] ==0 ) && (mp[{i,7}] ==0 ) ){
                cnt++;
                mp[{i,4}]++;
                mp[{i,5}]++;
                mp[{i,6}]++;
                mp[{i,7}]++;
            }
            if ( (mp[{i,6}] ==0 ) && (mp[{i,7}] ==0 ) && (mp[{i,8}] ==0 ) && (mp[{i,9}] ==0 ) ){
                cnt++;
                mp[{i,6}]++;
                mp[{i,7}]++;
                mp[{i,8}]++;
                mp[{i,9}]++;
            }

            
        }
        return cnt;
    }
};