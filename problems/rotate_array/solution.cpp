class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int rows = gcd(n, k);
        for(int i = 0; i < rows; i++) {
			//seperate into gcd(n,k) rows cases
            int temp = nums[i];
            int curr_idx = i;                
            for(int j = 0 ; j < n / rows; j++) {
				//Make a rorated move for each row by two temp
                int next_idx = (curr_idx + k) % n;
                int prev_temp = temp;
                temp = nums[next_idx];
                nums[next_idx] = prev_temp;
                curr_idx = next_idx;
            }
        }   
    }
};