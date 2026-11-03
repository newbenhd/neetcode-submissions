class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        vector<int> freqS1(26, 0), freqS2(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            freqS1[s1[i] - 'a']++;
            freqS2[s2[i] - 'a']++;
        }
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (freqS1[i] == freqS2[i]) matches++;
        }
        for (int left = 0, right = s1.size(); right < s2.size(); right++, left++) {
            if (matches == 26) return true;
            int index = s2[right] - 'a';
            freqS2[index]++;
            if (freqS1[index] == freqS2[index])
                matches++;
            else if (freqS1[index] + 1 == freqS2[index])
                matches--;
            int leftIndex = s2[left] - 'a';
            freqS2[leftIndex]--;
            if (freqS1[leftIndex] == freqS2[leftIndex])
                matches++;
            else if (freqS1[leftIndex] - 1 == freqS2[leftIndex])
                matches--;
        }
        return matches == 26;
    }
};
