class Solution {
    public:
        vector < int > findOrder(int numCourses, vector < vector < int >> & prerequisites) {
            unordered_map < int, vector < int >> neighbors;
            unordered_map < int, int > inDegrees;
            queue < int > q;
            vector < int > result;
            for (auto & edge: prerequisites) {
                inDegrees[edge[0]]++;
                neighbors[edge[1]].push_back(edge[0]);
            }
            for (int i = 0; i < numCourses; i++)
                if (!inDegrees.count(i))
                    q.push(i);
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                result.push_back(cur);
                for (auto neighbor: neighbors[cur])
                    if (--inDegrees[neighbor] == 0)
                        q.push(neighbor);
            }

            return result.size() == numCourses ? result : vector < int > ();
        }
};