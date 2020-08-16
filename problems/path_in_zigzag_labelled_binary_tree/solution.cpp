class Solution {
public:
      vector < int > pathInZigZagTree(int label) {
      vector < int > ans;
      while (label) {
          ans.push_back(label);
          label /= 2;
      }
      bool tmp = ans.size() % 2;
      reverse(ans.begin(), ans.end());
      for (int i = tmp; i < ans.size(); i += 2) {
          ans[i] = pow(2, i + 1) - ans[i] + pow(2, i) - 1;
      }
      return ans;
  }
};