class Solution {
public:
    long long minimumSteps(string s) {
        long long n=s.size(), ans = 0, zeros = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '0'){
                zeros++;
            }
            else{
                ans += zeros;
            }
        }

        return ans;
    }
};