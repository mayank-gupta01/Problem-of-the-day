class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        vector<int>nums(n,0);
        for(int i=0;i<n;i++){
            if(s[i] == 'a') nums[i] = 1;
            else if(s[i]=='e') nums[i] = 2;
            else if(s[i]=='i') nums[i] = 4;
            else if(s[i] == 'o') nums[i] = 8;
            else if(s[i] == 'u') nums[i] = 16;
        }

        //find xor with target 0;
        unordered_map<int,int>mp;
        int xr = 0, ans = INT_MIN;
        for(int i=0;i<n;i++){
            xr = xr ^ nums[i];
            if(xr == 0) ans = max(ans, i+1);
            if(mp.find(xr) == mp.end() && xr!=0){
                mp[xr] = i; 
            }
            ans = max(ans, i-mp[xr]);
        }

        return ans;
    }
};