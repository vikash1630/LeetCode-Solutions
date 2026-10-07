class Solution {
public:
    bool isValid(string s) {
        int cnt = 0;

        for(char ch : s) {
            if(ch == '(') cnt++;
            else if(ch == ')') {
                cnt--;
                if(cnt < 0) return false;
            }
        }

        return cnt == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        queue<string> q;
        unordered_set<string> vis;

        q.push(s);
        vis.insert(s);

        bool found = false;

        while(!q.empty()) {

            string curr = q.front();
            q.pop();

            if(isValid(curr)) {
                ans.push_back(curr);
                found = true;
            }

            if(found) continue;

            for(int i=0;i<curr.size();i++) {

                if(curr[i]!='(' && curr[i]!=')')
                    continue;

                string next =
                    curr.substr(0,i) +
                    curr.substr(i+1);

                if(vis.find(next)==vis.end()) {
                    vis.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};