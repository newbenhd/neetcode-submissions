class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxK = 0;
        for (int p : piles)
            maxK = p > maxK ? p : maxK;
        int left = 1, right = maxK;
        int out = maxK;
        while (left <= right)
        {
            int k = left + ((right - left) / 2);
            long long hours = 0;
            for (int p : piles)
                hours += ceil(double(p) / k);
            if (hours > h)
                left = k + 1;
            else {
                right = k - 1;
                out = k;
            }
        }
        return out;
    }
};
