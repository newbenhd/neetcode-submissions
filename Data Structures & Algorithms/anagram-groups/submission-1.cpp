class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const auto s : strs)
        {
            vector<int> count = vector(26, 0);
            for (const auto c : s)
            {
                count[c - 'a']++;
            }
            string key = "";
            for (const auto c : count)
            {
                key += to_string(c); // use operator overloading on std::string + int doesn't work in cpp
                key += ',';
            }
            if (mp.find(key) != mp.end())
            {
                mp[key].push_back(s);
            }
            else
            {
                mp[key] = {s};
            }
        }
        vector<vector<string>> output;
        for (const auto &[key, value] : mp)
        {
            output.push_back(value);
        }
        return output;
    }
};
