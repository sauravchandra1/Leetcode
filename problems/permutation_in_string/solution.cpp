class Solution {
public:
    bool isMatch(map < char, int > map1, map < char, int > map2) {

        for (auto ele: map1) {
            char ch = ele.first;
            if (map1[ch] > map2[ch])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {

        // O(n) time | O(m) space 
        // n : size of s2
        // m : number of different charater is used in input array
        if (s1.size() > s2.size()) return false;
        int left = 0;
        int right = s1.size() - 1;

        map < char, int > map1, map2;
        for (auto ch: s1)
            map1[ch]++;
        for (int i = left; i < right; i++) {
            map2[s2[i]]++;
        }

        while (right < s2.size()) {
            map2[s2[right]]++;
            if (isMatch(map1, map2))
                return true;
            map2[s2[left]]--;
            left++;
            right++;
        }
        return false;
    }
};