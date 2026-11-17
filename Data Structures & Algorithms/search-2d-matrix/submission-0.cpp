class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size() - 1;
        int boxSize = matrix[0].size();
        int partition = -1;
        while (left <= right)
        {
            int mid = left + ((right - left)/2);
            if (matrix[mid][0] <= target && matrix[mid][boxSize - 1] >= target)
            {
                partition = mid;
                break;
            } else if (matrix[mid][0] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (partition == -1)
            return false;
        vector<int> partitionBox = matrix[partition];
        left = 0, right = partitionBox.size() - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (partitionBox[mid] < target)
                left = mid + 1;
            else if (partitionBox[mid] > target)
                right = mid - 1;
            else
                return true;
        }
        return false;
    }
};
