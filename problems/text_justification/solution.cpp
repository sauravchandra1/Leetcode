class Solution {
public:
      string cejustify(vector < string > & words, int space) {
      int idx = 0;
      int te = words.size();
      if (te == 1) {
          while (space) {
              words[0].push_back(' ');
              space--;
          }
      } else {
          while (space) {
              words[idx].push_back(' ');
              space--;
              idx++;
              idx = idx % (te - 1);
          }
      }
      stringstream ss;
      for (string & word: words) {
          ss << word;
      }
      return ss.str();
  }

  string lejustify(vector < string > & words, int maxWidth) {
      stringstream ss;
      for (string & wrd: words) {
          ss << wrd;
          ss << " ";
      }
      string str = ss.str();
      str.resize(maxWidth, ' ');
      return str;
  }
  vector < string > fullJustify(vector < string > & words, int maxWidth) {
      int charCnt = 0;
      vector < string > out;
      vector < string > wrds;
      for (string & word: words) {
          if (wrds.size() + charCnt + word.size() > maxWidth) {
              out.push_back(cejustify(wrds, maxWidth - charCnt));
              charCnt = 0;
              wrds.clear();
          }
          charCnt += word.size();
          wrds.push_back(word);
      }
      out.push_back(lejustify(wrds, maxWidth));
      return out;
  }
};