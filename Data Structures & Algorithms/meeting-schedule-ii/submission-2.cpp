/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a.start < b.start;
        });
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0;i < intervals.size();i++) {
            if (pq.empty()) {
                pq.push(intervals[i].end);
            } else {
                int start = intervals[i].start;
                int end = intervals[i].end;

                if (start >= pq.top()) {
                    pq.pop();
                    pq.push(end);
                } else {
                    pq.push(end);
                }
            }
        }
        return pq.size();
    }
};
