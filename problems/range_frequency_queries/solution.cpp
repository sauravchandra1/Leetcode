class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mp;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
    }
   
    int query(int left, int right, int val) {
        if (mp.count(val) == 0) return 0;
        int l = lower_bound(mp[val].begin(), mp[val].end(), left) - mp[val].begin();
        int r = upper_bound(mp[val].begin(), mp[val].end(), right) - mp[val].begin(); 
        return r - l;
    }
};