class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out(nums.size(), 1); // size, value
        int prefix = 1;
        for (int i = 0; i < nums.size(); i++) {
            out[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            out[i] *= postfix;
            postfix *= nums[i];
        }
        return out;
    }
};
