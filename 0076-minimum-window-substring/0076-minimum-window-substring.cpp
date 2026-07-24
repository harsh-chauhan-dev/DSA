class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (int c : t) {
            need[c]++;
        }
        int required = need.size();
        int formed = 0;
        int left = 0;
        int minLen = INT_MAX;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {

            char c = s[i];
            window[c]++;

            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }
            while (formed == required) {
                if (i - left + 1 < minLen) {
                    minLen = i - left + 1;
                    start = left;
                }
                char ch = s[left];
                window[ch]--;
                if (need.count(ch) && window[ch] < need[ch])
                    formed--;

                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};