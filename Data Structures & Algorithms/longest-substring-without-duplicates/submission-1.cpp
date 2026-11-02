class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hm;
        int out = 0, left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (hm.find(s[i]) != hm.end() && hm[s[i]] + 1 >= left)
                left = hm[s[i]] + 1;
            if (i - left + 1 > out)
                out = i - left + 1;
            hm[s[i]] = i;
        }
        return out;
    }
};
