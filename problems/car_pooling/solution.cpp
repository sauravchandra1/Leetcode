class Solution {
    static bool cmp(vector < int > & v1, vector < int > & v2) {
        if (v1[1] < v2[1] || (v1[1] == v2[1] && v1[2] < v2[2]))
            return true;
        else return false;
    }
    public:
        bool carPooling(vector < vector < int >> & trips, int capacity) {
            sort(trips.begin(), trips.end(), cmp);
            int n = trips.size();
            priority_queue < pair < int, int > , vector < pair < int, int >> , greater < pair < int, int >> > heap;
            int count = trips[0][0];
            if (count > capacity)
                return false;
            heap.push({
                trips[0][2],
                trips[0][0]
            });
            for (int i = 1; i < n; i++) {
                while (!heap.empty() && heap.top().first <= trips[i][1]) {
                    count = count - heap.top().second;
                    heap.pop();
                }
                count += trips[i][0];
                if (count > capacity)
                    return false;
                heap.push({
                    trips[i][2],
                    trips[i][0]
                });
            }
            return true;
        }
};