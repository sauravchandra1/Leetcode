class Solution {
    public String minWindow(String s, String t) {
        if (s == null || t == null) {
            return "";
        }
        
        int[] need = new int[128];
        int[] window = new int[128];
        int cnt = 0;
        for (char c : t.toCharArray()) {
            if (need[c] == 0) {
                cnt++;
            }
            need[c]++;
        }
        
        int left = 0, right = 0, meet = 0, start = 0, len = Integer.MAX_VALUE;
        
        while (right < s.length()) {
            char c = s.charAt(right++);
            
            if (need[c] != 0) {
                window[c]++;
                if (window[c] == need[c]) {
                    meet++;
                }
            }
            
            while (meet == cnt) {
                if (right - left < len) {
                    len = right - left;
                    start = left;
                }
                
                char d = s.charAt(left++);
                if (need[d] != 0) {
                    if (need[d] == window[d]){
                        meet--;
                    }
                    window[d]--;
                }
            }
        }
        
        return len == Integer.MAX_VALUE ? "" : s.substring(start, start + len);
    }
}