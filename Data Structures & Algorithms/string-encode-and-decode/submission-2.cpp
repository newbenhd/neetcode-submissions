#define SEP '#'

class Solution {
public:

    string encode(vector<string>& strs) {
        string out = "";
        for (string str : strs) {
            int count = str.length();
            string countString = to_string(count);
            out += countString + SEP + str;
        }
        return out;
    }

    vector<string> decode(string s) {
        vector<string> out;
        string count = "";
        for (int i = 0; i < s.length();) {
            char c;
            while ((c = s[i]) >= 48 && c <= 57) {
                count += c;
                i++;
            }
            if (c == SEP) { // found string
                i++;
                int length = stoi(count);
                out.push_back(s.substr(i, length));
                i+= length;
                count = "";
            } else { // encoder mismatch
                break;
            }
        }
        return out;
    }
};
