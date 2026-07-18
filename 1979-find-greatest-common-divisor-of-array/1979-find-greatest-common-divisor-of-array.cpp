class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = INT_MAX;
        int big = INT_MIN;

        for(int i {0}; i<nums.size(); i++){
            small = min(nums[i], small);
            big = max(nums[i], big);
        }

        return gcd(small,big);
        
    }
};