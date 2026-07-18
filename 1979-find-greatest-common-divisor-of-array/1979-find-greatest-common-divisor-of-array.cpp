class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int num1 = nums[0];
        int num2 = nums[nums.size() - 1];
        int maximum = max(num1 , num2) , count = 0;
        for(int i = 1 ; i <= maximum ; i++){
            if(num1 % i == 0 && num2 % i == 0){
                count = i;
            }
        }
        return count;
    }
};