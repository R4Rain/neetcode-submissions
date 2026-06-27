class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (auto &stone: stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int stone1 = pq.top();
            pq.pop();

            int stone2 = pq.top();
            pq.pop();

            int remaining = stone1 - stone2;
            if (remaining > 0) {
                pq.push(remaining);
            }
        }

        if (pq.size() == 1) {
            return pq.top();
        } else {
            return 0;
        }
    }
};
