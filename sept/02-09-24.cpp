#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i=0, ans = 0,n=chalk.size();
        long sum = 0;
        for(auto it: chalk){
            sum += it;
        }
        k = k%sum;
        while(i<n){
            if(chalk[i] <= k){
                k -= chalk[i];
            }
            else{
                return i;
            }
            i++;
        }

        return ans;
    }
};


int main() {
    Solution s;
    vector<int>chalk = {5,1,5};
    int k = 22;
    cout<<s.chalkReplacer(chalk, k)<<endl;
    return 0;
}