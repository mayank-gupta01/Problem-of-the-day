class Solution {
public:
    int minBitFlips(int start, int goal) {
        long long xor_res = start^goal;
        int ans =0;
        while(xor_res>0){
            int d = xor_res%2;
            if(d) ans++;
            xor_res/=2;
        }
        return ans;
    }
};