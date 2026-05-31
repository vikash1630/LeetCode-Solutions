class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int wt = mass;
        for (int i = 0;i<asteroids.size();i++) {
            if (wt >= asteroids[asteroids.size() - 1]) return true;
            if (wt >= asteroids[i]) {
                wt += asteroids[i];
            }
            else return false;
        }
        return true;
    }
};