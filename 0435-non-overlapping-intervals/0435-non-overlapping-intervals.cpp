class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a,const vector<int>& b) {
                return a[1] < b[1];
        });

        int next = intervals[0][1];
        int cnt = 0;
        for (int i = 1;i<n;i++) {
            if (intervals[i][0] < next) {
                cnt++;
                continue;
            }
            next = intervals[i][1];
        }
        return cnt;
    }
};