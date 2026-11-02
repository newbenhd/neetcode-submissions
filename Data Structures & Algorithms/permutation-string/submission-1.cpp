class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> hm, hm2;
        int valid = 0, left = 0;
        for (char c : s1) hm[c]++;
        for (int i = 0; i < s2.size(); i++) {
            char c = s2[i];
            if (hm.find(c) == hm.end()) {
                hm2.clear();
                valid = 0;
                left = i + 1;
                continue;
            }
            if (hm2[c] == hm[c]) valid--;

            hm2[c]++;

            if (hm2[c] == hm[c]) valid++;

            while (hm2[c] > hm[c]) {
                char prevC = s2[left];
                if (hm2[prevC] == hm[prevC]) valid--;
                hm2[prevC]--;
                if (hm2[prevC] == hm[prevC]) valid++;
                left++;
            }
            if (valid == hm.size()) return true;
        }
        return false;
    }
};
