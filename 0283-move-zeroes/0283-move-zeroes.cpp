class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        for(int j {0}; j<n; j++){
            for(int i {0}; i<n-1; i++){
                if(nums[i] == 0){
                    int temp = nums[i];
                    nums[i] = nums[i+1];
                    nums[i+1] = temp;
                }
            }
        }
        for(int x : nums) cout<<x;
    }
};