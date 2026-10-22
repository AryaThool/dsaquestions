class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 1 ; i*i <= nums.size() ; ++i){
            if(n % i == 0){
              res += nums[i-1] * nums[i-1];
              if(i*i != n){
                res += nums[n / i - 1] * nums[n / i - 1];
              }
            }
        }
        return res;
    }
};