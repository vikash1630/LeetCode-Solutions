class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = height[0];
        int rightMax = height[n - 1];
        int i = 1;
        int j = n - 2;
        int ans = 0;
        while (i <= j) {
            if (leftMax < rightMax) {
                int a = min(leftMax, rightMax) - height[i];
                ans += max(a, 0);
                leftMax = max(leftMax, height[i]);
                i++;
            }
            else {
                int a = min(leftMax, rightMax) - height[j];
                ans += max(a, 0);
                rightMax = max(rightMax, height[j]);
                j--;
            }
        }
        return ans;
    }
};