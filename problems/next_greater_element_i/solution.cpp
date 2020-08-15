class Solution {
public:
     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums2.size(); ++i) {
            m.insert(make_pair(nums2[i], i));
        }
        for (int i = 0; i < nums1.size(); ++i) {
            const int iVal = nums1[i];
            unordered_map<int, int>::const_iterator it = m.find(iVal);
            if (it == m.cend()) {
                nums1[i] = -1;
            } else {
                bool found = false;
                const int nums2Idx = it->second;
                for (int j = nums2Idx + 1; j < nums2.size(); ++j) {
                    const int jVal = nums2[j];
                    if (jVal > iVal) {
                        nums1[i] = jVal;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    nums1[i] = -1;
                }
            }
        }
        return nums1;
    }
};