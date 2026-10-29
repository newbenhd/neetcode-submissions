class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> stack;
        vector<int> out(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
                while (!stack.empty() && temperatures[stack.back()] < temperatures[i]) {
                    int prevDay = stack.back();
                    out[prevDay] = i - prevDay;
                    stack.pop_back();
                }
                stack.push_back(i);
        }
        return out;
    }
};
