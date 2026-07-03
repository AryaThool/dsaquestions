class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int> temp(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0, num = nums[i];
            while (num > 0) {
                int lastDigit = num % 10;
                sum = sum + lastDigit;
                num = num / 10;
            }
            temp[i] = sum;
        }
        nums = temp;
        int min = *min_element(nums.begin(), nums.end());
        return min;
    }
};