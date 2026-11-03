class Solution {
   public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        unordered_map<char, int> hm, hm2;
        for (char c : t) {
            hm[c]++;
        }
        int have = 0, l = 0;
        pair<int, int> pointers = {-1, -1};
        int resLen = INT_MAX;
        for (int r = 0; r < s.size(); r++) {
            char rc = s[r];
            hm2[rc]++;

            if (hm.count(rc) && hm[rc] == hm2[rc]) have++;

            while (have == hm.size()) {
                if (resLen > (r - l + 1)) {
                    resLen = r - l + 1;
                    pointers = {l, r};
                }
                char lc = s[l++];
                hm2[lc]--;
                if (hm.count(lc) && hm[lc] > hm2[lc]) have--;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(pointers.first, resLen);
    }
};
