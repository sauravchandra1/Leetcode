class Solution {
public:
    
    // Time Complexity:- O(N^2LOG(N)) --> TLE (All passed but taken too long time)
    // Space Complexity:- O(N^2)
    
    // This function gives the minimum of length of two largest subarrays of +ve
    // starting on val, on both sides of val
    int get(vector<int>& v,int val){
        int end = lower_bound(v.begin(),v.end(),val) - v.begin();
        int start = upper_bound(v.begin(),v.end(),val) - v.begin() - 1;
        return min(v[end]-val-1,val-v[start]-1);
    }
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<int> rows[n],cols[n]; // stores the position of zeroes for every row and columns
        for(auto c:mines){
            rows[c[0]].push_back(c[1]);
            cols[c[1]].push_back(c[0]);
        }
        for(int i=0;i<n;i++){
            rows[i].push_back(-1); // push -1 , n to avoid checking corner cases
            rows[i].push_back(n);
            cols[i].push_back(-1);
            cols[i].push_back(n);
            sort(rows[i].begin(),rows[i].end()); // sort each rows and columns to perform binary search
            sort(cols[i].begin(),cols[i].end());
        }
        int ans = 0,r,c;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){ // maximise answer by considering every cell as the centre of plus sign
                r = get(rows[i],j);
                c = get(cols[j],i);
                ans = max(ans,1+min(r,c));
            }
        }
        return ans;
    }
};