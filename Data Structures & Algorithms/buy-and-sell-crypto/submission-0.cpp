class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int out = 0, lowest = prices[0];
        for (int p : prices)
        {
            int currProfit = p - lowest;
            if (currProfit > out)
                out = currProfit;
            if (p < lowest)
                lowest = p;
        }
        return out;
    }
};
