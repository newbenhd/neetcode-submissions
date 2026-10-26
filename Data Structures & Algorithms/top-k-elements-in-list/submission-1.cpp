class PriorityQueue
{
public:
    PriorityQueue(std::vector<std::pair<int, int>> &input);
    void enqueue(int key, int value);
    std::pair<std::pair<int, int>, int> dequeue();

private:
    int length;
    std::vector<std::pair<int, int>> data;
    void heapify(int i, int last);
    int left(int i);
    int right(int i);
    int parent(int i);
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /* 
        1. Create a priority queue and hashmap and vector of int
        2. Iterate the nums
        2.a. Increment the value of hashmap by 1 at the key of the current iteration number.
        3. Iterate the hashmap
        3.a. On each key-value, insert the key into the pq (log n) where weight is the value
        4. Insert k number of popped key from pq into the vector of int
        5. Return the vector
        */
       unordered_map<int, int> mp;
       for (int num : nums) {
        mp[num]++;
       }
       vector<pair<int, int>> appearance;
       for (auto &[key, value] : mp) {
        appearance.push_back(pair<int, int>(key, value));
       }
       PriorityQueue pq(appearance);
       vector<int> out;
       for (; k > 0; k--) {
        pair<pair<int, int>, int> d = pq.dequeue();
        if (d.second == 0) {
            out.push_back(d.first.first);
        }
       }
       return out;
    }
};




PriorityQueue::PriorityQueue(std::vector<std::pair<int, int>> &input)
{
    data = input;
    length = input.size();
    for (int i = length / 2 - 1; i >= 0; i--)
    {
        heapify(i, length);
    }
}

void PriorityQueue::enqueue(int key, int value)
{
}
std::pair<std::pair<int, int>, int> PriorityQueue::dequeue()
{ // data, success
    if (length < 1)
        return {{0,0}, 1};
    auto out = data[0];
    data[0] = data[length - 1];
    length--;
    if (length > 0)
        heapify(0, length);
    return {out, 0};
}
void PriorityQueue::heapify(int i, int last)
{
    while (i < last)
    {
        int l = left(i);
        int r = right(i);
        int child = l;
        if (l >= last) // there is no child
            break;
        if (r < last && data[l].second < data[r].second)
            child = r;
        if (data[child].second <= data[i].second) // heap rule satifies at index i
            break;
        if (data[child].second > data[i].second)
        {
            std::pair<int, int> temp = data[i];
            data[i] = data[child];
            data[child] = temp;
            i = child;
        }
    }
}
int PriorityQueue::left(int i) { return i * 2 + 1; }
int PriorityQueue::right(int i) { return i * 2 + 2; }
int PriorityQueue::parent(int i) { return (i - 1) / 2; /* floor down to int */ }