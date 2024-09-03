#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        string res = "";

        //covert the string
        for(auto it: s){
            int val = it-'a'+1;
            string temp = to_string(val);
            res+=temp;
        }

        cout<<"res after convert: "<<res<<endl;

        //k times loop
        int res2;
        while(k--){
            res2 = 0;
            for(auto it: res){
                int val = it-'0';
                res2 += val;
            }
            res = to_string(res2);
        }

        return res2;
    }
};


int main() {
    Solution s;
    int k = 2;
    string str = "zbax";
    cout<<s.getLucky(str, k)<<endl;
    return 0;
}