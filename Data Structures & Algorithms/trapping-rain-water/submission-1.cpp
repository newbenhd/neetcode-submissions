class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int waters = 0;
        int maxL = height[l], maxR = height[r];
        while (l < r)
        {
           if (maxL < maxR) {
                l++;
                maxL = max(maxL, height[l]);
                waters += maxL - height[l];
           } else {
                r--;
                maxR = max(maxR, height[r]);
                waters += maxR - height[r];
           }
        }
        return waters;
    }
};
