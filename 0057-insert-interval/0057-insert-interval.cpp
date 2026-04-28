class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;

        // Left
        while (i<n && intervals[i][1] < newInterval[0]) {
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }

        // Overlapping Part
        while (i<n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
        ans.push_back({newInterval[0],newInterval[1]});
        
        // Right
        while(i<n) {
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }

        return ans;


    }
};