class Solution {
public:
    bool isPalindrome(string s) {
        auto l = s.begin();
        auto r = s.end() - 1;
        while (l <= r)
        {
            if (*l >= 'A' && *l <= 'Z')
                *l += 32;
            if (*r >= 'A' && *r <= 'Z')
                *r += 32;
            if ((*l >= 'a' && *l <= 'z' && *r >= 'a' && *r <= 'z') || (*l >= '0' && *l <= '9' && *r >= '0' && *r <= '9'))
            {
                if (*l != *r)
                    return false;
                l++;
                r--;
            }
            else if ((*l >= 'a' && *l <= 'z' && *r >= '0' && *r <= '9') || (*l >= '0' && *l <= '9' && *r >= 'a' && *r <= 'z'))
                return false;
            else if ((*l >= 'a' && *l <= 'z') || (*l >= '0' && *l <= '9'))
                r--;
            else if ((*r >= 'a' && *r <= 'z') || (*r >= '0' && *r <= '9'))
                l++;
            else {
                l++;
                r--;
            }
        }
        return true;
    }
};
