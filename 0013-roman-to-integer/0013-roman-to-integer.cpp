class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {

            if (s[i] == 'M') ans += 1000;

            else if (s[i] == 'D') {
                if (i + 1 < n && s[i + 1] == 'M') {
                    ans += 500;
                    i++;
                    continue;
                }
                ans += 500;
            }

            else if (s[i] == 'C') {
                if (i + 1 < n && s[i + 1] == 'D') {
                    ans += 400;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'M') {
                    ans += 900;
                    i++;
                    continue;
                }
                ans += 100;
            }

            else if (s[i] == 'L') {
                if (i + 1 < n && s[i + 1] == 'D') {
                    ans += 450;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'M') {
                    ans += 950;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'C') {
                    ans += 50;
                    i++;
                    continue;
                }
                ans += 50;
            }

            else if (s[i] == 'X') {
                if (i + 1 < n && s[i + 1] == 'D') {
                    ans += 490;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'M') {
                    ans += 990;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'C') {
                    ans += 90;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'L') {
                    ans += 40;
                    i++;
                    continue;
                }
                ans += 10;
            }

            else if (s[i] == 'V') {
                if (i + 1 < n && s[i + 1] == 'D') {
                    ans += 495;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'M') {
                    ans += 995;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'C') {
                    ans += 95;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'L') {
                    ans += 45;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'X') {
                    ans += 5;
                    i++;
                    continue;
                }
                ans += 5;
            }

            else {
                if (i + 1 < n && s[i + 1] == 'D') {
                    ans += 499;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'M') {
                    ans += 999;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'C') {
                    ans += 99;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'L') {
                    ans += 49;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'X') {
                    ans += 9;
                    i++;
                    continue;
                }
                else if (i + 1 < n && s[i + 1] == 'V') {
                    ans += 4;
                    i++;
                    continue;
                }
                ans += 1;
            }
        }

        return ans;
    }
};