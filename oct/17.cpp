class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size(), maxi = INT_MIN, maxIdx = -1, diff=0, repIdx1 = -1, repIdx2 = -1 ;
        for(int i=n-1;i>=0;i--){
            if(maxi < s[i] - '0'){
                maxi = s[i] - '0';
                maxIdx = i;
            }

            if(diff < s[maxIdx] - s[i] && i < maxIdx){
                repIdx1 = i;
                repIdx2 = maxIdx;
            }
        }

        if(repIdx1 != -1){
            swap(s[repIdx1], s[repIdx2]);
        }

        int ans = stoi(s);
        return ans;
    }
};