class Solution {
public:
    string maxSumOfSquares(int n, int sum) {
        string ans = "";

        for (int i = 0; i < n; i++) {
            int digit = min(9, sum);
            ans += to_string(digit);
            sum -= digit;
        }

        if (sum > 0) return "";

        return ans;
    }
};