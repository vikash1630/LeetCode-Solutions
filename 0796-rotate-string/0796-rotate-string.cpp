class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string doubledS = s + s;
        int ind = doubledS.find(goal);
        if (ind >= 0) return true;
        return  false;

    }
};