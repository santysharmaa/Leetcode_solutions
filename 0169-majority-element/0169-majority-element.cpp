class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        for (int j = 0; j < n; j++) {
            int c = 0;

            for (int i = 0; i < n; i++) {
                if (nums[j] == nums[i]) {
                    c++;
                }
            }

            if (c > n / 2)
                return nums[j];
        }

        return -1; 
    }
};