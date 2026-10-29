class MinStack {
    vector<int> data;
    vector<int> prefix;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        data.push_back(val);
        int min = val;
        if (prefix.size() > 0 && prefix.back() < val)
            min = prefix.back();
        prefix.push_back(min);
    }
    
    void pop() {
        data.pop_back();
        prefix.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return prefix.back();
    }
};
