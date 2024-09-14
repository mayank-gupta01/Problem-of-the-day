class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(auto it: nums){
            maxi = max(maxi, it);
        }
        int count = 0, ans = 0;
        for(auto it : nums){
            if(it == maxi){
                count++;
                ans = max(ans, count);
            }
            else{
                count = 0;
            }
        }

        return ans;
    }
};