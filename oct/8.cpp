class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            char ch = s[i];

            if(ch == '['){
                cnt++;
            }
            else {
                if(cnt > 0) cnt--;
            }
        }

        return (cnt+1)/2;
    }
};