class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = 0;
        int n = cardPoints.size();
        int right = n - 1;
        int lsum = 0;
        int rsum = 0;
        while (left < k) {
            lsum += cardPoints[left];
            left++;
        }
        left--;
        int ans = lsum;
        while (left>=0) {
            lsum = lsum - cardPoints[left] + cardPoints[right];
            ans = max(ans,lsum);
            left--;
            right--;
        }
        return ans;
    }
};