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


    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
            return a.start < b.start;
        });
        int last = -1;
        for (auto &interval: intervals) {
            if (interval.start >= last) {
                last = interval.end;
            } else {
                return false;
            }
        }
        return true;
    }
};
