class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int out = 0;
        while (l < r)
        {
            int area = (r - l) * min(heights[l], heights[r]);
            if (area > out)
                out = area;
            if (heights[l] <= heights[r])
                l++;
            else
                r--;
        }
        return out;
    }
};
