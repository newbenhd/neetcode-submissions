class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hm;
        vector<unordered_set<char>> buckets(s.size() + 1);
        int freq = 0, left = 0, out = 0;
        for (int right = 0; right < s.size(); right++)
        {
            hm[s[right]]++;
            int rightCharFreq = hm[s[right]];
            buckets[rightCharFreq - 1].erase(s[right]);
            buckets[rightCharFreq].insert(s[right]);
            if (rightCharFreq > freq)
                freq = rightCharFreq;
            while (right - left + 1 - k > freq)
            {
                hm[s[left]]--;
                int leftCharFreq = hm[s[left]];
                buckets[leftCharFreq + 1].erase(s[left]);
                buckets[leftCharFreq].insert(s[left]);
                left++;
                while (freq > 0 && buckets[freq].empty())
                    freq--;
            }
            out = max(out, right - left + 1);
        }
        return out;
    }
};
