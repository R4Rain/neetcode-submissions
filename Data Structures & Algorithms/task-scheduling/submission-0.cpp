class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char t : tasks) freq[t]++;

        priority_queue<int> pq;
        for (auto& [_, count] : freq) {
            pq.push(count);
        }

        queue<pair<int, int>> cooldown; 
        // {remaining_count, available_time}

        int time = 0;

        while (!pq.empty() || !cooldown.empty()) {
            time++;

            if (!pq.empty()) {
                int count = pq.top();
                pq.pop();

                count--; // execute task

                if (count > 0) {
                    cooldown.push({count, time + n});
                }
            }

            // check if any task is ready to come back
            if (!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};