class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end()); // sort by start time
        
        vector<vector<int>> ans;
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= end) {
                // overlap => extend interval
                end = max(end, intervals[i][1]);
            } else {
                // no overlap => push previous
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        // push last interval
        ans.push_back({start, end});
        
        return ans;
    }
};