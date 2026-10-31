class Solution {
public:
    /*
    [0,1,2,3,4,5,6,7,8,9,10]
    [  1     4     7     10]
    [        4   6   8   10]
    */
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> points;
        for (int i = 0; i < position.size(); i++)
        {
            points.push_back({position[i], speed[i]});
        }
        sort(points.begin(), points.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return !(a.first < b.first); });
        vector<float> fleets;
        for (auto &point : points)
        {
            float time = ((target - point.first) / (1.0 * point.second));
            if (fleets.empty())
                fleets.push_back(time);
            else if (fleets.back() < time)
            {
                fleets.push_back(time);
            }
        }
        return fleets.size();
    }
};
