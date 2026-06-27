class KthLargest {
public:
    int _K;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    KthLargest(int k, vector<int>& nums) {
        for (auto &num : nums) {
            min_heap.push(num);
        }
        while (min_heap.size() > k) {
            min_heap.pop();
        }
        _K = k;
    }
    
    int add(int val) {
        min_heap.push(val);
        while (min_heap.size() > _K) {
            min_heap.pop();
        }
        return min_heap.top();
    }
};
