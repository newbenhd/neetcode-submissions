#include <unordered_set>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums) { // range access
            if (s.find(n) != s.end()) {
                return true;
            }
            s.insert(n);
        }
        return false;
    }
};