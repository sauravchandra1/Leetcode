class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() > nums2.size()) swap(nums1, nums2); 
    unordered_map<int,int> table;
    for(auto &x: nums1) table[x]++;
    nums1.clear();
    
    for(int i = 0; i != nums2.size() && !table.empty(); i++)
      if(table.count(nums2[i])){
        if(--table[nums2[i]] == 0) table.erase(nums2[i]);
        nums1.push_back(nums2[i]);
      }
    
    return nums1; 
  }
};