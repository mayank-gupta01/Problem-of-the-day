class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        unordered_map<char,int>mp;
        for(auto it: allowed){
            mp[it]++;
        }

        for(auto word: words){
            int len = 0;
            for(auto it: word){
                if(mp.find(it)!=mp.end()){
                    len++;
                }
            }
            if(word.size() == len) ans++;
        }

        return ans;
    }
};