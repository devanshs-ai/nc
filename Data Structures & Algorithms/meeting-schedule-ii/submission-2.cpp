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
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        int rooms = 1;
        int endtime = 0;
        if(intervals.size()==0){
            return 0;
        }

        for(auto& it: intervals){
            if(!pq.empty()){
                if(pq.top()<=it.start){
                    pq.pop();
                }else{
                    rooms++;
                }
            }
            pq.push(it.end);
        }
        return rooms;
    }
};
