class Solution {
  unordered_map < int, int > paths;
  public:
    int lengthLongestPath(string input) {
      paths[-1] = 0; 
      int pos = 0;
      int max_len = 0;
      while (pos < input.size()) {
        int t_count = 0;
        while (input[pos] == '\t') {
          t_count++;
          pos++;
        }
        int new_line_pos = input.find_first_of('\n', pos);
        if (new_line_pos == string::npos) {
          new_line_pos = input.size();
        }
        string name = input.substr(pos, new_line_pos - pos);
        if (name.find_first_of('.') == string::npos) 
        {
          paths[t_count] = paths[t_count - 1] + name.size() + 1; 
        } else {
          int file_path_len = paths[t_count - 1] + name.size();
          max_len = max(max_len, file_path_len);
        }
        pos = new_line_pos + 1; 
      } 
      return max_len;
    } 
};