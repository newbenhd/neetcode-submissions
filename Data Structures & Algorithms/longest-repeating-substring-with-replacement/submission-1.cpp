class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hm;
        int freq = 0, left = 0, out = 0;
        for (int right = 0; right < s.size(); right++)
        {
            hm[s[right]]++;
            freq = max(freq, hm[s[right]]);
            while (right - left + 1 - freq > k)
            {
                hm[s[left]]--;
                left++;
            }
            out = max(out, right - left + 1);
        }
        return out;
    }
};
