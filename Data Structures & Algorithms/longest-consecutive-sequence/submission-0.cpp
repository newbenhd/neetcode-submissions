class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int out = 0;
        for (int n : nums)
            set.insert(n);
        for (int key : set)
        {
            if (set.find(key - 1) != set.end())
                continue;
            int current = 1;
            while (set.find(key + 1) != set.end())
            {
                current++;
                key++;
            }
            if (current > out)
                out = current;
        }
        return out;
    }
};
