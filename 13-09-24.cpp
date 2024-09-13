class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int qLen = queries.size(), n = arr.size();
        vector<int>ans(qLen);
        vector<int>xors(n);

        int xorr = 0;
        for(int i=0;i<n;i++){
            xorr ^= arr[i];
            xors[i] = xorr;
        }

        for(int i=0;i<qLen;i++){
            int start = queries[i][0];
            int end = queries[i][1];

            int res = xors[end];
            if(start>0){
                res ^= xors[start-1];
            }

            ans[i] = res;
        }

        return ans;
    }
};