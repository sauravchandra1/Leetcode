class Solution {
public:
    
bool compare(vector<int>& nums1, vector<int>& nums2, int start_i, int start_j)
{
	int loop_size = min(nums1.size() - start_i, nums2.size() - start_j);

	for (int i = 0; i < loop_size; i++)
	{
		if (nums1[i + start_i] < nums2[i + start_j])
			return true;
		else if (nums1[i + start_i] > nums2[i + start_j])
			return false;
	}
	return nums1.size() - start_i < nums2.size() - start_j;
}

vector<vector<int>> largetsNum(vector<int>& nums)
{
	vector<vector<int>> res;
	res.resize(nums.size() + 1);
	res.back() = nums;

	for (int i = res.size() - 2; i >= 0; i--)
	{	
		int idx = 0;
		while (idx + 1 < res[i + 1].size())
		{
			if (res[i + 1][idx] < res[i + 1][idx + 1])
				break;
			idx++;
		}

		for (int j = 0; j < res[i + 1].size(); j++)
		{
			if (idx != j)
				res[i].push_back(res[i + 1][j]);
		}
	}
	return res;
}

vector<int> merge(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> res;
	int i = 0, j = 0;
	while (i < nums1.size() || j < nums2.size())
	{
			if (compare(nums1, nums2, i, j))
				res.push_back(nums2[j++]);
			else
				res.push_back(nums1[i++]);
	}
	return res;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, size_t k) 
{
	vector<vector<int>> largest_num1 = largetsNum(nums1);
	vector<vector<int>> largest_num2 = largetsNum(nums2);

	vector<int> res;

	int start = k > nums2.size() ? k - nums2.size() : 0;

	for (int i = start; i < largest_num1.size() && i <= k; i++)
	{
		vector<int> tmp = merge(largest_num1[i], largest_num2[k - i]);
		if (res.empty() || compare(res, tmp, 0, 0))
			res = tmp;
	}

	return res;
}
};