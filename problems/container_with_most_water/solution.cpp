class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = INT_MIN;
         int low = 0;
         int high = height.size() - 1;
         while (low < high) {
             max_water = max(max_water, min(height[low], height[high]) * (high - low));
             if (height[low] < height[high])
                 low++;
             else {
                 high--;
             }
         }
         return max_water;
    }
};