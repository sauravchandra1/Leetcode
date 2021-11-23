class Solution {
public:
    struct DSU {
        vector<int> e;
        DSU(int N) { e = vector<int>(N, -1); }
            int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
            bool same_set(int a, int b) { return get(a) == get(b); }
            int size(int x) { return -e[get(x)]; }
            bool unite(int x, int y) { 
                x = get(x), y = get(y);
                if (x == y) return false;
                if (e[x] > e[y]) swap(x, y);
                e[x] += e[y]; e[y] = x;
                return true;
            }
        };

        int largestComponentSize(vector<int>& nums) {
            DSU dsu(*max_element(nums.begin(), nums.end()) + 1); //create DSU struct with nodes 0, 1, 2, ... max element of the vector
            for(auto i: nums){
                for(int j = 2;j*j<=i;j++){ //factorize each number
                    if(i%j == 0){
                        dsu.unite(j, i);
                        dsu.unite(i/j, i);
                    }
                }
            }
            int ans = 1;
            unordered_map<int, int> freq;
            for(auto i: nums){
                int p = dsu.get(i); //get parent
                freq[p]++;
                ans = max(ans, freq[p]);
            }
            return ans;
        }
    // int largestComponentSize(vector<int>& nums) {
    //     const int N = 1e5 + 5;
    //     vector<unordered_set<int>> g(N);
    //     vector<bool> oc(N, false);
    //     int len = nums.size();
    //     for (int i = 0; i < len; i++) {
    //         int n = nums[i];
    //         vector<int> t;
    //         if (n % 2 == 0) {
    //             t.push_back(2);
    //             while (n % 2 == 0) n /= 2;
    //         }
    //         for (int j = 3; j <= sqrt(n); j++) {
    //             if (n % j == 0) {
    //                 t.push_back(j);
    //                 while (n % j == 0) n /= j;
    //             }
    //         }
    //         if (n > 2) t.push_back(n);
    //         for (int l = 0; l < t.size(); l++) {
    //             oc[t[l]] = true;
    //             for (int m = l + 1; m < t.size(); m++) {
    //                 g[t[l]].insert(t[m]);
    //                 g[t[m]].insert(t[l]);
    //             }
    //         }
    //     }
    //     unordered_set<int> se;
    //     for (auto& v : nums) se.insert(v);
    //     vector<bool> visited(N, false);
    //     function<int(int)> dfs = [&](int source) {
    //         if (visited[source]) return 0;
    //         int c = 0;
    //         visited[source] = true;
    //         for(auto it = se.begin(); it != se.end();) {
    //             int val = *it;
    //             if (val % source == 0) {
    //                 c++;
    //                 auto temp = it;
    //                 it++;
    //                 se.erase(temp);
    //             } else it++;
    //         }
    //         for (auto& node : g[source]) 
    //             if (!visited[node]) c += dfs(node);
    //         return c;
    //     };
    //     int ans = 0;
    //     for (int i = 2; i < N; i++) 
    //         if (oc[i])
    //             ans = max(ans, dfs(i));
    //     return ans;
    // }
};