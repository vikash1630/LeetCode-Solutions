class Solution {
private:
    int getSum(int num) {
        int sum = 0;
        while (num > 9) {
            int rem = num%10;
            num = num/10;
            sum += rem;
        }
        sum = sum + num;
        return sum;
    }
    
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        if (n == 0) return -1;
        for (int i = 0;i<n;i++) {
            int s = getSum(nums[i]);
            ans = min(s,ans);
        }
        return ans;
    }

};