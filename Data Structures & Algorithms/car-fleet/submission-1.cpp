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
        sort(points.rbegin(), points.rend());
        vector<double> fleets;
        for (auto &point : points)
        {
            double time = ((double)(target - point.first) / point.second);
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
