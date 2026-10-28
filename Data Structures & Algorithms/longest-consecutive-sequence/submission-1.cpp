class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int out = 0;
        for (int key : set)
        {
            if (set.find(key - 1) == set.end())
            {
                int current = 1;
                while (set.find(key + current) != set.end())
                    current++;
                if (current > out)
                    out = current;
            }
        }
        return out;
    }
};
