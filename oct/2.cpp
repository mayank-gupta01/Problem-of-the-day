class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp;
        for(auto it: arr){
            mp[it]=1;
        }
        
        int cnt = 1;
        for(auto it: mp){
            mp[it.first] = cnt;
            cnt++;
        }

        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            ans[i] = mp[arr[i]];
        }

        return ans;
    }
};