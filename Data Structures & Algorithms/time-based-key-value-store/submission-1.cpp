class TimeMap {
   public:
    TimeMap() {}
    void set(string key, string value, int timestamp) { store[key].push_back({value, timestamp}); }
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";
        const auto& values = store[key];
        int left = 0, right = values.size() - 1;
        int result = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (values[mid].second <= timestamp) {
                result = mid;
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return result == -1 ? "" : values[result].first;
    }

   private:
    unordered_map<string, vector<pair<string, int>>> store;
};
