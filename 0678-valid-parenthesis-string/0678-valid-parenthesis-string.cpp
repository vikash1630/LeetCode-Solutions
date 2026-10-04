class Solution {
  public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else { // '*'
                // '*' can be ')' -> low--
                // '*' can be empty -> low stays
                // '*' can be '(' -> high++
                low--;
                high++;
            }

            // Even the maximum possible opens became negative
            if (high < 0) {
                return false;
            }

            // Minimum cannot be negative
            low = max(0, low);
        }

        // We need one possible balance of exactly 0
        return low == 0;
    }
};