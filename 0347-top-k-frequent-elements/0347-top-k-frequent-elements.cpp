class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
       // Frquency count
        for (int num : nums) {
            freq[num]++;
        }
       // Pair of Priority queue
        priority_queue<pair<int, int>> qu;
        for (auto  &it : freq) {
            qu.push({it.second, it.first});
    
        }
        //pop the top frequent element 
        vector<int> ans;
        while (k--) {
            ans.push_back(qu.top().second);
            qu.pop();
        }
        return ans;
    }
};