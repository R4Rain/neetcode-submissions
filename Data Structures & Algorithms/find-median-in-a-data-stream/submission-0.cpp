class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        int size = max_heap.size() + min_heap.size();
        if (size == 0) return 0.0;

        if (size % 2 == 1) {
            return max_heap.top();
        } else {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
    }
};
