class Solution {
private:
    // Check if substring s[start...end] is palindrome
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    // Recursive helper with memoization to find min cuts from index 'start'
    int minCutsHelper(const string& s, int start, vector<int>& memo) {
        int n = (int)s.size();

        // If reached end or substring is palindrome, no cut needed
        if (start == n || isPalindrome(s, start, n - 1))
            return 0;

        // Return stored result if already computed
        if (memo[start] != -1)
            return memo[start];

        int minCuts = INT_MAX;

        // Try all possible partitions
        for (int end = start; end < n; end++) {
            if (isPalindrome(s, start, end)) {
                // 1 cut plus cuts for the remaining substring
                int cuts = 1 + minCutsHelper(s, end + 1, memo);
                minCuts = min(minCuts, cuts);
            }
        }

        // Store and return minimum cuts needed from this start
        return memo[start] = minCuts;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int> memo(n, -1);
        return minCutsHelper(s, 0, memo);
    }
};