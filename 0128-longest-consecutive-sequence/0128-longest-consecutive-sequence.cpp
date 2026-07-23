class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        if (nums.empty()) {
            return 0;
        }
        // Store all unique elements in a hash set for O(1) average lookup.
        unordered_set<int> st(nums.begin(), nums.end());

        // Only start counting if 'num' is the beginning of a sequence.
        // A sequence starts when (num - 1) does not exist in the set.
        for (int num : st) {
            if (!st.count(num - 1)) {
                int current = num;
                int length = 1;

                // Count the length of the consecutive sequence.
                while (st.count(current + 1)) {
                    current++;
                    length++;
                };
                // Update the maximum sequence length found so far.
                ans = max(ans, length);
            }
        }
        return ans;
    }
};