class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size());
        unordered_map<int, int> mp;
        for (const int n : nums) mp[n]++;
        for (const auto& [key, value] : mp) buckets[value - 1].push_back(key);
        vector<int> out;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int n : buckets[i]) {
                out.push_back(n);
                if (out.size() == k)
                    return out;
            }
        }
        return out;
    }
};