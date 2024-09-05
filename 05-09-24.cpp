#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sumNM = mean*(n+m);
        int sumM=0;
        for(auto it: rolls) sumM += it;
        int sumN = sumNM - sumM;

        vector<int>ans;
        int maxSum = 6*n;
        if(maxSum < sumN || sumN < n) return ans;

        int rem = sumN%n, quo = sumN/n;
        for(int i=0;i<n;i++){
            if(rem) {
                ans.push_back(quo+1);
                rem--;
            }
            else ans.push_back(quo);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>rolls = {3,2,4,3};
    int mean = 4, n = 2;
    vector<int>ans = s.missingRolls(rolls, mean, n);
    cout<<"Missing vector is: ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
}