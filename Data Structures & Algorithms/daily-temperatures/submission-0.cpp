class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int, int>> stack;
        vector<int> out(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            if (stack.empty()) {
                stack.push_back({temperatures[i], i});
            } else {
                pair<int, int> prev;
                while (!stack.empty() && (prev = stack.back()).first < temperatures[i]) {
                    out[prev.second] = i - prev.second;
                    stack.pop_back();
                }
                stack.push_back({temperatures[i], i});
            }
        }
        return out;
    }
};
